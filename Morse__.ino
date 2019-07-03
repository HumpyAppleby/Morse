#include <Morse.h>
Morse morse(13);
int input = 0;
char LUT[26][5]={
  "*_",
  "_***",
  "_*_*",
  "_**",
  "*",
  "**_*",
  "__*",
  "****",
  "**",
  "*___",
  "_*_",
  "*_**",
  "__",
  "_*",
  "___",
  "*__*",
  "__*_",
  "*_*",
  "***",
  "_",
  "**_",
  "***_",
  "*__",
  "_**_",
  "_*__",
  "__**"
};
//根据字母在字母表中的位置控制灯输出相应Morse码
void printLetter(int dex)
{
  char* p = (*LUT)+dex;
  while(p++)
  {
    if(*p == '*')
      morse.dot();
    else
      morse.dash();
  }
  morse.c_space();
}
//根据输入的字符(字母，空格或回车)控制灯输出相应Morse码
void printChar(char c)
{
  switch(c)
  {
    case ' ':
      morse.w_space();
      break;
    case '\n':
      break;
    default:
      printLetter(c-97);
      break;
  }
}
void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  if(Serial.available()>0)
    printChar(Serial.read());
}
