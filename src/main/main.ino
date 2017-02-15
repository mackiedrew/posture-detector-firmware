const int xPin = A3;
const int yPin = A2;
const int zPin = A1;

const int buzzer = 2;
const int interval = 1000;

int x = 0;
int y = 0;
int z = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read gyro data
  x = analogRead(xPin);
  y = analogRead(yPin);
  z = analogRead(zPin);
  
  // Output gyro data
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("; Y: ");
  Serial.print(y);
  Serial.print("; Z: ");
  Serial.print(z);
  Serial.println(";");

  // Buzzer Controller
  tone(buzzer, 1000);
  delay(interval);
  noTone(buzzer);
  delay(interval);
}
