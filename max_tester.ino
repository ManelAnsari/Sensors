#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include "ClosedCube_MAX30205.h"
ClosedCube_MAX30205 max30205;
#define PHONE_NUMBER "01814946110"   //???? ??? ???? 
 
DFRobot_SIM808 sim808(&Serial);
 float T;
 char phone[16];
void setup()
{  Serial.begin(9600);
  
 max30205.begin(0x48);
    while(!sim808.init()) {  
    Serial.print("Sim808 init error\r\n");  
    delay(1000);  
  }} 
  void loop() { 
  T=max30205.readTemperature();
  
   if(T>=38.1){sim808.callUp(PHONE_NUMBER);}
  }
