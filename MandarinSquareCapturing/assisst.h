#ifndef ASSISST_H_INCLUDED
#define ASSISST_H_INCLUDED

void Choose(int &position, int &direction, int &res, player &X);
                                             // Choose position and direction
                                             
void Random(player &A, int &position, int &direction,int &res);
                                                            // Machine play
void Save(player &s); // If all cell are empty , distribute 1 rock for each cell

bool CheckEmtyCells(player &s, int &res, int &index);   
                                               // There are many cells or not ?
                   
bool Check_5_Empty(player &s);
                  // All cell are empty, aren't they ?
				  
void Display_score(player &A, player & B);
                    
bool stopGame(player &X,player &a,player &b, Pagoda * &temple);
             
void Result(player &a,player &b);   				                     

#endif // ASSISST_H_INCLUDED
