const int ledPin =  3;// the number of the LED pin
const int inPin =  9;
int ledState = 255;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
int cycle = 3;
const long interval = 10;           // interval at which to blink (milliseconds)
int down = 1;
int pw = 1;
void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if ((digitalRead(inPin) == LOW) && (pw==1)) {
    analogWrite(ledPin, 255);
  }

  unsigned long currentMillis = millis();
  if (digitalRead(inPin) == HIGH) {
    pw=0;
    }
    
  if (pw==0 && (cycle >= 0)) {

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if (down == 1) {
        analogWrite(ledPin, ledState);
        ledState = ledState - 1;
        if (ledState <= 0) {
          down = 0;
        }
      }
      if (down == 0) {
        analogWrite(ledPin, ledState);
        ledState = ledState + 1;
        if (ledState >= 255) {
          down = 1;
          cycle = cycle - 1;
          if (cycle <= 0) {
            cycle = 3;
            pw=1;
          }

        }
      }
    }

  }
}

