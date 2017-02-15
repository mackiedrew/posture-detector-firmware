const int xPin = A3;
const int yPin = A2;
const int zPin = A1;

const int buzzer = 2;
const int interval = 1000;

// global accelerometer data
int x = 0;
int y = 0;
int z = 0;

int avgX;
int avgY;
int avgZ;


// Read gyro data
void readGyro(){  
  x = analogRead(xPin);
  y = analogRead(yPin);
  z = analogRead(zPin);
}

void calibrate(int interval2, int samples) {
  int totalX = 0;
  int totalY = 0;
  int totalZ = 0;
  
  for(int i = 0; i < samples; i++){
    delay(interval2);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read gyro
  readGyro();
  
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
