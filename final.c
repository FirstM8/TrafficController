/*
  Programmer: ANDREW WANAMAKER             Date: 11/12/2018
       Class: CE3151
        File: final.c
     Purpose: Main Control Function
*/

#include "final.h"

void main()
{   
  io_init(); // initialize io ports
  lcd_init(); // initialize the LCD display
  bishop_go();  // Starts traffic on bishop
  while(1)
  {
    bishop_go();  // Default State is Green Light on Bishop
    delay(1);

    if (PED_NORTH || PED_SOUTH) // When crosswalk button is pressed.
    {
      if (PED_NORTH){north_cw_alert();}  // Alerts that a Ped is waiting
      else{south_cw_alert();}
      
      while(PED_NORTH || PED_SOUTH){}  // debouncing the switch
      
      delay(1);
	  bishop_stop(); // Stops Bishop Ave
      delay(1);
      mc_stop();     // Stops miner circle
      delay(1);
      ped_go();      // Ped Go
      delay(1);
      ped_stop();    // Ped Stop
      delay(1);      
    }
    else if (CAR1 || CAR2) // When a car is waiting on Miner Circle.
    {
      mc_alert();     // Alerts that a Car is waiting
      
      while(CAR1 || CAR2){}           // debouncing the switch
      
      delay(1);
      bishop_stop();  // Stops Bishop Ave
      delay(1);       
      mc_go();        // Miner Circle Goes
      delay(1);
      mc_stop();      // Miner Circle Stops
      delay(1);
    }
  }

  return;
}