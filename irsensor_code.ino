int IRSensor1 = 2;
int IRSensor2 = 3;
int LED1=13;//RED1
int LED2=12;//YELLOW1
int LED3=11;//GREEN1
int LED4=10;//RED2
int LED5=8;//YELLOW2
int LED6=9;//GREEN2
const int buzzer=6;
int delayT=1000;
void setup() {
  Serial.begin(115200);
  Serial.println("Serial Working");
  pinMode(IRSensor1, INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(IRSensor2, INPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
}

void loop() {
  int sensor1Status = digitalRead(IRSensor1);
  if(sensor1Status ==1){
    digitalWrite(LED2,LOW);

    delay(delayT);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED4,LOW);
    digitalWrite(LED1,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED6,LOW);
    Serial.println("Motion detected");
  }
  else{
    tone(buzzer,1000);
    delay(1000);
    noTone(buzzer);
    
    digitalWrite(LED1,HIGH);
    digitalWrite(LED4,HIGH);
    digitalWrite(LED1,LOW);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED2,LOW);
    Serial.println("Motion ended");
  }
  int sensor2Status = digitalRead(IRSensor2);
   if(sensor2Status ==1){
    digitalWrite(LED5,LOW);
    delay(delayT);
    digitalWrite(LED5,HIGH);
    digitalWrite(LED4,LOW);
    digitalWrite(LED1,LOW);
    digitalWrite(LED6,LOW);
    Serial.println("Motion detected");
  }
  else{
    tone(buzzer,1000);
    delay(1000);
    noTone(buzzer);
    
    digitalWrite(LED4,HIGH);
    digitalWrite(LED1,HIGH);
    digitalWrite(LED6,HIGH);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    Serial.println("Motion ended");
  }
  if(sensor1Status == 1 && sensor2Status==1){
    digitalWrite(LED2,LOW);
    digitalWrite(LED5,LOW);
    delay(delayT);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED5,HIGH);
    digitalWrite(LED4,LOW);
    digitalWrite(LED1,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED6,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED1,LOW);
    digitalWrite(LED6,LOW);
    Serial.println("Motion detected");
  }
  
}
