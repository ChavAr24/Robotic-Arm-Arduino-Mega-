#include "Pins.h"
#include "Functions.cpp"

int x1Map, y1Map, x2Map, y2Map;  // variable for maping the values from the joystick

int baseV, shoulderV, elbowV, wristV;  // variables to store the values after store button is pressed.

int mode = 0; // 0 = follow, 1 = learn, 2 = ?

bool pressed = false; // boolean to store if button 7 was pressed or not.
bool thumbpresd = false; // boolean to store if button 1 was pressed or not.
bool indexpresd = false; // boolean to store if button 2 was pressed or not.
bool midpresd = false; // boolean to store if button 3 was pressed or not.
bool modepresd = false; // boolean to store if button 6 was pressed or not.

int wristpos =  90;

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
    int thumbv = digitalRead(sw1);
    int indexv = digitalRead(sw2);
    int midfingv = digitalRead(sw3);
    int wristpm = digitalRead(sw4);   // wrist position minus
    int wristpp = digitalRead(sw5);   // wrist position plus
    int modebtnv = digitalRead(sw6);
    int sw7v = digitalRead(sw7);
    delay(20);

//Mapping Joysticks
    x1Map = map(x1, 0, 1023, 0, 180); 
    y1Map = map(y1, 0, 1023, 0, 180);
    x2Map = map(x2, 0, 1023, 0, 180);  // 0, 1023, 0, 255 ; 0, 1023, 0, 180
    y2Map = map(y2, 0, 1023, 0, 180);
    Serial.println((String) " x1: " + x1Map + " | y1: " + y1Map + " | x2: " + x2Map + " | y2: " + y2Map + " | sw1: " + thumbv + " | sw2: " + indexv + " | sw3: " + midfingv + " | sw4: " + wristpm + " | sw5: " + wristpp + " | sw6: " + modebtnv + " | sw7: " + sw7v);


    if (sw7v == HIGH && pressed == false){
      pressed = true;
      delay(20);
    }
    else if (sw7v == HIGH && pressed == true){
      pressed = false; 
      delay(20);
    }

    if (pressed == false){
      base.write(x1Map);
      shoulder.write(y1Map);
      elbow.write(y2Map);
      wrist.write(x2Map);
      baseV = x1Map;
      shoulderV = y1Map;
      elbowV = y2Map;
      wristV = x2Map;
    }

    else if(pressed == true){
      base.write(baseV);
      shoulder.write(shoulderV);
      elbow.write(elbowV);
      wrist.write(wristV);
    }

    // code for the rest of the 4 servos to be controlled with the buttons. 
    // put this in a function
//    Serial.println(thumbv);
//    thumbpresd = btncontrollpressed(thumb, thumbpresd);
// thumb
    if (thumbv == 1 && thumbpresd == false){
      thumbpresd = true;
      if(thumbpresd == true){
        thumb.write(0);
      }
    }
    else if (thumbv == 1 && thumbpresd == true){
      thumbpresd = false;
      if(thumbpresd == false){
        thumb.write(90);
      }
    }
//    index
    if (indexv == 1 && indexpresd == false){
      indexpresd = true;
      if(indexpresd == true){
        index.write(0);
      }
    }
    else if (indexv == 1 && indexpresd == true){
      indexpresd = false;
      if(indexpresd == false){
        index.write(90);
      }
    }
//    midfing
    if (midfingv == 1 && midpresd == false){
      midpresd = true;
      if(midpresd == true){
        midfing.write(0);
      }
    }
    else if (midfingv == 1 && midpresd == true){
      midpresd = false;
      if(midpresd == false){
        midfing.write(90);
      }
    }
////    modebtn
//    if (modebtnv == 1 && modepresd == false){
//      modepresd = true;
//    }
//    else if (modebtnv == 1 && modepresd == true){
//      modepresd = false;
//    }
    

// left right (wrist rotation
    if (wristpm == 1){
      wristpos -= 3;
    }
    else if (wristpp == 1){
      wristpos += 3;
    }
    else{
      wristpos = wristpos;
    }
    wristrot.write(wristpos);

    
//    Serial.println(pressed);
    delay(20);
  }

  while (mode == 1){ // learn mode
    
  }
}


// one button registers the values of all joysticks when the button is pressed so the joystick can be released for other inputs.
