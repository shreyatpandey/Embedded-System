void sw1()
{
  long d=0;
  while(digitalRead(sw)==0)
  {
      d++;
      if(d>300000)
      {
        digitalWrite(buzzer,HIGH);
        delay(500);
        digitalWrite(buzzer,LOW);
        break;
      }
      
  }
  Serial.println(d);
  if(d>300000)
 toggle=~toggle;
}
