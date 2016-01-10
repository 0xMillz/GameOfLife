//**************************************************************
//Author: Mills McIlroy
//Date: October 4, 2015
//Description: This program uses the Cell class to play Conway's 
//   Game of Life.
//***************************************************************
#include <iostream>
#include "Cell.hpp"
#include "GameOfLife.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
   int userChoice;    
   
   do {
      
      cout << endl;
      cout << "Welcome to Conway's Game of Life!" << endl;
      cout << "Please choose one of these three starting shapes:" << endl;
      cout << "1. Fixed oscillator (blinker)" << endl;
      cout << "2. Glider" << endl;
      cout << "3. Gosper Glider Gun" << endl;  
      cout << "4. Quit" << endl;
      cin >> userChoice;
      
      
      if (userChoice == 1)
      {
         int row;
         int column;
         cout << "Thank you. The game will last for 100 generations." << endl;
         cout << "Choose where you would like the middle cell of the oscillator to be in a grid with" << endl;
         cout << "20 rows and 40 columns." << endl;
         cout << "The rows are numbered 0-19 and the columns are numbered 0-39." << endl;
         cout << "Enter a row #: " << endl;
         cin >> row;
         cout << "Enter a column #:" << endl;
         cin >> column;

         GameOfLife game;//create an object of the GameOfLife class
         game.oscillator(row, column);//passes starting cell to oscillator function
       

      }
      else if (userChoice == 2)
      {  
         int row;
         int column;
         cout << "Thank you. The game will last for 100 generations." << endl;
         cout << "Choose the cell that you would like the glider to be centered" << endl;
         cout << "around at the start of the game in a grid with 20 rows and 40 columns." << endl;
         cout << "The rows are numbered 0-19 and the columns are numbered 0-39." << endl;
         cout << "Enter a row #: " << endl;
         cin >> row;
         cout << "Enter a column #:" << endl;
         cin >> column;

         GameOfLife game;//create an object of the GameOfLife class
         game.glider(row, column);//passes starting cell to the glider function
      }
      else if (userChoice == 3)
      {
         int row;
         int column;
         cout << "Thank you. The game will last for 100 generations." << endl;
         cout << "Choose the cell where you would like the left top side of the" << endl;
         cout << "gosper glider gun to start. Keep in mind that the gun is 36 cells" << endl;
         cout << "wide so it may be partially off screen if you place it too far off center." << endl;
         cout << "The grid is 20 rows high and 40 columns wide." << endl;
         cout << "The rows are numbered 0-19 and the columns are numbered 0-39." << endl;
         cout << "Enter a row #: " << endl;
         cin >> row;
         cout << "Enter a column #:" << endl;
         cin >> column;

         GameOfLife game;//create an object of the GameOfLife class
         game.gliderGun(row, column);//passes starting cell to the glider function
      }
      else if (userChoice != 4)
         cout << "Please enter a valid input next time." << endl;  

      } while (userChoice != 4);
      
   return 0;
}
 
       
         
