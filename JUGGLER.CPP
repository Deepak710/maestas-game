#include<maestas.h>

void main()
{
 _setcursortype(0);
 char ch,ch1;
 player P;
 fstream f;
 Intro();
dee:
 Intro(1);
 while(1)
 {
  ch=0;
  if(kbhit())
   ch=getch();
  if(ch=='1')
  {
   do
   {
    P=GAME(player('a'));
    delay(1000);
    gotoxy(31,15);
    cout<<"YOUR TOTAL SCORE : "<<P.cri;
    cout<<"\n\n\n"<<char(-77)<<"\t    Continue??? ([y]for Next player/[n]to goto Main Menu) ";
    f.open("player.dat",ios::binary|ios::out|ios::app);
    f.write((char *)&P,sizeof(P));
    f.close();
    ch=getch();
    clrscr();
   }while(ch=='y'||ch=='Y');
   goto dee;
  }
  else if(ch=='2')
  {
   fstream f;
    f.open("player.dat",ios::in|ios::binary);
    f.seekg(0,ios::end);
    int i=f.tellp()/sizeof(P);
    f.close();
   Leaderboard(i);
   goto dee;
  }
  else if(ch=='3')
  {
   clrscr();
   ht();
   while(1)
   {
    if(kbhit())
     ch=getch();
    if(ch==27)
     goto dee;
   }
  }
  else
  if (ch=='a')
  {admin();
   goto dee;
  }
  else if(ch=='4')
   exit(0);
 else if(ch=='c')
 {
  clrscr();
  fstream f;
    f.open("player.dat",ios::in|ios::binary);
    f.seekg(0,ios::end);
    int i=f.tellp()/sizeof(P),n;
    f.close();
    cout<<"Enter Player's S.no : ";cin>>n;
     f.open("player.dat",ios::in|ios::binary);
     f.seekg((int)((n)*sizeof(P)),ios::cur);
     f.read((char*)&P,sizeof(P));
     f.close();
     if(P.ali)
      P=GAME(P);
     clrscr();
    delay(1000);
    gotoxy(31,15);
    cout<<"YOUR TOTAL SCORE : "<<P.cri;
    cout<<"\n\n\n"<<char(-77)<<"\t    Continue??? ([y]for Next player/[n]to goto Main Menu) ";
    f.open("player.dat",ios::binary|ios::out);
    f.seekg((int)((n)*sizeof(P)),ios::cur);
    f.write((char *)&P,sizeof(P));
    f.close();
  goto dee;
 }
}
}