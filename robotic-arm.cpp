
#include <Braccio.h> 
#include <Servo.h> 

Servo base;
Servo shoulder; 
Servo elbow;
Servo wrist_ver; 
Servo wrist_rot;
Servo gripper; 


int CONSTANT_SPEED = 10;
int FULL_SPEED = 10;
int SLOW_SPEED = 30;

//Base Positioning 
int rotation = 0; 

//Shoulder 
int min_angle_shoulder = 70; //
int max_angle_shoulder = 110;  // 

int min_angle_elbow = 45; 
int max_angle_elbow = 180; 

void setup() {
  // put your setup code here, to run once:
//  _Braccio
  Braccio.begin();
  loop();
}

void loop() {
  // put your main code here, to run repeatedly: 
  
    Braccio.ServoMovement(CONSTANT_SPEED,changeRotation(),150,20,20,90,10);
    delay(500);
    Braccio.ServoMovement(CONSTANT_SPEED,changeRotation(),90,0,20,180,10);
    Braccio.ServoMovement(CONSTANT_SPEED,changeRotation(),90,0,20,0,10);
    Braccio.ServoMovement(CONSTANT_SPEED,changeRotation(),90,0,20,180,100);
    Braccio.ServoMovement(CONSTANT_SPEED,changeRotation(),90,0,20,90,100);
    Braccio.ServoMovement(CONSTANT_SPEED,changeRotation(),150,20,20,90,160);
//    exit(0);
    Braccio.ServoMovement(CONSTANT_SPEED,90,90,90,90,90,0);
    Braccio.ServoMovement(CONSTANT_SPEED,90,90,90,90,90,45);
    Braccio.ServoMovement(CONSTANT_SPEED,360,90,90,90,90,90);
    Braccio.ServoMovement(CONSTANT_SPEED,90,90,90,90,90,130);
    stop();  
}

void stop() { 
  delay(5000); 
}
int changeRotation() {
   if(rotation > 180) { 
    return 0; 
   }
   rotation = rotation + 40;
   return rotation;
}






