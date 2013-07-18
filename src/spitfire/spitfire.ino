/*
 * Spitfire board is a plane simulation control board
 * Copyright (C) 2013  Antoine d'Otreppe de Bouvette
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see [http://www.gnu.org/licenses/].
 */

#define INPUT_COUNT 2
#define TIMEGUARD 100 // numper of milliseconds before a new input is taken into account

int inputs[INPUT_COUNT] = {
  2,
  6
};

int states[INPUT_COUNT];

char keymap[INPUT_COUNT * 2] = {
  'd', 'g',
  '6', '\0'
};

unsigned long fired[INPUT_COUNT];

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < INPUT_COUNT; ++i) {
    pinMode(inputs[i], INPUT);
    states[i] = readState(inputs[i]);
    fired[i] = 0;
  }
  
  // Wait for serial connection to be established
  while (!Serial);
}

int readState(int pin) {
  return digitalRead(pin);
}

void loop() {
  for (int i = 0; i < INPUT_COUNT; ++i) {
    unsigned long time = millis();
    
    int pin = inputs[i];
    int val = readState(pin);
    
    if (val != states[i] && time - fired[i] > TIMEGUARD) {
      states[i] = val;
      fired[i] = time;
      
      char response = keymap[i * 2 + (val == HIGH)];
      if (response) {
        Serial.print(response);
      }
    }
  }
}
