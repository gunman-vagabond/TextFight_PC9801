#include <dos.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "nt.h"
#include "chara2.c"

#define MAXCHARA   20
#define MAXMT      20
#define ENTAMAMAX  100

/*void keyin();*/
/* keyin.obj とコンパイルするときこれは不要みたい*/

struct enemy {
	int no;
	int x;
	int y;
	int count;
	int katasa;
} en_dt[MAXCHARA];

struct tama {
	int x;
	int y;
} mytama[MAXMT];

struct entama {
	int x;
	int y;
	int vx;
	int vy;
} enetama[ENTAMAMAX];

int nowx = 2;
int nowy = 12;

int shotf;
int outf;
int dekaf=0;
int stepcount;
int shutugenwait = 1;
int power = 0;
int renshakankaku;
int pause;
int wait;

putchara(int chno, int x, int y)
{
	int co1,co2;
	int far *vram;
	
	vram = (int far *)0xa0000000;
	vram += x + 80*y;
	
	for(co1=0; co1<ch_data[chno].yw; co1 ++){
		for(co2 = 0; co2<ch_data[chno].xw; co2++){
			if((x + co2)<=79 &&(x + co2)>=0 && (y + co1)<=20 && (y + co1) >=3 )
				*(vram)= ch_data[chno].charag[co1*ch_data[chno].xw+co2];
			vram++;
		}
		vram += (80 - ch_data[chno].xw);
	}
				
}
clearchara(int chno, int x, int y)
{
	int co1,co2;
	int far *vram;
	
	vram = (int far *)0xa0000000;
	vram += x + 80*y;
	
	for(co1=0; co1<ch_data[chno].yw; co1 ++){
		for(co2 = 0; co2<ch_data[chno].xw; co2++){
			if((x + co2)<=79 &&(x + co2)>=0 && (y + co1)<=20 && (y + co1) >=3 )
/*			if((x + co2)<=79 && (y + co1)<=20)*/
				*(vram)= ' ';
			vram++;
		}
		vram += (80 - ch_data[chno].xw);
	}
				
}

void kabekaki(int startp, int y)
{
	int i;
	
	for(i = 0; i<80; i++){
		*vram_adr(i,y+0) = kabe[(i+startp)%4 + 0*4];
		*vram_adr(i,y+1) = kabe[(i+startp)%4 + 1*4];
		*vram_adr(i,y+2) = kabe[(i+startp)%4 + 2*4];
	}
}

void putbom(int no,int x, int y)
{
	int co1,co2;
	int far *vram;
	
	vram = (int far *)0xa0000000;
	vram += x + 80*y;
	
	for(co1=0; co1<3; co1 ++){
		for(co2 = 0; co2<5; co2++){
			if((x + co2)<=79 && (y + co1)<=20)
				*(vram)= bom[no][co1*5+co2];
			vram++;
		}
		vram += (80 - 5);
	}
}

void bakuhatu(int chno,int x,int y,int count)
{
	int i;
	int tmp;
	int dx,dy;
	
	if(count == 50){
		clearchara(chno,x,y);
		return;
	}
	count %= 3;
		if(ch_data[chno].xw >= 6) dx = random(ch_data[chno].xw - 4);
		else dx = 0;
		if(ch_data[chno].yw >= 4) dy = random(ch_data[chno].yw - 2);
		else dy = 0;
	
		putbom(count,x+dx,y+dy);
		beep(200*(count+1));

}

int noenemy()
{
	int i;
	
	for(i=0;i<MAXCHARA;i++){
		if(en_dt[i].no != 0)
			return 0;
	}
	return 1;
}

/*自分の弾と敵キャラとの当り判定*/
void atari()
{
	int enno;
	int mtno;
	int tmp;
	int chno;
	
	for(enno= 0; enno<MAXCHARA; enno++){
		if(((chno=en_dt[enno].no)!=0)&&en_dt[enno].count <100){
			for(mtno = 0; mtno<MAXMT; mtno++){
				if(mytama[mtno].x){
					if(((tmp = (mytama[mtno].x -en_dt[enno].x))<ch_data[chno].xw)
					 && tmp >=0){
						if(((tmp = (mytama[mtno].y - en_dt[enno].y))<ch_data[chno].yw)
					 	 && tmp >=0){
							if(-- en_dt[enno].katasa <= 0){
								en_dt[enno].count = 100;
								/*爆発させる*/
							}
							mytama[mtno].x = 0;
						}
					}
				}
			}
		}
	}
}

void enetamaset(int no,int x,int y,int vx, int vy)
{
	enetama[no].x = x*10;
	enetama[no].y = y*10;
	enetama[no].vx = vx;
	enetama[no].vy = vy;
}

#define TATE 15

void enetamaderu(int chno,int x,int y,int mode)
{
	int vx,vy;
	int i = 0;
	int type ;
	int tmp;
	
	/*mode =1:必ず弾出せmode*/
	
	if(mode == 1);
	else {
		if(shotp[chno] == 0) return;
		if(random(100)>shotp[chno]) return;
	}
	while(enetama[i].y){
		i++;
		if(i>ENTAMAMAX) return;
	}
	beep(30);
	type = tamatype[chno];
	if(type == 1){ 				/*普通の弾*/
		vx = (nowx -x);
		vy = (nowy -y);
		tmp = sqrt(vx*vx + 4*vy*vy);
		if(!tmp) tmp = 1;
		vx = 2* TATE * vx / tmp;
		vy = 2* TATE * vy / tmp;

		enetamaset(i,x+1,y+1,vx,vy);
	} else if(type == 2){ 		/*直進型*/
		enetamaset(i,x+1,y+1,-25,0);
	} else if(type == 3){ 		/*6方向*/
		enetamaset(i,x+2,y+1,-25,0);
		while(enetama[i].y){i++;if(i>ENTAMAMAX) return;}
		enetamaset(i,x+2,y+1,25,0);
		while(enetama[i].y){i++;if(i>ENTAMAMAX) return;}
		enetamaset(i,x+2,y+1,10,10);
		while(enetama[i].y){i++;if(i>ENTAMAMAX) return;}
		enetamaset(i,x+2,y+1,-10,10);
		while(enetama[i].y){i++;if(i>ENTAMAMAX) return;}
		enetamaset(i,x+2,y+1,10,-10);
		while(enetama[i].y){i++;if(i>ENTAMAMAX) return;}
		enetamaset(i,x+2,y+1,-10,-10);
	} else if(type == 4) {		/*グラディウスもどき*/
		enetamaset(i,x+2,y  ,-40,0);
		while(enetama[i].y){i++;if(i>ENTAMAMAX) return;}
		enetamaset(i,x-1,y+2,-40,0);
		while(enetama[i].y){i++;if(i>ENTAMAMAX) return;}
		enetamaset(i,x-1,y+4,-40,0);
		while(enetama[i].y){i++;if(i>ENTAMAMAX) return;}
		enetamaset(i,x+2,y+6,-40,0);
	}
}

void enetamamove()
{
	int i;
	int far *vram;
	
	for(i= 0;i<ENTAMAMAX; i++){
		if(enetama[i].y){
			vram = (int far *)0xa0000000;
			vram += enetama[i].x/10 + enetama[i].y/10 * 80;
			*vram = ' ';
			enetama[i].x += enetama[i].vx;
			enetama[i].y += enetama[i].vy;
			if(enetama[i].x > 790 || enetama[i].x < 0
			  ||enetama[i].y > 200 || enetama[i].y < 30){
				enetama[i].y = 0;
				enetama[i].x = 0;
			} else if((enetama[i].x/10 - nowx)>=0 && (enetama[i].x/10 - nowx)<5
				   &&(enetama[i].y/10 - nowy)>=0 && (enetama[i].y/10 - nowy)<3){
			  	outf=1;
/*putsxy(0,0,"typeA");*/
				enetama[i].y = 0;
				enetama[i].x = 0;
			} else {
				vram = (int far *)0xa0000000;
				vram += enetama[i].x/10 + enetama[i].y/10 * 80;
				*vram = 'o';
			}
		}
	}
}


void tamaderu()
{
	int i = 0;
	while(mytama[i].x){
		i++;
		if(i>=MAXMT) return;
	}
	
	if(power >= 2){				/*弾２個*/
		mytama[i].x = nowx + 5;
		mytama[i].y = nowy + 0;
		while(mytama[i].x){
			i++;
			if(i>=MAXMT) return;
		}
		mytama[i].x = nowx + 5;
		mytama[i].y = nowy + 2;
		beep(1000);
	} else {					/*弾１個*/
		mytama[i].x = nowx + 5;
		mytama[i].y = nowy + 1;
		beep(1000);
	}
	
}

void tamamove()
{
	int i;
	int far *vram;
	
	for(i= 0;i<MAXMT; i++){
		if(mytama[i].x){
			vram = (int far *)0xa0000000;
			vram += mytama[i].x + 80*mytama[i].y;
			*vram = ' ';
			vram += 2;
			mytama[i].x += 2;
			if(mytama[i].x > 79)
				mytama[i].x = 0;
			else 
				*vram = '=';
		}
	}
}


void mymove()
{
	clearchara(0,nowx,nowy);
	keyin();
	if(nowx < 0) nowx = 0;
	if(nowx > 70) nowx = 70;
	if(nowy < 3) nowy = 3;
	if(nowy > 18) nowy = 18;
	
	putchara(0,nowx,nowy);
	if(shotf) {
		tamaderu();
		shotf = 0;
	}
}

void enemymove()
{
	int i,c0,c1;
	int min_n;
	char movev;
	int diffx,diffy;
	int myx,myy;
	int min_myx,max_myx,min_myy,max_myy;
	int chno;
	

	for(i=0;i<MAXCHARA;i++){
		if((chno = en_dt[i].no)!=0){
			if(en_dt[i].count >=100){
				if(en_dt[i].count == 100+
							(ch_data[chno].yw-2)*(ch_data[chno].yw-2)+3){
					bakuhatu(chno, en_dt[i].x, en_dt[i].y,50);
	/*ｐｏｗｅｒ　ｕｐ*/
					if(chno == ('u'-'a')){
						power ++;
						if(power ==1) renshakankaku = 2;
					}
					en_dt[i].no = 0;
				} else {
					bakuhatu(chno, en_dt[i].x, en_dt[i].y,
								en_dt[i].count - 100);
					en_dt[i].count ++;
				}
			} else 
			{
			clearchara(chno, en_dt[i].x, en_dt[i].y);
			movev = ch_data[chno].movedt[en_dt[i].count ++];
			if(ch_data[chno].movedt[en_dt[i].count] == 0) en_dt[i].count = 0;
			switch(movev){
				case '1': en_dt[i].x-=2; en_dt[i].y+=1; break;
				case '2': 		  		 en_dt[i].y+=1; break;
				case '3': en_dt[i].x+=2; en_dt[i].y+=1; break;
				case '4': en_dt[i].x-=2;                break;
				case '5':					  		    break;
				case '6': en_dt[i].x+=2;				break;
				case '7': en_dt[i].x-=2; en_dt[i].y-=1; break;
				case '8':				 en_dt[i].y-=1; break;
				case '9': en_dt[i].x+=2; en_dt[i].y-=1; break;
				case 'z': en_dt[i].x-=4; en_dt[i].y+=2; break;
				case 'x':				 en_dt[i].y+=2; break;
				case 'c': en_dt[i].x+=4; en_dt[i].y+=2; break;
				case 'a': en_dt[i].x-=4;                break;
				case 'd': en_dt[i].x+=4;                break;
				case 'q': en_dt[i].x-=4; en_dt[i].y-=2; break;
				case 'w':                en_dt[i].y-=2; break;
				case 'e': en_dt[i].x+=4; en_dt[i].y-=2; break;
				case '0': 	/*弾だしてもいいよ*/
					enetamaderu(chno, en_dt[i].x, en_dt[i].y,0);
					break;										   
				case 'p': 	/*必ず弾出せ*/
					enetamaderu(chno, en_dt[i].x, en_dt[i].y,1);
					break;										   
																   
			}
			/*画面からはみでたら消去*/
			if(  en_dt[i].x < 1-ch_data[chno].xw 
			  || en_dt[i].x > 79 
			  || en_dt[i].y < 3 
			  || en_dt[i].y > 21-ch_data[chno].yw  ) {
					en_dt[i].no = 0;
			}
			if((chno = en_dt[i].no)!=0) 
				putchara(chno, en_dt[i].x, en_dt[i].y);
			enetamaderu(chno, en_dt[i].x, en_dt[i].y,0);
			
			/*自分と敵キャラとの当り判定*/
			if((diffx = (en_dt[i].x - nowx))<5 
			  &&(diffx)> -ch_data[chno].xw
			  &&(diffy = (en_dt[i].y - nowy))<3 
			  &&(diffy)> -ch_data[chno].yw){
				min_myx = max(diffx,0);
				max_myx = min(5,ch_data[chno].xw+diffx);
	/* min_tekix = min_myx - diffx */
				
				min_myy = max(diffy,0);
				max_myy = min(3,ch_data[chno].yw+diffy);
				
		  		for(myy=min_myy; myy<max_myy; myy++){
				  	for(myx=min_myx; myx<max_myx; myx++){
			  			if(  (charag[1][myx+5*myy]!=' ')
			  			   &&(charag[chno][(myx-diffx)
			  			  					+ch_data[chno].xw*(myy-diffy)]
			  			  		!=' ')  ){
						  	outf = 1;
							if((--(en_dt[i].katasa))==0)
							  	en_dt[i].count = 100;
						  	return;
			
						}
					}
				}
			}

			}
		}
	}
}


void dekashutugen(int chno)
{
	int i= 0;
	int co;
	

	switch(chno){
		case ('q'-'a') :
		case ('s'-'a') :

			while(en_dt[i].no != 0){
				i++;
				if(i>MAXCHARA) return;
			}
			en_dt[i].no = chno;
			if(maxcount[chno] == 0) en_dt[i].count = 0;
			else en_dt[i].count = random(maxcount[chno]);
			if(shutugen_x[chno]==0)
				en_dt[i].x = 10 + random(65);
			else
				en_dt[i].x = shutugen_x[chno];
			if(shutugen_y[chno]==0)
				en_dt[i].y = 3 + random(21-ch_yw[chno]);
			else
				en_dt[i].y = shutugen_y[chno];
		
			en_dt[i].katasa = katasa[chno];
			break;
			
		case ('r'-'a') :
			for(co=0;co<18;co++){
				while(en_dt[i].no != 0){
					i++;
					if(i>MAXCHARA) return;
				}
				en_dt[i].no = chno;
				en_dt[i].count = random(20);
				en_dt[i].y = 6 + random(7);
				en_dt[i].x = 50 + random(15);
				en_dt[i].katasa = katasa[chno];
			}
			break;
	}
	
}

void shutugen()
{
	int i= 0;
	char chno;
	char tmp;
	
	if(--shutugenwait > 0) return;
	chno = shutudat[stepcount] - 'a';
	if(chno == ('q'-'a') || chno == ('r'-'a') || chno == ('s' - 'a')){
		dekaf = 1;
/*		stepcount ++;*/
		dekashutugen(chno);
		return;
	}
	if(chno == ('0' - 'a')){
		stepcount ++;
		shutugenwait = 20;
		return;
	}
	if(waitcount[chno] == 0)
		shutugenwait = random(15);
	else 
		shutugenwait = waitcount[chno];
/*	if(random(10) > shutugenp[chno]) return;*/
	stepcount ++;
	if(shutudat[stepcount]==0) stepcount = 0;
	while(en_dt[i].no != 0){
		i++;
		if(i>MAXCHARA) return;
	}
	en_dt[i].no = chno;
	if(maxcount[chno] == 0) en_dt[i].count = 0;
	else en_dt[i].count = random(maxcount[chno]);
/*	if(movedt[chno][tmp] == 'j')
		en_dt[i].count += movedt[chno][tmp+1]*10;*/
	if(shutugen_x[chno]==0)
		en_dt[i].x = 10 + random(65);
	else
		en_dt[i].x = shutugen_x[chno];
	if(shutugen_y[chno]==0)
		en_dt[i].y = 3 + random(21-ch_yw[chno]);
	else if(shutugen_y[chno] == 1){
		en_dt[i].y = 6 + random(7);
		en_dt[i].x = 50 + random(15);
	} else
		en_dt[i].y = shutugen_y[chno];
		
	en_dt[i].katasa = katasa[chno];
}
		
void pausegame()
{
putsxy(35,12,"PAUSE");
if(getch() == 'q') exit(0);
putsxy(35,12,"     ");
}

move(){
int i,co;
int kabecount=0;
int deadx,deady;

while(1){
	kabekaki(kabecount/2,0);
	kabekaki((kabecount++)/2,21);
	if(kabecount ==4) kabecount = 0;
	if(!dekaf)
		shutugen();
	mymove();
tamamove();
	enemymove();
	if(outf) {
		break;
	/*	mybakuhatu();
		outf = 0;*/
	}
	tamamove();
	atari();
	enetamamove();
	for(co=0;co<wait;co++);
	mymove();
tamamove();
	for(co=0;co<wait;co++);
tamamove();
atari();
	if(dekaf){
		if(noenemy()){
			dekaf = 0;
		stepcount ++;
		}
	}
if(pause) pausegame();
		
}
	deadx=nowx; deady=nowy;
	for(i=0;i<=20;i++){
		bakuhatu(0,deadx,deady,i%3);
		if(!dekaf)
			shutugen();
		enemymove();
		tamamove();
		atari();
		enetamamove();
		for(co=0;co<wait;co++);
		tamamove();
		for(co=0;co<wait;co++);
		keyin();
if(pause) pausegame();
	}
	bakuhatu(0,nowx,nowy,3);
	outf = 0;

}

void init()
{
	int i;
	
	wait = 20000;
	for(i=0;i<MAXCHARA;i++)
		en_dt[i].no = 0;
	for(i=0;i<ENTAMAMAX;i++){
		enetama[i].y = 0;
		enetama[i].x = 0;
	}
	for(i=0;i<MAXMT;i++)
		mytama[i].x = 0;
	nowx = 2;
	nowy = 12;
	shutugenwait = 1;
	dekaf = 0;
	stepcount = (stepcount-0) /10 *10;
	if(stepcount <0) stepcount = 0;
	power = 0;
	renshakankaku = 5;
}

main(int argc,char **argv)
{
	randomize();
	while(1){
	printf("\x1b*");
	funcclear();
	init();
	move();
}
}
