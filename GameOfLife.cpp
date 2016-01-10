//************************************************************************
//Author: Mills McIlroy
//Date: October 4, 2015
//Description: This is the GameOfLife class function implementation file.
//************************************************************************
#include "GameOfLife.hpp"
#include <iostream>
#include <cstdlib>//for system("clear")
#include <unistd.h>//for usleep()
using std::cout;
using std::endl;

void GameOfLife::oscillator(int x, int y)
{
   int row = x + 10;//Converts visible row # to match row # in the actual array
   int column = y + 20;//Converts visible column # to match column # in actual array 

   world[row][column].birth();
   world[row - 1][column].birth();//Starts the blinker in the vertical position
   world[row + 1][column].birth();//"  "

   system("clear");//clears the screen in preparation for the game 

   for (int i = 0; i < 40; i++)//iterates through the rows
   {
      for(int j = 0; j < 80; j++)//iterates through the columns
      {
         if ((i > 9 && i < 30) && (j > 19 && j < 60))//Prints to the visible 40 x 20 grid
         {
            if (world[i][j].getState() == false)
               cout << " ";
            else  
               cout << "O";
         }
      }
      if (i > 9 && i < 30)//Goes to the next line after each row is done printing 
         cout << endl;
   }
   
   usleep(250000);//Slows down the animation in between console prints
  
   Cell nextGen[40][80];//New array for the next generation 

   for (int count = 0; count < 100; count++)//Game will continue for 100 generations
   {  
      for (int i = 0; i < 40; i++)//iterates through the rows
      {       
         for(int j = 0; j < 80; j++)//iterates through the columns
         {     
            int neighbors = 0;//counts surrounding neighbors
          
            if(world[i - 1][j - 1].getState() == true)//upper left neighbor
               neighbors++;

            if(world[i - 1][j].getState() == true)//upper middle neighbor
               neighbors++;

            if(world[i - 1][j + 1].getState() == true)//upper right neighbor
               neighbors++;  
                           
            if(world[i][j - 1].getState() == true)//left neighbor
               neighbors++;

            if(world[i][j + 1].getState() == true)//right neighbor
               neighbors++;

            if(world[i + 1][j - 1].getState() == true)//bottom left neighbor
               neighbors++;

            if(world[i + 1][j].getState() == true)//bottom middle neighbor
               neighbors++;

            if(world[i + 1][j + 1].getState() == true)//bottom right neighbor
               neighbors++;       
            
            //This if/else statement applies the game rules to each cell and creates the next generation  
            if (world[i][j].getState() == true)
            {
               if (neighbors < 2)//If an occupied cell has zero or one neighbor, it dies
                  nextGen[i][j].death();
               else if (neighbors > 3)//If an occupied cell has more than 3 neighbors, it dies 
                  nextGen[i][j].death();
               else//If an occupied cell has two or three neighbors it continues to live on   
                  nextGen[i][j].birth();
             }
             else//If cell is unoccupied
             {
                if (neighbors == 3)//If an empty cell has exactly three neighbors, it comes alive
                   nextGen[i][j].birth();
             }                 
         } 
      }

      setWorld(nextGen);//The original array is replaced by the new generation

      //This nested loop resets nextGen for the next iteration  
      for (int i = 0; i < 40; i++)//iterates through the rows
      {
         for(int j = 0; j < 80; j++)//iterates through the columns
            nextGen[i][j].death();
      }                  
      
      system("clear");//clears the screen in preparation for displaying the next generation 

      //The following code prints the new generation to the console     
      for (int i = 0; i < 40; i++)//iterates through the rows
      {
         for(int j = 0; j < 80; j++)//iterates through the columns
         {
            if ((i > 9 && i < 30) && (j > 19 && j < 60))//Prints to the visible 40 x 20 grid
            {
               if (world[i][j].getState() == false)//world now holds the new data
                  cout << " ";
               else  
                  cout << "O";
            }
         }
         if (i > 9 && i < 30)//Goes to the next line after each row is done printing 
            cout << endl;
      }
     
      usleep(250000);//Slows down the animation in between console prints
  
   }                                                  
}        

void GameOfLife::glider(int x, int y)
{
   int row = x + 10;//Converts visible row # to match row # in the actual array
   int column = y + 20;//Converts visible column # to match column # in actual array 

   world[row + 1][column - 1].birth();//Starts the glider with long side down
   world[row + 1][column].birth();
   world[row + 1][column + 1].birth();
   world[row][column + 1].birth();
   world[row - 1][column].birth();

   system("clear");//clears the screen in preparation for the game 
   
   for (int i = 0; i < 40; i++)//iterates through the rows
   {
      for(int j = 0; j < 80; j++)//iterates through the columns
      {
         if ((i > 9 && i < 30) && (j > 19 && j < 60))//Prints to the visible 40 x 20 grid
         {
            if (world[i][j].getState() == false)
               cout << " ";
            else  
               cout << "O";
         }
      }
      if (i > 9 && i < 30)//Goes to the next line after each row is done printing 
         cout << endl;
   }
   
   usleep(250000);//Slows down the animation in between console prints
 
   Cell nextGen[40][80];//New array for the next generation 

   for (int count = 0; count < 100; count++)//Game will continue for 100 generations
   {  
      for (int i = 0; i < 40; i++)//iterates through the rows
      {       
         for(int j = 0; j < 80; j++)//iterates through the columns
         {     
            int neighbors = 0;//counts surrounding neighbors
          
            if(world[i - 1][j - 1].getState() == true)//upper left neighbor
               neighbors++;

            if(world[i - 1][j].getState() == true)//upper middle neighbor
               neighbors++;

            if(world[i - 1][j + 1].getState() == true)//upper right neighbor
               neighbors++;  
                           
            if(world[i][j - 1].getState() == true)//left neighbor
               neighbors++;

            if(world[i][j + 1].getState() == true)//right neighbor
               neighbors++;

            if(world[i + 1][j - 1].getState() == true)//bottom left neighbor
               neighbors++;

            if(world[i + 1][j].getState() == true)//bottom middle neighbor
               neighbors++;

            if(world[i + 1][j + 1].getState() == true)//bottom right neighbor
               neighbors++;       
            
            //This if/else statement applies the game rules to each cell and creates the next generation  
            if (world[i][j].getState() == true)
            {
               if (neighbors < 2)//If an occupied cell has zero or one neighbor, it dies
                  nextGen[i][j].death();
               else if (neighbors > 3)//If an occupied cell has more than 3 neighbors, it dies 
                  nextGen[i][j].death();
               else//If an occupied cell has two or three neighbors it continues to live on   
                  nextGen[i][j].birth();
             }
             else//If cell is unoccupied
             {
                if (neighbors == 3)//If an empty cell has exactly three neighbors, it comes alive
                   nextGen[i][j].birth();
             }                 
         } 
      }

      setWorld(nextGen);//The original array is replaced by the new generation

      //This nested loop resets nextGen for the next iteration  
      for (int i = 0; i < 40; i++)//iterates through the rows
      {
         for(int j = 0; j < 80; j++)//iterates through the columns
            nextGen[i][j].death();
      }             
       
      
      system("clear");//clears the screen in preparation for displaying the next generation 

      //The following code prints the new generation to the console     
      for (int i = 0; i < 40; i++)//iterates through the rows
      {
         for(int j = 0; j < 80; j++)//iterates through the columns
         {
            if ((i > 9 && i < 30) && (j > 19 && j < 60))//Prints to the visible 40 x 20 grid
            {
               if (world[i][j].getState() == false)//world now holds the new data
                  cout << " ";
               else  
                  cout << "O";
            }
         }
         if (i > 9 && i < 30)//Goes to the next line after each row is done printing 
            cout << endl;
      }
     
      usleep(250000);//Slows down the animation in between console prints
  
   }                                                  
}        

void GameOfLife::gliderGun(int x, int y)
{
   int row = x + 10;//Converts visible row # to match row # in the actual array
   int column = y + 20;//Converts visible column # to match column # in actual array 

   //Initial placement of the glider gun
   world[row][column].birth();//First group of cells on the left
   world[row + 1][column].birth();
   world[row][column + 1].birth();
   world[row + 1][column + 1].birth();
   
   world[row][column + 10].birth();//Second group of cells
   world[row - 1][column + 11].birth();
   world[row - 2][column + 12].birth();
   world[row - 2][column + 13].birth();
   world[row - 1][column + 15].birth();
   world[row][column + 16].birth();
   world[row + 1][column + 14].birth();
   world[row + 1][column + 16].birth();
   world[row + 1][column + 17].birth();
   world[row + 2][column + 16].birth();
   world[row + 3][column + 15].birth();
   world[row + 4][column + 13].birth();
   world[row + 4][column + 12].birth();
   world[row + 3][column + 11].birth();
   world[row + 2][column + 10].birth();
   world[row + 1][column + 10].birth();
   
   world[row + 2][column + 24].birth();//Third group of cells
   world[row + 1][column + 24].birth();
   world[row + 1][column + 22].birth();
   world[row][column + 21].birth();
   world[row][column + 20].birth();
   world[row - 1][column + 21].birth();
   world[row - 1][column + 20].birth();
   world[row - 2][column + 21].birth();
   world[row - 2][column + 20].birth();
   world[row - 3][column + 22].birth();
   world[row - 3][column + 24].birth();
   world[row - 4][column + 24].birth(); 

   world[row - 1][column + 34].birth();//Fourth group of cells
   world[row - 2][column + 34].birth();
   world[row - 1][column + 35].birth();
   world[row - 2][column + 35].birth();
     

   system("clear");//clears the screen in preparation for the game 
   
   for (int i = 0; i < 40; i++)//iterates through the rows
   {
      for(int j = 0; j < 80; j++)//iterates through the columns
      {
         if ((i > 9 && i < 30) && (j > 19 && j < 60))//Prints to the visible 40 x 20 grid
         {
            if (world[i][j].getState() == false)
               cout << " ";
            else  
               cout << "O";
         }
      }
      if (i > 9 && i < 30)//Goes to the next line after each row is done printing 
         cout << endl;
   }
   
   usleep(250000);//Slows down the animation in between console prints
 
   Cell nextGen[40][80];//New array for the next generation 

   for (int count = 0; count < 100; count++)//Game will continue for 100 generations
   {  
      for (int i = 0; i < 40; i++)//iterates through the rows
      {       
         for(int j = 0; j < 80; j++)//iterates through the columns
         {     
            int neighbors = 0;//counts surrounding neighbors
          
            if(world[i - 1][j - 1].getState() == true)//upper left neighbor
               neighbors++;

            if(world[i - 1][j].getState() == true)//upper middle neighbor
               neighbors++;

            if(world[i - 1][j + 1].getState() == true)//upper right neighbor
               neighbors++;  
                           
            if(world[i][j - 1].getState() == true)//left neighbor
               neighbors++;

            if(world[i][j + 1].getState() == true)//right neighbor
               neighbors++;

            if(world[i + 1][j - 1].getState() == true)//bottom left neighbor
               neighbors++;

            if(world[i + 1][j].getState() == true)//bottom middle neighbor
               neighbors++;

            if(world[i + 1][j + 1].getState() == true)//bottom right neighbor
               neighbors++;       
            
            //This if/else statement applies the game rules to each cell and creates the next generation  
            if (world[i][j].getState() == true)
            {
               if (neighbors < 2)//If an occupied cell has zero or one neighbor, it dies
                  nextGen[i][j].death();
               else if (neighbors > 3)//If an occupied cell has more than 3 neighbors, it dies 
                  nextGen[i][j].death();
               else//If an occupied cell has two or three neighbors it continues to live on   
                  nextGen[i][j].birth();
             }
             else//If cell is unoccupied
             {
                if (neighbors == 3)//If an empty cell has exactly three neighbors, it comes alive
                   nextGen[i][j].birth();
             }                 
         } 
      }

      setWorld(nextGen);//The original array is replaced by the new generation

      //This nested loop resets nextGen for the next iteration  
      for (int i = 0; i < 40; i++)//iterates through the rows
      {
         for(int j = 0; j < 80; j++)//iterates through the columns
            nextGen[i][j].death();
      }             
       
      
      system("clear");//clears the screen in preparation for displaying the next generation 

      //The following code prints the new generation to the console     
      for (int i = 0; i < 40; i++)//iterates through the rows
      {
         for(int j = 0; j < 80; j++)//iterates through the columns
         {
            if ((i > 9 && i < 30) && (j > 19 && j < 60))//Prints to the visible 40 x 20 grid
            {
               if (world[i][j].getState() == false)//world now holds the new data
                  cout << " ";
               else  
                  cout << "O";
            }
         }
         if (i > 9 && i < 30)//Goes to the next line after each row is done printing 
            cout << endl;
      }
     
      usleep(250000);//Slows down the animation in between console prints
  
   }                                                  
}        
 
void GameOfLife::setWorld(Cell nextGen[][80])
{
   for (int row = 0; row < 40 ; row++)
   {
      for (int column = 0; column < 80; column++)
      {
         world[row][column] = nextGen[row][column];//Assigns the next generation to the original array
      }
   }
}
                       

         
   

