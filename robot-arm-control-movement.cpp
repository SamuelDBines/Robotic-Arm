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
  Serial.begin(9600);
  loop();
}

void loop() {
  // put your main code here, to run repeatedly: 
    int x_pos = analogRead(A1);
    int y_pos = analogRead(A0);
 voltage(x_pos, y_pos);
    delay(500);
}
void voltage(int x_position, int y_position) {
  x_position = (180 / 5) * (  x_position / 180 ) ;
  y_position = (180 / 5) * (  y_position / 180 ) ;
   Serial.println(clawMovement());
  Braccio.ServoMovement(CONSTANT_SPEED,x_position,90,y_position,y_position,clawMovement(),clawMovement());
}
int clawMovement() {
  if(analogRead(A2) > 500) {
    return 90;
  } else {
    return 0;
  }
}
//int position() { 
//  return (180 - 5) * 
//}
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





