#include "Pins.h"

int x1Map, y1Map, x2Map, y2Map;  // variable for maping the values from the joystick

int base, shoulder, elbow, wrist;  // variables to store the values after store button is pressed.

int mode = 0; // 0 = follow, 1 = learn, 2 = ?
void loop() {
  if (sw7 == HIGH){
    if (mode <= 1){
      mode += 1;
    }
    else{
      mode = 0;
    }
  }
  
  while (mode == 0){  // follow mode
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
    int sw7v = digitalRead(sw7);

//    use while loop before mapping.
    // mapping joystick
    x1Map = map(x1, 0, 1023, 0, 180); 
    y1Map = map(y1, 0, 1023, 0, 255);
    x2Map = map(x2, 0, 1023, 0, 255);  // 0, 1023, 0, 255 , 0, 1023, 0, 180
    y2Map = map(y2, 0, 1023, 0, 255);
    Serial.println((String)" x1: " + x1Map + " | y1: " + y1Map + " | x2: " + x2Map + " | y2: " + y2Map + " | sw1: " + sw1v + " | sw2: " + sw2v + " | sw3: " + sw3v + " | sw4: " + sw4v + " | sw5: " + sw5v + " | sw6: " + sw6v);

    base.write(x1Map);
    shoulder.write(y1Map);
    elbow.write(y2Map);
    wrist.write(x2Map);
  
    delay(10);
  }

  while (mode == 1){ // learn mode
    
  }
}


// one button registers the values of all joysticks when the button is pressed so the joystick can be released for other inputs.
