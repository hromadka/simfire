const int ledYellowPin = 12;  
const int ledRedPin = 13;

const int RED = 0;
const int YELLOW = 1;
const int ORANGE = 2;  
const int leds[] = {RED, YELLOW, ORANGE};
const int LED_COUNT = 3;
int led = 0;

const int flickers[] = {50,60,70,80,90,100,110,120};
int flickercount = 0;
int OFF_TIME = 10;

void setup() {
  // put your setup code here, to run once:
    pinMode(ledYellowPin, OUTPUT);
    pinMode(ledRedPin, OUTPUT);
    flickercount = sizeof(flickers)/sizeof(flickers[0]);
    randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
    led = random(0,LED_COUNT);
    switch(led) {
      case RED:
        digitalWrite(ledRedPin, HIGH);
        break; 
      case YELLOW:
        digitalWrite(ledYellowPin, HIGH);
        break; 
      default:
        digitalWrite(ledRedPin, HIGH);
        digitalWrite(ledYellowPin, HIGH);
        break;     
    }
    delay(flickers[random(0, flickercount)]);

    digitalWrite(ledYellowPin, LOW);
    digitalWrite(ledRedPin, LOW);
    delay(OFF_TIME);
}
