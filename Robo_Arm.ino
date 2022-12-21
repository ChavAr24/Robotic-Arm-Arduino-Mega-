#include "Pins.h"
//#include "Functions.cpp"

int x1Map, y1Map, x2Map, y2Map, thumbMap, indexMap, midfingMap, wristMap;  // variable for maping the values from the joystick

int baseV, shoulderV, elbowV, wristV;  // variables to store the values after store button is pressed.

int mode = 0; // 0 = follow, 1 = learn, 2 = ?

bool pressed = false; // boolean to store if button 7 was pressed or not.
bool thumbpresd = false; // boolean to store if button 1 was pressed or not.
bool indexpresd = false; // boolean to store if button 2 was pressed or not.
bool midpresd = false; // boolean to store if button 3 was pressed or not.
bool modepresd = false; // boolean to store if button 7 was pressed or not.

int wristpos =  90;
int basepos = 90;
int shoulderpos =  90;
int wristjointpos = 90;
int elbowpos =  90;

void loop() {
  int modebtnv = digitalRead(sw6);
  delay(20);
  if (modebtnv == HIGH){
    if (mode < 1){
      mode += 1;
    }
    else{
      mode = 0;
    }
  }
  Serial.println(mode);
  delay(2000);
  if (mode == 0){
    while (mode == 0){  // follow mode
      Serial.println("follow");
      // reading joystick values:
      int x1 = analogRead(j1x);
      int y1 = analogRead(j1y);
      int x2 = analogRead(j2x);
      int y2 = analogRead(j2y);
      int thumbjv = analogRead(pt1);
      int indexjv = analogRead(pt2);
      int midfingjv = analogRead(pt3);
      int wristrotjv = analogRead(pt4);
      int thumbv = digitalRead(sw1);
      int indexv = digitalRead(sw2);
      int midfingv = digitalRead(sw3);
      int wristpm = digitalRead(sw4);   // wrist position minus
      int wristpp = digitalRead(sw5);   // wrist position plus
      int sw7v = digitalRead(sw7);
      delay(5);

//Mapping Joysticks
      x1Map = map(x1, 0, 1023, -40, 40); 
      y1Map = map(y1, 0, 1023, -40, 40);
      x2Map = map(x2, 0, 1023, -40, 40);  // 0, 1023, 0, 255 ; 0, 1023, 0, 180
      y2Map = map(y2, 0, 1023, -40, 40);
      thumbMap = map(thumbjv, 0, 1023, 0, 180); 
      indexMap = map(indexjv, 0, 1023, 0, 180);
      midfingMap = map(midfingjv, 0, 1023, 0, 180);  // 0, 1023, 0, 255 ; 0, 1023, 0, 180
      wristMap = map(wristrotjv, 0, 1023, 0, 180);
      Serial.println((String) " x1: " + x1Map + " | y1: " + y1Map + " | x2: " + x2Map + " | y2: " + y2Map + " | sw1: " + thumbv + " | sw2: " + indexv + " | sw3: " + midfingv + " | sw4: " + wristpm + " | sw5: " + wristpp + " | sw6: " + modebtnv + " | sw7: " + sw7v);
  
      if(x1Map > 1){basepos = basepos + x1Map;}
      if(x1Map < -1){basepos = basepos + x1Map;}

      if(y1Map > 1){shoulderpos = shoulderpos + y1Map;}
      if(y1Map < -1){shoulderpos = shoulderpos + y1Map;}
          
      if(x2Map > 1){wristjointpos = wristjointpos + x2Map;}
      if(x2Map < -1){wristjointpos = wristjointpos + x2Map;}

      if(y2Map > 1){elbowpos = elbowpos + y2Map;}
      if(y2Map < -1){elbowpos = elbowpos + y2Map;}

//    if (pressed == false){
      Serial.println((String) basepos + " " + shoulderpos + " " + elbowpos + " " + wristjointpos);
      if (basepos<0){basepos = 0;}
      else if (basepos>180){basepos = 180;}
      else {basepos = basepos;}

      if (shoulderpos<35){shoulderpos = 35;}
      else if (shoulderpos>145){shoulderpos = 145;}
      else {shoulderpos = shoulderpos;}

      if (elbowpos<0){elbowpos = 0;}
      else if (elbowpos>180){elbowpos = 180;}
      else {elbowpos = elbowpos;}

      if (wristjointpos<0){wristjointpos = 0;}
      else if (wristjointpos>180){wristjointpos = 180;}
      else {wristjointpos = wristjointpos;}

      base.write(basepos);
      shoulder.write(shoulderpos);
      elbow.write(elbowpos);
      wrist.write(wristjointpos);
      thumb.write(thumbMap);
      index.write(indexMap);
      midfing.write(midfingMap);
      wristrot.write(wristMap);

      modebtnv = digitalRead(sw6);
      if(modebtnv == HIGH){
        modepresd = true;
      }
      if(mode != 1 && modepresd == true){
        mode = 1;
        break;
      }
      
    
//    Serial.println(pressed);
      delay(10);
    }
  }
  
  else if ( mode == 1){
    while (mode == 1){ // learn mode
      Serial.println("learn");

      if (modebtnv == HIGH){
        mode = 0;
        break;
      }
    }
  }
}
