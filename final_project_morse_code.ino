/*
Jaskarn Dhillon
Dec 15, 2022
Final Project
*/
/*
flash led to display morse code
btn 1 will be dot
btn 2 will be dash
btn 3 will be letter space
btn 4 will be word space
user can type to display morse code, and the word/s...
will be pritned back to them
*/

#define btn1 2295
#define btn2 -30601
#define btn3 18615
#define btn4 10455
#include <IRremote.h> //including infrared remote header file
int RECV_PIN = 11; // the pin where you connect the output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;
int redRGB =6;
int blueRGB=10;
int greenRGB=9;
int value = 0;
int count = 0;
int t= 200;
int incomingByte=0;
int sCount=0;
char* letter;
String code;
void setup()
{
Serial.begin(9600);
irrecv.enableIRIn();
pinMode(redRGB, OUTPUT);
pinMode(greenRGB, OUTPUT);
pinMode(blueRGB, OUTPUT);
}
void loop()
{
  //gives the user an introduction and instructions
  while(count==0){
  Serial.println("Hi, I am your Morse Code Decoder/Encoder");
  Serial.println("You have two options:");
  Serial.println("Op 1: Type a word and the led will blink in morse code");
  Serial.println("Op 2: Use the IR remote and make the led blink in morse code");
  Serial.println("btn 1=dot, btn 2=dash, btn3=letter space, btn4=word space");
  Serial.println("Begin whenever you want!");
    count=1;
  }
if (Serial.available()>0) {
incomingByte = Serial.read();//read the input
checkSerial();
}
if (irrecv.decode(&results))
{
value = results.value;
irrecv.resume();
  
   if(value == btn1){//dot
dot();
	code=code+".";//add . to the string
}
  if(value == btn2){//dash
dash();
    code=code+"-";//add dash to the string
}
  if(value == btn3){//letter space
lSpace();
}
  if(value == btn4){//word space
wSpace();   
    Serial.print(" ");//print a space 
} 
	}

  //each letter has its own ".-" string 
  //string is reset after each letter
  //each string with only print once the letter space button is clikced
  //that button is tracked with a count where the count is reset each time
  if(code==".-" && sCount==1){
    Serial.print("a");
    sCount=0;
    code="";
  } 
  if(code=="-..." && sCount==1){
    Serial.print("b");
    sCount=0;
    code="";
  } 
  if(code=="-.-." && sCount==1){
    Serial.print("c");
    sCount=0;
    code="";
  } 
  if(code=="-.." && sCount==1){
    Serial.print("d");
    sCount=0;
    code="";
  } 
  if(code=="." && sCount==1){
    Serial.print("e");
    sCount=0;
    code="";
  } 
  if(code=="..-." && sCount==1){
    Serial.print("f");
    sCount=0;
    code="";
  } 
  if(code=="--." && sCount==1){
    Serial.print("g");
    sCount=0;
    code="";
  } 
  if(code=="...." && sCount==1){
    Serial.print("h");
    sCount=0;
    code="";
  } 
  if(code==".." && sCount==1){
    Serial.print("i");
    sCount=0;
    code="";
  } 
  if(code==".---" && sCount==1){
    Serial.print("j");
    sCount=0;
    code="";
  } 
  if(code=="-.-" && sCount==1){
    Serial.print("k");
    sCount=0;
    code="";
  } 
  if(code==".-.." && sCount==1){
    Serial.print("l");
    sCount=0;
    code="";
  } 
  if(code=="--" && sCount==1){
    Serial.print("m");
    sCount=0;
    code="";
  } 
  if(code=="-." && sCount==1){
    Serial.print("n");
    sCount=0;
    code="";
  } 
  if(code=="---" && sCount==1){
    Serial.print("o");
    sCount=0;
    code="";
  } 
  if(code==".--." && sCount==1){
    Serial.print("p");
    sCount=0;
    code="";
  } 
  if(code=="--.-" && sCount==1){
    Serial.print("q");
    sCount=0;
    code="";
  } 
  if(code==".-." && sCount==1){
    Serial.print("r");
    sCount=0;
    code="";
  } 
  if(code=="..." && sCount==1){
    Serial.print("s");
    sCount=0;
    code="";
  } 
  if(code=="-" && sCount==1){
    Serial.print("t");
    sCount=0;
    code="";
  } 
  if(code=="..-" && sCount==1){
    Serial.print("u");
    sCount=0;
    code="";
  } 
  if(code=="...-" && sCount==1){
    Serial.print("v");
    sCount=0;
    code="";
  } 
  if(code==".--" && sCount==1){
    Serial.print("w");
    sCount=0;
    code="";
  } 
  if(code=="-..-" && sCount==1){
    Serial.print("x");
    sCount=0;
    code="";
  } 
  if(code=="-.--" && sCount==1){
    Serial.print("y");
    sCount=0;
    code="";
  } 
  if(code=="--.." && sCount==1){
    Serial.print("z");
    sCount=0;
    code="";
  } 
}
void dot(){
digitalWrite(redRGB, HIGH);//dot
delay(t);//1 unit
digitalWrite(redRGB, LOW);
delay(t);//1 unit
}
void dash(){
digitalWrite(redRGB, HIGH);//dot
delay(t*3);//3 units
digitalWrite(redRGB, LOW);
delay(t);//1 unit
}
void lSpace(){
digitalWrite(redRGB, LOW);
delay(t*3);//3 units
sCount++;
}
void wSpace(){
digitalWrite(redRGB, LOW);//dash
delay(t*7); //7 units
}
void checkSerial(){
if (incomingByte == 97 || incomingByte == 65) 
{fA();}//a or A == fucntion fA
if (incomingByte == 98 || incomingByte == 66) 
{fB();}//so on downwards
if (incomingByte == 99 || incomingByte == 67) 
{fC();}
if (incomingByte == 100 || incomingByte == 68) 
{fD();}
if (incomingByte == 101 || incomingByte == 69) 
{fE();}
if (incomingByte == 102 || incomingByte == 70) 
{fF();}
if (incomingByte == 103 || incomingByte == 71) 
{fG();}
if (incomingByte == 104 || incomingByte == 72) 
{fH();}
if (incomingByte == 105 || incomingByte == 73) 
{fI();}
if (incomingByte == 106 || incomingByte == 74) 
{fJ();}
if (incomingByte == 107 || incomingByte == 75) 
{fK();}
if (incomingByte == 108 || incomingByte == 76) 
{fL();}
if (incomingByte == 109 || incomingByte == 77) 
{fM();}
if (incomingByte == 110 || incomingByte == 78) 
{fN();}
if (incomingByte == 111 || incomingByte == 79) 
{fO();}
if (incomingByte == 112 || incomingByte == 80) 
{fP();}
if (incomingByte == 113 || incomingByte == 81) 
{fQ();}
if (incomingByte == 114 || incomingByte == 82) 
{fR();}
if (incomingByte == 115 || incomingByte == 83) 
{fS();}
if (incomingByte == 116 || incomingByte == 84) 
{fT();}
if (incomingByte == 117 || incomingByte == 85) 
{fU();}
if (incomingByte == 118 || incomingByte == 86) 
{fV();}
if (incomingByte == 119 || incomingByte == 87) 
{fW();}
if (incomingByte == 120 || incomingByte == 88) 
{fX();}
if (incomingByte == 121 || incomingByte == 89) 
{fY();}
if (incomingByte == 122 || incomingByte == 90) 
{fZ();}
if (incomingByte == 32)
{f_();}
//prints the letter corresponding to each letter function
//done as a check to see if the desired outcome is fulfilled 
Serial.print(letter);
}
	// functions below place a sequence of dots and dashes
	// corresponding to their letter, such as a= dot, dash
	// sets the letter varible to its corresponing letter
  void fA(){
    dot();dash();lSpace();letter="a";
  }
  void fB(){
    dash();dot();dot();dot();lSpace();letter="b";
  }
  void fC(){
    dash();dot();dash();dot();lSpace();letter="c";
  }
  void fD(){
    dash();dot();dot();lSpace();letter="d";
  }
  void fE(){
    dot();dash();lSpace();letter="e";
  }
  void fF(){
    dot();lSpace();letter="f";
  }
  void fG(){
    dot();dot();dash();dot();lSpace();letter="g";
  }
  void fH(){
    dot();dot();dot();dot();lSpace();letter="h";
  }
  void fI(){
    dot();dot();lSpace();letter="i";
  }
  void fJ(){
    dot();dash();dash();dash();lSpace();letter="j";
  }
  void fK(){
    dash();dot();dash();lSpace();letter="k";
  }
  void fL(){
    dot();dash();dot();dot();lSpace();letter="l";
  }
  void fM(){
    dash();dash();lSpace();letter="m";
  }
  void fN(){
    dash();dot();lSpace();letter="n";
  }
  void fO(){
    dash();dash();dash();lSpace();letter="o";
  }
  void fP(){
    dot();dash();dash();dot();lSpace();letter="p";
  }
  void fQ(){
    dash();dash();dot();dash();lSpace();letter="q";
  }
  void fR(){
    dot();dash();dot();lSpace();letter="r";
  }
  void fS(){
    dot();dot();dot();lSpace();letter="s";
  }
  void fT(){
    dash();lSpace();letter="t";
  }
  void fU(){
    dot();dot();dash();lSpace();letter="u";
  }
  void fV(){
    dot();dot();dot();dash();lSpace();letter="v";
  }
  void fW(){
    dot();dash();dash();lSpace();letter="w";
  }
  void fX(){
    dash();dot();dot();dash();lSpace();letter="x";
  }
  void fY(){
    dash();dot();dash();dash();lSpace();letter="y";
  }
  void fZ(){
    dash();dash();dot();dot();lSpace();letter="z";
  }
  void f_(){
    wSpace();letter=" ";
  }

  
  
