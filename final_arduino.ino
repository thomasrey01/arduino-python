
int switchStateA1 = 0;
int switchStateA2 = 0;
int switchStateA3 = 0;
int switchStateB1 = 0;
int switchStateB2 = 0;
int switchStateB3 = 0;
int switchStateC1 = 0;
int switchStateC2 = 0;
int switchStateC3 = 0;
int resetState = 0;
char serialData;

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(13,INPUT);

}

void loop() {
  switchStateA1 = digitalRead(6);
  switchStateA2 = digitalRead(7);
  switchStateA3 = digitalRead(8);
  switchStateB1 = digitalRead(9);
  switchStateB2 = digitalRead(10);
  switchStateB3 = digitalRead(11);
  switchStateC1 = digitalRead(2);
  switchStateC2 = digitalRead(3);
  switchStateC3 = digitalRead(4);
  resetState = digitalRead(13);
  
  
  if(Serial.available() > 0){
    serialData = Serial.read();
    Serial.print(serialData);
  
    if (serialData == '0') {
      digitalWrite(7,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
    }
    if (switchState1 == HIGH){
    Serial.println(1);
  }
  else if (switchState2 == HIGH){
    Serial.println(2);
  }
  else if (switchState3 == HIGH){
    Serial.println(3);
  }
  else if (switchState4 == HIGH){
    Serial.println(4);
  }
  
    if (serialData == '1'){
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);

      if (switchState1 == HIGH){
    Serial.println(1);
  }
  else if (switchState2 == HIGH){
    Serial.println(2);
  }
  else if (switchState3 == HIGH){
    Serial.println(3);
  }
  else if (switchState4 == HIGH){
    Serial.println(4);
  }
    
      delay(2000);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);

      if (switchState1 == HIGH){
    Serial.println(1);
  }
  else if (switchState2 == HIGH){
    Serial.println(2);
  }
  else if (switchState3 == HIGH){
    Serial.println(3);
  }
  else if (switchState4 == HIGH){
    Serial.println(4);
  }
      

      delay(2000);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);

      if (switchState1 == HIGH){
    Serial.println(1);
  }
  else if (switchState2 == HIGH){
    Serial.println(2);
  }
  else if (switchState3 == HIGH){
    Serial.println(3);
  }
  else if (switchState4 == HIGH){
    Serial.println(4);
  }

      delay(2000);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);

      if (switchState1 == HIGH){
    Serial.println(1);
  }
  else if (switchState2 == HIGH){
    Serial.println(2);
  }
  else if (switchState3 == HIGH){
    Serial.println(3);
  }
  else if (switchState4 == HIGH){
    Serial.println(4);
  }
     
      delay(2000);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);

      if (switchState1 == HIGH){
    Serial.println(1);
  }
  else if (switchState2 == HIGH){
    Serial.println(2);
  }
  else if (switchState3 == HIGH){
    Serial.println(3);
  }
  else if (switchState4 == HIGH){
    Serial.println(4);
  }
      
      delay(2000);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);

      if (switchState1 == HIGH){
    Serial.println(1);
  }
  else if (switchState2 == HIGH){
    Serial.println(2);
  }
  else if (switchState3 == HIGH){
    Serial.println(3);
  }
  else if (switchState4 == HIGH){
    Serial.println(4);
  }
     

    }
  }
}
