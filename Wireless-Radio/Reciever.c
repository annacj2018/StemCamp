/*
  *Recieve
  *Project#10
  *Anna Jackson
  *06/16/17 
*/
#include "simpletools.h"
#include "fdserial.h"
void init_radio(fdserial *radio);                      

int main()                                    
{ 
 char c = '?';
 fdserial *xbee;
 
 //check to make sure the sender program is running on another board
 print("This board will recieve messages via wireless \n");
 print("You MUST start the program on the other board first!\n");
 while (c != 'Y' || c != 'y')
 {
   print("Is the other program started? ");
   scan("%c" , &c);
 }
 print("\n");
    
   
 //open a serial connection to the xbee radio//
 xbee = fdserial_open(0,1,0,9600);
 init_radio(xbee);
 
 //clear the sender's screen and tell them it is okay to start typing
 
 fdserial_txChar(xbee, CLS);
 dprint(xbee, "Connection established \n");
 dprint(xbee, "Click on this screen and type your message. \n");
 
 
 
 
 

 //get a character from the radio and print it on the screen
 
while(1)
  {
    c = fdserial_rxChar(xbee);
    if (c !=255)
    { 
    print("%c%", c);
    }     
  }  
}

void init_radio(fdserial *radio)
{
  const char channel= 'B'; //0x0 to 0x1A, must match your partner
  const char PAN_ID[] = "AAAA"; // 0x0 to 0xFFFF, Must match your partner
  const char DEST_ID[] ="0002"; //0x0 to 0xFFFF ,Must be your partner's SRC_ID
  const char SRC_ID[] = "0001"; //0x0 to 0xFFFF, must be your partner's DEST_ID\
  
  char result[32] = {0};
  
  dprint(radio, "+++");
  pause(50);
  dscan(radio, "%s" , &result);
  print("Radio  initialization: %s\n", result);
  pause(50);
  
  dprint(radio, "ATRE\n");
  dprint(radio, "ATCH%c\n" , channel);
  dprint(radio, "ATID%s\n" , PAN_ID);
  dprint(radio, "ATDL%s\n" , DEST_ID);
  dprint(radio, "ATMY%s\n");
  dprint(radio, "ATAC\n");
  dprint(radio, "ATCN\n");
  pause(500);
  print("\n");
}