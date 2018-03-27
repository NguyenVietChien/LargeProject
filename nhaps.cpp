#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);

}

 void square(int n){

 }
void map(int a){

     int x,y;
     int b=a/2;
     gotoxy(24,19); cout << (char)
    gotoxy(a,b); cout << (char)201;
	gotoxy(b+6, a+4); cout << (char)200;
	gotoxy(61,a-6); cout << (char)187;
	gotoxy(a+49, 10+b); cout << (char)188;
    int i = 0,j=0 ;
        for( y=0+b; y<=10+b; y++){
            if(y == 0+b || y == 10+b)
            for( x=1+a; x<49+a; x++){
                   if(y==0+b && x==19+7*i){
                            gotoxy(x,y);
                            cout << (char)203 ;
                            i++;
                   }
                   else if(y==10+b&&x==19+7*j){
                            gotoxy(x,y);
                            cout << (char)202 ;
                            j++;
                   }
                   else{
                        gotoxy(x,y);
                        cout<<(char)205;
					}
            }
            else if(y==5+b){
                    int m=1;



                gotoxy(0+a+7,11); cout<<(char)204;
                gotoxy(42+a,11); cout<<(char)185;

				gotoxy(0+a,y); cout<<(char)186;
				gotoxy(49+a,y); cout<<(char)186;
				//gotoxy(7+a,7+a); cout<<(char)186;
				for(int x=8+a; x<42+a; x++){
                        if(x==19+7*m){
                            gotoxy(x,y);
                            cout << (char)206 ;
                            m++;
                   }
                else {
                gotoxy(x,y);
                cout<<(char)205;
                }
                   }
            }
            else {
                    for(int i = 0 ; i <= 7; i++){
				gotoxy(7*i+a ,y); cout << (char)186;
                    }
            }
        cout << endl;
        }
}
int main(){
    int a;
   // cin >> a ;
    for(int i  = 0 ; i < 10 ; i++){
         cout << i << endl ;

    }
    for(int i  = 0 ; i < 10 ; i++){
         cout << i << endl ;

    }


    for(int i  = 0 ; i < 10 ; i++) cout << i ;
    for(int i  = 0 ; i < 10 ; i++) cout << i ;
    for(int i  = 0 ; i < 10 ; i++) cout << i ;
    for(int i  = 0 ; i < 10 ; i++) cout << i ;
    for(int i  = 0 ; i < 10 ; i++) cout << i ;
    for(int i  = 0 ; i < 10 ; i++) cout << i ;
     for(int i  = 0 ; i < 10 ; i++) cout << i ;
    for(int i  = 0 ; i < 10 ; i++) cout << i ;

     for(int i  = 1 ; i < 6 ; i++) cout << "         ||" << "  " << 10*i ;

    map(12);cout << endl << endl << endl;

    cout << endl << endl;
	return 0;
}
