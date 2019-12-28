#include<VirtualWire.h>
#define ina1 7
#define ina2 6
#define inb1 4
#define inb2 3
#define pwma 8
#define pwmb 5

void setup()
{
  pinMode(ina1,OUTPUT);
  pinMode(ina2,OUTPUT);
  pinMode(pwma,OUTPUT);
  pinMode(inb1,OUTPUT);
  pinMode(inb2,OUTPUT);
  pinMode(pwmb,OUTPUT);
   Serial.begin(9600);
   Serial.println("Ready");
   vw_setup(2000);
         digitalWrite(pwma,LOW);
      digitalWrite(pwmb,LOW);
   vw_rx_start(); // start the receiver
pinMode(13,OUTPUT);
}
void loop()
{
  byte message[VW_MAX_MESSAGE_LEN]; // buffer to hold incoming message
byte msgLength = VW_MAX_MESSAGE_LEN; // the size of the message

   if (vw_get_message(message, &msgLength)) // Non-Blocking
    {
        Serial.print("GOT:");
        for(int i=0; i< msgLength;i++)
        {
           Serial.write(message[i]);
        
       //Serial.println(message[0]);
       
       if(message[i]=='1')
       {
       Serial.println("Forward");
  digitalWrite(ina1,HIGH);
  digitalWrite(ina2,LOW);
  
  digitalWrite(inb1,HIGH);
  digitalWrite(inb2,LOW);
       }
       if(message[i]=='2')
  {     Serial.println("stop");
   digitalWrite(ina1,LOW);
  digitalWrite(ina2,LOW);
  
  digitalWrite(inb1,LOW);
  digitalWrite(inb2,LOW);
  }    
        if(message[i]=='3')
   {    Serial.println("Left");
    digitalWrite(ina1,HIGH);
  digitalWrite(ina2,LOW);
  
  digitalWrite(inb1,LOW);
  digitalWrite(inb2,LOW);
   }   
        if(message[i]=='4')
    {
      Serial.println("Right");      
 digitalWrite(ina1,LOW  );
  digitalWrite(ina2,LOW);
  
  digitalWrite(inb1,HIGH);
  digitalWrite(inb2,LOW);
    }  
        }
 
  }
}
