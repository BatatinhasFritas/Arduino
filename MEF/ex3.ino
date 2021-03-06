// coded by @B4tataFitas

const int LEDLeft = 13;
const int LEDCenter = 12;
const int LEDRight = 11;

const int buttonLeft = 7;
const int buttonRight = 8;

bool buttonRightState = false;
bool buttonLeftState = false;
bool previousButtonRightState = false;
bool previousButtonLeftState = false;
int currentLED = 1;

void setup() {
    Serial.begin(9600);
    pinMode(LEDLeft, OUTPUT);
    pinMode(LEDCenter, OUTPUT);
    pinMode(LEDRight, OUTPUT);
    pinMode(buttonLeft, INPUT);
    pinMode(buttonRight, INPUT);
}

void ledsState(int currentLED) {
    switch (currentLED) {
    case 0:
        digitalWrite(LEDLeft , LOW);
        digitalWrite(LEDCenter , LOW);
        digitalWrite(LEDRight , LOW);
        break;
    
    case 1:
        digitalWrite(LEDLeft , HIGH);
        digitalWrite(LEDCenter , LOW);
        digitalWrite(LEDRight , LOW);
        break;
    
    case 2:
        digitalWrite(LEDLeft , LOW);
        digitalWrite(LEDCenter , HIGH);
        digitalWrite(LEDRight , LOW);
        break;
    
    case 3:
        digitalWrite(LEDLeft , LOW);
        digitalWrite(LEDCenter , LOW);
        digitalWrite(LEDRight , HIGH);
        break;
    }

}

void loop() {

    buttonRightState = digitalRead(buttonRight);
    buttonLeftState = digitalRead(buttonLeft);

    if (buttonRightState && !previousButtonRightState && currentLED < 3) {
        currentLED++ ;
    }

    if (buttonLeftState && !previousButtonLeftState && currentLED > 1) {
        currentLED-- ;
    }

    ledsState(currentLED);
    //digitalWrite(LED, ledState);
    
    previousButtonRightState = buttonRightState;
    previousButtonLeftState = buttonLeftState;
}