//controlling 3 stepping motor controller
//must setting new (int totalswitch)
//char totalswitch = a ~ c (1 stepping) d, e, f(1-2), (2-3), (1-3) g(1-2-3)
//stepset() -> setting pulse -> end

#define ENA1    5
#define DIR1    6
#define STEP1   7
#define ENA2    8
#define DIR2    9//for direction
#define STEP2   10//for step signal
#define ENA3    11
#define DIR3    12
#define STEP3   13

#define limitrpm 870

char ch;
int count;
//steps, rpm, max, acc
int totalswitch;
//setting 3stepping motors (steps, pulse, maxpulse, acc, onoff)
int vstep1[4] = {110, 900, 470, 0, 0};
int vstep2[4];
int vstep3[4];

void setup() {
    Serial.begin(115200);
    pinMode(ENA1, OUTPUT);
    pinMode(STEP1, OUTPUT);
    pinMode(DIR1, OUTPUT);
    pinMode(ENA2, OUTPUT);
    pinMode(STEP2, OUTPUT);
    pinMode(DIR2, OUTPUT);
    pinMode(ENA3, OUTPUT);
    pinMode(STEP3, OUTPUT);
    pinMode(DIR3, OUTPUT);
    //stepper off
    digitalWrite(ENA1, HIGH);
    digitalWrite(DIR1, HIGH);
    digitalWrite(ENA2, HIGH);
    digitalWrite(DIR2, HIGH);
    digitalWrite(ENA3, HIGH);
    digitalWrite(DIR3, HIGH);
    }


void loop() {
  if (Serial.available() > 0) {
    ch = Serial.read();
    if (48 <= ch && ch <= 57) {
      stepset();
    } else {
      digitalWrite(ENA1, LOW);
      digitalWrite(ENA2, LOW);
      digitalWrite(ENA2, LOW);
      charconverter();
      stepmov();
    }
  // else { analog.read(potentiometer)) <- calculating status
}}

//to give a total switch values
void charconverter() {
  if (ch == 'q') {
    vstep[0] = 110;
  } else if (ch == 'w') {
    vstep[0] = 30;
  } else if (ch == 'e') {
    vstep[0] = 2;
  } else if (ch == 'r') {
    vstep[0] = 50;
  } else if (ch == 't') {
  } else if (ch == 'u') {
    vstep[0] = 110;
  } else if (ch == 'i') {
    vstep[0] = 20;
  } else if (ch == 'o') {
    vstep[0] = 20;
  } else if (ch == 'p') {
    vstep[0] = 20;
  } else if (ch == 'a') {
    vstep[0] = 20;
  } else if (ch == 's') {
    vstep[0] = 20;
  }
}

void stepset() {
  if (ch == '0') {
    digitalWrite(DIR, LOW);
    vstep[3] = 0;
  } else if(ch == '1') {
    vstep[3] = 1;
  } else if ( ch == '2') {
    vstep[3] = 2;
  } else if (ch == '3') {
    vstep[3] = 3;
  } else if (ch == '4') {
    vstep[3] = 4;
  } else if (ch == '5') {
    digitalWrite(DIR, HIGH);
    vstep[3] = 0;
  } else if (ch == '6') {
    vstep[3] = -1;
  } else if (ch == '7') {
    vstep[3] = -2;
  } else if (ch == '8') {
    vstep[3] = -3;
  } else if (ch == '9') {
    vstep[3] = -4;
  }    
}

void  stepmov() {    
  if (vstep[0] <= 1) {
    vstep[0] = 2;
  }
   for (count = 0; count < vstep[0]; count++) {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(vstep[1]);
    digitalWrite(STEP, LOW);
    pulseset()
  }
  Serial.println(vstep[1]);
  digitalWrite(ENA1, HIGH);
  digitalWrite(ENA2, HIGH);
  digitalWrite(ENA3, HIGH);
}

void pulseset() {
    if (vstep[1] >= vstep[2]) {
        vstep[1] = vstep[1] - vstep[3];
    } else {
        vstep[1] = vstep[2];
    }
}
