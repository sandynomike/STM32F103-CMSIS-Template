//  STM32F103-CMSIS-Template (edit as needed)
//  Target Microcontroller: STM32F103 (Blue Pill)
//  Mike Shegedin, 04/2023 (edit as needed)
//
//  main.c template to buil

//  main.c template to build CMSIS-based programs on the STM32F103
//  microcontroller. The template includes a blinky function that can
//  be used as a sanity check for the hardware and software toolchain.
//  If the toolchain is installed properly, the LED attached to GPIO
//  pin C13 (built-into the Blue Pill) will flash at about 1 Hz.


#include "stm32f103x6.h"  // Primary CMSIS header file


int main()
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;           // Enable GPIO Port C
  GPIOC->CRH &= ~(0b11 << GPIO_CRH_CNF13_Pos);  // Clear CNF Bits
  GPIOC->CRH |=  (0b01 << GPIO_CRH_MODE13_Pos); // Set MODE bits to 01

  while( 1 )
  {
    GPIOC->ODR ^= GPIO_ODR_ODR13;           // Toggle the LED
    for( uint32_t x=0 ; x<300000; x++) ;    // Pause approx 0.5 s
  }

}
