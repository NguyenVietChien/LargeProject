#include "show_map.h"
#include "init.h"

void Locate(int x, int y);

void Draw(int n,int x,int y);   // Draw n rocks at cell which its coordinate (x,y)

void Choose(int &position, int &direction, int &res, player &X){
	    
	    Colour(14);
	    string str1 = X.name+"'s turn : " ;
	    Locate(str1.length()+30,X.turn.y); cout << "     ";
		Locate(30,X.turn.y);                cout << str1 ;

		while(position <= 0|| position > 5|| X.cell[position].total==0){
     	    Locate(str1.length()+30,X.turn.y);
     	    cout << " ";
            if (!kbhit()){
               char c = getch();
               position =(int)c -48 ;
            }
        }
        Locate(str1.length()+31,X.turn.y); cout << position ;

		Locate(str1.length()+32,X.turn.y); cout << " " ;
		Locate(str1.length()+32,X.turn.y);

		do{
			Locate(str1.length()+32,X.turn.y);
     	    cout << " ";
            if (!kbhit()){
               char c = getch( );
               direction = (int)c - 48 ;
            }
		} while(direction != 0 && direction != 1);
        Locate(str1.length()+33,X.turn.y); cout << direction ;

        if(direction==1) res=-1;
        else res=1;
}

void Random(player &A, int &position, int &direction,int &res){

     do{
		position = rand()%4+1;

	 }while(A.cell[position].total==0);

      direction = rand()%1;
      
      if(direction==1) res = -1 ;
      else res = 1 ;
      Colour(14);
	  string str1 = A.name+"'s turn : " ;
	  Locate(str1.length()+31,A.turn.y); cout << position << " " << direction;
	  Locate(30,A.turn.y);                cout << str1 ;
}

void Save(player &s){    

     // if there is no rock in your row, distribute a rock in each of square
     
    for(int i = 1 ; i <= 5 ; i++){
        s.cell[i].total = 1;
        Draw(1,s.cell[i].coor.x,s.cell[i].coor.y);
        Colour(3);
        Locate(s.counts[i].coor.x,s.counts[i].coor.y);
        cout << 1 ;
    }
    s.capacity -= 5 ;
}

bool CheckEmtyCells(player &s, int &res, int &index){   // ham kiem tra co nhieu o trong hay k
    int counts=0;
    index+= res;
    while(s.cell[index].total==0){
        counts++;
        index+= res;
    }
    if(counts>1) return true;
    else return false;
}

bool Check_5_Empty(player &s){
    for(int i = 1 ; i <= 5 ; i++)
        if(s.cell[i].total!=0) return false ;
    return true ;
}

void Display_score(player &A, player & B){
	Locate(43,7); cout << "SCORE";
	Locate(29,9); cout << (char)201;
	Locate(29,17); cout << (char)200;
	Locate(61,9); cout << (char)187;
	Locate(61,17); cout << (char)188;
	for(int i = 0 ; i <= 6; i++){
		Locate(45,10+i); cout << (char)186 ;
		Locate(29,10+i); cout << (char)186 ;
		Locate(61,10+i); cout << (char)186 ;
	}
	for(int i = 0 ; i <= 30 ; i++){
	Locate(30+i,9);
	if(i==15) cout << (char)203 ;
	else cout << char(205);
	Locate(30+i,17);
	if(i==15) cout << (char)202 ;
	else cout << char(205);
    }
    Locate(37,15); cout << A.capacity ;
    Locate(53,15); cout << B.capacity ;
    Locate(35,11); cout << A.name ;
    Locate(51,11); cout << B.name ;

}

bool stopGame(player &X,player &a,player &b, Pagoda * &temple){
	if(temple[0].total==0&&temple[1].total==0){

		// Bring all rock for each of player

		for(int i = 1 ; i <= 5 ; i++){
			a.capacity += a.cell[i].total;
			b.capacity += b.cell[i].total;
			a.cell[i].total = b.cell[i].total = 0;
			Delete(a.cell[i].coor.x , a.cell[i].coor.y);
			Delete(b.cell[i].coor.x , b.cell[i].coor.y);
		}
		Sleep(1000);
		return true;
	}
	else if(Check_5_Empty(X)==true && X.capacity < 5) return true;
	else return false;
}

void Result(player &a,player &b){

    system("cls");
    Display_score(a,b);
    string s;
    if( a.capacity > b.capacity ){
       s = "*** CONGRATULATION (^_^)...."+ a.name + " is Winner ***";
    }
    else s = "*** CONGRATULATION (^_^)...."+ b.name + " is Winner ***";

    int loops = 0, color = 15 ;
    while( loops != 5 ){

        Locate(20,20);  cout << s ;
        Sleep(100);
        color --;
        Colour(color);
        if( color == 1 ) {
                color = 15;
                loops ++;
        }
    }
}
