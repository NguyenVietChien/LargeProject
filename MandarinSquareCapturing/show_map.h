#ifndef H1_H_INCLUDED
#define H1_H_INCLUDED

#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#include<string>
#include<stdio.h>
#include<conio.h>

using namespace std ;

void Locate(int x, int y);

void Colour(int k);

void Delete(int x,int y);         // Delete the cell which is eaten or chosen

void show_map();



#endif // H1_H_INCLUDED
