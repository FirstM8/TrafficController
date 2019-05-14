/*
  Programmer: ANDREW WANAMAKER             Date: 11/12/2018
       Class: CE3151
        File: final_funct.c
     Purpose: Define member functions.
*/

#include "final.h"

void io_init(void)
{
  /*P2M1 = 0x00;
  P2M2 = 0x00;       // Defalut of Bidirectional Mode is Used
  P3M1 = 0x00;
  P3M2 = 0x00;*/

  // Defualt Light Settings
  MC_RED = 1;
  MC_GREEN = 0;
  B_RED = 1;
  B_GREEN = 0;
  WALK = 0;
  NO_WALK = 1;

  return;
}
void lcd_init(void)
{
  //LCD Initializations
  ON = 1;
  BLON = 1;
  lcd_off();
  delay(1); 
  lcd_on();
  delay(1);
  lcd_clear();
  delay(1);
  lcd_fn_set();
  delay(1);
  lcd_mode_set();
  delay(1);

    return;
}

void north_cw_alert(void)
{
  write_data_to_lcd('P'); delay(1); write_data_to_lcd('E'); delay(1);
  write_data_to_lcd('D'); delay(1);
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('W'); delay(1); write_data_to_lcd('A'); delay(1);
  write_data_to_lcd('I'); delay(1); write_data_to_lcd('T'); delay(1);
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('N'); delay(1); write_data_to_lcd('O'); delay(1);
  write_data_to_lcd('R'); delay(1); write_data_to_lcd('T'); delay(1);
  write_data_to_lcd('H'); delay(1);

  return;
}

void south_cw_alert(void)
{
  write_data_to_lcd('P'); delay(1); write_data_to_lcd('E'); delay(1);
  write_data_to_lcd('D'); delay(1);
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('W'); delay(1); write_data_to_lcd('A'); delay(1);
  write_data_to_lcd('I'); delay(1); write_data_to_lcd('T'); delay(1);
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('S'); delay(1); write_data_to_lcd('O'); delay(1);
  write_data_to_lcd('U'); delay(1); write_data_to_lcd('T'); delay(1);
  write_data_to_lcd('H'); delay(1);

  return;
}

void mc_alert(void)
{
  write_data_to_lcd('M'); delay(1); write_data_to_lcd('I'); delay(1);
  write_data_to_lcd('N'); delay(1); write_data_to_lcd('E'); delay(1);
  write_data_to_lcd('R'); delay(1);
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('C'); delay(1); write_data_to_lcd('I'); delay(1);
  write_data_to_lcd('R'); delay(1); write_data_to_lcd('C'); delay(1);
  write_data_to_lcd('L'); delay(1); write_data_to_lcd('E'); delay(1);
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('C'); delay(1); write_data_to_lcd('A'); delay(1);
  write_data_to_lcd('R'); delay(1);

  return; 
}

void bishop_go(void)
{
  B_RED = 0;    // Red Light Off
  B_GREEN = 1;  //  Green Light On
  
  // Dsplays Message
  lcd_clear();
  delay(1);
  //lcd_2_line();
  delay(1);
  write_data_to_lcd('B'); delay(1); write_data_to_lcd('I'); delay(1); 
  write_data_to_lcd('S'); delay(1); write_data_to_lcd('H'); delay(1);
  write_data_to_lcd('O'); delay(1); write_data_to_lcd('P'); delay(1);
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('A'); delay(1); write_data_to_lcd('V'); delay(1);
  write_data_to_lcd('E'); delay(1); 
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('G'); delay(1); write_data_to_lcd('O'); delay(1);

  delay(500);
  lcd_clear();
  return;
}

void bishop_stop(void)
{
  int i;

  B_GREEN = 0;  //Green Light Off
  
  
  // Flash red to indicate Yellow Light
  for (i = 0; i < 8; ++i)
  {                        // Flahes light using even and odd numbers
    if ((i%2)==0){B_RED = 1; delay(12);}
    else {B_RED = 0; delay(12);}
  }
  
  B_RED = 1;   // Turn Red light on
  delay(3);
  return;
}

void mc_go(void)
{
  MC_RED = 0;    // Red Light Off
  MC_GREEN = 1;  // Green Light On
 
  // Outputs Message
  lcd_clear();
  delay(1);
  //lcd_2_line();
  delay(1);
  write_data_to_lcd('M'); delay(1); write_data_to_lcd('I'); delay(1);
  write_data_to_lcd('N'); delay(1);
  write_data_to_lcd('E'); delay(1); write_data_to_lcd('R'); delay(1);
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('C'); delay(1); write_data_to_lcd('I'); delay(1);
  write_data_to_lcd('R'); delay(1);
  write_data_to_lcd('C'); delay(1); write_data_to_lcd('L'); delay(1);
  write_data_to_lcd('E'); delay(1); 
  write_data_to_lcd(' '); delay(1);
  write_data_to_lcd('G'); delay(1); write_data_to_lcd('O'); delay(1);

  delay(500);
  lcd_clear();
  return;
}

void mc_stop(void)
{
  int i;
  
  MC_GREEN = 0; // Green Light Off
  
  // Flashes Red to indicate yellow light
  for (i = 0; i < 8; ++i)
  {                       // Flahes light using even and odd numbers
    if ((i%2)==0){MC_RED = 1; delay(12);}
    else {MC_RED = 0; delay(12);}
  }
  
  MC_RED = 1;  //Red Light On
  delay(3);
  return;
}

void ped_go(void)
{
  lcd_clear();
  NO_WALK = 0;  // Red Light Off
  WALK = 1;     // Green light on
  delay(500);
  return;
}

void ped_stop(void)
{
  int i;
  
  WALK = 0; // Green Light Off
  
  // Flashes Red light to indicate yellow light
  for (i = 0; i < 8; ++i)
  {                       // Flahes light using even and odd numbers
    if ((i%2)==0){NO_WALK = 1; delay(12);}
    else {NO_WALK = 0; delay(12);}
  }
  
  NO_WALK = 1; // Red light On
  delay(3);
  return;
}

void lcd_clear(void)
{
  RS = 0;
  RW = 0;
  EN = 1;
  LCD_DATA = 0x01;
  EN = 0;
}

void lcd_on(void)
{
  RS = 0;
  RW = 0;
  EN = 1;
  LCD_DATA = 0x0C;
  EN = 0;
}

void lcd_off(void)
{
  RS = 0;
  RW = 0;
  EN = 1;
  LCD_DATA = 0x08;
  EN = 0;
}

void lcd_fn_set(void)
{
  RS = 0;
  RW = 0;
  EN = 1;
  LCD_DATA = 0x30;
  EN = 0;
}

void lcd_mode_set(void)
{
  RS = 0;
  RW = 0;
  EN = 1;
  LCD_DATA = 0x06;
  EN = 0;
}

void lcd_2_line(void)
{
  RS = 0;
  RW = 0;
  EN = 1;
  LCD_DATA = 0x0C0;
  EN = 0;
}

void write_data_to_lcd(char dat)
{
  RS = 1;
  RW = 0;
  EN = 1;
  LCD_DATA = dat;
  EN = 0;
}

void delay(long x)
{
  long i;
  for(i = 0; i < x*1000; i++);
}