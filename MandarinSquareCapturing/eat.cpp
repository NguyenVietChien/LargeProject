#include "show_map.h"
#include "init.h"
#include "eat.h"

void EatPagoda(player &X,player &s,Pagoda* &temple,int &res,int &index);

void Praise(int n){
    string s;
    if(n==0) s = "GOOD !!! " ;
    if(n==1) s = "WELL_DONE !!!";
    if(n==2) s = "PERFECT !!! ";
    if(n==3) s = "GOOD JOB !!! ";
    if(n==4) s = "WONDERFUL !!! " ;
    int row=0 ;
    int m=15;
    while(1){
        Locate(60,30);  cout << s ;
        Sleep(100);
        Sleep(80);
        m--;
        Colour(m);
        if(m==1) {
                m=15;
                row++;
        }
        if(row==1) {
                Locate(60,30); cout << "                  ";
                break;
        }
    }
}

void EatSquare(player &X ,player &s,Pagoda* &temple, int &res, int &index){

       // Eat cell s for player X

    X.capacity+=s.cell[index].total;

    int xxx= s.cell[index].total;     // Total rock you eat

    s.cell[index].total=0;
    Delete(s.cell[index].coor.x,s.cell[index].coor.y);
    Locate(s.counts[index].coor.x,s.counts[index].coor.y);
	Colour(3) ; cout << s.cell[index].total ;

    index += res;

    int prints ;
    if(xxx >= 5){
        if(xxx ==5) prints =0 ;
        if(xxx > 5 && xxx <= 8) prints = 1 ;
        if(xxx > 8 && xxx <= 10) prints = 2 ;
        if(xxx > 10 && xxx < 15) prints = 3 ;
        if(xxx > 15) prints = 4;
        Praise(prints);
    }
    if( s.cell[index].total == 0 && s.cell[index+res].total != 0 ){
        index += res;
        EatSquare(X,s,temple,res,index);       // Eat combo squares,
    }
    if( index == 2*res+3 && X.temp == 0 && s.cell[index].total == 0 ){
        EatPagoda(X,s,temple,res,index);       // Even Temple.
}
}

void EatPagoda(player &X,player &s,Pagoda* &temple,int &res,int &index){


    X.capacity += temple[(res+1)/2].total ;
    int xxx = temple[(res+1)/2].total,prints ;

    temple[(res+1)/2].total = 0;
    Delete(temple[(res+1)/2].coor.x-1,temple[(res+1)/2].coor.y);\

    Locate(temple[(res+1)/2].coor.x+8*res-1,
	temple[(res+1)/2].coor.y); cout << temple[(res+1)/2].total << " ";

	if(xxx >= 5){
         if(xxx == 5) prints = 0 ;
         if(xxx > 5 && xxx <= 8) prints = 1 ;
         if(xxx > 8 && xxx <= 10) prints = 2 ;
         if(xxx > 10 && xxx < 15) prints = 3 ;
         if(xxx > 15) prints = 4;
    }
    Praise(prints);
}
