const int trigPin =9;
const int echoPin = 10;
int LED1=13;//RED1
int LED2 = 12;//RED2
int LED3=11;//GREEN1
int LED4= 8;//GREEN2
const int buzzer=6;
int delayT=8000;
long duration;
int distance;
int safetyDistance;
void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  safetyDistance = distance;
  if (safetyDistance == 10){
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    //digitalWrite(buzzer, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    tone(buzzer,1000);
    delay(1000);
    noTone(buzzer);
    digitalWrite(LED2,LOW);
    digitalWrite(LED1,LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED3, HIGH);
  }

  Serial.print("Distance:");
  Serial.print(distance);
  Serial.print("cm");
}
