const int xPin = A3;
const int yPin = A2;
const int zPin = A1;

const int buzzer = 2;
const int range = 20;

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

void calibrate(int sampleRate, int samples) {
  Serial.println("Calibrating your posture, sit up!");
  int totalX = 0;
  int totalY = 0;
  int totalZ = 0;
  
  for(int i = 0; i < samples; i++){
    Serial.println(i);
    readGyro();
    totalX += x;
    totalY += y;
    totalZ += z;
    delay(sampleRate);
  }
a
  avgX = totalX / samples;
  avgY = totalY / samples;
  avgZ = totalZ / samples;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  calibrate(2000, 5);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read gyro
  readGyro();
  
  // Output gyro data
  Serial.print("X: ");
  Serial.print(x - avgX);
  Serial.print("; Y: ");
  Serial.print(y - avgY);
  Serial.print("; Z: ");
  Serial.print(z - avgZ);
  Serial.println(";");

  // Buzzer Controller
  if (abs(z - avgZ) > range){
    tone(buzzer, 1000);
  } else {
    noTone(buzzer);
  }
}
