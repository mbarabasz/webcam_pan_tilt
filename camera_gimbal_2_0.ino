#include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;
int step = 10;
// Motor 1 pins
int m1_1 = 3;
int m1_2 = 4;
int m1_3 = 5;
int m1_4 = 6;

// Motor 2 pins
int m2_1 = 7;
int m2_2 = 8;
int m2_3 = 9;
int m2_4 = 10;

int del = 850;

boolean up = false;
boolean down = false;
boolean left = false;
boolean right = false;

void setup() {
  irrecv.enableIRIn(); // Start the receiver
  pinMode(m1_1, OUTPUT);     
  pinMode(m1_2, OUTPUT);     
  pinMode(m1_3, OUTPUT);     
  pinMode(m1_4, OUTPUT);     

  pinMode(m2_1, OUTPUT);     
  pinMode(m2_2, OUTPUT);     
  pinMode(m2_3, OUTPUT);     
  pinMode(m2_4, OUTPUT);   
}

void loop() {
  readIr();
  for (int i=0; i<=step; i++){
    if (up){
      backward_m2();
    }else if (down){
      forward_m2();
    }else if (left){
      backward_m1();
    }else if (right){
      forward_m1();
    }
  };
  resetFlags();
}

void resetFlags(){
  up = false;
  down = false;
  left = false;
  right = false;
}
void readIr(){
  if (irrecv.decode(&results)) {
      //Serial.println(results.value, DEC); // Print the Serial 'results.value'
      irrecv.resume();   // Receive the next value
      if (results.value == 3261853764){
        up = true;
      }else if (results.value == 3305092678){
        down = true;
      }else if (results.value == 1972149634){
        left = true;
      }else if (results.value == 1400905448){
        right = true;
      }else if (results.value == 2331063592){
        //center
      }
   }
}

void forward_m1(){
  forwards(m1_1, m1_2, m1_3, m1_4);
}

void backward_m1(){
  backwards(m1_1, m1_2, m1_3, m1_4);
}

void motorOff_m1(){
  motorOff(m1_1, m1_2, m1_3, m1_4);
}

void forward_m2(){
  forwards(m2_1, m2_2, m2_3, m2_4);
}

void backward_m2(){
  backwards(m2_1, m2_2, m2_3, m2_4);
}

void motorOff_m2(){
  motorOff(m2_1, m2_2, m2_3, m2_4);
}

void motorOff(int s1, int s2, int s3, int s4){
  digitalWrite(s1, LOW); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, LOW); 
}

void backwards(int s1, int s2, int s3, int s4){
  digitalWrite(s1, HIGH); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, HIGH); 
  digitalWrite(s2, HIGH); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, HIGH); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, HIGH); 
  digitalWrite(s3, HIGH); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, HIGH); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, HIGH); 
  digitalWrite(s4, HIGH); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, HIGH); 
  delayMicroseconds(del);              

  digitalWrite(s1, HIGH); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, HIGH); 
  delayMicroseconds(del);              
}

void forwards(int s1, int s2, int s3, int s4){
  digitalWrite(s1, HIGH); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, HIGH); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, HIGH); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, HIGH); 
  digitalWrite(s4, HIGH); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, HIGH); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, HIGH); 
  digitalWrite(s3, HIGH); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, LOW); 
  digitalWrite(s2, HIGH); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, HIGH); 
  digitalWrite(s2, HIGH); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              

  digitalWrite(s1, HIGH); 
  digitalWrite(s2, LOW); 
  digitalWrite(s3, LOW); 
  digitalWrite(s4, LOW); 
  delayMicroseconds(del);              
  
}
