#include <Servo.h>

Servo ESC_1;
Servo ESC_2;
char t;
int M1Speed = 100;
int M2Speed = 100;
int IN1=5;
int IN2=6;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  ESC_1.attach(3, 1000, 2000);
  ESC_2.attach(5, 1000, 2000);
  Serial.begin(9600);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    t = Serial.read();
    Serial.println(t);
  }
  else if (t == 'F') {
    ESC_1.write(100);
    ESC_2.write(100);
  } else if (t == 'B') {
    ESC_1.write(0);
    ESC_2.write(0);
  } else if (t == 'R') {
    ESC_1.write(0);
    ESC_2.write(100);
  } else if (t == 'L') {
    ESC_1.write(100);
    ESC_2.write(0);
  } else if (t == 'W') {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (t == 'w') {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  } else {
    ESC_1.write(0);
    ESC_2.write(0);
  }

  delay(10);
}
