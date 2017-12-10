#include<dos.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
#include<iostream.h>

struct bri
{
 int pos[2],cha,l;
};

struct
    {long double sta_cha,sta_bat[3],sta_del[3];
    }j;

class player
{
 public:
  long score;
  int diff,chance,level,sno,n,de,ali;
  float cri;
  char name[15];
  bri T[4][42];
  player(char ch)
  {
    clrscr();
    fstream f;
        fstream fi("game.dat",ios::binary|ios::in|ios::out);
    fi.read((char*)&j,sizeof(j));
    fi.close();
    f.open("player.dat",ios::in|ios::binary);
    f.seekg(0,ios::end);
    int i=f.tellp()/sizeof(Pla);
    f.close();
    cout<<"Enter Player "<<i+1<<" Name : ";
    gets(name);
    cout<<"Enter Difficulty    : ";
    do
    {cin>>diff;}
    while(diff!=1&&diff!=2&&diff!=3);
    sno=++i;
    score=-1;
    chance=j.sta_cha;
    level=0;
    ali=1;
    if(diff==1)
    {
     n=j.sta_bat[0];de=j.sta_del[0];
    }
    else if(diff==2)
    {
     n=j.sta_bat[1];de=j.sta_del[1];
    }
    else
    {
     n=j.sta_bat[2];de=j.sta_del[2];
    }
    fn(T);
   }
   player()
   {
   }
}Pla;

void Intro()
{
  int j,k;
  _setcursortype(0);
  char cho,a[]="Ze' MAEStAS Gaming Centre";
  textbackground(CYAN);
  textcolor(RED);
  clrscr();
  for(int e=1;e<=13;e++)
  {
   gotoxy(36,e);
   delay(20);
   cout<<"M" ;
   gotoxy(36,e-1);
   cout<<" ";
  }
  delay(50);
  for( e=1;e<=13;e++)
  {
   gotoxy(37,e);
   delay(20);
   cout<<"A";
   gotoxy(37,e-1);
   cout<<" ";
  }
  delay(50);
  for( e=1;e<=13;e++)
  {
   gotoxy(38,e);
   delay(20);
   cout<<"E";
   gotoxy(38,e-1);
   cout<<" ";
  }
  delay(50);
  for( e=1;e<=13;e++)
  {
   gotoxy(39,e);
   delay(20);
   cout<<"S";
   gotoxy(39,e-1);
   cout<<" ";
  }
  delay(50);
  for( e=1;e<=13;e++)
  {
   gotoxy(40,e);
   delay(20);
   cout<<"t";
   gotoxy(40,e-1);
   cout<<" ";
  }
  delay(50);
  for( e=1;e<=13;e++)
  {
   gotoxy(41,e);
   delay(20);
   cout<<"A";
   gotoxy(41,e-1);
   cout<<" ";
  }
  delay(50);
  for( e=1;e<=13;e++)
  {
   gotoxy(42,e);
   delay(20);
   cout<<"S";
   gotoxy(42,e-1);
   cout<<" ";
  }
  delay(500);
  gotoxy(62,22);
  cout<<"By :";
  for(int r=25;r<=66;r++)
  {
   gotoxy(r,23);delay(20);
   cout<<"Abishek Raj V.G";
   gotoxy(r-1,23);
   cout<<" ";
  }
  for(int o=25;o<=66;o++)
  {
   gotoxy(o,24);
    cout<<"Deepak .B";
   delay(20);
   gotoxy(o-1,24);
    cout<<" ";
  }
  for(int m=25;m<=66;m++)
  {
   gotoxy(m,25);
   delay(20);
   cout<<"Joe. S. Thomas";
   gotoxy(m-1,25);
   cout<<" ";
  }
  delay(5000);
  textbackground(CYAN);
  textcolor(RED+BLINK);
  clrscr();
  for(j=0;a[j];j++)
  {
   gotoxy(29+j,13);
    cout<<a[j];
   delay(150);
  }
  delay(1000);
  clrscr();
}
void Intro(int e)
{
   clrscr();
   textbackground(BLUE + BLINK);
   textcolor(WHITE);
   clrscr();
   cout<<"\n\t\t\t\t       JUGGLER\n\t\t\t\t       _______\n\n\n\n\n\n";
   for(e=45;e>=2;e--)
   {
    gotoxy(e,11);
    delay(30);
    cout<<"1. PLAY THE GAME";
    gotoxy(e+16,11);
    cout<<" ";
   }
   for(e=45;e>=2;e--)
   {
    gotoxy(e,12);
    delay(30);
    cout<<"2. LEADERBOARD";
    gotoxy(e+14,12);
    cout<<" ";
   }
   for(e=45;e>=2;e--)
   {
    gotoxy(e,13);
    delay(30);
    cout<<"3. HOW TO PLAY";
    gotoxy(e+14,13);
    cout<<" ";
   }
   for(e=45;e>=2;e--)
   {
    gotoxy(e,14);
    delay(30);
    cout<<"4. EXIT";
    gotoxy(e+7,14);
    cout<<" ";
   }
   textbackground(BLUE + BLINK);
   textcolor(WHITE);
   clrscr();
   cout<<"\n\t\t\t\t       JUGGLER\n\t\t\t\t       _______\n\n\n\n\n\n\n\n 1. PLAY THE GAME\n 2. LEADERBOARD\n 3. HOW TO PLAY\n 4. EXIT";
}
inline void BRICK(bri B[4][42],int e,int d)
{
 if(B[e][d].l&&e>=0&&e<4)
 {
  gotoxy(B[e][d].pos[0],B[e][d].pos[1]);
   cout<<char(B[e][d].cha);
 }
}
void Cheat(bri a[4][42],int f)
{
 for(int k=0;k<42;k++)
 {
  a[f][k].pos[0]=0;
  a[f][k].pos[1]=0;
  a[f][k].cha=0;
  a[f][k].l=0;
 }
}
void fn(bri a[4][42])
{
 int j,k;
 for(j=0;j<4;j++)
  for(k=0;k<42;k++)
  {
   a[j][k].pos[0]=0;
   a[j][k].pos[1]=0;
   a[j][k].cha=0;
   a[j][k].l=0;
  }
 for(j=0;j<11;j++)
 {
  a[0][j].pos[0]=35+j;
  a[0][j].pos[1]=11;
  a[0][j].cha=2;
  a[0][j].l=1;
 }
 for(j=0;j<7;j++)
 {
  a[1][j].pos[0]=29+j;
  a[1][j].pos[1]=11;
  a[1][j].cha=2;
  a[1][j].l=1;
 }
 for(j=7;j<14;j++)
 {
  a[1][j].pos[0]=38+j;
  a[1][j].pos[1]=11;
  a[1][j].cha=2;
  a[1][j].l=1;
 }
 for(j=0;j<5;j++)
 {
  a[2][j].pos[0]=32+j;
  a[2][j].pos[1]=8;
  a[2][j].cha=2;
  a[2][j].l=1;
 }
 for(;j<10;j++)
 {
  a[2][j].pos[0]=39+j;
  a[2][j].pos[1]=8;
  a[2][j].cha=2;
  a[2][j].l=1;
 }
 for(;j<15;j++)
 {
  a[2][j].pos[0]=26+(j-10);
  a[2][j].pos[1]=11;
  a[2][j].cha=2;
  a[2][j].l=1;
 }
 for(;j<20;j++)
 {
  a[2][j].pos[0]=38+(j-15);
  a[2][j].pos[1]=11;
  a[2][j].cha=2;
  a[2][j].l=1;
 }
 for(;j<25;j++)
 {
  a[2][j].pos[0]=51+(j-20);
  a[2][j].pos[1]=11;
  a[2][j].cha=2;
  a[2][j].l=1;
 }
  for(j=0;j<5;j++)
 {
  a[3][j].pos[0]=6+j;
  a[3][j].pos[1]=6;
  a[3][j].cha=2;
  a[3][j].l=1;
  a[3][j+5].pos[0]=37+j;
  a[3][j+5].pos[1]=6;
  a[3][j+5].cha=2;
  a[3][j+5].l=1;
  a[3][j+10].pos[0]=69+j;
  a[3][j+10].pos[1]=6;
  a[3][j+10].cha=2;
  a[3][j+10].l=1;
 }
 k=0;
 for(j=15;j<19;j++,k++)
 {
  a[3][j].pos[0]=6+k;
  a[3][j].pos[1]=12;
  a[3][j].cha=2;
  a[3][j].l=1;
  a[3][j+4].pos[0]=69+k;
  a[3][j+4].pos[1]=12;
  a[3][j+4].cha=2;
  a[3][j+4].l=1;
 }
 k=0;
 for(j=23;j<28;j++,k++)
 {
  a[3][j].pos[0]=11;
  a[3][j].pos[1]=7+k;
  a[3][j].cha=2;
  a[3][j].l=1;
  a[3][j+5].pos[0]=68;
  a[3][j+5].pos[1]=7+k;
  a[3][j+5].cha=2;
  a[3][j+5].l=1;
 }
 a[3][34].pos[0]=37;
 a[3][34].pos[1]=12;
 a[3][34].cha=2;
 a[3][34].l=1;
 a[3][35].pos[0]=41;
 a[3][35].pos[1]=12;
 a[3][35].cha=2;
 a[3][35].l=1;
 a[3][36].pos[0]=36;
 a[3][36].pos[1]=11;
 a[3][36].cha=2;
 a[3][36].l=1;
 a[3][37].pos[0]=37;
 a[3][37].pos[1]=10;
 a[3][37].cha=2;
 a[3][37].l=1;
 a[3][38].pos[0]=38;
 a[3][38].pos[1]=11;
 a[3][38].cha=2;
 a[3][38].l=1;
 a[3][39].pos[0]=40;
 a[3][39].pos[1]=11;
 a[3][39].cha=2;
 a[3][39].l=1;
 a[3][40].pos[0]=41;
 a[3][40].pos[1]=10;
 a[3][40].cha=2;
 a[3][40].l=1;
 a[3][41].pos[0]=42;
 a[3][41].pos[1]=11;
 a[3][41].cha=2;
 a[3][41].l=1;
}
void BAT(int a,int n)
{
 for(int j=0;j<n;j++)
 {
  gotoxy(a+j,23);
  cout<<char(-33);
 }
}

inline void BAL(int a,int b)
{
 gotoxy(a,b);
 cout<<'o';
}
void CH(bri B[4][42],int a,int b,int fi,int &e,long &f)
{
  int j,i;
  for(j=0;j<42;j++)
  {
   if(B[fi][j].l&&a+1==B[fi][j].pos[0]&&b+1==B[fi][j].pos[1])
   {
    B[fi][j].cha--;
    for(i=0;i<42;i++)
     BRICK(B,fi,i);
    if(!B[fi][j].cha)
    {
     B[fi][j].l--;
     for(i=0;i<42;i++)
      BRICK(B,fi,i);
     f+=1000;
    }
    for(i=0;i<42;i++)
     BRICK(B,fi,i);
    if(e==3)
     e=2;
    else if(e==4)
     e=1;
    else if(e==2)
     e=3;
    else if(e==1)
     e=4;
   }
   else if(B[fi][j].l&&a-1==B[fi][j].pos[0]&&b-1==B[fi][j].pos[1])
   {
    B[fi][j].cha--;
    for(i=0;i<42;i++)
     BRICK(B,fi,i);
    if(!B[fi][j].cha)
    {
     B[fi][j].l--;
     for(i=0;i<42;i++)
      BRICK(B,fi,i);
     f+=1000;
    }
    for(i=0;i<42;i++)
     BRICK(B,fi,i);
    if(e==3)
     e=2;
    else if(e==4)
     e=1;
    else if(e==2)
     e=3;
    else if(e==1)
     e=4;
   }
   else if(B[fi][j].l&&a+1==B[fi][j].pos[0]&&b-1==B[fi][j].pos[1])
   {
    B[fi][j].cha--;
    for(i=0;i<42;i++)
     BRICK(B,fi,i);
    if(!B[fi][j].cha)
    {
     B[fi][j].l--;
     for(i=0;i<42;i++)
      BRICK(B,fi,i);
     f+=1000;
    }
    for(i=0;i<42;i++)
     BRICK(B,fi,i);
    if(e==3)
     e=2;
    else if(e==4)
     e=1;
    else if(e==2)
     e=3;
    else if(e==1)
     e=4;
   }
   else if(B[fi][j].l&&a-1==B[fi][j].pos[0]&&b+1==B[fi][j].pos[1])
   {
    B[fi][j].cha--;
    for(i=0;i<42;i++)
     BRICK(B,fi,i);
    if(!B[fi][j].cha)
    {
     B[fi][j].l--;
     for(i=0;i<42;i++)
      BRICK(B,fi,i);
     f+=1000;
    }
    for(i=0;i<42;i++)
     BRICK(B,fi,i);
    if(e==3)
     e=2;
    else if(e==4)
     e=1;
    else if(e==2)
     e=3;
    else if(e==1)
     e=4;
   }
  }
}
int CH(bri B[4][42],int fi)
{
  for(int j=0;j<42;j++)
   if(B[fi][j].l)
    return 0;
 return 1;
}
void TAB(int a,int n)
{
 for(int j=0;j<n;j++)
 {
  gotoxy(a+j,23);
  cout<<' ';
 }
}
inline void LAB(int a,int b)
{
 gotoxy(a,b);
 cout<<' ';
}
player GAME(player p)
{
 long scr=p.score;
 register bri B[4][42];
 for(int rol=0;rol<4;rol++)
  for(int col=0;col<42;col++)
   B[rol][col]=p.T[rol][col];
 register ji=p.level,chnc=p.chance;
 randomize();
 _setcursortype(0);
  st3:
    textbackground(WHITE);
    textcolor(BLACK);
    clrscr();
    register n=p.n,de=p.de,c,r,dir,bat;
    r=22;
    register char ch;
    char choise;
    int k,i,j;
    do
    {
     bat=10+random(58);
    }while(bat%2);
    for(int co=1;co<=80;co++)
    {
     gotoxy(co,1);
     cout<<'_';
     gotoxy(co,24);
     cout<<'_';
    }
    for(int ro=1;ro<=24;ro++)
    {
     gotoxy(1,ro);
     cout<<char(-77);
     gotoxy(80,ro);
     cout<<char(-77);
    }
    gotoxy(60,1);
    cout<<" SCORE : "<<scr+1<<' ';
    gotoxy(6,1);
    cout<<" CHANCE LEFT : "<<chnc+1<<' ';
    for (int ii=0;ii<42;ii++)
     BRICK(B,ji,ii);
    while(1)
    {
     ch=0;
     if(kbhit())
      ch=getch();
     c=bat+(n/2);
     if((ch=='a'||ch=='A')&&bat>2)
      bat-=2;
     if((ch=='d'||ch=='D')&&bat+n<80)
      bat+=2;
     BAT(bat,n);
     c=bat+(n/2);
     BAL(c,r);
     delay(10);
     TAB(bat,n);
     LAB(c,r);
     if(ch=='q'||ch=='Q')
      break;
    }
    BAL(c,r);
    BAT(bat,n);
    ch=getch();
    if(ch=='a'||ch=='A')
     dir=2;
    if(ch=='d'||ch=='D')
     dir=1;
    while(1)
    {
     while((c<=79)&&(c>=2)&&(r<=22)&&(r>=2))
     {
      BAL(c,r);
      if(scr>0)
       scr--;
      gotoxy(69,1);
       cout<<scr+1<<' ';
      BAT(bat,n);
      CH(B,c,r,ji,dir,scr);
      delay(de);
      LAB(c,r);
      TAB(bat,n);
      if(kbhit())
       ch=getch();
      if((ch=='a'||ch=='A') && bat>2)
       bat-=2;
      else if((ch=='d'||ch=='D') && bat+n<80)
       bat+=2;
      if((ch=='a'||ch=='A') && bat==2)
       ch='d';
      else if((ch=='d'||ch=='D') && bat+n==80)
       ch='a';
      else if(ch=='p'||ch=='P')
       goto st6;
      if(dir==1)
      {c++;r--;}
      else if(dir==2)
      {c--;r--;}
      else if(dir==3)
      {c--;r++;}
      else if(dir==4)
      {c++;r++;}
     }
      if(!(scr-1)||!scr||!(scr-2))
      {
       clrscr();
       gotoxy(32,11);
       p.ali=0;
       cout<<"YOU LOST!!!!!!!";
       delay(3000);
       break;
      }
      if(CH(B,ji))
      {
       ji++;
       chnc+=2;
       n-=2;
       if(p.diff==3&&ji%2)
	n-=2;
       de-=3;
       scr+=2500;
       if(ji+1==5)
       {
	clrscr();
	gotoxy(32,11);
	cout<<"YOU  WON!!!!!!!";
	delay(3000);
	break;
       }
       for(k=0,j=3;k<4;k++,j--)
       {
	gotoxy(29,14);
	cout<<"Next level begins in..."<<j;
	delay(350);
       }
       gotoxy(29,14);
	cout<<"                       ";
       goto st3;
      }
     if(kbhit())
      ch=getch();
   st6 :
     if(ch=='p'||ch=='P')
     {
      textbackground(BLUE);
      textcolor(RED+BLINK);
      clrscr();
      while(1)
      {
       gotoxy(35,10);
       cout<<"Pause Menu";
       gotoxy(35,11);
	cout<<"_____ ____";
	gotoxy(28,14);
	cout<<"1. Resume";
       gotoxy(28,15);
	cout<<"2. Quit";
       delay(500);
       choise=getch();
       if(choise=='c')
	Cheat(B,ji);
       else if(choise=='1')
	goto st3;
       else if(choise=='2')
	break;
      }
      break;
     }
     if((ch=='a'||ch=='A') && bat==2)
       ch='d';
     else if((ch=='d'||ch=='D') && bat+n==80)
       ch='a';
	if(c==1)
     {
      c=2;
      if(dir==2)
       dir=1;
      else if(dir==3)
       dir=4;
     }
     if(c==80)
     {
      c=79;
      if(dir==1)
       dir=2;
      else if(dir==4)
       dir=3;
     }
     if(r==1)
     {
      r=2;
      if(dir==2)
       dir=3;
      else if(dir==1)
       dir=4;
     }
     if((r==23)&&(c>=bat)&&(c<=bat+(n-1)))
     {
      r=22;
      if(dir==3&&(ch=='a'||ch=='A'))
       dir=2;
      else if(dir==4&&(ch=='d'||ch=='D'))
       dir=1;
      else if(dir==3&&(ch=='d'||ch=='D'))
       dir=1;
      else if(dir==4&&(ch=='a'||ch=='A'))
       dir=2;
      else if(dir==3)
       dir=2;
      else if(dir==4)
       dir=1;
     }
     if((r==23)&&((c<bat)||(c>bat+(n-1))))
      if(!chnc)
      {
       gotoxy(21,1);
	cout<<chnc;
       gotoxy(32,11);
       p.ali=0;
	cout<<"YOU LOST!!!!!!!";
       delay(3000);
       break;
      }
      else
      {
       chnc--;
       gotoxy(21,1);
	cout<<chnc+1;
       for(k=0,j=3;k<4;k++,j--)
       {
	gotoxy(29,14);
	cout<<"Next chance begins in..."<<j;
	delay(350);
       }
       gotoxy(29,14);
	cout<<"                         ";
       r=22;
       do
       {
	bat=10+random(58);
       }while(bat%2);
       while(1)
       {
	ch=0;
	if(kbhit())
	 ch=getch();
	c=bat+(n/2);
	if((ch=='a'||ch=='A')&&bat>2)
	 bat-=2;
	if((ch=='d'||ch=='D')&&bat+n<80)
	 bat+=2;
	BAT(bat,n);
	 c=bat+(n/2);
	BAL(c,r);
	delay(10);
	TAB(bat,n);
	LAB(c,r);
	if(ch=='q'||ch=='Q')
	 break;
       }
       BAL(c,r);
       BAT(bat,n);
       ch=getch();
       if(ch=='a'||ch=='A')
	dir=2;
       if(ch=='d'||ch=='D')
	dir=1;
      }
    }
    p.score=scr;
    p.level=ji;
    p.chance=chnc;
    p.n=n;
    p.de=de;
    for(int h=0;h<4;h++)
     for(int g=0;g<42;g++)
      p.T[h][g]=B[h][g];
    p.cri=(p.score*(p.level+1)*(p.chance+1)*p.diff)/(n*de*1.0);
    return p;
}

void Leaderboard(int i)
{
    player T;int n=0;
    ifstream fin("player.dat",ios::binary);
    player *b=new player[i];
    while(fin.read((char *)&T,sizeof(T)))
     b[n++]=T;
    fin.close();
    int st=0,f=0,en=15,k,w=i/15+1,x=0;
st5:
    textbackground(BLUE + BLINK);
    textcolor(WHITE);
    clrscr();
    if(!f)
    { st=0,f=0,en=15; }
    cout<<"\t\t\t\t  HIGH SCORES\n";
    cout<<"\t\t\t\t  ____ ______\n\n\n\n";
    cout<<"S.NO\tPlayer         \tCriteria   Score\tLevel   Difficulty   Chances\n";
    cout<<"____\t______         \t________   _____\t_____   __________   _______\n\n";
     for(int j=st;j<en&&j<n;j++)
     {
      cout<<b[j].sno<<".\t ";
      for(k=0;k<strlen(b[j].name);k++)
       cout<<b[j].name[k];
      for(;k<14;k++)
       cout<<' ';
      cout.setf(ios::fixed);
      cout<<"  "<<setprecision(3)<<b[j].cri<<"\t   "<<setw(6)<<b[j].score<<"          "<<b[j].level+1<<"       "<<b[j].diff<<"           "<<b[j].chance<<endl;
     }
    while(1)
    {
     char choise=0;
     if(kbhit())
      choise=getch();
     if(choise=='1')
     {
      for(j=0;j<i-1;j++)
       for(k=0;k<i-j-1;k++)
	if(b[k].sno>b[k+1].sno)
	{
	 T=b[k];
	 b[k]=b[k+1];
	 b[k+1]=T;
	}
      delay(500);
      textbackground(BLUE + BLINK);
      textcolor(WHITE);
      clrscr();f=0;
      goto st5;
     }
     else if(choise=='2')
     {
      for(j=0;j<i-1;j++)
       for(k=0;k<i-j-1;k++)
	if(strcmpi(b[k].name,b[k+1].name)>0)
	{
	 T=b[k];
	 b[k]=b[k+1];
	 b[k+1]=T;
	}
      delay(500);
      textbackground(BLUE + BLINK);
      textcolor(WHITE);
      clrscr();f=0;
      goto st5;
     }
     else if(choise=='3')
     {
      for(j=0;j<i-1;j++)
       for(k=0;k<i-j-1;k++)
	if(b[k].cri<b[k+1].cri)
	{
	 T=b[k];
	 b[k]=b[k+1];
	 b[k+1]=T;
	}
      delay(500);
      textbackground(BLUE + BLINK);
      textcolor(WHITE);
      clrscr();f=0;
      goto st5;
     }
     else if(choise=='4')
     {
      for(j=0;j<i-1;j++)
       for(k=0;k<i-j-1;k++)
	if(b[k].score<b[k+1].score)
	{
	 T=b[k];
	 b[k]=b[k+1];
	 b[k+1]=T;
	}
      delay(500);
      textbackground(BLUE + BLINK);
      textcolor(WHITE);
      clrscr();f=0;
      goto st5;
     }
     else if(choise=='5')
     {
      for(j=0;j<i-1;j++)
       for(k=0;k<i-j-1;k++)
	if(b[k].level>b[k+1].level)
	{
	 T=b[k];
	 b[k]=b[k+1];
	 b[k+1]=T;
	}
      delay(500);
      textbackground(BLUE + BLINK);
      textcolor(WHITE);
      clrscr();f=0;
      goto st5;
     }
     else if(choise=='6')
     {
      for(j=0;j<i-1;j++)
       for(k=0;k<i-j-1;k++)
	if(b[k].diff<b[k+1].diff)
	{
	 T=b[k];
	 b[k]=b[k+1];
	 b[k+1]=T;
	}
      delay(500);
      textbackground(BLUE + BLINK);
      textcolor(WHITE);
      clrscr();f=0;
      goto st5;
     }
     else if(choise=='7')
     {
      for(j=0;j<i-1;j++)
       for(k=0;k<i-j-1;k++)
	if(b[k].chance<b[k+1].chance)
	{
	 T=b[k];
	 b[k]=b[k+1];
	 b[k+1]=T;
	}
      delay(500);
      textbackground(BLUE + BLINK);
      textcolor(WHITE);
      clrscr();f=0;
      goto st5;
     }
     else if(choise==80)
     {
      st+=15;
      en+=15;
      f=1;
      x++;
      if(st==-15)
       f=0;
      else if(st==i)
      {
       st=i-15;
       en=i;
      }
      goto st5;
     }
     else if(choise==72)
     {
      st-=15;
      en-=15;
      f=1;
	 x--;
      if(st==-15||x>w)
      { f=0;x--;}
      else if(st==i||x<w)
      {
       st=i-15;
       en=i;x++;
      }
      goto st5;
     }
     else if(choise==27)
       break;
   }
}
void ht()
{
   cout<<"\t\t\tHow To Play"<<"\n\t\t\t___ __ ____";
   cout<<"\nTo move the bat left press A and to move it right press D";
   cout<<"\nPress Space to launch the ball ";
   cout<<"\nYou can move the bat to your desired location before launching the ball"<<endl;
   cout<<"\nDifficulty"<<endl<<"__________"<<endl<<" 1.Easy 2.Medium 3.Hard";
   cout<<"\n\nChoose on what basis do you to read the leaderboard";
   cout<<"\n__________________________________________________"<<endl;
   cout<<"\n1.Serial number order\n 2.Name \n 3. Score \n 4.Level reached \n 5.Difficulty \n 6.Chances Left"<<endl;
   cout<<"\n\n Your score will be calculated using the following formulae ";
   cout<<"\n\tPoints * Levels cleared * Chances Left * Difficulty chosen";
   cout<<"\n\t__________________________________________________________";
   cout<<"\n\t      current size of bat * current delay speed";
   cout<<"\n\nEnjoy The GAME :)";
}
int login()
{
 struct
 {
  long double a[10],b[10];
 }l;
 ifstream fout("admin.dat",ios::binary);
 fout.read((char *)&l,sizeof(l));
 char s[10],q[10],ch=0;
 int i=0;
 for(i=0;i<10;i++)
  s[i]=l.a[i];
 for(i=0;i<10;i++)
  q[i]=l.b[i];
 i=0;
 cout<<"enter username : ";
 char user[10];
 gets(user);
 cout<<"enter password : ";
 char pass[10];
 while(ch!=13)
 {
  ch=getch();
  if(ch==13||i==10)
   pass[i++]='\0';
  else
  {
   pass[i++]=ch;
   cout<<'*';
  }
 }
 if(strcmp(s,user)||strcmp(q,pass))
  return 1;
 else
  return 0;
}
void admin()
{
 int f=0;
 while(1)
 {
  clrscr();
  cout<<"\t\t\t\tAdministrator\n";
  cout<<"\t\t\t\t_____________\n\n\n";
  if(!login())
  {
   cout<<"\n\n\t\t\t\tLogin Successful!!!";
   getch();f++;break;
  }
  else
  {
   cout<<"\n\n\t\t\t\tLogin Failed...";
   cout<<"\n\n\n\t\t1. Retry\n\t\t2. Exit";
   char ch=getch();
   if(ch=='1')
    continue;
   else
    break;
  }
 }
 if(f)
 {
st11 :
  clrscr();
  char ch;
  cout<<"\t\t\t\tAdministrator\n";
  cout<<"\t\t\t\t_____________\n\n\n";
  cout<<"1. Delete Players w.r.t S.No"<<endl;
  cout<<"2. Delete Players w.r.t Criteria"<<endl;
  cout<<"3. Delete Players w.r.t Difficulty"<<endl;
  cout<<"4. Wipeout Leaderboards"<<endl;
  cout<<"5. Change Username and Password"<<endl;
  cout<<"6. Change Game Parameters"<<endl;
  cout<<"7. Back to Main Menu ";
  while(1)
  {
   ch=0;
   if(kbhit())
    ch=getch();
   if(ch=='1')
   {
    clrscr();
    int u,l;
    player T;
    ifstream f("player.dat",ios::binary);
    ofstream fout("temp.dat",ios::binary);
    f.seekg(0,ios::end);
    int i=f.tellg()/sizeof(T);
    f.seekg(0,ios::beg);
    cout<<"Number of Players : "<<i<<"\n\n";
    cout<<"Enter lower limit : ";cin>>l;l--;
    cout<<"Enter upper limit : ";cin>>u;u--;
    int n=0;
    while(f.read((char *)&T,sizeof(T)))
    {
      if(T.sno<=l)
     {
      T.sno=++n;
      fout.write((char *)&T,sizeof(T));
     }
    }
    f.seekg(sizeof(l)*u,ios::beg);
    while(f.read((char *)&T,sizeof(T)))
    {T.sno=n++;
      fout.write((char *)&T,sizeof(T));
    }
    cout<<"\n\n\n\t\tSuccess";
    getch();
    f.close();fout.close();
    remove("player.dat");
    rename("temp.dat","player.dat");
    goto st11;
   }
   else if(ch=='2')
   {
    clrscr();
    float c;
    player T;
    ifstream f("player.dat",ios::binary);
    ofstream fout("temp.dat",ios::binary);
    f.seekg(0,ios::end);
    int i=f.tellg()/sizeof(T);
    f.seekg(0,ios::beg);
    cout<<"Enter Minimum Criteria : ";cin>>c;
    int n=0;
    while(f.read((char *)&T,sizeof(T)))
    {
     if(T.cri>c)
     {
      T.sno=++n;
      fout.write((char *)&T,sizeof(T));
     }
    }
    cout<<"\n\n\n\t\tSuccess";
    getch();
    f.close();fout.close();
    remove("player.dat");
    rename("temp.dat","player.dat");
    goto st11;
   }
   else if(ch=='3')
   {
    clrscr();
    int d;
    player T;
    ifstream f("player.dat",ios::binary);
    ofstream fout("temp.dat",ios::binary);
    f.seekg(0,ios::end);
    int i=f.tellg()/sizeof(T);
    f.seekg(0,ios::beg);
    cout<<"Enter Difficulty : ";cin>>d;
    int n=0;
    while(f.read((char *)&T,sizeof(T)))
    {
     if(T.diff!=d)
     {
      T.sno=++n;
      fout.write((char *)&T,sizeof(T));
     }
    }
     cout<<"\n\n\n\t\tSuccess";
    getch();
    f.close();fout.close();
    remove("player.dat");
    rename("temp.dat","player.dat");
    goto st11;
   }
   else if(ch=='4')
   {
    clrscr();
    ofstream f("temp.dat",ios::binary);
    f.close();
    remove("player.dat");
    rename("temp.dat","player.dat");
    ifstream fin("player.dat",ios::binary);
    fin.seekg(0,ios::end);
    int i=f.tellp()/sizeof(player);
    if(!i)
     cout<<"\n\n\n\t\tSuccess";
    getch();
    break;
   }
   else if(ch=='5')
   {
    clrscr();
    struct
    {
     long double a[10],b[10];
    }l;
    ifstream fout("admin.dat",ios::binary);
    fout.read((char *)&l,sizeof(l));
    fout.close();
    ofstream f("admin.dat",ios::binary);
    char s[10],q[10],ch=0;
    int i=0;
    for(i=0;i<10;i++)
     s[i]=l.a[i];
    for(i=0;i<10;i++)
     q[i]=l.b[i];
    cout<<"Your Current Username : ";puts(s);
    cout<<"Your Current Password : ";puts(q);
    cout<<"\n\n\nEnter New Username : ";gets(s);
    cout<<"Enter New Password : ";gets(q);
    for(i=0;i<10;i++)
     l.a[i]=s[i];
    for(i=0;i<10;i++)
     l.b[i]=q[i];
    f.write((char*)&l,sizeof(l));
    cout<<"\n\n\n\t\tUsername and Password Changed!!!";
    getch();
    break;
   }
    else if(ch=='6')
   {
st12 :
    clrscr();
    fstream f("game.dat",ios::binary|ios::in|ios::out);
    f.read((char*)&j,sizeof(j));
    cout<<"\n\n1. Initialize";
    cout<<"\n2. Alter initial no of chances ";
    cout<<"\n3. Alter initial size of bat ";
    cout<<"\n4. Alter initial delay time ";
    cout<<"\n5. Back to Menu";
    fstream fi("game.dat",ios::binary|ios::in|ios::out);
    fi.read((char *)&j,sizeof(j));
     ch=getch();
    int alter;
    clrscr();
    if(ch=='1')
    {
     ifstream fi("game.dat",ios::binary);
     fi.read((char *)&j,sizeof(j));
     goto st12;
    }
    else if(ch=='2')
    {
     cout<<"Current : "<<j.sta_cha;
     cout<<"\nEnter initial no of chances : ";cin>>alter;
     j.sta_cha=alter;
     fi.seekg(0);
     fi.write((char *)&j,sizeof(j));
     clrscr();
     goto st12;
    }
    else if(ch=='3')
    {
     int d;
     cout<<"Enter difficulty : ";cin>>d;
     cout<<"Current : "<<j.sta_bat[d-1];
     cout<<"Enter initial size of bat : ";cin>>alter;
     j.sta_bat[d-1]=alter;
     fi.seekg(0);
     fi.write((char *)&j,sizeof(j));
     clrscr();
     goto st12;
    }
    else if(ch=='4')
    {
     int d;
     cout<<"Enter difficulty : ";cin>>d;
     cout<<"Current : "<<j.sta_del[d-1];
     cout<<"Enter initial delay time : ";cin>>alter;
     j.sta_del[d-1]=alter;
     fi.seekg(0);
     fi.write((char *)&j,sizeof(j));
     clrscr();
     goto st12;
    }
   else if(ch=='4')
    goto st11;
   }
    else if(ch=='7')
     break;
   }
  }
 }
