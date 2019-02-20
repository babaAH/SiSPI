#define red 2
int water;

void setup() {
  pinMode(A0,INPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  water = (analogRead(A0));
  Serial.println(water);
  if(water >= 250)
  {
    digitalWrite(red, HIGH);
  }
  if(water <= 250)
  {
    digitalWrite(red, LOW);
  }
}
