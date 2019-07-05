//s表示空格，A表示字母间间隙
#include<Arduino.h>
#define ms 250
void dot()
{
  digitalWrite(13,HIGH);
  delay(ms);
  digitalWrite(13,LOW);
  delay(ms);
}
void dash()
{
  digitalWrite(13,HIGH);
  delay(ms*4);
  digitalWrite(13,LOW);
  delay(ms);
}
void cspace()
{
  digitalWrite(13,HIGH);
  delay(ms*3);
  digitalWrite(13,LOW);
  delay(ms);
}
void wspace()
{
  digitalWrite(13,HIGH);
  delay(ms*7);
  digitalWrite(13,LOW);
  delay(ms);
}
char morse[][4]={
  {'.','-'},
  {'-','.','.','.'},
  {'-','.','-','.'},
  {'-','.','.'},
  {'.'},
  {'.','.','-','.'},
  {'-','-','.'},
  {'.','.','.','.'},
  {'.','.'},
  {'.','-','-','-'},
  {'-','.','-'},
  {'.','-','.','.'},
  {'-','-'},
  {'-','.'},
  {'-','-','-'},
  {'.','-','-','.'},
  {'-','-','.','-'},
  {'.','-','.'},
  {'.','.','.'},
  {'-'},
  {'.','.','-'},
  {'.','.','.','-'},
  {'.','-','-'},
  {'-','.','.','-'},
  {'-','.','-','-'},
  {'-','-','.','.'} ,
};

String cstr="";
  String mstr="";
  int i,j,k=0,n=0;
  void setup()
  {
  pinMode(13,OUTPUT);
 Serial.begin(9600);
  }

void loop() {
  String mstr="";
  while(Serial.available()>0)
  {
    k=1;
    cstr+=char(Serial.read());
    n++;
    delay(2);
  }
 if(k)
 { 
  for(i=0;i<n;i++)
    {if(cstr[i]==' ')
          { delay(10);
            mstr+='S';
          }
     else  
      for(j=0;j<4;j++)
        {
         if(morse[int(cstr[i]-97)][j]!=0)
          mstr+=char(morse[int(cstr[i]-97)][j]);
        }
      if(cstr[i+1]) 
        mstr+='A';  
    }
   
 } 
 Serial.println(mstr);
 for(i=0;mstr[i]!='\0';i++)
 {
  if(mstr[i]=='.')        dot();
  else if(mstr[i]=='A')   wspace(); 
  else if(mstr[i]=='S')   cspace();
  else if(mstr[i]=='-')   dash();
  }
 
}
