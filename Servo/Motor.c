/*
  *project # 7
  *Anna Jackson
  *Servo
  *Control a servo motor with two buttons 
*/
#include "simpletools.h" 
#include "servo.h"
//constants are names we use to make our program easier to understand and maintain//

const int RIGHT = (9);
const int LEFT = (2);
const int servo = (14); 

//servo angles in our library are shown x10, for example, 90 deg = 900

const int RSTOP = 1700;
const int LSTOP = 10;
                    

int main()                                    
{
  int angle = 900;
 
  while(1)
  { // get pushbutton state//
  if(input(LEFT) == 1)
  {
    angle = angle - 18; 
  }  
  
  if (input(RIGHT) == 1)
  {
    angle = angle  + 18;
  }
  //limit the angle of the servo to keep it from breaking//
  
  if (angle > RSTOP)
  { 
  angle = RSTOP; 
  }
  
  if (angle < LSTOP)
  { 
  angle = LSTOP; 
  }
  
  //update the serial console (screen output)
  print( "%c angle = %d %c", HOME, angle, CLREOL);
  
  servo_angle(servo, angle);
  
  pause(25);
  
  //end of while loop//
 }   
 
}
