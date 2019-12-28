void forward()
{ 
  Serial.println("Forward");
  digitalWrite(ina1,HIGH);
  digitalWrite(ina2,LOW);
  digitalWrite(inb1,HIGH);
  digitalWrite(inb2,LOW);

}

void left()
{
  Serial.println("Left");
  digitalWrite(ina1,HIGH);
  digitalWrite(ina2,LOW);
  digitalWrite(inb1,LOW);
  digitalWrite(inb2,LOW);
}

void right()
{
  Serial.println("Right");
  digitalWrite(ina1,LOW);
  digitalWrite(ina2,LOW);
  digitalWrite(inb1,HIGH);
  digitalWrite(inb2,LOW);

}

void back()
{
  Serial.println("Back");
  digitalWrite(ina1,LOW);
  digitalWrite(ina2,HIGH);
  digitalWrite(inb1,LOW);
  digitalWrite(inb2,HIGH);
  
}

void halt()
{
  Serial.println("Stop");
  digitalWrite(ina1,LOW);
  digitalWrite(ina2,LOW);
  digitalWrite(inb1,LOW);
  digitalWrite(inb2,LOW);
        
}
