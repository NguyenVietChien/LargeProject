#ifndef SHOW_MAP_H_INCLUDED
#define SHOW_MAP_H_INCLUDED

class Coordinates{
    public:
    int x,y;
};
class Pagoda{
    public:
    int total;
    Coordinates coor;
};
class Square {
    public:
    int total;           //  The total stone of each of square
    Coordinates coor;      // Coordinates of square
};
class player{
    public:
    string name;        // Name of player
    Square cell[6];
    Square counts[6];      // Count total stone of each square
    int capacity;   //  Score of player
    int temp;       //  The total stone brought on hand
    Coordinates turn;
    void get_name(string _name){
        name = _name ;
    }
};

void Draw(int n,int x,int y);   // Draw n rocks at cell which its coordinate (x,y)

void Show_Score(int n, player &a,player &b);

void init(player &a,player &b, Pagoda* &temple,int &number); // Creat data of player

#endif // SHOW_MAP_H_INCLUDED
