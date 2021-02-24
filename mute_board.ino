
const int btnPin = 8;
const int led1Pin = 10;
const int led2Pin = 11;
enum fcnMode
{
  LED1,
  LED2,
  NBSTATE
};
int ledState1 = LOW, ledState2 = LOW;
unsigned long buttonState = 0;
int funcState = 1;
void setup()
{
  Serial.begin(9600);
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop()
{
  ChangeMuteOption();
}

void ChangeMuteOption()
{
  buttonState = pulseIn(btnPin, HIGH, 1000000);
  if (buttonState > 50)
  {
    funcState += 1;
    Serial.println(funcState);
  }
  funcState = funcState % NBSTATE;
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  switch (funcState)
  {

  case LED1:
    digitalWrite(led1Pin, HIGH);
    break;
  case LED2:
    digitalWrite(led2Pin, HIGH);
    break;
  }
}
