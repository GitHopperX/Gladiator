#include <AFMotor.h>
#include <Servo.h>

// DC motor on M2

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);


// DC hobby servo
Servo servo1;
// Stepper motor on M3+M4 48 steps per revolution

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");

  // turn on servo
  servo1.attach(9);

  // turn on motor #2
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);

}

int i;
char data = "";
// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
  if (Serial.available() > 0){data = Serial.read();}
  Serial.println(data);

    if (data == 'L') {
      motor1.run(RELEASE); //FORWARD
      motor2.run(FORWARD); //FORWARD
    }

     if (data == 'R') {
      motor2.run(RELEASE); //FORWARD
      motor1.run(FORWARD); //FORWARD
    }

  }
