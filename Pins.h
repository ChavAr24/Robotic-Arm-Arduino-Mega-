#include <Servo.h>

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
#define sw7 22  // button 7 pin 22
#define pt1 A4  // potentiometer pin 23 
#define pt2 A5  // potentiometer pin 24
#define pt3 A6  // potentiometer pin 25
#define pt4 A7  // potentiometer pin 26


Servo base;     // base
Servo shoulder; // shoulder
Servo elbow;    // elbow
Servo wrist;    // wrist arm joint
Servo wristrot; // wrist rotation 
Servo thumb;    // thumb / first finger
Servo index;    // index / second finger
Servo midfing;  // third finger

void setup() {
  // put your setup code here, to run once:
  pinMode(j1x,INPUT);
  pinMode(j1y,INPUT);
  pinMode(j2x,INPUT);
  pinMode(j2y,INPUT);

  pinMode(pt1, INPUT);
  pinMode(pt2, INPUT);
  pinMode(pt3, INPUT);
  pinMode(pt4, INPUT);
  
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(sw6, INPUT);
  pinMode(sw7, INPUT);
  shoulder.attach(8);
  base.attach(9);
  elbow.attach(10);
  wrist.attach(11);
  wristrot.attach(12);
  thumb.attach(13);
  index.attach(14);
  midfing.attach(15);
  
  wristrot.write(0);
  thumb.write(0);
  index.write(0);
  midfing.write(0);
  
  Serial.begin(9600);
}
