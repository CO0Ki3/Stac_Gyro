#include "Wire.h"
#include "I2Cdev.h"
#include "MPU9250.h"
MPU9250 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;
float Axyz[3];
void setup() {
  Wire.begin();
  Serial.begin(9600);
  accelgyro.initialize();
  delay(1000);
}
void loop() {
  accelgyro.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
  Axyz[0] = (double) ax / 16384;
  Axyz[1] = (double) ay / 16384;
  Axyz[2] = (double) az / 16384;
  int x = Axyz[0]*100;
  int y = Axyz[1]*100;
  int z = Axyz[2]*100;
  Serial.print("X : ");
  Serial.println(x);
  Serial.print("Y : ");
  Serial.println(y);
  Serial.print("Z : ");
  Serial.println(z);
  Serial.println();
  delay(1000);
}
