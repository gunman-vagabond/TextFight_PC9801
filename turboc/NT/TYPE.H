extern struct ch_dat {
	int no;
	char *charag;
	char *movedt;
	int maxcount;
	/* random(maxcount)　にて出現時の movedt のポインタ？を決定
		０なら movedt[0]　から読む*/
	int shotp,tamatype;
	/*	shotp : random(100)>shotp で弾発射 
		10 だと結構出す　
		0 でもmovedt にpを書いておけば弾発射*/
	int katasa;
	int xw,yw;
	int shutugen_x,shutugen_y;
	int waitcount;
	/* waitcount : 次に出現するキャラまでの待ちカウント
					０の時は random(15)　
		廃止案が持ち上がっている*/
	
	
} ch_data[];

extern struct shutu_p {
	int chara_no;
	int loc_x,loc_y;
	int count;
	int wait;
} shutu_patarn[];

extern char *bom[];
extern char *kabe;
