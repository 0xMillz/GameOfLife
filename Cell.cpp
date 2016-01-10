//*****************************************************************
//Author: Mills McIlroy
//Date: October 4, 2015
//Description: This is the Cell class function implementation file.
//*****************************************************************
#include "Cell.hpp"

Cell::Cell()
{
   alive = false;

}

void Cell::birth()
{
   alive = true;

}

void Cell::death()
{
   alive = false;

}

bool Cell::getState()
{
   return alive;
}
   
