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
int input, previousMillis = 0, difrence, nowMillis = 0; //readed value storing in 'input'
bool state = 0; //It's used for control the lights (on/off)
//End of variable settings

void setup() {
  Serial.begin(9600); //Serial communication starts
  //Pin mode settings
  pinMode(inputPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  //End of pin mode settings
}

void loop() {
  if (input > 1700) {   //if input value bigger than 1700 (button pressed), this will be activated.
    nowMillis = millis(); //this line and next two lines are preventing unwanted blinkings
    if((nowMillis - previousMillis) >= 150){  //If previous turn on/off command newer than 150 milliseconds program ignores new command
      previousMillis = nowMillis;
      state = !state; //LED states updating
      //Updated state writing the LEDs
      digitalWrite(ledPin1, state);
      digitalWrite(ledPin2, state);
      digitalWrite(ledPin3, state);
      digitalWrite(ledPin4, state);
      digitalWrite(ledPin5, state);
      //End of writing
    }
  }
  input = pulseIn(inputPin, HIGH, 25000); // signal receiving is processing here. I have taken this and 45. lines from Beaver's Hobby Youtube Channel: Silly Arduino Project #1
  delay(50);
}