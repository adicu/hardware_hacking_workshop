int direction = -1;
int LED = 8;
#define NUMLEDS 4
int brightness[NUMLEDS];
int pause;

int PAUSEPIN = 2;
int PAUSEIRQ = 0;

void setup()
{
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 
 pause = 0;
 
 for (int i=0; i < NUMLEDS; i++) {
   brightness[i] = 0;
 }
 
 pinMode(PAUSEPIN, INPUT_PULLUP);
 attachInterrupt(PAUSEIRQ, pauseIsr, CHANGE);
}

void pauseIsr(void) {
  int val;
  
  val = digitalRead(PAUSEPIN);
  
  if (val == HIGH) {
    pause = 0;
  } else {
    pause = 1;
  }
}

void loop()
{
  int i;
  int delayTime;
  int potValue;
  
  if (pause)
    return;
  
  if(LED == 11 || LED == 8)
  {
   direction = -direction; 
  }
  
  potValue = analogRead(A0);
  delayTime = potValue / 5 + 10;
  
  delay(delayTime);
  
  for (i = 0; i < NUMLEDS; i++) {
    brightness[i] >>= 1; // divide everything by two
  }
  
  brightness[LED-8] = 255;
  
  for (i = 0; i < NUMLEDS; i++) {
    analogWrite(i + 8, brightness[i]);
  }
  
  LED += direction;
}
