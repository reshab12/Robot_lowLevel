#include <avr/io.h>
#include <avr/interrupt.h>

//This blinks the LED with an interrupt every second.
//ISR(TIMER1_COMPA_vect) {
//  PINB |= _BV(PINB5);  
//}

ISR(PCINT2_vect){
  PINB |= _BV(PINB5); 
  //OCR2B = 0;
}

void init() {
  cli();
  //Set up the Pins as input and output.
  DDRB &= 0;
  DDRD &= 0;
  DDRB |= _BV(DDB5);  //Set LED as output

  //DDRB |= _BV(DDB0);  //Set D8 as output
  //DDRB |= _BV(DDB3);  //Set D11 as output. PWM
  //DDRB |= _BV(DDB2);  //Set D10 as output

  DDRD |= _BV(DDD2);  //Set D2 as output
  DDRD |= _BV(DDD3);  //Set D3 as output. PWM
  DDRD |= _BV(DDD4);  //Set D4 as output. 

  //DDRD |= (1<<DDD7); //Set D7 as output.

  //Start rotating motors in one direction
  //PINB |= _BV(PINB0);
  PIND |= _BV(PIND2);
  PIND |= _BV(PIND7);

  //Set up the timer interrupts.
  TCCR1A &= 0; //Reset Register
  TCCR1B &= 0; //Reset Register
  OCR1A = 15624;  // = (target time / timer resolution) - 1 or 1 / 6.4e-5 - 1 = 15624
  //OCR1A = 15624>>1;  // divide by two >>EDIT added this line<<
  TCCR1B |= (1 << WGM12);  // CTC
  TCCR1B |= (1 << CS10);   // Set CS10 and CS12 bits for 1024 prescaler:
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);  // timer compare intrupt for A

  TCCR2A &= 0;
  TCCR2B &= 0;
  //OCR2A = 200; //set duty cicle
  OCR2B = 200; //set duty cicle

  TCCR2A |= (1<<WGM21) | (1<<WGM20); //Fast PWM Mode
  //TCCR2B |= (1<<WGM22);
  TCCR2B |= (1<<CS22); //Set prescaler to 64.
  //TCCR2A |= (1<<COM2A1); //Set clear on match and not inverted mode
  //TCCR2A &= ~(1<<COM2A0);
  TCCR2A |= (1<<COM2B1); //Set clear on match and not inverted mode
  TCCR2B &= ~(1<<COM2B0);

  //Set up the pin change interrupts.
  PCMSK2 &= 0;
  PCICR &= 0;
  PCICR |= (1<< PCIE2);
  PCMSK2 |= (1<< PCINT23);
  sei();
}

int main() {

  init();

  while (1) {

  }

  return 0;  // We will never get here!
}