// this is the header file that tells the compiler what pins and ports, etc.
// are available on this chip.
#include <avr/io.h>

// define what pins the LEDs are connected to.
// in reality, PD6 is really just '6'
#define LED PA0

// Some macros that make the code more readable
#define output_low(port,pin) port &= ~(1<<pin)
#define output_high(port,pin) port |= (1<<pin)
#define set_input(portdir,pin) portdir &= ~(1<<pin)
#define set_output(portdir,pin) portdir |= (1<<pin)

// this is just a program that 'kills time' in a calibrated method
void delay_ms(uint16_t ms) {
  uint16_t delay_count = F_CPU / 72000;
  volatile uint16_t i;

  while (ms != 0) {
    for (i=0; i != delay_count; i++);
    ms--;
  }
}

int main(void) {
  // initialize the direction of PORTD #6 to be an output
  set_output(DDRA, LED);  

  while (1) {
	uint16_t time = 200;
  
    // turn on the LED for 200ms
    output_high(PORTA, LED);
    delay_ms(time);
    // now turn off the LED for another 200ms
    output_low(PORTA, LED);
    delay_ms(time);
    // now start over
  }
}