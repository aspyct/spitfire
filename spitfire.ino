
#define INPUT_COUNT 1

int inputs[INPUT_COUNT] = {
  2
};

int states[INPUT_COUNT];

char keymap[INPUT_COUNT * 2] = {
  'd', 'g'
};

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < INPUT_COUNT; ++i) {
    pinMode(inputs[i], INPUT);
    states[i] = readState(inputs[i]);
  }
  
  // Wait for serial connection to be established
  while (!Serial);
}

int readState(int pin) {
  return digitalRead(pin);
}

void loop() {
  for (int i = 0; i < INPUT_COUNT; ++i) {
    int pin = inputs[i];
    int val = readState(pin);
    
    if (val != states[i]) {
      states[i] = val;
      Serial.print(keymap[i * 2 + val == HIGH]);
    }
  }
}
