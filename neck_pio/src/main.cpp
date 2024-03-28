#include <Arduino.h>

bool neck[6][24] = {{0}};

int current_string = 0;
int strings_n = 6;
int strings[6] = {40, 41, 42, 43, 44, 45};

int frets_n = 5;
int frets[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  Serial.begin(115200);

  for (int string = 0; string < strings_n; string++) {
    pinMode(strings[string], OUTPUT);
    digitalWrite(strings[string], HIGH);
  }

  for (int fret = 0; fret < frets_n; fret++) {
    pinMode(frets[fret], INPUT_PULLUP);
    digitalWrite(frets[fret], HIGH);
  }
}

void debug(int string, int fret, int value) {
  Serial.print("Changed: ");
  Serial.print("String: ");
  Serial.print(string);
  Serial.print(" Fret: ");
  Serial.print(fret);
  Serial.print(" Value: ");
  Serial.print(value);
  Serial.print("\n");
  Serial.flush();
}

void changed(int string, int fret, int value) {
  // notify somehow
  debug(string, fret, value);
}

void check_string(int string) {
  digitalWrite(strings[string], LOW);
  for (int fret = 0; fret < frets_n; fret++) {
    int x = !digitalRead(frets[fret]);
    if (x != neck[string][fret]) {
      changed(string, fret, x);
      neck[string][fret] = x;
    }
  }
  digitalWrite(strings[string], HIGH);
}

void loop() {
  check_string(current_string);
  current_string = (current_string + 1) % strings_n;
}
