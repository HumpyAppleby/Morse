void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
 
}
int income;
void loop()
{
  if(Serial.available()>0)
  {
    delay(10);
    income=Serial.read()-'0';
    digitalWrite(12,LOW);
    delay(10);
    if(income&0x01){
      digitalWrite(7,HIGH);
    }
    else
    {
        digitalWrite(7,LOW);

    }
    if((income>>1)&0x01){
      digitalWrite(2,HIGH);
    }else{
        digitalWrite(2,LOW);

    }
    if((income>>2)&0x01){
      digitalWrite(8,HIGH);
    }else{
        digitalWrite(8,LOW);

    }
    if((income>>3)&0x01)
    {
      digitalWrite(4,HIGH);
    }
    else
    {
        digitalWrite(4,LOW);
    }
    delay(10);
    digitalWrite(12,HIGH);
  delay(5);

  }
}