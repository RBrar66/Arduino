int ledPin =  8;
String letters[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
int dotDelay = 200;
     

     

void setup() {

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char c;
  if(Serial.available()){
    c = Serial.read();
    if(c >= 'a' && c <= 'z'){
      flashSequence(letters[c-'a']);
    }
    else if (c >= 'A' && c <= 'Z'){
      flashSequence(letters[c-'A']);
    }
    else if (c == ' '){
      delay(dotDelay * 5);
    }
  }
}

void flashSequence(String sequence){
  int i = 0;
  while(sequence[i] == '.' || sequence[i] == '-'){
    flashDotDash(sequence[i]);
    ++i;
  }
  delay(dotDelay * 3);
}

void flashDotDash(char dotdash){
  digitalWrite(ledPin, HIGH);
  if(dotdash == '.'){
    delay(dotDelay);
  }
  else{
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}
