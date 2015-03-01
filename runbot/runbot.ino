//#include <Servo.h>

//Servo myServo;
int rn=3,rp=6;
int ln=9,lp=11;
//int servopin=10;
double totalX=400.0;
double timeTot=1000.0;
void setup() {                
  // initialize the digital pin as an output.
  pinMode(rp, OUTPUT); 
  pinMode(rn, OUTPUT); 
  pinMode(lp, OUTPUT); 
  pinMode(ln, OUTPUT);
  //myServo.attach(servopin); 
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  long data=0,t=0,angle;
  float p=0;
  while(Serial.available())
  {
    p=Serial.parseFloat();
    data=p;
  //data=p/1000;
  //angle=p%1000;
    t=abs(data*timeTot/totalX);
    if(data<0)
    {
      analogWrite(rp, 100);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(rn, LOW);    // turn the LED off by making the voltage LOW
      analogWrite(lp, 102);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(ln, LOW);    // turn the LED off by making the voltage LOW  
      delay(t);               // wait for a second      
    }
    else if(data>0)
    {
      digitalWrite(rp, LOW);    // turn the LED off by making the voltage LOW
      analogWrite(rn, 100);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(lp, LOW);    // turn the LED off by making the voltage LOW
      analogWrite(ln, 102);   // turn the LED on (HIGH is the voltage level)
      delay(t);               // wait for a second
    }
    else
    {
      digitalWrite(rn, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(ln, LOW);    // turn the LED off by making the voltage LOW  
      digitalWrite(rp, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(lp, LOW);
    }
  }
  /*if(angle<0)
    angle+=180;
  myServo.write(angle);  // turn the LED off by making the voltage LOW  */
}
