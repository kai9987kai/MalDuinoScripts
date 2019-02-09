/*
Copyright (c) 2017 Seytonic, Spacehuhn (Licensed under MIT)
For more information see: github.com/seytonic/malduino
*/

#include "Keyboard.h"
#include "Mouse.h"

#define blinkInterval 50
#define ledPin 3
#define buttonPin 6

int defaultDelay = 4;
int defaultCharDelay = 5;
int rMin = 0;
int rMax = 100;

bool ledOn = true;

void typeKey(int key){
  Keyboard.press(key);
  delay(defaultCharDelay);
  Keyboard.release(key);
}

void setup(){
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  if(digitalRead(buttonPin) == LOW){
    
    Keyboard.begin();
    Mouse.begin();
    
    /* ----- Begin-Script -----*/
    
    /* [Parsed By Duckuino (Licensed under MIT) - for more information visit: https://github.com/Nurrl/Dckuino.js] */    
    delay(1250);

    delay(defaultDelay);
    while(1){
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
    Keyboard.press(KEY_F2);
    Keyboard.press(KEY_F1);
    Keyboard.press(KEY_F3);
    Keyboard.press(KEY_F5);
    Keyboard.press(KEY_F6);
    Keyboard.press(KEY_F7);
    Keyboard.press(KEY_F8);
    Keyboard.press(KEY_F9);
    Keyboard.press(KEY_F10);
    Keyboard.press(KEY_F11);
    Keyboard.press(KEY_F12);
    Keyboard.press(KEY_F11);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(114);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.print("q");
    Keyboard.print("w");
    Keyboard.print("e");
    Keyboard.print("r");
    Keyboard.print("t");
    Keyboard.print("y");
    Keyboard.print("u");
    Keyboard.print("i");
    Keyboard.print("o");
    Keyboard.print("p");
    Keyboard.print("[");
    Keyboard.print("{");
    Keyboard.print("}");
    Keyboard.print("]");
    Keyboard.print("a");
    Keyboard.print("s");
    Keyboard.print("d");
    Keyboard.print("f");
    Keyboard.print("g");
    Keyboard.print("h");
    Keyboard.print("j");
    Keyboard.print("k");
    Keyboard.print("l");
    Keyboard.print(";");
    Keyboard.print(":");
    Keyboard.print("'");
    Keyboard.print("@");
    Keyboard.print("~");
    Keyboard.print("#");
    Keyboard.print("\"");
    Keyboard.print("|");
    Keyboard.print("z");
    Keyboard.print("x");
    Keyboard.print("c");
    Keyboard.print("v");
    Keyboard.print("b");
    Keyboard.print("n");
    Keyboard.print("m");
    Keyboard.print("<");
    Keyboard.print(">");
    Keyboard.print("?");
    Keyboard.print("/");
    Keyboard.print("1");
    Keyboard.print("2");
    Keyboard.print("3");
    Keyboard.print("4");
    Keyboard.print("5");
    Keyboard.print("6");
    Keyboard.print("7");
    Keyboard.print("8");
    Keyboard.print("9");
    Keyboard.print("0");
    Keyboard.print("!");
    Keyboard.print("""");
    Keyboard.print("£");
    Keyboard.print("$");
    Keyboard.print("%");
    Keyboard.print("^");
    Keyboard.print("&");
    Keyboard.print("*");
    Keyboard.print("(");
    Keyboard.print(")");
    Keyboard.print("_");
    Keyboard.print("-");
    Keyboard.print("=");
    Keyboard.print("+");
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press(KEY_RIGHT_GUI);
    Keyboard.press(KEY_RIGHT_GUI);
    Keyboard.press(KEY_RIGHT_GUI);
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.press(KEY_BACKSPACE);
    Keyboard.press(KEY_RETURN);
    Keyboard.press(KEY_TAB);
    Keyboard.press(KEY_ESC);
    Keyboard.press(KEY_INSERT);
    Keyboard.press(KEY_DELETE);
    Keyboard.press(KEY_PAGE_UP);
    Keyboard.press(KEY_PAGE_DOWN);
    Keyboard.press(KEY_HOME);
    Keyboard.press(KEY_END);
    Keyboard.press(KEY_CAPS_LOCK);


    


    
    
    Keyboard.releaseAll();
    };
    /* ----- End-Script -----*/
    
    Keyboard.end();
  }
}

void loop(){
  ledOn = !ledOn;
  digitalWrite(ledPin, ledOn);
  delay(blinkInterval);
}
