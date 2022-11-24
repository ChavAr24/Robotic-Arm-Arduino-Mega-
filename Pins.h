#include <Stepper.h>

#define j1x A0  // Joystick 1 x axis pin 0 = 508 - 514, anything below values of zero is negative direction and anything above is positive direction.
#define j1y A1  // Joystick 1 y axis pin 0 = 508 - 514, anything below values of zero is negative direction and anything above is positive direction.
#define j2x A2  // Joystick 2 x axis pin 0 = 514 - 524, anything below values of zero is negative direction and anything above is positive direction.
#define j2y A3  // Joystick 2 y axis pin 0 = 514 - 524, anything below values of zero is negative direction and anything above is positive direction.
#define sw1 2   // button 1 pin 2
#define sw2 3   // button 2 pin 3
#define sw3 4   // button 3 pin 4
#define sw4 5   // button 4 pin 5
#define sw5 6   // button 5 pin 6
#define sw6 7   // button 6 pin 7
#define ENL 52 // H-bridge enable pin for speed control (1,2)
#define ENR 51 // H-bridge enable pin for speed control (3,4)
#define MC1 53 // H-bridge leg 1
#define MC2 50 // H-bridge leg 2
#define MC3 53 // H-bridge leg 3
#define MC4 50 // H-bridge leg 4

const int stepsPerRevolution = (320*64) / 100;  // steps for stepper // 4096 // 2048

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  pinMode(j1x,INPUT);
  pinMode(j1y,INPUT);
  pinMode(j2x,INPUT);
  pinMode(j2y,INPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(sw6, INPUT);

  pinMode(ENL, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
  pinMode(ENR, OUTPUT);
  pinMode(MC3, OUTPUT);
  pinMode(MC4, OUTPUT); 

  myStepper.setSpeed(20); //works from 1 - 18// crashes after 18 // 18 is fast enoughfor the base

  Serial.begin(9600);
}
