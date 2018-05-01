#include<iostream>
#include<windows.h>
#include<string>
#include<stdio.h>
#include<conio.h>


using namespace std;

void gotoxy(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

class Coordinates{
    public:
    int x,y;
};
class Pagoda{
    public:
    int total;
    Coordinates coor;
};
class Oquan {
    public:
    int total;           //  The total stone of each of square
    Coordinates coor;      // Coordinates of square
};
class player{

    public:
    string name;        // Name of player
    Oquan cell[6];
    Oquan counts[6];      // Count total stone of each square
    int capacity;   //  Score of player
    int temp;       //  The total stone brought on hand

    void get_name(string _name){
        name = _name ;
    }

};

void Colour(int k){
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, k);
}
void show_map();

void Draw(int n,int x,int y);    // Draw n rocks at cell which has coordinate x,y

void Delete(int x,int y);         // Delete the cell which is eaten

void init(player &a,player &b, Pagoda* &temple,int &number); // Creat data of player

bool Check_Empty_cels(player &s, int & a,int &index);  // Are there many empty cells ?

bool Check_5_Empty(player &s);    // There are 5 empty cells or not ?

void Show_string(int n);

void Save(player &s);

void EatSquare(player &X ,player &s,Pagoda* &temple, int &a, int &index);

void EatPagoda(player &X,player &s,Pagoda* &temple,int &a,int &index);

void Show_Score(int n,player&a,player &b);

void Result(player &a,player &b);

void EatSquare(player &X ,player &s,Pagoda* &temple, int &a, int &index){   // Eat cell s for player X

    X.capacity+=s.cell[index].total;
    int xxx= s.cell[index].total;
    int prints ;
    s.cell[index].total=0;
    Delete(s.cell[index].coor.x,s.cell[index].coor.y);
    gotoxy(s.counts[index].coor.x,s.counts[index].coor.y);  Colour(3) ; cout << s.cell[index].total ;
    index+=a;
    if(xxx ==4 || xxx == 3) prints =0 ;
    if(xxx >= 5 && xxx <= 8) prints = 1 ;
    if(xxx > 8 && xxx <= 10) prints = 2 ;
    if(xxx > 10 && xxx < 15) prints = 3 ;
    if(xxx > 15 ) prints = 4;
    Show_string(prints);

    if(s.cell[index].total==0 && s.cell[index+a].total!=0){
        index+=a;
        EatSquare(X,s,temple,a,index);
    }
    if(index == 2*a+3 && X.temp == 0 && s.cell[index].total == 0)
        EatPagoda(X,s,temple,a,index);

}
void Show_string(int n){
    string s;
    if(n==0) s = "GOOD !!! " ;
    if(n==1) s = "WELL_DONE !!!";
    if(n==2) s = "PERFECT !!! ";
    if(n==3) s = "GOOD JOB !!! ";
    if(n==4) s = "WONDERFUL !!! " ;
    int row=0 ;
    int m=15;
    while(1){

        gotoxy(60,30);  cout << s ;
        Sleep(100);
        Sleep(80);
        m--;
        Colour(m);
        if(m==1) {
                m=15;
                row++;
        }
        if(row==3) {
                gotoxy(60,30); cout << "                  ";
                break;
        }
    }
}
void EatPagoda(player &X,player &s,Pagoda* &temple,int &a,int &index){
    X.capacity+=temple[(a+1)/2].total ;
    int xxx = temple[(a+1)/2].total ;
    int prints ;
    temple[(a+1)/2].total = 0;
    Delete(temple[(a+1)/2].coor.x-1,temple[(a+1)/2].coor.y);
    gotoxy(temple[(a+1)/2].coor.x+7*a-1,temple[(a+1)/2].coor.y); cout << temple[(a+1)/2].total << " ";
    if(xxx ==4 || xxx == 3) prints =0 ;
    if(xxx >= 5 && xxx <= 8) prints = 1 ;
    if(xxx > 8 && xxx <= 10) prints = 2 ;
    if(xxx > 10 && xxx < 15) prints = 3 ;
    if(xxx > 15 ) prints = 4;
    Show_string(prints);
}
void _eat(player &X,player &s,player &A,player &B, Pagoda * &temple, int &index, int &a)
{
    while(!Check_Empty_cels(s,a,index))
    {
       if(index == 2*a+3 && X.temp == 0 && s.cell[index].total == 0){
        EatPagoda(X,s,temple,a,index);
        index+=a;
        a = -a;
        index+=a;
       }
       else{
            index+=a;
            EatSquare(X,s,temple,a,index);
       }
    }
}
void Recall_Directing(int &position, int &direction, int &a, player &X);

bool stopGame(player &X,player &a,player &b, Pagoda * &temple){
	if(temple[0].total==0&&temple[1].total==0){
		for(int i = 1 ; i <= 5 ; i++){
			a.capacity+=a.cell[i].total;
			b.capacity+=b.cell[i].total;
		}
		return true;
	}
	else if(Check_5_Empty(X)==true && X.capacity < 5) return true;
	else return false;

}
bool _move(player &X,player &s, int &index, int &a, Pagoda* & temple){

    index+=a;

    while(X.temp > 0 && a*index < 3*a+3){
        s.cell[index].total++;  // distribute to index;
        Sleep(500);
		gotoxy(s.counts[index].coor.x,s.counts[index].coor.y);
		Colour(3) ; cout << s.cell[index].total << " " ;

        Draw(s.cell[index].total,s.cell[index].coor.x,s.cell[index].coor.y);
                       // finish distributing to index
        index+=a;
        X.temp--;
    }

            //  finish distributing
    if(index == 2*a+3 && X.temp == 0 && s.cell[index].total == 0){
        EatPagoda(X,s,temple,a,index);
        return false ;
    }
    if(index == 3*a+3 && X.temp == 0)  return false;   // neu chia toi cung duong thi mat luot

    if(index == 3*a+3 && X.temp  > 0){ // neu tren tay van con thi chia cho chua
            temple[(a+1)/2].total++;
            X.temp--;
            Sleep(500);
            Draw(temple[(a+1)/2].total,temple[(a+1)/2].coor.x-1,temple[(a+1)/2].coor.y);
            Colour(3);
            gotoxy(temple[(a+1)/2].coor.x+7*a-1,temple[(a+1)/2].coor.y); cout << temple[(a+1)/2].total ;
            a=-a;
            return true;
    }
    if(a*index < 3*a+3 && X.temp == 0){    // neu tren tay chia het se :

            if(s.cell[index].total > 0) {

            X.temp=s.cell[index].total;

            s.cell[index].total = 0;

            Delete(s.cell[index].coor.x,s.cell[index].coor.y);
            gotoxy(s.counts[index].coor.x,s.counts[index].coor.y);
            Colour(3) ; cout << s.cell[index].total << " " ;

			_move(X,s,index,a,temple);  // boc tiep
            }
            //else if(Check_Empty_cels(s,a, index))  return false;
             // mat luot
            else{
            	     index+=a;
                     EatSquare(X,s,temple,a,index);
                    return false;
            }
    }
}
void Random(player &A, int &position, int &direction) ;

void _distribute(int &position,int &direction,player &A,player &B, Pagoda* &temple,int &a,int &number){
    int index ;
    cout << endl << endl << endl;
   // gotoxy(10,29); cout << "                                                   ";
   // gotoxy(10,30); cout << "                                                   ";

    gotoxy(10,34); cout << A.name <<" is the first player : " ;
    if(number==1){
        Random(A,position,direction);
    }
    else{
        cin >> position >> direction ;
        Recall_Directing(position,direction,a,A);
    }


    A.temp=A.cell[position].total;
    A.cell[position].total=0;
    Delete(A.cell[position].coor.x , A.cell[position].coor.y);
    gotoxy(A.counts[position].coor.x,A.counts[position].coor.y);
    Colour(3) ; cout << A.cell[position].total ;

    index = position;

    while(1){

            while(_move(A,A,index,a,temple)){
                if(_move(A,B,index,a,temple)==false) break ;
            }

            Show_Score(1,A,B);

            if(stopGame(B,A,B,temple)) break;
            gotoxy(10,35); cout << "                                           ";
            gotoxy(10,35);cout << B.name << "'s turn : " ;
            if(Check_5_Empty(B)) Save(B);

            cin >> position >> direction ;
            Recall_Directing(position,direction,a,B);
            B.temp=B.cell[position].total;
            B.cell[position].total=0;

            gotoxy(B.counts[position].coor.x,B.counts[position].coor.y);
            Colour(3) ; cout << B.cell[position].total << " " ;

            Delete(B.cell[position].coor.x,B.cell[position].coor.y);
            index=position;

            while(_move(B,B,index,a,temple))
                if(_move(B,A,index,a,temple)==false) break ;

            Show_Score(1,A,B);
            if(stopGame(A,A,B,temple)) break;
            gotoxy(10,34); cout << "                                             ";



            gotoxy(10,34);cout << A.name << "'s turn : ";

            if(Check_5_Empty(A)) Save(A);

            if(number == 2){
                    cin >> position >> direction ;
                    Recall_Directing(position,direction,a,A);
            }
            else{
                    Random(A,position,direction);
            }
            A.temp=A.cell[position].total;
            A.cell[position].total=0;
            gotoxy(A.counts[position].coor.x,A.counts[position].coor.y);
            Colour(3) ; cout << A.cell[position].total << " ";

            Delete(A.cell[position].coor.x,A.cell[position].coor.y);
            index=position;
    }
}



void Random(player &A, int &position, int &direction){
     while(A.cell[position].total!=0){
        position = rand()%5;
     }
      direction = rand()%1;
}
int main()
{
    class player A,B;                     // Data of player
    class Pagoda *temple = new Pagoda[2];     // Data of pagoda
    int position;                           // the position quare is chosen
    int direction;              //  the direction square is chosen
    int a;                // reverse direction
    int number ;
    show_map();
    init(A,B,temple,number);
    _distribute(position,direction,A,B,temple,a,number);
    for(int i = 1 ; i <= 5 ; i++){
			A.capacity+=A.cell[i].total;
			B.capacity+=B.cell[i].total;
		}
    Result(A,B);
    return 0;

}

void init(player &a,player &b, Pagoda* &temple, int &number){
    a.capacity = 0;
    b.capacity = 0;
    temple[0].total = 10;
    temple[1].total = 10;
    temple[0].coor.x= 15;
    temple[0].coor.y= 16;
    temple[1].coor.x= 69;
    temple[1].coor.y= 16;
    a.temp=0;
    b.temp=0;
    for(int i = 1 ; i <= 5 ; i++){
         a.cell[i].coor.x = 9*i+15;
         a.cell[i].coor.y = 13;
         b.cell[i].coor.x = 9*i+15;
         b.cell[i].coor.y = 19;

         a.counts[i].coor.x = 9*i+15;
         a.counts[i].coor.y = 9;
         b.counts[i].coor.x = 9*i+15;
         b.counts[i].coor.y = 23;

         a.cell[i].total = 5;
         b.cell[i].total = 5;

    }
    for(int i = 1 ; i <= 5 ; i++ ){
                Draw(5,a.cell[i].coor.x,a.cell[i].coor.y);
                Draw(5,b.cell[i].coor.x,b.cell[i].coor.y);
                gotoxy(a.counts[i].coor.x,a.counts[i].coor.y);
                Colour(3) ; cout << a.cell[i].total ;
                gotoxy(b.counts[i].coor.x,b.counts[i].coor.y);
                Colour(3) ; cout << b.cell[i].total ;
    }
     Draw(10,temple[1].coor.x-1,temple[1].coor.y);
     Draw(10,temple[0].coor.x-1,temple[0].coor.y);
     {
     Colour(3);
     gotoxy(temple[0].coor.x-8,temple[0].coor.y); cout << temple[0].total ;
     gotoxy(temple[1].coor.x+6,temple[1].coor.y); cout << temple[1].total ;
     }

     string player1, player2 ;

     /*gotoxy(24,4); cout << "1 player ...Press 1 :";
     gotoxy(24,5); cout << "2 players...Press 2 :";

     cin >> number ;
     */
     number = 2 ;

     gotoxy(24,4); cout << "                           ";
     gotoxy(24,5); cout << "                           ";

     fflush(stdin);

     if(number==2){
        Colour(14);
        gotoxy(24,4); cout << "   Name of player A : ";
        cin >> player1 ;
        a.get_name(player1);

        gotoxy(24,5); cout << "   Name of player B : ";
        cin >> player2 ;
        b.get_name(player2);
        gotoxy(24,4); cout << "                            ";
        gotoxy(24,5); cout << "                            ";
     }
     else{
        Colour(14);
        player1 = "May" ;
        a.get_name(player1);
        gotoxy(24,5) ; cout << "                        ";
        gotoxy(24,4);cout << "    Your name:  ";
        cin >> player2 ;
        b.get_name(player2);
        gotoxy(24,4) ; cout << "                        ";
     }

      Show_Score(1,a,b);
      Show_Score(2,a,b);
}
void Show_Score(int n, player &a,player &b){
    if(n==1){
     Colour(15);
     gotoxy(24,5); cout << "Score of " << a.name << " : " << a.capacity ;
     gotoxy(24,25); cout << "Score of " << b.name << " : " << b.capacity ;
    }
    if(n==2){
        Colour(11);
        string str1 = "Choose 0 if you turn RIGHT...     ";
        string str2 = "Choose 1 if you turn LEFT ...      ";
        string str3 = "      Are you OK ?               ";
        for(int i = 0 ; i < str1.length() ; i ++){
            gotoxy(20+i,30);
            cout << str1[i];
            Sleep(100);
        }
        for(int i = 0 ; i < str2.length() ; i ++){
            gotoxy(20+i,31);
            cout << str2[i];
            Sleep(100);
        }
        Sleep(1000);
        for(int i = 0 ; i < str3.length() ; i ++){
            gotoxy(20+i,32);
            cout << str3[i];
            Sleep(200);
        }
    }
}
void Draw(int n,int x,int y){     // ve n quan o o co toa do (x;y)
    int countss=0;
    for(int i = x-2 ; i <= x+2 ; i++){
        for(int j = y-1 ; j <= y+1 ; j++){
            if(countss < n){
                gotoxy(i,j); Colour(10) ; cout << "o";
                countss++;
            }
            else{
                    gotoxy(i,j); cout << " ";
            }
        }
    }
}

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


void Recall_Directing(int &position, int &direction, int &a, player &X){

    while((!(position > 0 && position < 6) || !(direction==0||direction==1))&&X.cell[position].total!=0){
            gotoxy(10,36);
            cout << "Choose again please ! :";
            cin >> position >> direction;
        }

        if(direction==1) a=-1;
        else a=1;
}
void Result(player &a,player &b){
    system("cls");
    if(a.capacity > b.capacity){
       Colour(3);
       gotoxy(10,10) ; cout << "CONGRATULATION ! "<< a.name << " is winner!" ;
   }
    else{
    	gotoxy(10,10) ; cout << "CONGRATULATION ! "<< b.name << " is winner!" ;
    }

}
void Delete(int x,int y){
        for(int i = x-2 ; i <= x+2 ; i++){
              for(int j = y-1 ; j <= y+1 ; j++){
                    gotoxy(i,j); cout << " ";
              }
        }
}
void Save(player &s){
    for(int i = 0 ; i <= 5 ; i++){
        s.cell[i].total = 1;
        Draw(1,s.cell[i].coor.x,s.cell[i].coor.y);
        Colour(3);
        gotoxy(s.counts[i].coor.x,s.counts[i].coor.y);
        cout << 1 ;
    }
    s.capacity-=5 ;

}
bool Check_Empty_cels(player &s, int &a, int &index){   // ham kiem tra co nhieu o trong hay k
    int counts=0;
    index+=a;
    while(s.cell[index].total==0){
        counts++;
        index+=a;
    }
    if(counts>1) return true;
    else return false;
}
bool Check_5_Empty(player &s){
    for(int i = 1 ; i <= 5 ; i++)
        if(s.cell[i].total!=0) return false ;
    return true ;
}
