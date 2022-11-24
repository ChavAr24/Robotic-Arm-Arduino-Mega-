#include "Pins.h"
//#include "Functions.h"

int x1Map, y1Map, x2Map, y2Map;  // variable for maping the values from the joystick


//Functions

void forward (int rate)
{
    digitalWrite(ENL, LOW);
    digitalWrite(ENR, LOW);
    digitalWrite(MC1, HIGH);
    digitalWrite(MC2, LOW);
    digitalWrite(MC3, HIGH);
    digitalWrite(MC4, LOW);
    
    analogWrite(ENL, rate);
    analogWrite(ENR, rate);
}

//Motor goes backward at given rate (from 0-255)
void reverse (int rate)
{
    digitalWrite(ENL, LOW);
    digitalWrite(ENR, LOW);
    digitalWrite(MC1, LOW);
    digitalWrite(MC2, HIGH);
    digitalWrite(MC3, LOW);
    digitalWrite(MC4, HIGH);
    
    analogWrite(ENL, rate);
    analogWrite(ENR, rate);
}

//Stops motor
void brake ()
{
    digitalWrite(ENL, LOW);
    digitalWrite(ENR, LOW);
    digitalWrite(MC1, LOW);
    digitalWrite(MC2, LOW);
    digitalWrite(MC3, LOW);
    digitalWrite(MC4, LOW);
    
    digitalWrite(ENL, HIGH);
    digitalWrite(ENR, HIGH);
}



// Main
void loop() {
  // reading joystick values:
  int x1 = analogRead(j1x);
  int y1 = analogRead(j1y);
  int x2 = analogRead(j2x);
  int y2 = analogRead(j2y);
  int sw1v = digitalRead(sw1);
  int sw2v = digitalRead(sw2);
  int sw3v = digitalRead(sw3);
  int sw4v = digitalRead(sw4);
  int sw5v = digitalRead(sw5);
  int sw6v = digitalRead(sw6);

  // mapping joystick
  x1Map = map(x1, 0, 1023, 0, 255); 
  y1Map = map(y1, 0, 1023, 0, 255);
  x2Map = map(x2, 0, 1023, 0, 255);  // 0, 1023, 0, 255  0, 1024, 0, 500
  y2Map = map(y2, 0, 1023, 0, 255);
  Serial.println((String)" x1: " + x1Map + " | y1: " + y1Map + " | x2: " + x2Map + " | y2: " + y2Map + " | sw1: " + sw1v + " | sw2: " + sw2v + " | sw3: " + sw3v + " | sw4: " + sw4v + " | sw5: " + sw5v + " | sw6: " + sw6v);

// Motor 1 ( Arm1)
  if (y2Map > 130){
    forward(y2Map);
  }
  else if (126 < y2Map < 130){
    brake();
  }
  else if (y2Map < 126){
    reverse(y2Map);
  }


//stepper (Base)
  if (x2Map > 130){
    myStepper.step(stepsPerRevolution);
    delay(10);
  }
  else if (126 < x2Map > 130){
    myStepper.step(0);
  }
  else if (x2Map < 126){
    myStepper.step(-stepsPerRevolution);
    delay(10);
  }
}
