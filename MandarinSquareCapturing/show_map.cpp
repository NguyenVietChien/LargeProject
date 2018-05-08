#include "show_map.h"

void Locate(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void Colour(int k){
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, k);
}

void Delete(int x,int y){
        for(int i = x-2 ; i <= x+2 ; i++){
              for(int j = y-1 ; j <= y+1 ; j++){
                    Locate(i,j); cout << " ";
              }
        }
}

void show_map(){
    int x,y;
    Colour(5);
    Locate(10,10); ;cout << (char)201;
	Locate(10,22); cout << (char)200;
	Locate(73,10); cout << (char)187;
	Locate(73,22); cout << (char)188;
    int i = 0,j=0 ;
        for(y = 10; y <= 22; y++){
            if(y== 10 || y == 22)
            for( x = 11; x < 73; x++){
                   if(y == 10 && x == 19+9*i){
                            Locate(x,y);
                            cout << (char)203 ;
                            i++;
                   }
                   else if(y==22 && x==19+9*j){
                            Locate(x,y);
                            cout << (char)202 ;
                            j++;
                   }
                   else{
                        Locate(x,y);
                        cout<<(char)205;
					}
            }
            else if(y==16){
                    int m=1;
                Locate(19,16); cout<<(char)204;
                Locate(64,16); cout<<(char)185;
				Locate(10,16); cout<<(char)186;
				Locate(73,16); cout<<(char)186;
				for(int x = 20; x < 64; x++){
                        if(x == 19+9*m){
                            Locate(x,y);
                            cout << (char)206 ;
                            m++;
                   }
                else {
                Locate(x,y);
                cout<<(char)205;
                }
                   }
            }
            else
                for(int i = 0 ; i <= 7; i++){
				        Locate(9*i+10 ,y); cout << (char)186;
                    }
        cout << endl;
        }
        Colour(10);
        Locate(25,2); cout << "___MANDARIN SQUARE CAPTURING___";

}

