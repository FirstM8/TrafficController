/*
  Programmer: ANDREW WANAMAKER             Date: 11/12/2018
       Class: CE3151
        File: final.h
     Purpose: Declare member functions and define pins.
*/

#ifndef FINAL_H
#define FINAL_H

#include <AT89X51.H>

#define RW P1_0
#define EN P1_1
#define RS P1_2
#define ON P1_3
#define BLON P1_4
#define dbg_led P1_7
#define LCD_DATA P0

// Miner Circle Lights
#define MC_RED P2_0
#define MC_GREEN P2_1

// Bishop Lights
#define B_RED P2_2
#define B_GREEN P2_3

// Crosswalk Lights
#define WALK P3_0
#define NO_WALK P3_1

// Sensors
#define CAR1 P2_6
#define CAR2 P2_7
#define PED_NORTH P2_4
#define PED_SOUTH P2_5

//Description: Initalizes the IO on the 8051
//        Pre: none
//       Post: IO Modes Set
void io_init(void);

//Description: Initializes the LCD Display
//        Pre: none
//       Post: LCD on and set up
void lcd_init(void);

//Description: Displays there is a Ped at the North cross walk
//        Pre: none
//       Post: Output to display
void north_cw_alert(void);

//Description: Displays there is a Ped at the South cross walk
//        Pre: none
//       Post: Output to display
void south_cw_alert(void);

//Description: Displays a car waiting at Miner Circle
//        Pre: none
//       Post: Output to display
void mc_alert(void);

//Description: Stops traffic on Bishop Ave
//        Pre: none
//       Post: Changes Traffic light to Red
void bishop_stop(void);

//Description: Starts traffic on Bishop Ave
//        Pre: none
//       Post: Changes traffic light to Green
void bishop_go(void);

//Description: Stops traffic on Miner Circle
//        Pre: none
//       Post: Changes traffic light to red
void mc_stop(void);

//Description: Starts traffic on Miner Circle
//        Pre: none
//       Post: Changes traffic light to Green
void mc_go(void);

//Description: Stops Ped Crossing
//        Pre: none
//       Post: Changes Ped Light to Red
void ped_stop(void);

//Description: Starts the Ped Crossing
//        Pre: none
//       Post: Changes Ped light to Green
void ped_go(void);

//Description: Clears LCD Screen
//        Pre: none
//       Post: LCD Cleared
void lcd_clear(void);

//Description: Turns on the LCD
//        Pre: none
//       Post: LCD is On
void lcd_on(void);

//Description: Turns off the LCD
//        Pre: none
//       Post: LCD Off
void lcd_off(void);

//Description: Sets the Function of the LCD
//        Pre: none
//       Post: Function is set
void lcd_fn_set(void);

//Description: Sets the mode of the LCD
//        Pre: none
//       Post: Mode is set
void lcd_mode_set(void);

//Description: Moves cusor to the second line
//        Pre: none
//       Post: Coursor on second line
void lcd_2_line(void);

//Description: Sends message to the LCD
//        Pre: character
//       Post: Data is sent to the LCD
void write_data_to_lcd(char dat);

//Description: Loops Nothing to Delay
//        Pre: Positive Integer
//       Post: none
void delay(long x);

#endif