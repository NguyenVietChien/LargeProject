#include "show_map.h"
#include "init.h"
#include "eat.h"
#include "move.h"


void Locate(int x, int y);

void Colour(int k);

void Delete(int x,int y);         // Delete the cell which is eaten or chosen

void Draw(int n,int x,int y);  // Draw n rocks at cell which its coordinate (x,y)

void Praise(int n);         

void EatSquare(player &X ,player &s,Pagoda* &temple, int &res, int &index);

void EatPagoda(player &X,player &s,Pagoda* &temple,int &res,int &index);

bool _move(player &X,player &s, int &index, int &res, Pagoda* & temple);

bool _move(player &X,player &s, int &index, int &res, Pagoda* & temple){

     // Move and distribute with position and direction which are chosen

    index += res;

    while(X.temp > 0 && res*index < 3*res+3){
        s.cell[index].total++;  // distribute to index;
        Sleep(500);
		Locate(s.counts[index].coor.x,s.counts[index].coor.y);
		Colour(3) ; cout << s.cell[index].total << " " ;

        Draw(s.cell[index].total,s.cell[index].coor.x,s.cell[index].coor.y);
                       // finish distributing to index
        index+= res;
        X.temp--;
    }           //  finish distributing

    if( index == 2*res+3 && X.temp == 0 && s.cell[index].total == 0 ){
        EatPagoda(X,s,temple,res,index);
        return false ;
    }
    if(index == 3*res+3 && X.temp == 0)  return false;
	           // if you distribute to final destination, you lose your turn

    if(index == 3*res+3 && X.temp  > 0){
	                    // if there are rocks in your hand, distribute to Temple
            temple[(res+1)/2].total++;
            X.temp--;
            Sleep(500);
            Draw(temple[(res+1)/2].total,temple[(res+1)/2].coor.x-1,temple[(res+1)/2].coor.y);
            Colour(3);
            Locate(temple[(res+1)/2].coor.x+8*res-1,temple[(res+1)/2].coor.y); cout << temple[(res+1)/2].total;
            res = - res ;
            return true;
    }
    if(res*index < 3*res+3 && X.temp == 0){

	            // if there are no rock in your hand, we will :

            if(s.cell[index].total > 0) {

            // + Pick and Delete
            X.temp=s.cell[index].total;
            s.cell[index].total = 0;
            Delete(s.cell[index].coor.x,s.cell[index].coor.y);
            Locate(s.counts[index].coor.x,s.counts[index].coor.y);
            Colour(3) ; cout << s.cell[index].total << " " ;

            // + continue distributing
			_move(X,s,index,res,temple);
            }
            else{
               // Eat
               index+= res;
                EatSquare(X,s,temple, res ,index);
                return false;
            }
    }
}


