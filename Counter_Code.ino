//Declaring the segment pins for the LED Display
//I had to use a bunch of analog pins because there was an issue wth some of the digital pins on my cheap knock off arduino HAHA
int a = A5;
int b = A4;
int c = A3;
int d = A2;
int e = A1;
int f = A0;
int g = 13;

//Declaring Digit Pins
int d1 = 2;
int d2 = 3;
int d3 = 4;
int d4 = 5;

//Declaring Buttons
int b1 = 7;
int b2 = 6;
int b3 = 9;
int b4 = 8;

//Creating variables for tracking CP and VP
int CP = 0;
int VP = 0;

//Setting the delay when multiplexing the LED digits
int del = 2;

//Setting Digit and Segment pins as outputs, Buttons as inputs
void setup(){
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
}

//Main loop, functions showCP(), showVP() are below!
void loop(){
  showCP(CP);
  showVP(VP);

//If I press b1, increase CP by 1
  if (digitalRead(b1)==HIGH){
    CP+=1; 
    delay(100);
  }
//If I press b2, decrease CP by 1
  else if(digitalRead(b2) ==HIGH && CP >0){
    CP-=1;
    delay(100);
  }
//If I press b3, increase VP by 1
   else if(digitalRead(b3) ==HIGH){
    VP+=1;
    delay(100);
  }
//If I press b4, decrease VP by 1
   else if(digitalRead(b4) ==HIGH && VP >0){
    VP-=1;
    delay(100);
  }

}

//This function displays the CP on the first LED display, the funcion numbah() is below!
void showCP(int x){
//  Display on first digit
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
//  The remainder of CP divided by 100 then divided by 10 (e.g. if CP=90, remainder of 91/100 = 91, 91/10 =9 (arduino auto rounds down), first digit will display 9)
  numbah((x%100)/10);
// Wait before displaying second number (The wait I programmed is 2 miliseconds, you won't be able to see it with the human eye. This allows the arduino to display more than 1 digit for us to see)
  delay(del);
// Display on second digit
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
//  The remainder of CP divided by 10(e.g. if CP=91, remainder of 91/10 = 1,second digit will display 1)
  numbah(x%10);
  delay(del);
}

//This function displays the VP on the first LED display, the funcion numbah() is below!
void showVP(int x){
  digitalWrite(d3, LOW);
  digitalWrite(d4, HIGH);
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  numbah((x%100)/10);
  delay(del);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, LOW);
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  numbah(x%10);
  delay(del);
}
//This function determines which digit pins to activate for each number (e.g. To display 0, you need to activate a,b,c,d,e,f while for 1 you only need to activate b,c)
void numbah(int x){
  if (x == 0){
  analogWrite(a, 255);
  analogWrite(b, 255);
  analogWrite(c, 255);
  analogWrite(d, 255);
  analogWrite(e, 255);
  analogWrite(f, 255);
  digitalWrite(g, LOW);
  }
  else if(x == 1){
  analogWrite(a, 0);
  analogWrite(b, 255);
  analogWrite(c, 255);
  analogWrite(d, 0);
  analogWrite(e, 0);
  analogWrite(f, 0);
  digitalWrite(g, LOW);    
  }
    else if(x == 2){
  analogWrite(a, 255);
  analogWrite(b, 255);
  analogWrite(c, 0);
  analogWrite(d, 255);
  analogWrite(e, 255);
  analogWrite(f, 0);
  digitalWrite(g, HIGH);    
  }
      else if(x == 3){
  analogWrite(a, 255);
  analogWrite(b, 255);
  analogWrite(c, 255);
  analogWrite(d, 255);
  analogWrite(e, 0);
  analogWrite(f, 0);
  digitalWrite(g, HIGH);    
  }
      else if(x == 4){
  analogWrite(a, 0);
  analogWrite(b, 255);
  analogWrite(c, 255);
  analogWrite(d, 0);
  analogWrite(e, 0);
  analogWrite(f, 255);
  digitalWrite(g, HIGH);    
  }
      else if(x == 5){
  analogWrite(a, 255);
  analogWrite(b, 0);
  analogWrite(c, 255);
  analogWrite(d, 255);
  analogWrite(e, 0);
  analogWrite(f, 255);
  digitalWrite(g, HIGH);    
  }
      else if(x == 6){
  analogWrite(a, 255);
  analogWrite(b, 0);
  analogWrite(c, 255);
  analogWrite(d, 255);
  analogWrite(e, 255);
  analogWrite(f, 255);
  digitalWrite(g, HIGH);    
  }
      else if(x == 7){
  analogWrite(a, 255);
  analogWrite(b, 255);
  analogWrite(c, 255);
  analogWrite(d, 0);
  analogWrite(e, 0);
  analogWrite(f, 0);
  digitalWrite(g, LOW);    
  }
      else if(x == 8){
  analogWrite(a, 255);
  analogWrite(b, 255);
  analogWrite(c, 255);
  analogWrite(d, 255);
  analogWrite(e, 255);
  analogWrite(f, 255);
  digitalWrite(g, HIGH);    
  }
      else if(x == 9){
  analogWrite(a, 255);
  analogWrite(b, 255);
  analogWrite(c, 255);
  analogWrite(d, 255);
  analogWrite(e, 0);
  analogWrite(f, 255);
  digitalWrite(g, HIGH);    
  }
  else if(x =999){
  analogWrite(a, 0);
  analogWrite(b, 0);
  analogWrite(c, 0);
  analogWrite(d, 0);
  analogWrite(e, 0);
  analogWrite(f, 0);
  digitalWrite(g, HIGH);
  }
}
