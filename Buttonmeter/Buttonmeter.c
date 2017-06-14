/*
 *Project #5
 *Anna Jackson
 *Buttonmeter - Use a button to turn on and off and LED
 *06/14/17 
*/
#include "simpletools.h"                      

int main()                                   
{
  

 
  while(1)
  {
    if(input(0)== 1) 
    {
      putChar(HOME);
      print("I've been pressed! %c\n",CLREOL);
      high(26);
      low(27);
      
      
     
    }
    else
    { 
    putChar(HOME);
    print("Press Me! %c\n",CLREOL); 
    high(27);
    low(26);
            
    }  
    pause(100);
 }  
}
