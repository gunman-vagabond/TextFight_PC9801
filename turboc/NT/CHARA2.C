
struct ch_dat {
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
	
	
} ch_data[] = {
	{
	/*	    -_   	*/
	/*a)   mc>=-	*/
	/*      -~' 	*/
		0,
		" -_, mc>=- -~' ",
		"",
		0,0,0,0,5,3,0,0,0
	},
	{
		/*       ^ 
  		  b)   =o#><		
                 v  	*/
        1,
		"  ^  =o#><  v  ",
		{"444444444411111111444444444477777777"},
		36,1,1,1,
		5,3,79,0,0
	},{2,

			/*	   -==e<	*/
			/*c)    (cP  	*/
			/*     /:::: 	*/
		"-==e< (cP /::::",
		/*c*/	  {"444444447711p5p55500044444"},
		24,0,1,1,
		5,3,79,18,0
	},{3,
            /*     /<#>=    */
            /*d)   {IHB- 	*/
            /*     /<#>= 	*/

            "/<#>={IHB-/<#>=",
		/*d*/	  {"7aa7aa7aa7aa7aa7aa7aa7aappp9dd9dd9dd9dd9dd9dd9dd9dd1aa1aa1aa1aa1aa1aa1aa1aappp3dd3dd3dd3dd3dd3dd3dd3dd"},
		20,0,1,2,
		5,3,79,0,0
	},{4,
			/*	   ,*#*,	*/
			/*e)   ##o##    */
			/*     '*#*'    */
	
			  ",*#*,##o##'*#*'",
		/*e*/	  {"1111771777111177177711111771777711771777177111171777117"},
		55,10,3,3,
		5,3,79,0,0
	},{5,
            /*     +++++    */
            /*f)    +++  	*/
            /*     -=OK) 	*/
     
             "+++++ +++ -=OK)",
		/*f*/	  {"45"},
		0,5,1,1,
		5,3,79,3,0
	},{6,
            /*     -=B__    */
            /*g)   *(OH:  	*/
            /*     -=B~~ 	*/
    
              "-=B__*(OH:-=B~~",
		/*g*/	  {"aaaaaaaaaaaqaaqaaqqaqqawwwwwwwwwwaaaaaaaaaaazaazaazzazzaxxxxxxxxxx"},
		32,1,1,1,
		5,3,79,0,0
	},{7,
            /*	   -WWWc    */
            /*h)   =|O:[ 	*/
            /*	   -MMMc 	*/
    
        	  "-WWWc=|O:[-MMMc",
		/*h*/	  {"444444444444444888666666222444444444444444222666666888"},
		54,5,1,5,
		5,3,79,0,0
	},{8,
            /*      O-)     */
			/*i)   O*O-) 	*/
			/*      O-)  	*/
           
	       " O-) O*O-) O-) ",
		/*i*/	  {"777aaaaaaaa111222333ddddd998877aaa123d98aaaaaaaaaaaaaaaaa"},		2,1,1,5,
		5,3,79,0,0
	},{9,
			/*	      I|E       */
			/*j)   ,  I|E  ^	*/
			/*     *(O ==##=	*/
			/*     '  I|E  v	*/
			/*        I|E   	*/
		
		  "   I|E   ,  I|E  ^*(O ==##='  I|E  v   I|E   ",
		/*j*/	  {"4070704040101040"},
		10,2,1,10,
		9,5,79,0,15
	},{10,
			/*	    +^+     */
			/*k)   d=H=b 	*/
			/*	    .M. 	*/
		
		  " +^+ d=H=b .M. ",
		/*k*/	  
{"40404040404040404040404040404040404040404040404040404040404040404040404040404040wwwwwwwwwwwwwwwwwwww"},
		60,1,1,2,
		5,3,79,18,6
	},{11,
			/*      <<<     */
			/*l)   B)))- 	*/
			/*      <<< 	*/
		
	      " <<< B)))- <<< ",
		/*l*/	  {"404040404040404040404000000000606060606060606060606060"},
		10,8,1,1,
		5,3,79,0,0
	},{12,
			/*	    /~~%    */
			/*m)   <o/ / 	*/
			/*	   ()_/ 	*/
	
			  " /~~%<o/ /()_/ ",
		/*m*/	  {"400400400400400000ww88747400401414141z4z"},
		15,3,1,2,
		5,3,79,0,0
	},{13,
			/*      XXXXX   */
			/*n)   ((=)=))	*/
			/*     (=)=)=)  */
			/*      XXXXX   */
	
		      " XXXXX ((=)=))(=)=)=) XXXXX ",
		/*n*/	  {"87774774474441441141112233363366369669969998"},
		1,5,2,10,
		7,4,79,10,30
	},{14,
			/*	   vV/vV    */
			/*o)    %Vv/	*/ 
			/*      "V 		*/
		
		  "vV/vV %Vv/ \"V  ",
		/*o*/	  {"404040404040404040404040404040404040404040404040404040404040404040404040404040404040a6a6a6xxxxxxxxxxxxxxxxxxxx"},
		60,0,1,10,
		5,3,79,3,0
	},{15,
			/*	   =-.-=    */
			/*p)   (]Dx*	*/
			/*	   _,m__ 	*/
	
			  "=-.-=(]Dx*_,m__",
		/*p*/	  {"444414414414414100606060606000802000000047aaa7aa77aaqaaaqaaaqaaqaqaqq"},
		4,3,1,1,
		5,3,79,0,0
	},{16,
/*q)   -<##++++   
	  ,,KHD>})]   
	====I*HB>}))] 
	||||O#HBD>}))]
	====I*HB>}))] 
	  ''KHD>})]   
	   -<##++++   */
	
 	  "   -<##++++     ,,KHD>})]   ====I*HB>}))] ||||O#HBD>}))]====I*HB>}))]   ''KHD>})]      -<##++++   ",
		/*q*/	  {"222222ppp888888ppp88888ppp22222ppp"},
		0,0,4,100,
		14,7,55,8,50
	},{17,
   			/*	    .(o))),     */
   			/*r)   O))()c))) 	*/
   			/*     ((()O)c() 	*/
   			/*      "(o())'  	*/
   	
			  " .(o))), O))()c)))((()O)c() \"(o())' ",
		/*r*/	  {"48562545p268554586524268aqazazaqpdcdcdede"},
		0,0,1,10,
		9,4,0,0,1
	},{18,
/*	^_____ /~~~~%
s)	v-----/_ [] _%
	  _______________
	 /ooooooooooooooo%
	<() l () l ()l  ()>
	 %ooooooooooooooo/
	  ~~~~~~~~~~~~~~~   */
			"^_____ /~~~~%      v-----/_ [] _%       _______________   /ooooooooooooooo% <() l () l ()l  ()> %ooooooooooooooo/   ~~~~~~~~~~~~~~~  ",
		/*s*/	  {"4p4p4p4554p4p4p4p4p4p4p4p4p6p6p6556p6p6p6p6p6p6p6p6p6p"},
		0,0,1,100,
		19,7,70,14,50
	},{19,
/*	 ^>-<^/  ^</>
t)	<L<^>%<^</K>,1>
	 </<vLv><xVv<>"
	<>-><vV>Xv>~<V>
	 <V/v  <V~Kv>>  */
			" ^>-<^/  ^</>  <L<^>%<^</K>,1> </<vLv><xVv<>\"<>-><vV>Xv>~<V> <V/v  <V~Kv>> ",
		/*t*/	  {"40404040404040404040zzzzzz1404040404040404040408wwwwww"},
		20,0,0,500,
		15,5,79,3,10
	},{20,
	/*		 /---%l */
	/*u)     l<P>l 	*/
	/*       %---/ 	*/
	
		"/---%l<P>l%---/",
		/*u*/     {"4444444444874747744744144114141223636336636696699696986666666666666"},
		0,8,1,8,
		5,3,79,10,0
	},{21,
/*	   ﾛEIﾖ   
v)	  E=HTEH  
	 I=IEITHI 
	EHI=IE=ﾛﾖH*/

			"   ﾛEIﾖ     E=HTEH   I=IEITHI EHI=IE=ﾛﾖH",
		/*v*/	  {"45"},
		1,0,0,500,
		10,4,79,17,0
	}
	
	/*  
	no,
	*charag,
	*movedt,
	maxcount,shotp,tamatype,katasa,
	xw,yw,shutugen_x,shutugen_y,waitcount 
	*/
};



char *o_shutudat = {"abcdedcbavqbbbbbbbbbbbbbbbbbbbbbbbubbbcbbfbbbbbcbfbbbbbcbbbbcbbfbbbcbfbbbbcbfbbbcbbbfbbbbbubbbbbbbdfddddddcdddddcddddfdddfddddddducddddddfdddggggggegggggggeggggggggegggegggeggcgggggq00bbbbbbbbbbbbbfbbbbbbbubbbbcbbfbbcbbiciiifiiiifiiiiciifikpkkppkpkppkppkppkpkpukpppkkkjnjnnnjnnnnjnjj00s00bbbttllllttuttllllfllflcctommoommmooomuomoobbeegggeeooo0r00"};


char *bom[] = {"(@))/@)%X)/(),)",
			/*  @)%X) 		*/
			/*  /(),)		*/
			   "`((')(X`@)%(+)Q",
			/*  (X`@) 		*/
			/*  %(+)Q  		*/
			   " . ,`; .:%, : '"
			/*  ; .:% 		*/
			/*  , : ' 		*/
			};

char *kabe = {"HE=EE=EHEHE="};
