## MPU6050 Yaw Angle Calculation

### Purpose

The purpose of this Arduino code is to interface with the MPU6050 Inertial Measurement Unit (IMU) sensor and calculate the yaw angle. The yaw angle represents the rotation around the z-axis.

### Components

- Arduino board
- MPU6050 sensor


### Key Functions and Logic

#### Initialization

- The code initializes I2C communication 
- It configures the MPU6050 by setting the power management, accelerometer configuration, and gyroscope configuration registers.
```
  // MPU6050 I2C address
const int MPU6050_ADDRESS = 0x68; //  AD0 pin is connected to GND

// MPU6050 registers
const int MPU6050_REG_GYRO_CONFIG = 0x1B;   // Gyroscope configuration register
const int MPU6050_REG_ACCEL_CONFIG = 0x1C;  // Accelerometer configuration register
const int MPU6050_REG_PWR_MGMT_1 = 0x6B;    // Power management register 1
const int MPU6050_REG_ACCEL_XOUT_H = 0x3B;  // Accelerometer X-axis data register
const int MPU6050_REG_GYRO_ZOUT_H = 0x47;    // Gyroscope Z-axis data register

int16_t gyro_z;
```

#### Main Loop

- In the main loop, the code reads raw Z-axis gyroscope data from the MPU6050 register.
- It converts the gyroscope data into angular velocity using the specified sensitivity factor (131 LSB/(degrees/s)).
- The calculated angular velocity represents the yaw rate.
- The yaw angle is printed to the serial monitor, allowing you to observe the sensor's output.
```
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
```


