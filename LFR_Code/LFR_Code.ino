int s[6]; 

// Motor 
int ENA = 7;
int motorInput1 = 6;
int motorInput2 = 5;
int motorInput3 = 4;
int motorInput4 = 3;
int ENB = 2;

//motorspeed 
int fs=75;
int ms1=13 ;
int ms2=26;
int ms3=39;
int ms4=52;
int ms5=65;
int ms6;
int ms7;
int turnspd = 120;
int lms ;
int rms;
int error;
int th=220;
int endpointtime=200;
int breaktime=100;
int flag;
void setup()
{
  

  
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

 delay(700);

 

}
void loop()
{ 
  read_sensor_values();
  if(error == 0)forward();
  if(error == 1)left1();
  if(error == 2)left2();
  if(error == 3)left3();
  if(error == 4)left4();
  
  if(error == -1)right1();
  if(error == -2)right2();
  if(error == -3)right3();
  if(error == -4)right4();
  
  if(error == 9 ){
  forward();
  delay(120);
   
      read_sensor_values();
      if(error==10 ){ 
    sharpLeftTurn();
      }else{ 
        return;
      }
 }
 if( error == 12 || error == 11  ){
   sharpLeftTurn();
   delay(400);
 }
 if(error == 7){
  forward();
  delay(100);
   
      read_sensor_values();
      if(error==10 ){ 
    sharpLeftTurn();
      }else{ 
        return;
      }
 }
 if(error == -7){
  forward();
  delay(100);
  read_sensor_values();
      if(error==10 ){ 
    sharpRightTurn();
      }else{ 
        return;
      }
  
 }
 if (error == 5 || error == 6 ) sharpLeftTurn();
  if (error == -5 || error == -6 ) sharpRightTurn();   

}

void read_sensor_values()
{
 
  for (int i = 0 ; i < 6 ; i++) {
    s[i] = analogRead(i);
    (s[i]> th)? s[i]=1 : s[i]=0;
  
  }
if ((s[0] == 1) && (s[1] == 1) && (s[2] == 1) && (s[3] == 1) && (s[4] == 1) && (s[5] == 0))
   error =8 ;
else if ((s[0] == 1) && (s[1] == 1) && (s[2] == 1) && (s[3] == 1) && (s[4] == 0) && (s[5] == 0))
   error =7 ;
 else if ((s[0] == 1) && (s[1] == 1) && (s[2] == 1) && (s[3] == 0) && (s[4] == 0) && (s[5] == 0))
    error =6 ;
else if ((s[0] == 1) && (s[1] == 0) && (s[2] == 0) && (s[3] == 0) && (s[4] == 0) && (s[5] == 0))
    error =5 ;
else if ((s[0] == 1) && (s[1] == 1) && (s[2] == 0) && (s[3] == 0) && (s[4] == 0) && (s[5] == 0))
    error =4 ;
else if ((s[0] == 0) && (s[1] == 1) && (s[2] == 0) && (s[3] == 0) && (s[4] == 0) && (s[5] == 0))
    error =3 ;
else if ((s[0] == 0) && (s[1] == 1) && (s[2] == 1) && (s[3] == 0) && (s[4] == 0) && (s[5] == 0))
    error =2;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 1) && (s[3] == 0) && (s[4] == 0) && (s[5] == 0))
    error =1 ;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 1) && (s[3] == 1) && (s[4] == 0) && (s[5] == 0))
    error =0 ;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 1) && (s[4] == 0) && (s[5] == 0))
    error =-1 ;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 1) && (s[4] == 1) && (s[5] == 0))
    error =-2 ;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 0) && (s[4] == 1) && (s[5] == 0))
    error =-3 ;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 0) && (s[4] == 1) && (s[5] == 1))
    error =-4 ;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 0) && (s[4] == 0) && (s[5] == 1))
    error =-5 ;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 1) && (s[4] == 1) && (s[5] == 1))
    error =-6 ;
else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 1) && (s[3] == 1) && (s[4] == 1) && (s[5] == 1))
    error =-7 ;
else if ((s[0] == 0) && (s[1] == 1) && (s[2] == 1) && (s[3] == 1) && (s[4] == 1) && (s[5] == 1))
    error =-8 ;    
else if ((s[0] == 1) && (s[1] == 1) && (s[2] == 1) && (s[3] == 1) && (s[4] == 1) && (s[5] == 1))
    error =9 ;
else if((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 0) && (s[4] == 0) && (s[5] == 0))
    error =10 ;
 else if((s[0] == 1) && (s[1] == 0) && (s[2] == 1) && (s[3] == 0) && (s[4] == 0) && (s[5] == 0))
    error =11 ;
 else if((s[0] == 1) && (s[1] == 0) && (s[2] == 1) && (s[3] == 1) && (s[4] == 0) && (s[5] == 0))
    error =12 ;        
}


void forward()
{
analogWrite(ENA,fs ); 
  analogWrite(ENB,fs ); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void stopbot()
{
digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void breakbot(){
digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput4, HIGH);
  digitalWrite(motorInput3,LOW);  
}

void sharpRightTurn() {
  analogWrite(ENA,turnspd ); 
      analogWrite(ENB, turnspd);
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void sharpLeftTurn() {
  analogWrite(ENA,turnspd ); 
      analogWrite(ENB, turnspd);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void left1(){
   rms = fs+ms1;
   lms = fs-ms1;
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void left2(){
   rms = fs+ms2;
   lms = fs-ms2;
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void left3(){
   rms = fs+ms3;
   lms = fs-ms3;
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void left4(){
   rms = fs+ms4;
   lms = fs-ms4;
   rms = constrain(rms, 0, 255);
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void left5(){
   rms = fs+ms5;
   lms = fs-ms5;
   rms = constrain(rms, 0, 255);
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void right1(){
   rms = fs-ms1;
   lms = fs+ms1;
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void right2(){
   rms = fs-ms2;
   lms = fs+ms2;
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void right3(){
   rms = fs-ms3;
   lms = fs+ms3;
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void right4(){
   rms = fs-ms4;
   lms = fs+ms4;
   lms = constrain(lms, 0, 255);
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
void right5(){
   rms = fs-ms5;
   lms = fs+ms5;
   lms = constrain(lms, 0, 255);
analogWrite(ENA,rms ); 
  analogWrite(ENB, lms); 

  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput4, LOW);
  digitalWrite(motorInput3,HIGH);
}
