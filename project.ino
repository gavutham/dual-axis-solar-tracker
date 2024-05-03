#include <Servo.h>

//Analog input pin numbers of LDRs

int bottomRight = A1;
int bottomLeft = A2;
int topRight = A3;
int topLeft = A4;

//Servo motors PWM pin numbers
int baseMotor = 9;
int upperMotor = 6;

//declaring Servos
Servo base;
Servo upper;


void setup() {
  //setting up servos
  base.attach(baseMotor);
  upper.attach(upperMotor);
}

void loop() {
  //reading ldrs values
  float topLeftValue = analogRead(topLeft);
  float topRightValue = analogRead(topRight);
  float bottomLeftValue = analogRead(bottomLeft);
  float bottomRightValue = analogRead(bottomRight);

  //reading motor values
  int baseValue = base.read();
  int upperValue = upper.read();

  //avg calculations for precision
  float leftAvg = (bottomLeftValue + topLeftValue) / 2;
  float rightAvg = (bottomRightValue + topRightValue) / 2;
  float bottomAvg = (bottomLeftValue + bottomRightValue) / 2;
  float topAvg = (topLeftValue + topRightValue) / 2;

  //for rotating base motor
  if (upperValue <= 90) {
    if (leftAvg < rightAvg){
      base.write(baseValue + 1);
    } else {
      base.write(baseValue - 1);
    }
  } else {
    if (leftAvg < rightAvg){
      base.write(baseValue - 1);
    } else {
      base.write(baseValue + 1);
    }
  }

  //for rotating upper motor
  if (bottomAvg < topAvg) {
    upper.write(upperValue + 1);
  } else {
    upper.write(upperValue - 1);
  }

  delay(50);
}