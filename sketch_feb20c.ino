// Pin assignement
const int btnPin = 8;
const int led1Pin = 9;
const int led2Pin = 10;
const int led3Pin = 11;
enum fcnMode {
 
 LED2,
 LED3,
 NBSTATE
}; // OFF = 0 and NBSTATE=2
int ledState1 = LOW, ledState2 = LOW, ledState3 = LOW;           // ledState used to set the LED
unsigned long buttonState = 0;
int funcState = 1;
unsigned long currentMillis1, currentMillis2, currentMillis3;      // will store current time
unsigned long previousMillis1, previousMillis2, previousMillis3;      // will store last time LED was updated
const long interval1 = 100;           // interval at which to blink (milliseconds)
const long interval2 = 300;
const long interval3 = 500;
void setup() {
 Serial.begin(9600); // initialize serial port
 pinMode(btnPin, INPUT_PULLUP);
 pinMode(led1Pin, OUTPUT);
 pinMode(led2Pin, OUTPUT);
 pinMode(led3Pin, OUTPUT);
}

void loop() {
 buttonPressed();
 setMode();
}

void buttonPressed() {
 buttonState = pulseIn(btnPin, HIGH, 1000000);
 if (buttonState > 50) {
   funcState += 1;
   //Serial.print("Button state n: ");
   Serial.println(funcState);
 }
 funcState = funcState % NBSTATE;
}
void setMode() {
 // All Off
 digitalWrite(led1Pin, LOW);
 digitalWrite(led2Pin, LOW);
 digitalWrite(led3Pin, LOW);
// Serial.print("Function : ");
 //Serial.println(funcState);
 switch (funcState) {

   case LED2:
     digitalWrite(led2Pin, HIGH);
     break;
   case LED3:
     digitalWrite(led3Pin, HIGH);
     break;
   
 }
}

void blinkLed2() {
 currentMillis2 = millis();
 if (currentMillis2 - previousMillis2 >= interval2) {
   // save the last time you blinked the LED
   previousMillis2 = currentMillis2;
   // if the LED is off turn it on and vice-versa:
   if (ledState2 == LOW) {
     ledState2 = HIGH;
   } else {
     ledState2 = LOW;
   }
   // set the LED with the ledState of the variable:
   digitalWrite(led2Pin, ledState2);
 }
}
void blinkLed3() {
 currentMillis3 = millis();
 if (currentMillis3 - previousMillis3 >= interval3) {
   // save the last time you blinked the LED
   previousMillis3 = currentMillis3;
   // if the LED is off turn it on and vice-versa:
   if (ledState3 == LOW) {
     ledState3 = HIGH;
   } else {
     ledState3 = LOW;
   }
   // set the LED with the ledState of the variable:
   digitalWrite(led3Pin, ledState3);
 }
}
