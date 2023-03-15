int motor1forward = 27;
int motor1back = 14;
int motor2back = 26;
int motor2forward = 25; 

//motor2 = right wheel

int trigPinFront = 23;
int echoPinFront = 22;

int trigPinLeft = 19;
int echoPinLeft = 18;

int trigPinRight = 17;
int echoPinRight = 16;

void setup() {
  pinMode(motor1back, OUTPUT);
  pinMode(motor1forward, OUTPUT);
  pinMode(motor2back, OUTPUT);
  pinMode(motor2forward, OUTPUT);

  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);

  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);

  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);

}

void loop() {
  long durationFront, durationLeft, durationRight;
  long distanceFront, distanceLeft, distanceRight;

  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  durationFront = pulseIn(echoPinFront, HIGH);
  distanceFront = (durationFront / 2) / 29.1;

  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);
  durationLeft = pulseIn(echoPinLeft, HIGH);
  distanceLeft = (durationLeft / 2) / 29.1;

  digitalWrite(trigPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);
  durationRight = pulseIn(echoPinRight, HIGH);
  distanceRight = (durationRight / 2) / 29.1;

  if (distanceFront >= 10 and distanceLeft <=10) {
    digitalWrite(motor1forward, LOW); // go back
    digitalWrite(motor2back, HIGH);
    digitalWrite(motor1back, HIGH);
    digitalWrite(motor2forward, LOW);
    delay(200);
    
    digitalWrite(motor1forward, LOW); // left turn
    digitalWrite(motor2forward, HIGH);
    digitalWrite(motor1back, HIGH);
    digitalWrite(motor2back, LOW );
    delay(150);
  }

  else if(distanceFront >=10 and distanceRight <=10){
    digitalWrite(motor1forward, LOW); // go back
    digitalWrite(motor2back, HIGH);
    digitalWrite(motor1back, HIGH);
    digitalWrite(motor2forward, LOW);
    delay(200);
    
    digitalWrite(motor1forward, HIGH); // right turn
    digitalWrite(motor2forward, LOW);
    digitalWrite(motor1back, LOW);
    digitalWrite(motor2back, HIGH);
    delay(150);
  }

  else if (distanceFront <= 10) {
    digitalWrite(motor1forward, HIGH); // go forward
    digitalWrite(motor2back, LOW);
    digitalWrite(motor1back, LOW);
    digitalWrite(motor2forward, HIGH);
  }

}

