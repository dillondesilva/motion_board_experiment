#define TRIGGER_BEAM 6
#define TRIGGER_RECEIVER 8
void setup() {
  // put your setup code here, to run once:
  
   pinMode(TRIGGER_BEAM, OUTPUT);
   pinMode(TRIGGER_RECEIVER, INPUT);
   digitalWrite(TRIGGER_BEAM, HIGH);
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int laserCalibrated = digitalRead(TRIGGER_RECEIVER);
  if (laserCalibrated == 1) {
    Serial.println("Laser is calibrated");
  } else {
    Serial.println("Please postion laser to calibrate");
  }
}
