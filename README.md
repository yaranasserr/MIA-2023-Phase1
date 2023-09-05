# MIA-2023-Phase2
# Motor Encoder Calculation

This README provides calculations for determining the rotation per second (RPS) and pulse per second (PPS) for a motor encoder with specific parameters.

## Parameters

- Pulse per rotation (PPR) = 540
- Wheel radius (R) = 0.2 meters
- Max speed (V) = 0.5 meters per second

## Calculation

To calculate the rotation per second (RPS) and pulse per second (PPS), we'll use the following equations:

1. Calculate the rotation per second (RPS):RPS = Max Speed / (2 * π * Wheel Radius)
RPS = 0.5 m/s / (2 * π * 0.2 m)
RPS ≈ 0.3979 rotations per second

2. Calculate the pulse per second (PPS):

PPS = 0.3979 RPS * 540 PPR
PPS ≈ 214.626 pulses per second
## Results

For a motor encoder with the specified parameters:

- Rotation per second (RPS) ≈ 0.3979 rotations per second
- Pulse per second (PPS) ≈ 214.626 pulses per second

Assume that the Pulse per second= cutoff frequency 
## CutOff Frequency = 214.626 Hz


