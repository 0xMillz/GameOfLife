//**************************************************************
//Author: Mills McIlroy
//Date: October 4, 2015
//Description: This is the GameOfLife class specification file.
//**************************************************************
#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP
#include "Cell.hpp"

class GameOfLife
{
   private:
      Cell world[40][80];//A grid with 40 rows and 80 columns
   public:
      void oscillator(int x, int y);
      void glider(int x, int y);
      void gliderGun(int x, int y);
      void setWorld(Cell nextGen[][80]);

};
#endif



