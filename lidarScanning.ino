#include<Wire.h>
#include<LIDARLite.h>

LIDARLite lidarLite;

int cal_cnt = 0;
int PUL1 = 7;
int DIR1 = 6;
int PUL2 = 8;
int DIR2 = 3;
int dist;
int result;
int xStep = 0; 
int yStep = 0;

char rx_byte = 0;

String rx_str = "";

boolean not_number;

void setup(){
  
  Serial.begin(115200);
  
  pinMode(PUL1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(PUL2, OUTPUT);
  pinMode(DIR2, OUTPUT);
  
//  Serial.println("Type in the number of steps you want to move.");

  lidarLite.begin(0,true);
  lidarLite.configure(1);
}

void loop(){
  
  if(Serial.available() > 0){
    
//    Serial.println("Serial available.");
   
   rx_byte = Serial.read();
   
   if((rx_byte >= '0') && (rx_byte <= '9')){
     
    rx_str += rx_byte; 
    
   } else if(rx_byte == 'a'){
     
     Serial.println(rx_byte);
     
     result = rx_str.toInt();
     
     turnRight(result);
     
     not_number = false;
     rx_str = "";
     
   } else if(rx_byte == 'b'){
     
     result = rx_str.toInt();
     
     turnLeft(result);
     
     not_number = false;
     rx_str = "";
     
   } else if(rx_byte == 'c'){
     
     result = rx_str.toInt();
     
     tiltUp(result);
     
     not_number = false;
     rx_str = "";
     
   } else if(rx_byte == 'd'){
     
     result = rx_str.toInt();
     
     tiltDown(result);
     
     not_number = false;
     rx_str = "";
  
   }   
  } else {
    
    not_number = true;
    
  }
  
}

void turnRight(int stepsRight) {
  
  for(int i = 0; i < stepsRight; i++){
    
   digitalWrite(DIR1,HIGH);
   digitalWrite(PUL1,HIGH);
   delayMicroseconds(50);
   digitalWrite(PUL1,LOW);

   xSteps = xSteps + 1;
   dist = lidarLite.distance(false);

   Serial.println(xSteps);
   Serial.println(ySteps);
   Serial.println(dist);

   delayMicroseconds(50);
   


  }
  
}

void turnLeft(int stepsLeft){
  
  for(int i = 0; i < stepsLeft; i++){
    
   digitalWrite(DIR1,LOW);
   digitalWrite(PUL1,HIGH);
   delayMicroseconds(50);
   digitalWrite(PUL1,LOW);

   xSteps = xSteps - 1;
   dist = lidarLite.distance(false);

   Serial.println(xSteps);
   Serial.println(ySteps);
   Serial.println(dist);

   delayMicroseconds(50);
   
  }
  
}

void tiltUp(int stepsUp){
  
   for(int i = 0; i < stepsUp; i++){
    
     digitalWrite(DIR2,HIGH);
     digitalWrite(PUL2,HIGH);
     delayMicroseconds(50);
     digitalWrite(PUL2,LOW);

     ySteps = ySteps + 1;
     dist = lidarLite.distance(false);

     Serial.println(xSteps);
     Serial.println(ySteps);
     Serial.println(dist);

     delayMicroseconds(50);
   
    }
  
}

void tiltDown(int stepsDown){
  
  for(int i = 0; i < stepsDown; i++){
    
    digitalWrite(DIR2,LOW);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL2,LOW);

     ySteps = ySteps - 1;
     dist = lidarLite.distance(false);

     Serial.println(xSteps);
     Serial.println(ySteps);
     Serial.println(dist);

     delayMicroseconds(50);
   
   }
  
}
