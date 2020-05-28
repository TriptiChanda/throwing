#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(0,1);

int dirD1 = 11;
int dirD2 = 12;
int pwm4 = 7;
int mflag1,mflag2;
int cnt1,stflag1,stflag2,j;
volatile int i = 50;
//unsigned long int prevmilli1,currmilli1,interval1;
//int l1,r1;


void setup() {
  // put your setup code here, to run once:
pinMode(dirD1,OUTPUT);
pinMode(dirD2,OUTPUT);
pinMode(pwm4,OUTPUT);
mflag1 = 0;
mflag2 = 0;
//cnt1 = 0;
stflag1 = 0;
stflag2 = 0;
//i=50;
//j=0;

Serial.begin(9600);
  ps2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
noInterrupts();
   
if(mflag1==1)
 {
  
  if(i<255)
  {
    analogWrite(pwm4,i);
   digitalWrite(dirD1,HIGH);
   digitalWrite(dirD2,LOW);
  }
   
  mflag1 = 0 ;
  i=i+70;

 
 }
/*else if(stflag1==1)
{
 digitalWrite(dirD1,HIGH);
   digitalWrite(dirD2,HIGH);
 analogWrite(pwm4,0); 
 stflag1= 0;  
}*/

else if(mflag2==1)
{
 
  if(i>0)
  {
   analogWrite(pwm4,i);
   digitalWrite(dirD1,HIGH);
   digitalWrite(dirD2,LOW);
  
  }
  
   mflag2 = 0;
   i = i-70;
 
}
/*else if(stflag2==1)
{
 analogWrite(pwm4,0); 

 stflag2 = 0;
}*/
  
  
interrupts();
  if(ps2.readButton(PS2_UP)==0)
  {
    mflag1 = 1;
   
  }

 /* else if(ps2.readButton(PS2_UP)==1)
  {
    stflag1 = 1;
  }*/

 else if(ps2.readButton(PS2_DOWN)==0)
  {
    mflag2 = 1;
   
  }
  /* else if(ps2.readButton(PS2_DOWN)==1)
  {
    stflag2 = 1;
  }*/
 }

