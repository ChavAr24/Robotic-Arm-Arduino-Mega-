#include "Pins.h"

int x1Map, y1Map, x2Map, y2Map;  // variable for maping the values from the joystick

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
  x2Map = map(x2, 0, 1024, 0, 500);  // 0, 1023, 0, 255
  y2Map = map(y2, 0, 1023, 0, 255);
  Serial.println((String)" x1: " + x1Map + " | y1: " + y1Map + " | x2: " + x2Map + " | y2: " + y2Map + " | sw1: " + sw1v + " | sw2: " + sw2v + " | sw3: " + sw3v + " | sw4: " + sw4v + " | sw5: " + sw5v + " | sw6: " + sw6v);


// Step one revolution in one direction:
  if (x2Map > 130){
//    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(10);
  }
//  
//  // Step one revolution in the other direction:
  else if (x2Map < 126){
//    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(10);
  }
//  delay(50);
}
// try hooking up 12v and increase the speed of the steppper
