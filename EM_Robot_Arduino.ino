#include <Servo.h>

const int K_BACKSPACE = 8;
const int K_TAB = 9;
const int K_RETURN = 13;
const int K_PAUSE = 19;
const int K_ESCAPE = 27;
const int K_SPACE = 32;
const int K_EXCLAIM = 49;
const int K_QUOTEDBL = 39;
const int K_HASH = 51;
const int K_DOLLAR = 52;
const int K_AMPERSAND = 55;
const int K_QUOTE = 39;
const int K_LEFTPAREN = 57;
const int K_RIGHTPAREN = 48;
const int K_ASTERISK = 56;
const int K_PLUS = 61;
const int K_COMMA = 44;
const int K_MINUS = 45;
const int K_PERIOD = 46;
const int K_SLASH = 47;
const int K_0 = 48;
const int K_1 = 49;
const int K_2 = 50;
const int K_3 = 51;
const int K_4 = 52;
const int K_5 = 53;
const int K_6 = 54;
const int K_7 = 55;
const int K_8 = 56;
const int K_9 = 57;
const int K_COLON = 59;
const int K_SEMICOLON = 59;
const int K_LESS = 44;
const int K_EQUALS = 61;
const int K_GREATER = 46;
const int K_QUESTION = 47;
const int K_AT = 50;
const int K_LEFTBRACKET = 91;
const int K_BACKSLASH = 92;
const int K_RIGHTBRACKET = 93;
const int K_CARET = 54;
const int K_UNDERSCORE = 45;
const int K_BACKQUOTE = 96;
const int K_a = 97;
const int K_b = 98;
const int K_c = 99;
const int K_d = 100;
const int K_e = 101;
const int K_f = 102;
const int K_g = 103;
const int K_h = 104;
const int K_i = 105;
const int K_j = 106;
const int K_k = 107;
const int K_l = 108;
const int K_m = 109;
const int K_n = 110;
const int K_o = 111;
const int K_p = 112;
const int K_q = 113;
const int K_r = 114;
const int K_s = 115;
const int K_t = 116;
const int K_u = 117;
const int K_v = 118;
const int K_w = 119;
const int K_x = 120;
const int K_y = 121;
const int K_z = 122;
const int K_DELETE = 127;
const int K_KP0 = 256;
const int K_KP1 = 257;
const int K_KP2 = 258;
const int K_KP3 = 259;
const int K_KP4 = 260;
const int K_KP5 = 261;
const int K_KP6 = 262;
const int K_KP7 = 263;
const int K_KP8 = 264;
const int K_KP9 = 265;
const int K_KP_PERIOD = 266;
const int K_KP_DIVIDE = 267;
const int K_KP_MULTIPLY = 268;
const int K_KP_MINUS = 269;
const int K_KP_PLUS = 270;
const int K_KP_ENTER = 271;
const int K_UP = 273;
const int K_DOWN = 274;
const int K_RIGHT = 275;
const int K_LEFT = 276;
const int K_INSERT = 277;
const int K_HOME = 278;
const int K_END = 279;
const int K_PAGEUP = 280;
const int K_PAGEDOWN = 281;
const int K_F1 = 282;
const int K_F2 = 283;
const int K_F3 = 284;
const int K_F4 = 285;
const int K_F5 = 286;
const int K_F6 = 287;
const int K_F7 = 288;
const int K_F8 = 289;
const int K_F9 = 290;
const int K_F10 = 291;
const int K_F11 = 292;
const int K_F12 = 293;
const int K_NUMLOCK = 300;
const int K_CAPSLOCK = 301;
const int K_SCROLLOCK = 302;
const int K_RSHIFT = 303;
const int K_LSHIFT = 304;
const int K_RCTRL = 305;
const int K_LCTRL = 306;
const int K_RALT = 307;
const int K_LALT = 308;
const int K_RMETA = 319;
const int K_LMETA = 311;
const int K_PRINT = 316;


bool curKeys[316];

const float TIME_PER_DEGREE = 1000.0 * 2.631 / 180.0 * 0.7;

const int LED_PS = 13;
const int leftServo = 11;
const int rightServo = 12;
const int pin1 = 2;
const int pin2 = 4;
const int pwm1 = 3;
const int pin3 = 6;
const int pin4 = 7;
const int pwm2 = 5;
const int energize = 10;
//io 8 energizing

Servo servoLeft;
Servo servoRight;

void setup()
{
  servoLeft.attach(leftServo);
  servoRight.attach(rightServo);
  servoLeft.write(55);
  servoRight.write(100);
  // put your setup code here, to run once:
  for (int i = 0; i < 316; i++)
  {
    curKeys[i] = false;
  }

  //setup our pins
  pinMode(LED_PS, OUTPUT);      // sets the digital pin as output
  pinMode(leftServo, OUTPUT);

  //begin serial communication
  Serial.begin(9600);
  Serial.println("Initialized arduino and serial communication");

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pwm1, OUTPUT);

  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pwm2, OUTPUT);

  pinMode(energize, OUTPUT);
}

int readline(int readch, char *buffer, int len)
{
  static int pos = 0;
  int rpos;

  if (readch > 0)
  {
    switch (readch)
    {
      case '\n': // Ignore new-lines
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos; //line is complete
      case '\r': // Return on CR
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos; //line is complete
      default:
        if (pos < len - 1)
        {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }//end if checking overflow
    }//do different things depending on character
  }//if there is data

  // No end of line has been found, so return -1.
  return 0;
}

int readSerial()
{
  int currentValue = -1;
  char curText[255];

  if (readline(Serial.read(), curText, 255) > 0) {
    //This converts the read value to an integer
    currentValue = atoi(curText);
  }//end read of next keypress event

  if (currentValue != -1)
  {
    Serial.print("Received:");
    Serial.print(curText);
    Serial.print(" Read as :");
    Serial.println(currentValue);
  }
  return currentValue;
}

//Note: this isn't handling shift key holding
void processKeyDown(int keyCode)
{
  if (!curKeys[keyCode])
  {
    curKeys[keyCode] = true; //This was the first time it was pressed

    if (keyCode == K_SPACE)
    {
      digitalWrite(LED_PS, HIGH); //LED ON
      Serial.println("LED ON");
    }
    else if (keyCode == K_z) //122
    {
      Serial.println("Servo arm DOWN"); //Move both servo arms down
      for (int i = 0; i <= 70; i++)
      {
        servoLeft.write(i + 55);
        servoRight.write(100 - i);
        delay(15);
      }
    }
    else if (keyCode == K_LEFT) //276
    {
      Serial.println("Robot move LEFT"); //Move robot left
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      analogWrite(pwm1, 255);

      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
      analogWrite(pwm2, 255);
    }
    else if (keyCode == K_RIGHT) //275
    {
      Serial.println("Robot move RIGHT"); //Move robot right
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      analogWrite(pwm1, 255);

      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
      analogWrite(pwm2, 255);
    }
    else if (keyCode == K_UP) //273
    {
      Serial.println("Robot move Forward"); //Move robot forward
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      analogWrite(pwm1, 255);

      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
      analogWrite(pwm2, 255);
    }
    else if (keyCode == K_DOWN) //274
    {
      Serial.println("Robot move Forward"); //Move robot backward
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      analogWrite(pwm1, 255);

      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
      analogWrite(pwm2, 255);
    }
    else if (keyCode == K_c) //99
    {
      Serial.println("Robot arms are De-Energized"); //De-Energyize arms
      digitalWrite(energize, HIGH);
    }
  }
}
//Note: this isn't handling shift key holding
void processKeyUp(int keyCode)
{
  if (curKeys[keyCode])
  {
    // the key is released
    curKeys[keyCode] = false;

    if (keyCode == K_SPACE)//32
    {
      digitalWrite(LED_PS, LOW);   // Turn led off
      Serial.println("Turning LED OFF");
    }
    else if (keyCode == K_z) //122
    {
      Serial.println("Servo arm UP"); //Move both servo arms up
      for (int i = 0; i <= 70; i++)
      {
        servoLeft.write(125 - i);
        servoRight.write(i + 30);
        delay(15);
      }
    }
    else if (keyCode == K_LEFT) //276
    {
      Serial.println("Robot STOP"); //Stop robot
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      analogWrite(pwm1, 255);

      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      analogWrite(pwm2, 255);
    }
    else if (keyCode == K_RIGHT) //275
    {
      Serial.println("Robot STOP"); //Stop robot
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      analogWrite(pwm1, 255);

      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      analogWrite(pwm2, 255);
    }
    else if (keyCode == K_UP) //273
    {
      Serial.println("Robot STOP"); //Stop robot
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      analogWrite(pwm1, 255);

      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      analogWrite(pwm2, 255);
    }
    else if (keyCode == K_DOWN) //274
    {
      Serial.println("Robot STOP"); //Stop robot
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      analogWrite(pwm1, 255);

      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      analogWrite(pwm2, 255);
    }
    else if (keyCode == K_c) //99
    {
      Serial.println("Robot arms are energized"); //energyize arms
      digitalWrite(energize, LOW);
    }
  }
}

void processKeyHeld()
{
  //check the curKeysArray to see if a key is pressed
}

void loop()
{
  //Read serial keypress
  int curKeyCode = readSerial();

  if (curKeyCode > 0 && curKeyCode < 317)
  {
    //only process keydown or keyup when a key is toggled
    // these seem likely to be where most of your code will go
    if (!curKeys[curKeyCode])
    {
      //Key is freshly pressed
      processKeyDown(curKeyCode);
    }
    else
    {
      //Key was already pressed
      processKeyUp(curKeyCode);
    }
  }

  //inside processKeyHeld you can trigger another event based on keystate
  processKeyHeld();
}
