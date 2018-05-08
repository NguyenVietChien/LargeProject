#ifndef SHOW_MAP_H_INCLUDED
#define SHOW_MAP_H_INCLUDED
#include "show_map.h"
#include "init.h"

void Praise(int n); 
           // Praise if you eat more than 5 rocks

void EatSquare(player &X ,player &s,Pagoda* &temple, int &res, int &index);
              // Eat cell s for player X 
              
void EatPagoda(player &X,player &s,Pagoda* &temple,int &res,int &index);
             // Eat Temple res for player X

#endif // SHOW_MAP_H_INCLUDED
