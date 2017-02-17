int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int button1Pin = 3;
int button1State;
boolean reverse = 0;
int motorSpeed = 0;
int prevState;
 
void setup()
{
  pinMode(button1Pin, INPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
}
 
void loop()
{
  button1State = digitalRead(button1Pin);
  
  if (button1State == HIGH && prevState != button1State)
  {
    reverse = 0;
    motorSpeed = 0;
  }
  else if (button1State == LOW && prevState != button1State)
  {
    reverse = 1;
    motorSpeed = 0;
  }
  
  motorSpeed += 5;
  
  if (motorSpeed > 255)
  {
    motorSpeed = 255;
  }
  
  if (motorSpeed < 0)
  {
    motorSpeed = 0;
  }
  
  prevState = button1State;
  
  setMotor(motorSpeed, reverse);
  
}
 
void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}
