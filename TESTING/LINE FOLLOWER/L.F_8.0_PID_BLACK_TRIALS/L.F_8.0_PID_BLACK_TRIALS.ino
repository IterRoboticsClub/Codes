//DO GROUND

static const uint8_t pins[]={A0,A1,A2,A3,A4,A5,12,13};

int s[8]={0,0,0,  0,0, 0,0,0},  
    de[8]={0,0,0, 0,0, 0,0,0},  

    
int   L1=727,  L2=327,  L3=337,  L4=137,  L5=537,  L6=437,  L7=637,
      
      R1=717,  R2=716,  R3=736,  R4=734,  R5=735,  R6=731,  R7=733,
      
      T1=000,  T2=100,  T3=104,  T4=300,  T5=304,  T6=004,  T7=006,  T8=106,
     
      RET1=700,         RET2=304,         RET3=300,         RET4=710,

      LET1=007,         LET2=027,         LET3=006,         LET4=106,

      AWT=727;          CTR=707      


float Kp=1.0,  Ki=0.0,  Kd=0.5,
      P=0,     I=0,     D=0,
      PID=0,   err=0,   p_err=0,
      cnt=0,   p_I=0;

int   dms=125, lms = 0, rms =0,  i=0,
      lm1=2,    EL=3,   lm2=4,
      rm1=5,    ER=6,   rm2=7;
      ind=0;    dec=0;


  void setup ()
{

 pinMode(EL,OUTPUT); 
 pinMode(ER,OUTPUT); 
 pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT);
 
 Serial.begin(9600); 
 
}

void loop()
{ 
    read_check();
    calculate_pid();
    motor_control();
}


void read_check()
{
  for(i=0;i<8;i++)
     
   {    s[i]=digitalRead(pins[i]); }
 
  for(i=0;i<8;i++)
      {      
        de[i]=s[i];
        if(i==0)
           {  ind=100;  }
        
        else if(i==1)
                {  ind=200;  }
        
        else if(i==2)
                {   ind=400;  }
         
        else if(i==3)
                {  ind=10; }
        
        else if(i==4)
                {  ind=20; }
        
        else if(i==5)
                {  ind=1;  } 
               
        else if(i==6)
                {  ind=2;  }
                
        else if(i==7)
                {  ind=4;  } 
                
        dec=dec+ind;
      }
      
   if(dec==L7)
     {    err=-7;  }
   
   else if(dec==L6)
           {  err=-6;  }
   
   else if(dec==L5)
           {  err=-5;  }
   
   else if(dec==L4)
           {  err=-4;  }
   
   else if(dec==L3)
           {  err=-3;  }
           
   else if(dec==L2)
           {  err=-2;  }
           
   else if(dec==L1)
           {  err=-1;  }
   
   else if(dec==C0)
           {  err=0;   }
   
   else if(dec==R1)
           {  err=1;   }
   
   else if(dec==R2)
           {  err=2;   }
   
   else if(dec==R3)
           {  err=3;   }
   
   else if(dec==R4)
           {  err=4;   }
   
   else if(dec==R5)
           {  err=5;   }
   
   else if(dec==R6)
           {  err=6;   }
   
   else if(dec==R7)
           {  err=7;   }
   
   
  
}

void calculate_pid()
{
    P = err;
    I = I + err;
    D = err-p_err;
    
    PID = (Kp*P) + (Ki*I) + (Kd*D);
    
    p_I=I;
    p_err=err;
    
}

void display_values()
{
  Serial.print("\n---------------------------------------------------------------------\nP= ");
  Serial.print(P);
  Serial.print("\nI= ");
  Serial.print(I);
  Serial.print("\nD= ");
  Serial.print(D);
  Serial.print("\nPID value = ");
  Serial.print(PID);
  Serial.print("\nLEFT MOTOR SPEED= ");
  Serial.print(lms);
  Serial.print("\nRIGHT MOTOR SPEED= ");
  Serial.print(rms);
  Serial.println("\n----------------------------------------------------------------------");
}

void motor_control()
{
    // Calculating the effective motor speed:
    lms = dms-PID;
    rms = dms+PID;
    
    // The motor speed should not exceed the max PWM value
    constrain(lms,0,150);
    constrain(rms,0,150);
	
          if(err>0)
            {    rt();    }
          
          else if(err<0)
             {    lt();    }
             
           else if(err=0)
             {    st();      }
} 
    void rt()
    {
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      analogWrite(EL,lms);
      analogWrite(ER,rms);
      delay(75);
    }
     
     void lt()
    {
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      analogWrite(EL,lms);
      analogWrite(ER,rms);
      delay(75);
    }
     
     void st()
    {
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      analogWrite(EL,lms);
      analogWrite(ER,rms);
      delay(75);
    }
    
      






































//           1 2 4   1 2  1 2 4
//    C0[8]={1,1,1, 0,0, 1,1,1};  =707
//
//int L1[8]={1,1,1, 0,1, 1,1,1},  =727
//    L2[8]={1,1,0, 0,1, 1,1,1},  =327
//    L3[8]={1,1,0, 1,1, 1,1,1},  =337
//    L4[8]={1,0,0, 1,1, 1,1,1},  =137
//    L5[8]={1,0,1, 1,1, 1,1,1},  =537
//    L6[8]={0,0,1, 1,1, 1,1,1},  =437
//    L7[8]={0,1,1, 1,1, 1,1,1};  =637
//    
//int R1[8]={1,1,1, 1,0, 1,1,1},  =717
//    R2[8]={1,1,1, 1,0, 0,1,1},  =716
//    R3[8]={1,1,1, 1,1, 0,1,1},  =736
//    R4[8]={1,1,1, 1,1, 0,0,1},  =734
//    R5[8]={1,1,1, 1,1, 1,0,1},  =735
//    R6[8]={1,1,1, 1,1, 1,0,0},  =731
//    R7[8]={1,1,1, 1,1, 1,1,0};  =733


//
//
//int T[8]={0,0,0, 0,0, 0,0,0};    =000
//         {1,0,0, 0,0, 0,0,0};    =100
//         {1,0,0, 0,0, 0,0,1};    =104
//         {1,1,0, 0,0, 0,0,0};    =300
//         (1,1,0, 0,0, 0,0,1};    =304
//      
//         {0,0,0, 0,0, 0,0,1};    =004
//         {0,0,0, 0,0, 0,1,1};    =006
//         {1,0,0, 0,0, 0,1,1};    =106
//         
//         {1,1,1, 1,1, 1,1,1};    =727//if all white
//         
//int RET[8]={1,1,1, 0,0, 0,0,0};  =700
//           {1,1,0, 0,0, 0,0,1};  =304
//           {1,1,0, 0,0, 0,0,0};  =300
//           {1,1,1, 1,0, 0,0,0};  =710
//           
//int LET[8]={0,0,0, 0,0, 1,1,1};  =007
//           {0,0,0, 0,1, 1,1,1};  =027
//           {0,0,0, 0,0, 0,1,1};  =006
//           {1,0,0, 0,0, 0,1,1};  =106

