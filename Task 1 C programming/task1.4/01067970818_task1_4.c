/*
 * File: task1.4
 * Author: Yara Mohamed
 * Description: C program that takes two sensor measurements (just
                two arrays) and generates only one new array measurement
                with any averaging method, such as Kalman Filter.
 * Date: 13/8/2023
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

float mpu6050[ARRAY_SIZE] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[ARRAY_SIZE] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};

float average(float a, float b, float weightA, float weightB);

int main() {

    float average(float a, float b, float weightA, float weightB)
    {
        return (weightA * a + weightB * b) / (weightA + weightB);
    }
    // Sensor accuracies
    float accuracyMpu6050 = 0.79;
    float accuracyBno55 = 0.92;

    // Weighting factors based on accuracies
    float weightMpu6050 = accuracyMpu6050 / (accuracyMpu6050 + accuracyBno55);
    float weightBno55 = accuracyBno55 / (accuracyMpu6050 + accuracyBno55);

    // Generate the new array using averaging method
    float result[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = average(mpu6050[i], bno55[i], weightMpu6050, weightBno55);
    }

    // Display the resulting array
    printf("Generated Array with Good Rating :\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%.2f ", result[i]);
    }
    printf("\n");

    return 0;
}
