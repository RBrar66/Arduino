void setup() {
  // put your setup code here, to run once:
  

  Serial.begin(9600);
  for(int i = 4; i<7; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  const int sensorPin = A0;
  const float baselineTemp = 29;
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = (voltage - 0.5) *100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);
  
  if(temperature < baselineTemp){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  else if(temperature >= baselineTemp && temperature < baselineTemp + 2.0){
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  else if(temperature >= baselineTemp + 2.0 && temperature < baselineTemp + 4.0){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  }
  else if(temperature >=baselineTemp + 4.0){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }
  delay(2);
}
