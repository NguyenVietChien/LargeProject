#include "show_map.h"
#include "init.h"


void Draw(int n,int x,int y){     // ve n quan o o co toa do (x;y)
    int countss=0;
    for(int i = x-2 ; i <= x+2 ; i++){
        for(int j = y-1 ; j <= y+1 ; j++){
            if(countss < n){
                Locate(i,j); Colour(10) ; cout << "o";
                countss++;
            }
            else{
                    Locate(i,j); cout << " ";
            }
        }
    }
}

void Show_Score(int n, player &A,player &B){

    if(n==1){   // show score
     Colour(12);
     Locate(30,5); cout << "Score of " << A.name << " : " << A.capacity ;
     Locate(30,26); cout << "Score of " << B.name << " : " << B.capacity ;
    }
    if(n==2){      // Introduction of the game
        Colour(11);
        string str1 = "Choose 0 if you turn RIGHT...";
        string str2 = "Choose 1 if you turn LEFT ...";
        string str3 = "  Are you readly ?";
        string str4 = "   LET'S GO !!! " ;
        for(int i = 0 ; i < str1.length() ; i ++){
            Locate(25+i,28);
            cout << str1[i];
            Sleep(100);
        }
        for(int i = 0 ; i < str2.length() ; i ++){
            Locate(25+i,29);
            cout << str2[i];
            Sleep(100);
        }
        Sleep(100);
        for(int i = 0 ; i < str3.length() ; i ++){
            Locate(28+i,30);
            cout << str3[i];
            Sleep(100);
        }
        Sleep(100);
        Locate(28,32); cout << str4 ;
        Sleep(200);
    }
}

void init(player &a,player &b, Pagoda* &temple, int &number){
    a.capacity = b.capacity = 0;
    temple[0].coor.x= 15;
    temple[1].coor.x= 69;
    temple[0].coor.y= temple[1].coor.y = 16;
    temple[0].total = temple[1].total = 10;
    a.temp = b.temp = 0;
    a.turn.x = b.turn.x = 10;
    a.turn.y = 34;
    b.turn.y = 35 ;
    for(int i = 1 ; i <= 5 ; i++){
         a.cell[i].coor.x = b.cell[i].coor.x = 9*i+15;
         a.cell[i].coor.y = 13;
         b.cell[i].coor.y = 19;

         a.counts[i].coor.x = b.counts[i].coor.x = 9*i+15;
         a.counts[i].coor.y = 8;
         b.counts[i].coor.y = 24;
         a.cell[i].total = b.cell[i].total = 5;
    }
    for(int i = 1 ; i <= 5 ; i++ ){
                Draw(5,a.cell[i].coor.x,a.cell[i].coor.y);
                Draw(5,b.cell[i].coor.x,b.cell[i].coor.y);
                Locate(a.counts[i].coor.x,a.counts[i].coor.y);
                Colour(3) ; cout << a.cell[i].total ;
                Locate(b.counts[i].coor.x,b.counts[i].coor.y);
                Colour(3) ; cout << b.cell[i].total ;
    }
     Draw(10,temple[1].coor.x-1,temple[1].coor.y);
     Draw(10,temple[0].coor.x-1,temple[0].coor.y);
     {
     Colour(3);
     Locate(temple[0].coor.x-9,temple[0].coor.y); cout << temple[0].total ;
     Locate(temple[1].coor.x+7,temple[1].coor.y); cout << temple[1].total ;
     }
     Colour(12);
     string player1, player2 ;
     Locate(30,4); cout << "1 player ...Press 1 :";
     Locate(30,5); cout << "2 players...Press 2 :";

     while(number!=1 && number!=2){
     	Locate(51,5); cout << " " ;
        if (!kbhit())
        {
            char ch = getch();
            number=(int)ch - 48 ;
        }
     }
     Locate(52,5); cout << number ;
     Sleep(300);
     Locate(30,4); cout << "                           ";
     Locate(30,5); cout << "                           ";

     fflush(stdin);

     if(number==2){
        Colour(14);
        Locate(30,4); cout << "Name of player A : ";
        cin >> player1 ;
        a.get_name(player1);

        Locate(30,5); cout << "Name of player B : ";
        cin >> player2 ;
        b.get_name(player2);
        Locate(30,4); cout << "                            ";
        Locate(30,5); cout << "                            ";
     }
     else{
        Colour(14);
        player1 = "Machine" ;
        a.get_name(player1);
        Locate(30,5) ; cout << "                        ";
        Locate(30,4); cout << "Your name:  ";
        cin >> player2 ;
        b.get_name(player2);
        Locate(30,4) ; cout << "                        ";
     }
      Show_Score(1,a,b);
      Show_Score(2,a,b);
}
