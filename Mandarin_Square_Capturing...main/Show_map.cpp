#include "Show_map.h"

void show_map(){
    int x,y;
    Colour(5);
    gotoxy(10,10); ;cout << (char)201;
	gotoxy(10,22); cout << (char)200;
	gotoxy(73,10); cout << (char)187;
	gotoxy(73,22); cout << (char)188;
    int i = 0,j=0 ;
        for(y = 10; y <= 22; y++){
            if(y== 10 || y == 22)
            for( x = 11; x < 73; x++){
                   if(y == 10 && x == 19+9*i){
                            gotoxy(x,y);
                            cout << (char)203 ;
                            i++;
                   }
                   else if(y==22 && x==19+9*j){
                            gotoxy(x,y);
                            cout << (char)202 ;
                            j++;
                   }
                   else{
                        gotoxy(x,y);
                        cout<<(char)205;
					}
            }
            else if(y==16){
                    int m=1;
                gotoxy(19,16); cout<<(char)204;
                gotoxy(64,16); cout<<(char)185;
				gotoxy(10,16); cout<<(char)186;
				gotoxy(73,16); cout<<(char)186;
				for(int x = 20; x < 64; x++){
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
            else
                for(int i = 0 ; i <= 7; i++){
				        gotoxy(9*i+10 ,y); cout << (char)186;
                    }
        cout << endl;
        }
        Colour(10);
        gotoxy(24,2); cout << "MANDARIN SQUARE CAPTURING";

}
