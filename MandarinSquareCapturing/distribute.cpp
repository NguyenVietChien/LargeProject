#include "show_map.h"
#include "init.h"
#include "move.h"
#include "assisst.h"

void _distribute(int &position,int &direction,player &A,player &B,
                                         Pagoda* &temple,int &res,int &number){
	int index ;
    while(1){
    	    if(number == 2)
                    Choose(position,direction,res,A);
            else
                    Random(A,position,direction,res);

            //Pick up and Delete
            A.temp=A.cell[position].total;
            A.cell[position].total=0;
            Locate(A.counts[position].coor.x,A.counts[position].coor.y);
            Colour(3) ; cout << A.cell[position].total << " ";
            Delete(A.cell[position].coor.x,A.cell[position].coor.y);

            index=position;

            while(_move(A,A,index,res,temple)){
                if(_move(A,B,index,res,temple)==false) break ;
            }
                      // Player A finished playing
            Show_Score(1,A,B);

            // Play B start playing
            if (stopGame(B,A,B,temple)) break;
            
            if (Check_5_Empty(B)) Save(B); 

            position = 0 ;

            Choose(position,direction,res,B);

            B.temp=B.cell[position].total;
            B.cell[position].total=0;
            Locate(B.counts[position].coor.x,B.counts[position].coor.y);
            Colour(3) ; cout << B.cell[position].total << " " ;

            Delete(B.cell[position].coor.x,B.cell[position].coor.y);
            index=position;

            while(_move(B,B,index,res,temple))
                if(_move(B,A,index,res,temple)==false) break ;
            // Play B finished playing
            Show_Score(1,A,B);
            if(stopGame(A,A,B,temple)) break;

            // Play A start playing
            if(Check_5_Empty(A)) Save(A);

            position = 0 ;
    }
}

