/*#define MAXENEMYNO 9*/

char *movedt[] = {{""},
			/*      1234567890123456789012345678901234567890123456789012345 */
		/*b*/	  {"444444444411111111444444444477777777"},
		/*c*/	  {"444444447711p5p55500044444"},
		/*d*/	  {"7aa7aa7aa7aa7aa7aa0009dd9dd9dd9dd9dd9dd1aa1aa1aa1aa1aa1aa0003dd3dd3dd3dd3dd3dd"},
		/*e*/	  {"1111771777111177177711111771777711771777177111171777117"},
		/*f*/	  {"454545"},
		/*g*/	  {"aaaaaaaaaaaaaaaa7aa7aa77a77a8888"},
		/*h*/	  {"444444444444444888666666222444444444444444222666666888"},
		/*i*/	  {"777aaaaaaaa111222333ddddd998877aaa123d98aaaaaaaaaaaaaaaaa"},
		/*j*/	  {"4070704040101040"},
		/*k*/	  {"404040404040404040404040404040404040404040404040404040404040404040404040404040404040404040wwwwwwwwwwwwwwwwwwww"},
		/*l*/	  {"40404040404040404040400000000060606060606060606060"},
		/*m*/	  {"400400400400400000ww88747400401414141z4z"},
		/*n*/	  {"87774774474441441141112233363366369669969998"},
		/*o*/	  {"404040404040404040404040404040404040404040404040404040404040404040404040404040404040a6a6a6xxxxxxxxxxxxxxxxxxxx"},
		/*p*/	  {"444414414414414100606060606000802000000047aaa7aa77aaqaaaqaaaqaaqaqaqq"},
		/*q*/	  {"222222ppp888888ppp88888ppp22222ppp"},
		/*r*/	  {"48562545p268554586524268aqazazaqpdcdcdede"},
		/*s*/	  {"4p4p4p4554p4p4p4p4p4p4p4p4p6p6p6556p6p6p6p6p6p6p6p6p6p"},
		/*t*/	  {"40404040404040404040zzzzzz1404040404040404040408wwwwww"},
		/*u*/     {"4444444444874747744744144114141223636336636696699696986666666666666"},
		/*v*/	  {"45"},
				  {"   "}

				  };
/*char *shutudat = {"u000u000ttttbbbbbbbbbbbttbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsbooooooooobbobbobbobbobbobbobbo0r0bbbbbbbbbbbbbbqrbbbbcbbbbbcbbbbbcbbdbcdddddbdcdbddddddddddcdddddfdhhhhdhhhdhhhfhhhhhdhfhhhhfhhhhhhhhiiiiiiklklklklklggghggghggfgggggfggcggggggggcgeegcegceeeceeeeeeeeeeeceekkkkkkkkkkkkjbebjebdbjbcbjbbejbbjbjbbjomoooomoooomomoon000rrrrrrrrrrrrrrrrr000000000000000000000000q0000000000ppppppppppppppppp"};*/
char *shutudat = {"vqbbbbbbbbbbbbbbbbbbbbbbbubbbcbbfbbbbbcbfbbbbbcbbbbcbbfbbbcbfbbbbcbfbbbcbbbfbbbbbubbbbbbbdfddddddcdddddcddddfdddfddddddducddddddfdddggggggegggggggeggggggggegggegggeggcgggggq00bbbbbbbbbbbbbfbbbbbbbubbbbcbbfbbcbbiciiifiiiifiiiiciifikpkkppkpkppkppkppkpkpukpppkkkjnjnnnjnnnnjnjj00s00bbbttllllttuttllllfllflcctommoommmooomuomoobbeegggeeooo0r00"};

					/* a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u,*/
int maxcount[] 		= {1,36,24,20,55, 5,54,32, 2, 2,60,10,15, 1,60, 4, 0, 0, 0,20, 0, 1,1};
int shotp[] 		= {0, 1, 2,10,10, 1, 5, 1, 0, 1, 1,10, 3, 5, 0, 3, 0, 0, 0, 0,10, 0,1};
int ch_xw[]			= {5, 5, 5, 5, 5, 5, 5, 5, 5, 9, 5, 5, 5, 7, 5, 5,14, 9,19,15, 5,10,1};
int ch_yw[] 		= {3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 3, 3, 3, 4, 3, 3, 7, 4, 7, 5, 3, 4,1};
int waitcount[]     = {0, 0, 0, 0, 0, 0, 0, 0, 0,15, 6, 0,12,50, 0, 0,50, 1, 1,10, 0, 0,1};
int tamatype[] 		= {0, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1,1};
int katasa[] 		= {0, 1, 1, 1, 2, 1, 1, 3, 5, 5, 1, 1, 5,10,10, 1,99,10,99,500,8,99,1};
int shutugen_x[] 	= {0,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,55, 0,70,70,79,79,1};
int shutugen_y[] 	= {0, 0,18, 0, 0, 3, 0, 0, 0, 0,18, 0,18,10, 3, 0, 8, 1,14, 3,10,17,1};

char *charag[] = {" -_, mc>=- -~' ",
			/*a)   mc>=-	*/
			/*      -~' 	*/
				  "  ^  =o#><  v  ",
  			/*b)   =o#><	*/	
            /*       v  	*/
				  "-==e< (cP /::::",
			/*c)    (cP  	*/
			/*     /:::: 	*/
                  "/<#>={IHB-/<#>=",
            /*d)   {IHB- 	*/
            /*     /<#>= 	*/
				  ",*#*,##o##'*#*'",
			/*e)   ##o##    */
			/*     '*#*'    */
                  "+++++ +++ -=OK)",
            /*f)    +++  	*/
            /*     -=OK) 	*/
                  "-=B__*(OH:-=B~~",
            /*g)   *(OH:  	*/
            /*     -=B~~ 	*/
            	  "-WWWc=|O:[-MMMc",
            /*h)   =|O:[ 	*/
            /*	   -MMMc 	*/
                  " O-) O*O-) O-) ",
			/*i)   O*O-) 	*/
			/*      O-)  	*/
				  "   I|E   ,  I|E  ^*(O ==##='  I|E  v   I|E   ",
			/*j)   ,  I|E  ^	*/
			/*     *(O ==##=	*/
			/*     '  I|E  v	*/
			/*        I|E   	*/
				  " +^+ d=H=b .M. ",
			/*k)   d=H=b 	*/
			/*	    .M. 	*/
			      " <<< B)))- <<< ",
			/*l)   B)))- 	*/
			/*      <<< 	*/
				  " /~~%<o/ /()_/ ",
			/*m)   <o/ / 	*/
			/*	   ()_/ 	*/
			      " XXXXX ((=)=))(=)=)=) XXXXX ",
			/*n)   ((=)=))	*/
			/*     (=)=)=)  */
			/*      XXXXX   */
				  "vV/vV %Vv/ \"V  ",
			/*o)    %Vv/	*/ 
			/*      "V 		*/
				  "=-.-=(]Dx*_,m__",
			/*p)   (]Dx*	*/
			/*	   _,m__ 	*/
/*q)   -<##++++   
	  ,,KHD>})]   
	====I*HB>}))] 
	||||O#HBD>}))]
	====I*HB>}))] 
	  ''KHD>})]   
	   -<##++++   */
	   			  "   -<##++++     ,,KHD>})]   ====I*HB>}))] ||||O#HBD>}))]====I*HB>}))]   ''KHD>})]      -<##++++   ",
   				  " .(o))), O))()c)))((()O)c() \"(o())' ",
   			/*r)   O))()c))) 	*/
   			/*     ((()O)c() 	*/
   			/*      "(o())'  	*/
/*	^_____ /~~~~%
s)	v-----/_ [] _%
	  _______________
	 /ooooooooooooooo%
	<() l () l ()l  ()>
	 %ooooooooooooooo/
	  ~~~~~~~~~~~~~~~   */
			"^_____ /~~~~%      v-----/_ [] _%       _______________   /ooooooooooooooo% <() l () l ()l  ()> %ooooooooooooooo/   ~~~~~~~~~~~~~~~  ",
/*	 ^>-<^/  ^</>
t)	<L<^>%<^</K>,1>
	 </<vLv><xVv<>"
	<>-><vV>Xv>~<V>
	 <V/v  <V~Kv>>  */
			" ^>-<^/  ^</>  <L<^>%<^</K>,1> </<vLv><xVv<>\"<>-><vV>Xv>~<V> <V/v  <V~Kv>> ",
			"/---%l<P>l%---/",
	/*u)     l<P>l 	*/
	/*       %---/ 	*/
/*	   €EI÷   
v)	  E=HTEH  
	 I=IEITHI 
	EHI=IE=€÷H*/
			"   €EI÷     E=HTEH   I=IEITHI EHI=IE=€÷H",


	         "             "
            };
            

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
