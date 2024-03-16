#include <Arduino.h>

#define STRING_1 40
#define STRING_2 42
#define STRING_3 43
#define STRING_4 44
#define STRING_5 45
#define STRING_6 46

int frets_n = 5;
int frets[5] = {2, 3, 4, 5, 6};

void setup() {
  Serial.begin(115200);

  pinMode(STRING_1, OUTPUT);
  pinMode(STRING_2, OUTPUT);
  pinMode(STRING_3, OUTPUT);
  pinMode(STRING_4, OUTPUT);
  pinMode(STRING_5, OUTPUT);
  pinMode(STRING_6, OUTPUT);

  for (int fret = 0; fret < frets_n; fret++) {
    pinMode(frets[fret], INPUT_PULLUP);
  }
}

void print(int fret, int x) {
  Serial.print("Fret");
  Serial.print(fret);
  Serial.print(": ");
  Serial.print(x);
  Serial.print("    \n");
}
void loop() {
  digitalWrite(STRING_1, LOW);
  Serial.print("\033[0;0H");
  Serial.print("            \n");
  for (int fret = 0; fret < frets_n; fret++) {
    int x = digitalRead(frets[fret]);
    print(fret, x);
  }
  Serial.print("            \n");
  Serial.flush();
}
