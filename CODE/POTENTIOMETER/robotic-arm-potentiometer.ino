/**
 * Robotic Arm using potentiometer by Jorge
 * 
 * Based on "How to Move Your 4 Servos Robot using Potentiometers?" by Zenent Robotic
 *
 */
#include <Servo.h>

// SERVOS
Servo BASE;      // BASE SERVO
Servo SHOULDER;  // SHOULDER SERVO
Servo ELBOW;     // ELBOW SERVO
Servo HAND;      // HAND SERVO

// POTENTIOMETERS
int POTBASE = 0;       // BASE POTENTIOMETER
int POTSHOULDER = 1;   // SHOULDER POTENTIOMETER
int POTELBOW = 2;      // ELBOW POTENTIOMETER
int POTHAND = 3;       // HAND POTENTIOMETER

// POTENTIOMETER VALUES
int VAL01;   // BASE POTENTIOMETER VALUE
int VAL02;   // SHOULDER POTENTIOMETER VALUE
int VAL03;   // ELBOW POTENTIOMETER VALUE
int VAL04;   // HAND POTENTIOMETER VALUE

void setup () {
  // SERVOS ATTACHS
  BASE.attach(2);      // BASE SERVO ATTACH TO PIN 2
  SHOULDER.attach(4);  // SHOULDER SERVO ATTACH TO PIN 4
  ELBOW.attach(7);     // ELBOW SERVO ATTACH TO PIN 7
  HAND.attach(8);      // HAND SERVO ATTACH TO PIN 8
}

void loop () {
  // ANALOG READS
  // Here we read the value of the potentiometer, which ranges from 0 to 1023
  VAL01 = analogRead(POTBASE);
  VAL02 = analogRead(POTSHOULDER);
  VAL03 = analogRead(POTELBOW);
  VAL04 = analogRead(POTHAND);

  // VALUES SCALING
  VAL01 = map(VAL01, 0 , 1023, 0, 180);
  VAL02 = map(VAL02, 0 , 1023, 0, 180);
  VAL03 = map(VAL03, 0 , 1023, 0, 180);
  VAL04 = map(VAL04, 0 , 1023, 110, 180);

  // SEND VALUES TO SERVOS
  BASE.write(VAL01);      // MOVE BASE SERVO ACCORDING TO THE ANALOG READING
  SHOULDER.write(VAL02);  // MOVE SHOULDER SERVO ACCORDING TO THE ANALOG READING
  ELBOW.write(VAL03);     // MOVE ELBOW SERVO ACCORDING TO THE ANALOG READING
  HAND.write(VAL04);      // MOVE HAND SERVO ACCORDING TO THE ANALOG READING

  // TIME BETWEEN ACTION AND ACTION
  delay(15);
}
