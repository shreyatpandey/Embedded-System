long us1()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  time=pulseIn(echo1,HIGH);
  return (microsecondsToCentimeters(time));
}

long us2()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  time=pulseIn(echo2,HIGH);
  return (microsecondsToCentimeters(time));
}

long us3()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  time=pulseIn(echo3,HIGH);
  return (microsecondsToCentimeters(time));
}

long us4()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  time=pulseIn(echo4,HIGH);
  return (microsecondsToCentimeters(time));
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
