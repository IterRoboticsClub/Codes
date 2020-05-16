struct grid
{
      char visit;
      char block;
      int x,y;
      int adj[4];
      int block_height;
      int weight[35];
};
int min_weight;
int flag=0;
int sum_path1;
int sum_path2;
int sum_path3;
int sum_path4;
int top_path1;
int top_path2;
int top_path3;
int top_path4;
int path1[50];
int path2[50];
int path3[50];
int path4[50];
int source,destination;
int block_number=0;
int stack[100];int top=0; 
struct grid node[35];
int line_sensor[5]={0, 0, 0, 0, 0};
int height_sensor[7]={0, 0, 0, 0, 0, 0, 0};
int initial_motor_speed=255;
int i,j,h,k;
char present_direction='n';
int present_node=0;
void part2()
{
 // while(block_number!=0)
  {
    hold();
    reverse();
    drop();
    if(node[present_node].block_height==1)
    {
      source=present_node;
      destination=16;
    }
    else if(node[present_node].block_height==3)
    {
      source=present_node;
      destination=17;
    }
    else if(node[present_node].block_height==5)
    {
      source=present_node;
      destination=18;
    }
    if((node[16].block=='n')&&(node[17].block=='n')&&(node[18].block=='n'))//if all the places are vacant
    {
      path_finder();
    }
  }
 }
void path_finder()
{
  refresh();
  top_path1++;
  top_path2++;
  top_path3++;
  top_path4++;
  if((node[source].adj[0]==-99)||(node[node[source].adj[0]].block=='y'))
  {
    sum_path1=1000;
  }
  else
  {
  sum_path1=node[destination].weight[source];
  }
  if((node[source].adj[1]==-99)||(node[node[source].adj[1]].block=='y'))
  {
    sum_path2=1000;
  }
  else
  {
  sum_path2=node[destination].weight[source];
  }
  
  if((node[source].adj[2]==-99)||(node[node[source].adj[2]].block=='y'))
  {
    sum_path3=1000;
  }
  else
  {
  sum_path3=node[destination].weight[source];
  }
  if((node[source].adj[3]==-99)||(node[node[source].adj[3]].block=='y'))
  {
    sum_path4=1000;
  }
  else
  {
  sum_path4=node[destination].weight[source];
  }
  path1[top_path1]=source;
  path2[top_path2]=source;
  path3[top_path3]=source;
  path4[top_path4]=source;
   top_path1++;
  top_path2++;
  top_path3++;
  top_path4++;
  
  path1[top_path1]=node[source].adj[0];
  path2[top_path2]=node[source].adj[1];
  path3[top_path3]=node[source].adj[2];
  path4[top_path4]=node[source].adj[3];
  if(node[source].adj[0]!=-99)
  sum_path1=sum_path1+node[destination].weight[node[source].adj[0]];
   if(node[source].adj[1]!=-99)
  sum_path2=sum_path2+node[destination].weight[node[source].adj[1]];
   if(node[source].adj[2]!=-99)
  sum_path3=sum_path3+node[destination].weight[node[source].adj[2]];
   if(node[source].adj[3]!=-99)
  sum_path4=sum_path4+node[destination].weight[node[source].adj[3]];
  
  
  while(flag==0)
  {
    min_weight=sum_path1;
    if(min_weight>sum_path2)
    min_weight=sum_path2;
    if(min_weight>sum_path3)
    min_weight=sum_path3;
    if(min_weight>sum_path4)
    min_weight=sum_path4;
    if(min_weight==sum_path1)
    {
      

    
    
     }
  }
  
  
}
void refresh()
{
  for(i=0;i<50;i++)
  {
    path1[i]=999;
    path2[i]=999;
    path3[i]=999;
    path4[i]=999; 
  }
  top_path1=-1;
  top_path2=-1;
  top_path3=-1;
  top_path4=-1;
  sum_path1=0;
  sum_path2=0;
  sum_path3=0;
  sum_path4=0;
  flag=0;
}

void hold()
{
    digitalWrite(40,HIGH);
    digitalWrite(41,LOW);
    delay(1600);
    pause();
}
void drop()
{
    digitalWrite(40,LOW);
    digitalWrite(41,HIGH);
    delay(1000);
    pause();
}
void backtrack()
{
  top--;
  
  if (stack[top]==node[present_node].adj[0])
  {
    if(present_direction=='n')
    move_a_bit();
    else if(present_direction=='e')
    {
      move_a_bit();
      turn_left();
    }
     else if(present_direction=='s')
    {
      move_a_bit();
      turn_left();
      turn_left();
    }
     else if(present_direction=='w')
    {
      move_a_bit();
      turn_right();
    }
    present_direction='n';
    present_node=node[present_node].adj[0];
    node[present_node].visit='y';
  
  }
  else if (stack[top]==node[present_node].adj[1])
  {
    if(present_direction=='n')
     {
      move_a_bit();
      turn_left();
      turn_left();
    }
    else if(present_direction=='e')
    {
      move_a_bit();
      turn_right();
    }
     else if(present_direction=='s')
   move_a_bit();
     else if(present_direction=='w')
    {
      move_a_bit();
      turn_left();
    }
    present_direction='s';
    present_node=node[present_node].adj[1];
    node[present_node].visit='y';
    
  }    
  
  else if (stack[top]==node[present_node].adj[2])
  {
    if(present_direction=='n')
     {
      move_a_bit();
      turn_left();
      
    }
    else if(present_direction=='e')
    {
      move_a_bit();
      turn_left();
      turn_left();
    }
     else if(present_direction=='s')
     {
   move_a_bit();
   turn_right();
     }
     
     else if(present_direction=='w')
    {
      move_a_bit();
    }
    present_direction='w';
    present_node=node[present_node].adj[2];
    node[present_node].visit='y';
    
  } 
  
    
  
   else if (stack[top]==node[present_node].adj[3])
  {
    if(present_direction=='n')
     {
      move_a_bit();
      turn_right();
      
    }
    else if(present_direction=='e')
    {
      move_a_bit();
      
    }
     else if(present_direction=='s')
   {
     move_a_bit();
     turn_left();
   }
     else if(present_direction=='w')
    {
      move_a_bit();
      turn_left();
      turn_left();
    }
    present_direction='e';
    present_node=node[present_node].adj[3];
    node[present_node].visit='y';
    
  }
  
}



void pause_claw()
{
  digitalWrite(40,LOW);//for claw
 digitalWrite(41,LOW);
}
void decide()
{ 
  node[present_node].visit='y';
  if ((node[present_node].adj[0]!=-99)&&(node[node[present_node].adj[0]].visit=='n'))
  {
    if(present_direction=='n')
    move_a_bit();
    else if(present_direction=='e')
    {
      move_a_bit();
      turn_left();
    }
     else if(present_direction=='s')
    {
      move_a_bit();
      turn_left();
      turn_left();
    }
     else if(present_direction=='w')
    {
      move_a_bit();
      turn_right();
    }
    present_direction='n';
    present_node=node[present_node].adj[0];
    node[present_node].visit='y';
    top++;
    stack[top]=present_node;
  }
  else if ((node[present_node].adj[1]!=-99)&&(node[node[present_node].adj[1]].visit=='n'))
  {
    if(present_direction=='n')
     {
      move_a_bit();
      turn_left();
      turn_left();
    }
    else if(present_direction=='e')
    {
      move_a_bit();
      turn_right();
    }
     else if(present_direction=='s')
   move_a_bit();
     else if(present_direction=='w')
    {
      move_a_bit();
      turn_left();
    }
    present_direction='s';
    present_node=node[present_node].adj[1];
    node[present_node].visit='y';
    top++;
    stack[top]=present_node;
  }    
  
  else if ((node[present_node].adj[2]!=-99)&&(node[node[present_node].adj[2]].visit=='n'))
  {
    if(present_direction=='n')
     {
      move_a_bit();
      turn_left();
      
    }
    else if(present_direction=='e')
    {
      move_a_bit();
      turn_left();
      turn_left();
    }
     else if(present_direction=='s')
     {
   move_a_bit();
   turn_right();
     }
     
     else if(present_direction=='w')
    {
      move_a_bit();
    }
    present_direction='w';
    present_node=node[present_node].adj[2];
    node[present_node].visit='y';
    top++;
    stack[top]=present_node;
  } 
  
    
  
   else if ((node[present_node].adj[3]!=-99)&&(node[node[present_node].adj[3]].visit=='n'))
  {
    if(present_direction=='n')
     {
      move_a_bit();
      turn_right();
      
    }
    else if(present_direction=='e')
    {
      move_a_bit();
      
    }
     else if(present_direction=='s')
   {
     move_a_bit();
     turn_left();
   }
     else if(present_direction=='w')
    {
      move_a_bit();
      turn_left();
      turn_left();
    }
    present_direction='e';
    present_node=node[present_node].adj[3];
    node[present_node].visit='y';
    top++;
    stack[top]=present_node;
  } 
  else  backtrack();
}  
void move_a_bit()
{ 
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    delay(450);
}
void pause()
 {
    digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,LOW);
    digitalWrite(40,LOW);
    digitalWrite(41,LOW);
    delay(10);
    
  }
  void turn_left()
{
   
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,170);   //Left Motor Speed
    analogWrite(13,180);
	
	delay(550);
	pause();
}
 void turn_right()
{
   
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
	
	delay(550);
	pause();
}

void setup()
{
 pinMode(12,OUTPUT); //PWM Pin 1 for left motor
 pinMode(13,OUTPUT); //PWM Pin 2 for right motor
 pinMode(24,OUTPUT); //Left Motor Pin 1
 pinMode(26,OUTPUT); //Left Motor Pin 2
 pinMode(34,OUTPUT); //Right Motor Pin 1
 pinMode(36,OUTPUT);  //Right Motor Pin 2
 pinMode(40,OUTPUT);//for claw
 pinMode(41,OUTPUT);
stack[top]=0;

j=0;
for(i=0;i<7;i++)
{
  node[i].x=j;
  node[i].y=0;
  node[i].visit='n';
  node[i].block='n';
  node[i].block_height=0;
  j++;
}
j=0;
for(i=7;i<14;i++)
{
  node[i].x=j;
  node[i].y=1;
  node[i].visit='n';
  node[i].block='n';
  node[i].block_height=0;
  j++;
}
j=0;
for(i=14;i<21;i++)
{
  node[i].x=j;
  node[i].y=2;
  node[i].visit='n';
  node[i].block='n';
  node[i].block_height=0;
  j++;
}
j=0;
for(i=21;i<28;i++)
{
  node[i].x=j;
  node[i].y=3;
  node[i].visit='n';
  node[i].block='n';
  node[i].block_height=0;
  j++;
}
j=0;
for(i=28;i<35;i++)
{
  node[i].x=j;
  node[i].y=4;
  node[i].visit='n';
  node[i].block='n';
  node[i].block_height=0;
  j++;
}
//now initialising each node with different weights considering different different points as origin
i=0;j=0;
for(i=0;i<35;i++)
{
  h=node[i].x;
  k=node[i].y;
  for(j=0;j<35;j++)
  {
    node[i].weight[j]=(node[j].x-h)+(node[j].y-k);
    if(node[i].weight[j]<0)
    node[i].weight[j]=(-1)*(node[i].weight[j]);
  }
}

 Serial.begin(9600); //Enable Serial Communications
}

void loop()
{
 sensors_read();
 if((height_sensor[0]==1)||(height_sensor[1]==1)||(height_sensor[2]==1)||(height_sensor[3]==1)||(height_sensor[4]==1)||(height_sensor[5]==1)||(height_sensor[6]==1))
 {
   pause();
   save_height();
   if(block_number==3)
   {
     digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,LOW);
    delay(1000);
    part2();
    {//after completing the task bot will stop for 1 seconds
    
      digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,LOW);
    delay(1000);
    reverse();
    }
   }
   else
   {
   reverse();
   
   decide();
   }
 }
 else
 {
 follow();
 if((line_sensor[0]==1)&&(line_sensor[1]==1)&&(line_sensor[2]==1)&&(line_sensor[3]==1)&&(line_sensor[4]==1))
   {
  pause();
  decide();
    }
 }
 


}

void sensors_read()
{
  line_sensor[0]=digitalRead(A0);//reading the values from the sensors both height and line
  line_sensor[1]=digitalRead(A1);
  line_sensor[2]=digitalRead(A2);
  line_sensor[3]=digitalRead(A3);
  line_sensor[4]=digitalRead(A4);
  height_sensor[0]=digitalRead(A5);
  height_sensor[1]=digitalRead(A6);
  height_sensor[2]=digitalRead(A7);
  height_sensor[3]=digitalRead(A8);
  height_sensor[4]=digitalRead(A9);
  height_sensor[5]=digitalRead(A10);
  height_sensor[6]=digitalRead(A11);
  
}

void follow()
{
  
    if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==1)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
   {
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,150);   //Left Motor Speed
    analogWrite(13,180);
   }
  else if((line_sensor[0]==0)&&(line_sensor[1]==1)&&(line_sensor[2]==1)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
  {
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,120);   //Left Motor Speed
    analogWrite(13,180);
    }
  else if((line_sensor[0]==0)&&(line_sensor[1]==1)&&(line_sensor[2]==0)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
   {
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,90);   //Left Motor Speed
    analogWrite(13,180);
    }
  else if((line_sensor[0]==1)&&(line_sensor[1]==1)&&(line_sensor[2]==0)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
   {
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,50);   //Left Motor Speed
    analogWrite(13,180);
    }
    
    else if((line_sensor[0]==1)&&(line_sensor[1]==1)&&(line_sensor[2]==1)&&(line_sensor[3]==1)&&(line_sensor[4]==1))
  {
    /*digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,LOW);
    delay(1000);*/
    pause();
    
  }
    
  else if((line_sensor[0]==1)&&(line_sensor[1]==0)&&(line_sensor[2]==0)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,0);   //Left Motor Speed
    analogWrite(13,180);
    } 
    else if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==1)&&(line_sensor[3]==1)&&(line_sensor[4]==0))
  {
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,180);   //Left Motor Speed
    analogWrite(13,130);
    }
  else if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==0)&&(line_sensor[3]==1)&&(line_sensor[4]==0))
   {
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,180);   //Left Motor Speed
    analogWrite(13,90);
    }
  else if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==0)&&(line_sensor[3]==1)&&(line_sensor[4]==1))
   {
    digitalWrite(24,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,180);   //Left Motor Speed
    analogWrite(13,50);
    }
  else if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==0)&&(line_sensor[3]==0)&&(line_sensor[4]==1))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,HIGH);
    digitalWrite(36,LOW);
    analogWrite(12,180);   //Left Motor Speed
    analogWrite(13,0);
    }
    
    else 
       {
    digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,LOW);
    analogWrite(12,180);   //Left Motor Speed
    analogWrite(13,180);
   }
   
}
void reverse()
{
  while(1)
  {
    line_sensor[0]=digitalRead(A0);//reading the values from the sensors both height and line
    line_sensor[1]=digitalRead(A1);
    line_sensor[2]=digitalRead(A2);
    line_sensor[3]=digitalRead(A3);
    line_sensor[4]=digitalRead(A4);
  
    
    if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==1)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
    analogWrite(12,170);   //Left Motor Speed
    analogWrite(13,180);
   }
  else if((line_sensor[0]==0)&&(line_sensor[1]==1)&&(line_sensor[2]==1)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
  {
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
    analogWrite(12,120);   //Left Motor Speed
    analogWrite(13,160);
    }
  else if((line_sensor[0]==0)&&(line_sensor[1]==1)&&(line_sensor[2]==0)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
    analogWrite(12,90);   //Left Motor Speed
    analogWrite(13,180);
    }
  else if((line_sensor[0]==1)&&(line_sensor[1]==1)&&(line_sensor[2]==0)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
    analogWrite(12,160);   //Left Motor Speed
    analogWrite(13,50);
    }
    
    else if((line_sensor[0]==1)&&(line_sensor[1]==1)&&(line_sensor[2]==1)&&(line_sensor[3]==1)&&(line_sensor[4]==1))
  {
    /*digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,LOW);
    //delay(1000);*/
    pause();
    present_node=stack[top];
    break;
    
  }
    
  else if((line_sensor[0]==1)&&(line_sensor[1]==0)&&(line_sensor[2]==0)&&(line_sensor[3]==0)&&(line_sensor[4]==0))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,LOW);
    digitalWrite(36,LOW);
    analogWrite(12,180);   //Left Motor Speed
    analogWrite(13,0);
    } 
    else if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==1)&&(line_sensor[3]==1)&&(line_sensor[4]==0))
  {
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
    analogWrite(12,120);   //Left Motor Speed
    analogWrite(13,180);
    }
  else if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==0)&&(line_sensor[3]==1)&&(line_sensor[4]==0))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
    analogWrite(12,80);   //Left Motor Speed
    analogWrite(13,180);
    }
  else if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==0)&&(line_sensor[3]==1)&&(line_sensor[4]==1))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
    analogWrite(12,40);   //Left Motor Speed
    analogWrite(13,180);
    }
  else if((line_sensor[0]==0)&&(line_sensor[1]==0)&&(line_sensor[2]==0)&&(line_sensor[3]==0)&&(line_sensor[4]==1))
   {
    digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,HIGH);
    analogWrite(12,0);   //Left Motor Speed
    analogWrite(13,180);
    }
    
    else 
       {
    digitalWrite(24,LOW);
    digitalWrite(26,LOW);
    digitalWrite(34,LOW);
    digitalWrite(36,LOW);
    analogWrite(12,160);   //Left Motor Speed
    analogWrite(13,180);
   }
  }
   
}










void save_height()
{
  height_sensor[0]=digitalRead(A5);
  height_sensor[1]=digitalRead(A6);
  height_sensor[2]=digitalRead(A7);
  height_sensor[3]=digitalRead(A8);
  height_sensor[4]=digitalRead(A9);
  height_sensor[5]=digitalRead(A10);
  height_sensor[6]=digitalRead(A11);
  
  if((height_sensor[0]==1)&&(height_sensor[1]==1)&&(height_sensor[2]==1)&&(height_sensor[3]==1)&&(height_sensor[4]==1)&&(height_sensor[5]==1)&&(height_sensor[6]==1))
  {
    node[present_node].block='y';
    node[present_node].block_height=5;
    top--;
    block_number++;
  }
 else if((height_sensor[0]==1)&&(height_sensor[1]==1)&&(height_sensor[2]==1)&&(height_sensor[3]==1)&&(height_sensor[4]==1))
 {
   node[present_node].block='y';
    node[present_node].block_height=3;
    top--;
    block_number++;
 }
 else if((height_sensor[0]==1)&&(height_sensor[1]==1))
 {
   node[present_node].block='y';
    node[present_node].block_height=1;
    top--;
    block_number++;
 }
 else
 {
 top--;//just for testing as block height was not recognised
 block_number++;
 }
                           
}        
