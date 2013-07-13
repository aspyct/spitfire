#define INPUT_COUNT 1
#define TIMEGUARD 100 // numper of milliseconds before a new input is taken into account

int inputs[INPUT_COUNT] = {
  2
};

int states[INPUT_COUNT];

char keymap[INPUT_COUNT * 2] = {
  'd', 'g'
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
      Serial.print(keymap[i * 2 + val == HIGH]);
    }
  }
}
