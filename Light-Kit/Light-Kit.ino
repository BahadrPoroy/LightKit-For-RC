//Pin definitions
#define inputPin 3
#define ledPin1 4
#define ledPin2 5
#define ledPin3 6
//End of pin definitions

//Variable settings
int input, previousMillis = 0, nowMillis = 0, i = 0, mode = 0;  //readed value storing in 'input', 'i' used for welcoming lights, 'mode' used for controlling the light modes
//End of variable settings

void setup() {
  Serial.begin(9600);  //Serial communication starts
  //Pin mode settings
  pinMode(inputPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  //End of pin mode settings
  for (i = 0; i <= 3; i++) {
    welcoming();
  }
}

void loop() {

  switch (mode) {
    case (0):
      noLight();
      break;
    case (1):
      lowBeam();
      break;
    case (2):
      highBeam();
      break;
  }
  input = pulseIn(inputPin, HIGH, 25000);  // signal receiving is processing here. I have taken this line from Beaver's Hobby Youtube Channel: Silly Arduino Project #1
  previousMillis = millis();               //this line and next three lines are preventing unwanted blinkings
  nowMillis = millis();
  while (nowMillis - previousMillis <= 150) {
    nowMillis = millis();
  }
  if (input >= 1850) {  //if input value bigger than 1850 (button pressed), this will be activated.
    if (mode == 0) {
      mode = (mode + 1) % 3;
    } else if (mode == 1) {
      mode = (mode + 1) % 3;
    } else if (mode == 2) {
      mode = (mode + 1) % 3;
    }
  } else {
    mode = mode;
  }
  Serial.print("İnput: ");
  Serial.println(input);
  Serial.println(mode);
}

void lowBeam() {
  // writing new states of the LEDs
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  //End of writing
}

void highBeam() {
  // writing new states of the LEDs
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  //End of writing
}

void noLight() {
  // writing new states of the LEDs
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin1, LOW);
  //End of writing
}

void welcoming() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  delay(100);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  delay(200);
}