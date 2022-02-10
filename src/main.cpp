#include <msp430.h>

int main(void)
{
  volatile unsigned long i;

  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
  P4DIR |= BIT7;                            // P1.0 set as output
  P1DIR |= BIT0;
  while(1)                                  // continuous loop
  {
      for(i=50000; i>0; i--);                   // Delay
      {
          P4OUT ^= BIT7;                        // XOR P1.0
      }
      for(i=100000; i>0; i--);
      {
          P1OUT ^= BIT0;
      }
  }
}
