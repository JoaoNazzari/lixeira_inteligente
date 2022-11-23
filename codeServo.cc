#include <Servo.h>
Servo Servo;
int cm = 0;
int PortaServo = 5;
int Abrir = 180;
int Fechar = 0;


long readUltrasonicDistance(int triggerPin, int echoPin){
pinMode(triggerPin, OUTPUT);
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);

digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);
pinMode(echoPin, INPUT);

return pulseIn(echoPin, HIGH);
}

void setup(){
Serial.begin(9600);
Servo.attach(PortaServo);
}

void loop(){
cm = 0.01723 * readUltrasonicDistance(6, 7);
Serial.print(cm);
Serial.println("cm");

if(cm <= 30){
Servo.write(Abrir);
delay(10000);
}
else{
Servo.write(Fechar);
}
delay(100);
}
