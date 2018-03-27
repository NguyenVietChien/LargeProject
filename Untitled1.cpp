#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}
void show_map(){

    int a=14,b=11;
     int x,y;
     //for(int i = 0 ; i < 5 ; i++)

    gotoxy(a-4,b-1);
	cout << (char)201;
	gotoxy(b-1, a+8);
	cout << (char)200;
	gotoxy(a+59,a-4);
	cout << (char)187;
	gotoxy(a+59,b+11);
	cout << (char)188;
    int i = 0,j=0 ;
        for(y = b-1; y <= 11+b; y++){
            if(y== b-1 || y == 11+b)
            for( x = a-3; x < a+59; x++){
                   if(y == b-1 && x == 19+9*i){
                            gotoxy(x,y);
                            cout << (char)203 ;
                            i++;
                   }
                   else if(y==11+b && x==19+9*j){
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
                gotoxy(a+5,b+5); cout<<(char)204;
                gotoxy(a+50,b+5); cout<<(char)185;
				gotoxy(a-4,y); cout<<(char)186;
				gotoxy(59+a,y); cout<<(char)186;
				for(int x = a+6; x < a+50; x++){
                        if(x == 19+9*m){
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
				gotoxy(9*i+a-4 ,y); cout << (char)186;
                    }
            }
        cout << endl;
        }
}
int main()
{
    show_map();
	//for(int  i = 0 ; i <  210 ; i++) cout << i << " " << (char)i <<endl;
	return 0;
}
