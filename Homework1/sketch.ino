// Ahmet Furkan Demir
// 1901 001 1019

#include <Wire.h>
#include <MPU6050.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
MPU6050 mpu;
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Wire.begin(21, 22);
  Serial.begin(9600);
  mpu.initialize();
  mpu.setSleepEnabled(false);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
}

void loop() {
  int16_t temperature = mpu.getTemperature();
  float totalyTemperature = (temperature / 340.00) + 36.53;
  Serial.println("Accelerometer - m/s^2");
  Serial.print(mpu.getAccelerationX());
  Serial.print(", ");
  Serial.print(mpu.getAccelerationY());
  Serial.print(", ");
  Serial.println(mpu.getAccelerationZ());
  Serial.println("Gyroscope - rps");
  Serial.print(mpu.getRotationX());
  Serial.print(", ");
  Serial.print(mpu.getRotationY());
  Serial.print(", ");
  Serial.println(mpu.getRotationZ());
  Serial.println("Temperature: ");
  Serial.print(totalyTemperature);
  Serial.println(" degC");
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Accelerometer - m/s^2");
  display.setCursor(0, 8);
  display.print(mpu.getAccelerationX());
  display.print(',');
  display.setCursor(40, 8);
  display.print(mpu.getAccelerationY());
  display.print(',');
  display.setCursor(80, 8);
  display.print(mpu.getAccelerationZ());
  display.setCursor(0, 22);
  display.print("Gyroscope - rps");
  display.setCursor(0, 32);
  display.print(mpu.getRotationX());
  display.print(',');
  display.setCursor(40, 32);
  display.print(mpu.getRotationY());
  display.print(',');
  display.setCursor(80, 32);
  display.print(mpu.getRotationZ());
  display.setCursor(0, 45);
  display.print("Temperature:");
  display.setCursor(0, 55);
  display.print(totalyTemperature, 2);
  display.print(" degC");
  display.display();
  delay(1000);
}