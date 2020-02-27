// Trigger bool setup
bool isTriggered = false;

// Timing setup
unsigned long initTime;
unsigned long completionTime;
unsigned long elapsedTime;

// Beam and receiver setup
#define TRIGGER_BEAM 6
#define TERMINAL_BEAM 7
#define TRIGGER_RECEIVER 8
#define TERMINAL_RECEIVER 10

void setup() {
  pinMode(TRIGGER_BEAM, OUTPUT);
  pinMode(TERMINAL_BEAM, OUTPUT);

  pinMode(TRIGGER_RECEIVER, INPUT);
  pinMode(TERMINAL_RECEIVER, INPUT);
  
  // Initialize beams as activated
  digitalWrite(TRIGGER_BEAM, HIGH);
  digitalWrite(TERMINAL_BEAM, HIGH);

  initTime = 0;
  completionTime = 0;
  elapsedTime = 0;

  Serial.begin(9600);
}

void loop() {
  // If the beam hasn't been triggered, program
  // should keep looking for it to be cut
  if (!isTriggered) {
    int beamTriggerStatus = digitalRead(TRIGGER_RECEIVER);

    if (beamTriggerStatus == 0) {
      initTime = millis();
      isTriggered = true;
      Serial.println("Beam Broken");
    }
  } else {
    int experimentTerminateStatus = digitalRead(TERMINAL_RECEIVER);

    if (experimentTerminateStatus == 0) {
      completionTime = millis();   
      elapsedTime = completionTime - initTime;
      Serial.println("Elapsed Time:");
      Serial.println(elapsedTime);
    }
  }
}
