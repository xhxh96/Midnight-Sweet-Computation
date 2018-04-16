/*
 * Vincent's sensor drivers.
 *
 */

#define trigPinU  11 //grey jumper wire
#define echoPinU  8  // white jumper wire
#define leftIR    A4
#define rightIR   A5

int duration;

void setupSensors() {
  //DDRB |= 00001000;   //trigPinU (PB3) set to OUTPUT (1), 
  //DDRB &= 11111110;   //echoPinU (PB0) set to INPUT (0)
  DDRC &= 11001111;   //PC4 and PC5 both set to INPUT (0)

  
  pinMode(trigPinU, OUTPUT);
  pinMode(echoPinU, INPUT);
  //pinMode(leftIR, INPUT);
  //pinMode(rightIR, INPUT);
  
}

void startSensors() {
  // Ultrasound
  digitalWrite(trigPinU, LOW);
  //PORTB &= 11110111;    //digitalWrite(trigPinU, LOW),  trigPinU = PB3, set to 0
  delayMicroseconds(5);
  
  digitalWrite(trigPinU, HIGH);
  //PORTB |= 00001000;    //digitalWrite(trigPinU, HIGH), trigPinU = PB3, set to 1
  delayMicroseconds(10);
    
  duration = pulseIn(echoPinU, HIGH, 4000);
  ultraInCm = (duration/2) / 29.1;

  //IR Sensors
  //its either CLEAR or TOO NEAR
  //rightIRreading = digitalRead(rightIR);
  rightIRreading = (PINC & 0b00010000) ? 1 : 0;  //rightIRreading = digitalRead(rightIR), Arduino Analog Pin 4 (ADC4) = PC4

  //leftIRreading = digitalRead(leftIR);
  leftIRreading =  (PINC & 0b00100000) ? 1 : 0;  //leftIRreading = digitalRead(leftIR), Arduino Analog Pin 5 (ADC5) = PC5
}
