#include <Arduino.h> //Standard Arduino libary
#include <LiquidCrystal_I2C.h>
#include <Wire.h> // måske ikke nødvendigt
#include "Packets.h"

#define SERVO_SET_Baudrate  57600  //Baudrate is set to the right number

PacketsClass pck;

LiquidCrystal_I2C lcd(0x27, 20, 4);


void modeOne(bool modeOne){
 
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd. print("Mode One");
  while (modeOne == true) {


    String Gesture;

    if (Serial.available() > 0) {
      Gesture = Serial.readStringUntil('\n');
      delay (100);
    }
  
if (Gesture.equals("waveIn")) {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Mode One");
  lcd.setCursor(7, 1);
  lcd.print("Motor 1");
  lcd.setCursor(2, 2);
  lcd.print("Rotation");
  
    int vel = -10; //Servo 1 goal position
    

    pck.setGoalVelocityPacket(vel, 0x01);
  
  }


if (Gesture.equals("waveOut")) {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Mode One");
  lcd.setCursor(6, 1);
  lcd.print("wave 2");
  lcd.setCursor(4, 2);
  lcd.print("Moving");

     int vel = -10; //Servo 1 goal position
    

    pck.setGoalVelocityPacket(vel, 0x02);
  
  }

if (Gesture.equals ("fist")) {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Mode One");
  lcd.setCursor(8, 1);
  lcd.print("Fist");
  lcd.setCursor(4, 2);
  lcd.print("Moving");
  
     int vel = -10; //Servo 1 goal position
    

    pck.setGoalVelocityPacket(vel, 0x03);
  
  }


if (Gesture.equals ("fingersSpread")) {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Mode One");
  lcd.setCursor(3, 1);
  lcd.print("FingersSpread");
  lcd.setCursor(3, 2);
  lcd.print("using hand");
  int vel = -5; //Servo 1 goal position
    

    pck.setGoalVelocityPacket(vel, 0x04);
    delay(50);
     pck.setGoalVelocityPacket(vel, 0x05);
    
    //Here the hand should be made so it can close and open depending on the users intention
  
  }

  
if (Gesture.equals ("rest")) {
  lcd.clear();
  int vel = 0;
     pck.setGoalVelocityPacket(vel, 0x01); 
     delay(50);
     pck.setGoalVelocityPacket(vel, 0x02);
     delay(50);
      pck.setGoalVelocityPacket(vel, 0x03);
      delay(50);
       pck.setGoalVelocityPacket(vel, 0x04);
       delay(50);
        pck.setGoalVelocityPacket(vel, 0x05);
        delay(50);
  
  }


if (Gesture.equals("modeTwo")) {
  modeOne = false;
}
}
}


void modeTwo(bool modeTwo){
 
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd. print("Mode Two");
  while (modeTwo == true) {


    String Gesture;

    if (Serial.available() > 0) {
      Gesture = Serial.readStringUntil('\n');
      delay (100);
    }
  
if (Gesture.equals("waveIn")) {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Mode Two");
  lcd.setCursor(7, 1);
  lcd.print("Motor 1");
  lcd.setCursor(2, 2);
  lcd.print("Rotation");
  
    int vel = 10; //Servo 1 goal position
    

    pck.setGoalVelocityPacket(vel, 0x01);
  
  }


if (Gesture.equals("waveOut")) {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Mode Two");
  lcd.setCursor(6, 1);
  lcd.print("waveOut");
  lcd.setCursor(4, 2);
  lcd.print("Moving");

     int vel = 10; //Servo 1 goal position
    

    pck.setGoalVelocityPacket(vel, 0x02);
  
  }

if (Gesture.equals ("fist")) {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Mode Two");
  lcd.setCursor(8, 1);
  lcd.print("Fist");
  lcd.setCursor(4, 2);
  lcd.print("Moving");
  
     int vel = 10; //Servo 1 goal position
    

    pck.setGoalVelocityPacket(vel, 0x03);
  
  }


if (Gesture.equals ("fingersSpread")) {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Mode Two");
  lcd.setCursor(3, 1);
  lcd.print("FingersSpread");
  lcd.setCursor(3, 2);
  lcd.print("using hand");
  int vel = 5; //Servo 1 goal position
    

    pck.setGoalVelocityPacket(vel, 0x04);
    delay(50);
     pck.setGoalVelocityPacket(vel, 0x05);
    
    //Here the hand should be made so it can close and open depending on the users intention
  
  }

  
if (Gesture.equals ("rest")) {
  lcd.clear();
  int vel = 0;
     pck.setGoalVelocityPacket(vel, 0x01); 
     delay(50);
     pck.setGoalVelocityPacket(vel, 0x02);
     delay(50);
      pck.setGoalVelocityPacket(vel, 0x03);
      delay(50);
       pck.setGoalVelocityPacket(vel, 0x04);
       delay(50);
        pck.setGoalVelocityPacket(vel, 0x05);
        delay(50);
  
  }


if (Gesture.equals("modeOne")) {
  modeTwo = false;
}
}
}



void setup() {

  Serial.flush();    // Clear the serial buffer of garbage data before running the code.
  
  Serial.begin(SERVO_SET_Baudrate);

  pck.setToVelControl(0x01, 0x01);
  delay(10);
  pck.setToVelControl(0x02, 0x01);
  delay(10);
  pck.setToVelControl(0x03, 0x01);
  delay(10);
  pck.setToVelControl(0x04, 0x01);
  delay(10);
  pck.setToVelControl(0x05, 0x01);
  delay(10);
  
  pck.setProfileVelocity(100);
  pck.setProfileAcceleration(100);

  pck.setTorquePacket(0x01, true);
  delay(20);
  pck.setTorquePacket(0x02, true);
  delay(20);
  pck.setTorquePacket(0x03, true);
  delay(20);
  pck.setTorquePacket(0x04, true);
  delay(20);
  pck.setTorquePacket(0x05, true);

  lcd.begin();
  lcd.backlight();

}

void loop() {
  String Gesture;
  if (Serial.available() > 0) {
    Gesture = Serial.readStringUntil('\n');
    delay(100);
  }
  lcd.clear();

  if (Gesture.equals("modeOne")) {
    modeOne(true);
  };

  if (Gesture.equals("modeTwo")) {
    modeTwo(true);
  };

} 
