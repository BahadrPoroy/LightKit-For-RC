// I have taken the signal reading method from here: Beaver's Hobby Youtube Channel: Silly Arduino Project #1

//Pin definitions
#define inputPin 3
#define ledPin1 4
#define ledPin2 5
#define ledPin3 6
#define ledPin4 7
#define ledPin5 8
//End of pin definitions

//Variable settings
int input, previousMillis = 0, difrence, nowMillis = 0, i = 0;  //readed value storing in 'input'
bool state = 0;                                                 //It's used for control the lights (on/off)
//End of variable settings

void setup() {
  Serial.begin(9600);  //Serial communication starts
  //Pin mode settings
  pinMode(inputPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  //End of pin mode settings
  for (i = 0; i < 3; i++) {
    welcome_signal();
  }
}

void loop() {
  if (input > 1600) {                           //if input value bigger than 1700 (button pressed), this will be activated.
    nowMillis = millis();                       //this line and next two lines are preventing unwanted blinkings
    if ((nowMillis - previousMillis) >= 150) {  //If previous turn on/off command newer than 150 milliseconds program ignores new command
      headlight();
    }
  }
  input = pulseIn(inputPin, HIGH, 25000);  // signal receiving is processing here. I have taken this line from Beaver's Hobby Youtube Channel: Silly Arduino Project #1
}

void headlight() {
  previousMillis = nowMillis;
  state = !state;  //LED states updating
  //Updated state writing the LEDs
  digitalWrite(ledPin3, state);
  delay(100);
  digitalWrite(ledPin2, state);
  digitalWrite(ledPin4, state);
  delay(100);
  digitalWrite(ledPin1, state);
  digitalWrite(ledPin5, state);
  delay(100);
  //End of writing
}

void welcome_signal() {
  digitalWrite(ledPin3, HIGH);
  delay(100);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin2, HIGH);
  delay(100);
  digitalWrite(ledPin3, LOW);
  delay(100);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin1, HIGH);
  delay(100);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin2, LOW);
  delay(100);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin1, LOW);
  delay(200);
}