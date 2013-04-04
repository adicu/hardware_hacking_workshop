int direction = -1;
int LED = 8;

void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  int i;
  
  if(LED == 11 || LED == 8)
  {
   direction = -direction; 
  }
  delay(100);
  
  digitalWrite(LED, LOW);
  
  LED += direction;
  
  digitalWrite(LED, HIGH);
  
}
