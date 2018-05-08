
#include "show_map.h"
#include "init.h"
#include "eat.h"
#include "move.h"
#include "assisst.h"
#include "distribute.h"

using namespace std;

void play(){
	class player A,B;                     // Data of player
    class Pagoda *temple = new Pagoda[2];     // Data of pagoda
    int position;                           // the position quare is chosen
    int direction;          //  the direction square is chosen
    int res;                // reverse direction
    int number ;            // amount player
    show_map();
    init(A,B,temple,number);
    _distribute(position,direction,A,B,temple,res,number);
    Result(A,B);
}

int main()
{
	while(1){
		
		//PlaySound (TEXT ( "playmusic" ), NULL, SND_ASYNC);
    	int decide;    // replay or not ?
    	play();
    	Colour(14);
    	Locate(30,27); cout << "if(you want to replay) ";
        Locate(30,28); cout << "   press 1 ; ";
        Locate(30,29); cout << "else press 0 ;   ";
    	cin >> decide ;
    	if(decide==0) break;
    	else {
    		system("cls");
    	}
    }
	return 0;
}



