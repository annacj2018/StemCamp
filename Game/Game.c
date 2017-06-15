/*
 *Project #6
 *Anna Jackson
 *Reaction Game using a button and two LED's
 *06/14/17 
*/
#include "simpletools.h"                      

int main()                                   
{
  int TimeCounter ;
  char PlayAgain = 'Y' ;
  int interval ;
  float Score = 0;
  int rounds = 0;
  
  srand(CNT);
  
  print("Game Instructions: \n");
  print("The green LED will turn on when the game starts. \n");
  print("When the blue LED turns on, let go of the button as fast as you can! \n\n");
  

 
  while(PlayAgain == 'Y' || PlayAgain == 'y')
  { 
  print("Press and hold the button to start!");
  
  while (input(8) == 0)
  { 
  //Intentional empty brackets// 
  } 
  
  high(0);
  low(1) ;
  
  interval = (rand() % 1001) + 500 ;
  pause(interval); 
  
 low(0);
  high(1);
  
  TimeCounter = 0;
  while (input(8) == 1 )
  
  { 
  pause(1);
  TimeCounter = TimeCounter + 1;
  } 
  low(1) ;
  
  if (TimeCounter > 0 )
  {
  print(" Your time was %d ms.\n", TimeCounter);
   Score = Score + TimeCounter ;
   rounds = rounds + 1;
  }  
   else   
  {
    print("You've let go of the button before time. Try ,try , again! \n");
  }
  
  print("Would you like to play again? (Y/N)" );
  scan("%c", &PlayAgain) ;
  //end of while loop for play again
  } 
  Score = Score / rounds;
  print( "Farwell my friend! Your Score was: %0.2f ms.\n");
  
  return 0;
   
}

