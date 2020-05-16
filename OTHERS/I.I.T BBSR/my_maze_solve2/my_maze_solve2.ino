int lPin1 = 2;
int lPin2 = 4;
int rPin1 = 7;
int rPin2 = 8;
int pwm1=9;
int pwm2=10;
int sensors[] = {0, 0, 0};
int surface[] = {0, 0, 0};
int threshold=700;
char path[100];
char pathf[100];
char revpath[100];
int p=0,i=0,limit=0,j=0;
int m=0,n=0,k=0,f=0,r=0,cnt=1,prev=0;
int c=0;
void setup()
{
 
 pinMode(2,OUTPUT); //Left Motor Pin 1
 pinMode(4,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(8,OUTPUT);  //Right Motor Pin 2
 Serial.begin(9600); //Enable Serial Communications

}

void loop()
{
  sensors_read();
  maze_solver();
}

void sensors_read()
{ 
for (int i = 0; i < 3; i++)
  {
    sensors[i] = analogRead(i);
    
  if(sensors[i]<threshold)
  {
    surface[i]=0;
  }
  else if(sensors[i]>threshold)
  {
    surface[i]=1;
  }
  }
}

void brake()
{
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(2);
}

void right()
{
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);  //FOR RIGHT
    digitalWrite(8,LOW);
    delay(2);
}

void left()
{
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);  //FOR LEFT
    digitalWrite(8,HIGH);
    delay(2);
}

void straight()
{
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);    //FOR STRAIGHT
    digitalWrite(8,HIGH);
}

void back()
{
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(2);
}
 
void maze_solver()
{
  if(surface[0]==0)
  {
    follow();
  }
   else if(surface[0]==1)
   {
     for(limit=0;limit<=c;limit++)
     {
      follow(); 
     }
     if(limit>c)
     {
      back();
      path[p]='b';
      p++;
     }
   }
}
void follow()
{
  //FOR SIPMLE LINE 
  
  if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==1))    //WHITE-WHITE-BLACK-WHITE-WHITE
    {
      straight();
      path[p]='s';
      p++;
  }
    
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==1)&&(surface[5]==1))    //BLACK-BLACK-WHITE-WHITE-WHITE
    {
      left();
      path[p]='l';
      p++;
    }
    
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==1))    //BLACK-BLACK-BLACK-WHITE-WHITE
    {
      left();
      path[p]='l';
      p++;
    }
     
      else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==1))    //WHITE-BLACK-BLACK-WHITE-WHITE
    {
      left();
      path[p]='l';
      p++;
    }
    
     else if((surface[1]==0)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==1))    //BLACK-WHITE-BLACK-WHITE-WHITE
    {
      left();
      path[p]='l';
      p++;
    }
    
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==0))    //WHITE-WHITE-BLACK-BLACK-BLACK
    {
      right();
      path[p]='r';
      p++;
    } 
    
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==0))    //WHITE-WHITE-WHITE-BLACK-BLACK
    {
      right();
      path[p]='r';
      p++;
    } 
    
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==1))    //WHITE-WHITE-BLACK-BLACK-WHITE
    {
      right();
      path[p]='r';
      p++;
    } 
    
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==0))    //WHITE-WHITE-BLACK-WHITE-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
   
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==1)&&(surface[4]=0)&&(surface[5]==1))    //WHITE-WHITE-WHITE-BLACK-WHITE
   {
      right();
      path[p]='r';
      p++;
   }
    
//----------------------------------------------------------------------------------------------------------------------------------------

  //FOR T NODE;
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==0))    //BLACK-BLACK-BLACK-BLACK-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==0))    //BLACK-BLACK-WHITE-BLACK-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==0))    //WHITE-BLACK-BLACK-BLACK-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==1))    //BLACK-BLACK-BLACK-BLACK-WHITE
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==1))    //WHITE-BLACK-BLACK-BLACK-WHITE
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==0))    //WHITE-BLACK-WHITE-BLACK-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==1))    //BLACK-BLACK-WHITE-BLACK-WHITE
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==1))    //WHITE-BLACK-WHITE-BLACK-WHITE
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==0)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==0))    //BLACK-WHITE-BLACK-WHITE-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==0)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==0))    //BLACK-WHITE-BLACK-BLACK-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==0))    //BLACK-BLACK-BLACK-WHITE-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==0))    //WHITE-BLACK-BLACK-WHITE-BLACK
    {
      right();
      path[p]='r';
      p++;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==1))    //BLACK-WHITE-BLACK-BLACK-WHITE
    {
      right();
      path[p]='r';
      p++;
    }
    //AFTER IT REACHES THE END OF MAZE---------------------------------------------------------------------------------------------------------
    else if(surface[0]==0&&surface[1]==0&&surface[2]==0&&surface[3]==0&&surface[4]==0&&surface[5]==0)    //BLACK-BLACK-BLACK-BLACK-BLACK-BLACK
    {
     brake();
     digitalWrite(13,HIGH);
     digitalWrite(12,LOW);    //FOR GLOWING RED LED AFTER REACHING TO END POINT
     delay(2);
     back();
     go_to_start();
     delay(2);
    }
    else 
    {
      straight();
      path[p]='s';
      p++;
    }
 }  //END OF FOLLOW FUNCTION
  
  void simplify()
  {
    pathf[0]=path[0];
    for(p=1;p!='/0';p++)
    {
      if(pathf[f]!=path[p])
      {
        pathf[f]=path[p];
        f++;
      }
    }
    for(f=0;pathf[f]!='/0';f++)
    {
      n++;
    }
    m=n;
    for(j=0;j<m;j++)
    {
    for(f=0;f<n;f++)
    {
      if(pathf[f]=='b')
      {
        if(pathf[f-1]=='l'&&pathf[f+1]=='r')  //LBR=B
          {
            pathf[f-1]='b';
            pathf[f]=pathf[f+2];
            pathf[f+1]=pathf[f+3];
            n=n-2;
          }
        else if(pathf[f-1]=='r'&&pathf[f+1]=='s')  //RBS=L
          {
            pathf[f-1]='l';
            pathf[f]=pathf[f+2];
            pathf[f+1]=pathf[f+3];
            n=n-2;
          }
        else if(pathf[f-1]=='r'&&pathf[f+1]=='l')  //RBL=B
         {
           pathf[f-1]='b';
           pathf[f]=pathf[f+2];
           pathf[f+1]=pathf[f+3];
           n=n-2;
         }
        else if(pathf[f-1]=='l'&&pathf[f+1]=='s')  //LBS=R
         {
           pathf[f-1]='r';
           pathf[f]=pathf[f+2];
           pathf[f+1]=pathf[f+3];
           n=n-2;
         }
        else if(pathf[f-1]=='s'&&pathf[f+1]=='s')  //SBS=B
         {
           pathf[f-1]= 'b';
           pathf[f]=pathf[f+2];
           pathf[f+1]=pathf[f+3];
           n=n-2;
         }
         else if(pathf[f-1]=='r'&&pathf[f+1]=='r')  //RBR=S
         {
           pathf[f-1]='s';
           pathf[f]=pathf[f+2];
           pathf[f+1]=pathf[f+3];
           n=n-2;
         }
         else if(pathf[f-1]=='l'&&pathf[f+1]=='l')  //LBL=S
         {
           pathf[f-1]='s';
           pathf[f]=pathf[f+2];
           pathf[f+1]=pathf[f+3];
           n=n-2;
         }
         else if(pathf[f-1]=='s'&&pathf[f+1]=='l')  //SBL=R
         {
           pathf[f-1]='r';
           pathf[f]=pathf[f+2];
           pathf[f+1]=pathf[f+3];
           n=n-2;
         }
         else if(pathf[f-1]=='s'&&pathf[f+1]=='r')  //SBR=L
         {
           pathf[f-1]='l';
           pathf[f]=pathf[f+2];
           pathf[f+1]=pathf[f+3];
           n=n-2;
         }
      }
    }
  }
 }
 
  void revepath()  
 {
    r=0;
    for(f=n-1;f>=0;f--)
    {  
      if(pathf[f]=='s')
       {
         revpath[r]=pathf[f];
         r++;
       }
       else if(pathf[f]=='r')
       {
         revpath[r]='l';
         r++;
       }
       else if(pathf[f]=='l')
       {
         revpath[r]='r';
         r++;
       }
    }
 }
 
 void reverse_conditions()
 {
  //FOR TURNING AND 3-POINT NODE
    if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==1))    //WHITE-WHITE-BLACK-WHITE-WHITE=STRAIGHT
    {
      c=0;
    }
    
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==1)&&(surface[5]==1))    //BLACK-BLACK-WHITE-WHITE-WHITE=LEFT
    {
      c=2;
    }
    
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==1))    //BLACK-BLACK-BLACK-WHITE-WHITE=LEFT
    {
      c=2;
    }
     
      else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==1))    //WHITE-BLACK-BLACK-WHITE-WHITE=LEFT
    {
      c=2;
    }
    
     else if((surface[1]==0)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==1))    //BLACK-WHITE-BLACK-WHITE-WHITE=LEFT
    {
      c=2;
    }
    
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==0))    //WHITE-WHITE-BLACK-BLACK-BLACK=RIGHT
    {
      c=1;
    } 
    
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==0))    //WHITE-WHITE-WHITE-BLACK-BLACK=RIGHT
    {
      c=1;
    } 
    
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==1))    //WHITE-WHITE-BLACK-BLACK-WHITE=RIGHT
    {
      c=1;
    } 
    
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==0))    //WHITE-WHITE-BLACK-WHITE-BLACK=RIGHT
    {
      c=1;
    }
   
    else if((surface[1]==1)&&(surface[2]==1)&&(surface[3]==1)&&(surface[4]=0)&&(surface[5]==1))    //WHITE-WHITE-WHITE-BLACK-WHITE=RIGHT
   {
      c=1;
   }
    
//----------------------------------------------------------------------------------------------------------------------------------------

  //FOR T NODE;
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==0))    //BLACK-BLACK-BLACK-BLACK-BLACK=RIGHT
    {
      c=1;
    }
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==0))    //BLACK-BLACK-WHITE-BLACK-BLACK=RIGHT
    {
      c=1;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==0))    //WHITE-BLACK-BLACK-BLACK-BLACK=RIGHT
    {
      c=1;
    }
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==1))    //BLACK-BLACK-BLACK-BLACK-WHITE=RIGHT
    {
      c=1;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==1))    //WHITE-BLACK-BLACK-BLACK-WHITE=RIGHT
    {
      c=1;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==0))    //WHITE-BLACK-WHITE-BLACK-BLACK=RIGHT
    {
      c=1;
    }
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==1))    //BLACK-BLACK-WHITE-BLACK-WHITE=RIGHT
    {
      c=1;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==1))    //WHITE-BLACK-WHITE-BLACK-WHITE=RIGHT
    {
      c=1;
    }
    else if((surface[1]==0)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==0))    //BLACK-WHITE-BLACK-WHITE-BLACK=RIGHT
    {
      c=1;
    }
    else if((surface[1]==0)&&(surface[2]==1)&&(surface[3]==0)&&(surface[4]==0)&&(surface[5]==0))    //BLACK-WHITE-BLACK-BLACK-BLACK=RIGHT
    {
      c=1;
    }
    else if((surface[1]==0)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==0))    //BLACK-BLACK-BLACK-WHITE-BLACK=RIGHT
    {
      c=1;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==0)&&(surface[4]==1)&&(surface[5]==0))    //WHITE-BLACK-BLACK-WHITE-BLACK=RIGHT
    {
      c=1;
    }
    else if((surface[1]==1)&&(surface[2]==0)&&(surface[3]==1)&&(surface[4]==0)&&(surface[5]==1))    //BLACK-WHITE-BLACK-BLACK-WHITE=RIGHT
    {
      c=1;
    }
    //AFTER IT REACHES TO THE START OF MAZE---------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    else 
    {
      c=0;
    }
 }
 
 void go_to_start()
 { 
   simplify();
   revepath();
   reverse_conditions();
   if(c==0)
   { 
     straight();
   }
   else if(c!=0)
   {  r++;
     if(revpath[r]=='r')
     {
       right();
       r++;
     }
     else if(revpath[r]=='l')
     {
       left();
       r++;
     }
     else if(revpath[r]=='s')
     {
       straight();
       r++;
     }
   }
   else if(c==3)
   {
     digitalWrite(11,HIGH);
     digitalWrite(10,LOW);    //For Green LED
     brake();
   }
 }
