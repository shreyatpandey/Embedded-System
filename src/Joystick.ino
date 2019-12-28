void joystick()
{
  if(analogRead(y)>900)
    right();
    else if(analogRead(y)<100)
    left();
    else if(analogRead(x)<100)
    back();
    else if(analogRead(x)>900)
    forward();
    else
    halt();
}
