#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
Servo servo1;

void setup() {
  Serial.begin(9600);// set up Serial library at 9600 bps

  // turn on servo
  servo1.attach(9);

  // turn on DC motor
  motor1.setSpeed(55);
  motor1.run(RELEASE);
  motor2.setSpeed(55);
  motor2.run(RELEASE);

}

int i;
char data = "";
int spd, key = 0;

void loop() {
  //Communication With Car
  if (Serial.available() > 0) {
    data = Serial.read();
  }
  Serial.println(data);

  //Car Speed control
  if (data >= '0' && data <= '9') {
    spd = data;
    spd = data - 47;
    spd = (spd * 20) + 55;
    Serial.println(spd);
    //delay(1000);
    motor1.setSpeed(spd);
    motor2.setSpeed(spd);
  }
  
  //Car Start
  if (data == 'X'){
    key = 1;
  }
  if (data == 'x'){
    key = 0;
  }

  //Car Drive
  if (key == 1) {
    switch (data) {
      case 'L': //LEFT
        motor1.setSpeed(spd);
        motor2.setSpeed(spd);
        motor1.run(RELEASE);
        motor2.run(FORWARD);
        break;
      case 'R': //RIGHT
        motor1.setSpeed(spd);
        motor2.setSpeed(spd);
        motor2.run(RELEASE);
        motor1.run(FORWARD);
        break;
      case 'B': //BACK
        motor1.setSpeed(spd);
        motor2.setSpeed(spd);
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        break;
      case 'F': //FORWARD
        motor1.setSpeed(spd);
        motor2.setSpeed(spd);
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        break;
      case 'I': //FORWARD RIGHT
        motor1.setSpeed(spd);
        motor2.setSpeed(spd - spd / 2);
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        break;
      case 'J': //BACKWARD RIGHT
        motor1.setSpeed(spd);
        motor2.setSpeed(spd - spd / 2);
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        break;
      case 'G': //FORWARD LEFT
        motor1.setSpeed(spd - spd / 2);
        motor2.setSpeed(spd);
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        break;
      case 'H': //BACKWARD LEFT
        motor1.setSpeed(spd - spd / 2);
        motor2.setSpeed(spd);
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        break;
      case 'S': //STOP
        motor1.setSpeed(spd);
        motor2.setSpeed(spd);
        motor1.run(RELEASE);
        motor2.run(RELEASE);
    }
  }
}
