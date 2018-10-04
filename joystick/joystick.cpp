

#include "potentiometer.h"

_joystick joystick; 
int x_position = analogRead(A1); 
int y_position = analogRead(A2); 
//Initialize Braccio object
_joystick::_joystick() {
}


void _joystick::begin() {
	Serial.begin(9600);
}

float voltage() {
	return analogRead(A1) * (5.0 / 1023.0);
}
