const byte VOL_UP_BTN = 1;
const byte VOL_UP_BTN = 2;
int debounceDelay = 20;
int previousMillis = 0;

bool lastButtonState = false;

void setup() {
  Serial.begin(115200);
  pinMode(VOL_UP_BTN, INPUT);
  pinMode(VOL_DOWN_BTN, INPUT);
}

void loop() {

  if(digitalRead(VOL_UP_BTN) == HIGH) {
    Serial.println("Volume goes up");
  }

  bool buttonState = digitalRead(VOL_DOWN_BTN);
  if(millis() - previousMillis > debounceDelay) {
    if(lastButtonState != buttonState) {
      if(buttonState == HIGH) {
        Serial.println("Volume goes up");
        Serial.println("has debounce");
        previousMillis = millis();
      }
      lastButtonState = buttonState;
    }
  }
}
