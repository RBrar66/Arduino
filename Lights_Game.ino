 void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button = 0;
  int x = 200;
  
  digitalWrite(2,LOW);
  digitalWrite(6,HIGH);
  delay(x);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  
  delay(x);
  button = digitalRead(8);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH); 
  if(button == 1){
    digitalWrite(7, HIGH);
  }
  delay(x);
  button = digitalRead(8);
  if(button == 1){
    digitalWrite(7, HIGH);
  }
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  delay(x);
  digitalWrite(7, LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  delay(x);

  
}
