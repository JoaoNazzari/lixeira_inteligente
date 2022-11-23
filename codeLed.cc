const int vermelho = 8;
int cm = 0;

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
}

void loop(){
cm = 0.01723 * readUltrasonicDistance(7, 6);
Serial.print(cm);
Serial.println("cm");

if(cm <= 13){
digitalWrite(vermelho, HIGH);
delay(400);
digitalWrite(vermelho, LOW);
delay(400);
 }
delay(500);
}
