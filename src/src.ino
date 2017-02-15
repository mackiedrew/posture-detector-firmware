
const int buzzer = 2;
const int interval = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer, interval); // Send 1KHz sound signal...
  delay(interval);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(interval);        // ...for 1sec
}
