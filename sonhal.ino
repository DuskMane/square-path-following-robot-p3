 
  //left motor setup
  #define INL1 12
  #define INL2 13
  #define PWML 3
  
  //right motor setup
  #define INR1 7
  #define INR2 8
  #define PWMR 9

  //HCSR1 setup
  #define TRIG1 5
  #define ECHO1 6
  #define TRIG2 2 
  #define ECHO2 10
  #define TRIG3 11
  #define ECHO3 4



  
void setup() {
  // put your setup code here, to run once:
  
  pinMode(PWML,OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(INL1,OUTPUT);
  pinMode(INL2,OUTPUT);
  pinMode(INR1,OUTPUT);
  pinMode(INR2,OUTPUT);

  Serial.begin (9600);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
}

long duration, cm, onMesafe, sagMesafe;
long threedata[3];
unsigned long interval = 0;
void loop() {
  onMesafe = distanceFront();
  sagMesafe = distanceRight();
  if(sagMesafe < 10)
  {
    fullStop();
    delay(300);
    turnLeftFor(300);
    
  }
  if(sagMesafe < 20){
    turnLeftFor(25);
  }
  if(onMesafe < 20){
      backward();
  }
  if(onMesafe >= 25 && sagMesafe <= 35){
    if(sagMesafe < 10)
  {
    fullStop();
    delay(300);
    turnLeftFor(300);
    
  }
    if(sagMesafe < 20){
      turnLeftFor(25);
    }
    fullForward();
  }
  if(onMesafe >= 25 && sagMesafe > 45){
    fullForward();
    delay(300);
    fullStop();
    delay(500);
    turnRight();
    delay(320);
    fullStop();
    delay(500);
    if( onMesafe >= 30)
    {
      fullForward();
      delay(100);
    }
    if ( onMesafe < 30)
    {
      backFor(200);
    }
  }
  if(onMesafe < 25 && sagMesafe <= 35){
    if(sagMesafe < 10)
  {
    fullStop();
    delay(300);
    turnLeftFor(300);
    
  }
    backFor(400);
    turnLeft();
    delay(400);
  }
  if(onMesafe < 25 && sagMesafe > 35){
    backFor(200);
    turnLeft();
    delay(550);
  }
}

long distanceFront(){
  long cm1,cm2,cm3;
  digitalWrite(TRIG1, LOW);
  delay(5);
  digitalWrite(TRIG1, HIGH);
  delay(10);
  digitalWrite(TRIG1, LOW);
  duration = pulseIn(ECHO1, HIGH);
  cm1 = (duration/2)/ 29.1;
  cm2 = (duration/2)/ 29.1;
  cm3 = (duration/2)/ 29.1;
  cm = (cm1+cm2+cm3)/3;
  delay(50);
  return cm;
}
long distanceRight(){
  long cm1,cm2,cm3;
  digitalWrite(TRIG2, LOW);
  delay(5);
  digitalWrite(TRIG2, HIGH);
  delay(10);
  digitalWrite(TRIG2, LOW);
  duration = pulseIn(ECHO2, HIGH);
  cm1 = (duration/2)/ 29.1;
  cm2 = (duration/2)/ 29.1;
  cm3 = (duration/2)/ 29.1;
  cm = (cm1+cm2+cm3)/3;
  delay(50);
  return cm;
}
void backward() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, HIGH);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  analogWrite(PWML,120);
  analogWrite(PWMR,151);
  
}
void solGeri() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, HIGH);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  analogWrite(PWML,120);
  analogWrite(PWMR,0);
  
}
void fullForward() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,123);
  analogWrite(PWMR,155);//142
}

void forward() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,116);
  analogWrite(PWMR,145); 
}

void fullStop() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  
  analogWrite(PWML,0);
  analogWrite(PWMR,0);
  
}

void turnRight() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,140);
  analogWrite(PWMR,0);
}
void turnRight90() {
  turnRight();
  delay(900);
  fullStop();
}
void turnLeft() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, HIGH);
  
  analogWrite(PWML,0);
  analogWrite(PWMR,145);//125
}
void turnLeft90() {
  turnLeft();
  delay(950);
  fullStop();
}
//smart commands
void turnLeft180() {
  turnLeft();
  delay(950);
  fullStop();
}
int turnLeftFor(int leftTime) {
  turnLeft();
  delay(leftTime);
  fullStop();
}
void forwardFor(int forwardTime) {
  fullForward();
  delay(forwardTime);
  fullStop();
}
void backFor(int backTime) {
  backward();
  delay(backTime);
  fullStop();
}
void rotateLeft() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,122);
  analogWrite(PWMR,160);  
}
void rotateRight() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,130);
  analogWrite(PWMR,110);  
}
