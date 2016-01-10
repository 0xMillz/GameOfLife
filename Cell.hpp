//********************************************************
//Author: Mills McIlroy
//Date: October 4, 2015
//Description: This is the Cell class specification file.
//********************************************************
#ifndef CELL_HPP
#define CELL_HPP

class Cell
{
   private:
      bool alive;//True if state is alive, false if dead
   public:
      Cell();
      void birth();//Changes alive to true
      void death();//Changes alive to false
      bool getState();//Returns true if alive, false if dead
       
};
#endif


            
         
