#include <Wire.h>

// MPU6050 I2C address
const int MPU6050_ADDRESS = 0x68; //  AD0 pin is connected to GND

// MPU6050 registers
const int MPU6050_REG_GYRO_CONFIG = 0x1B;   // Gyroscope configuration register
const int MPU6050_REG_ACCEL_CONFIG = 0x1C;  // Accelerometer configuration register
const int MPU6050_REG_PWR_MGMT_1 = 0x6B;    // Power management register 1
const int MPU6050_REG_ACCEL_XOUT_H = 0x3B;  // Accelerometer X-axis data register
const int MPU6050_REG_GYRO_ZOUT_H = 0x47;    // Gyroscope Z-axis data register

int16_t gyro_z;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Initialize MPU6050 WITH IC2 COMMUNICATION
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(MPU6050_REG_PWR_MGMT_1); 
  Wire.write(0); 
  Wire.endTransmission();
  
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(MPU6050_REG_ACCEL_CONFIG); // Select the accelerometer configuration register
  Wire.write(0); // Set full-scale range for accelerometer to +/- 2g
  Wire.endTransmission();
  
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(MPU6050_REG_GYRO_CONFIG); // Select the gyroscope configuration register
  Wire.write(0); // Set full-scale range for gyroscope to +/- 250 degrees/s
  Wire.endTransmission();
}

void loop() {
  // Read gyroscope data (Z-axis)
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(MPU6050_REG_GYRO_ZOUT_H); // Start with register for Gyroscope Z-axis data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS, 2, true);

  gyro_z = Wire.read() << 8 | Wire.read();

  // Calculate yaw angle (angle along z-axis)
  float angular_velocity = gyro_z / 131.0; // 131 LSB/(degrees/s) for the specified gyro configuration

  Serial.print("Yaw Angle: ");
  Serial.println(angular_velocity);

  delay(100); 
}
