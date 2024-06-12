# DIY Handheld Battery Monitor

This README provides instructions and information about the battery monitoring system implemented in a DIY handheld device. The system utilizes the SPI interface for communicating battery status in real-time.

## Overview

The system measures the voltage level of the battery connected to an analog pin on a microcontroller and sends this data over SPI to a host device. This setup is intended for use in low-power, real-time applications such as a handheld gaming device or portable instrument.

## Features

- **Real-Time Battery Monitoring**: Measures battery voltage in real-time and sends it via SPI.
- **Interrupt-Driven Communication**: Utilizes the SPI interrupt to handle data transmission seamlessly in the background.
- **Simple and Efficient**: Runs an empty loop in the main program while handling all data communication in the interrupt service routine, optimizing power consumption.

## Hardware Requirements

- Any compatible microcontroller with SPI support and an ADC (Analog to Digital Converter).
- Battery connected to an ADC capable pin (in this example, `A2`).

## Software Setup

1. **Configure the microcontroller**:
   - Set up the SPI communication by configuring the `MISO` pin as output.
   - Enable SPI and SPI interrupt in the setup to allow asynchronous data handling.

2. **Voltage Reading and Calibration**:
   - Adjust the `analogRead(batteryPin)-440)/2` formula based on your battery's voltage range and the reference voltage of your ADC for accurate readings.

## Installation

1. **Upload the provided code** to your microcontroller using your preferred IDE (e.g., Arduino IDE).
2. **Connect the battery** to the specified analog pin (`A2`).
3. **Connect the SPI lines** (MISO, MOSI, SCK, SS) to your host device if necessary.

## Usage

Once the setup is complete and the code is running:
- The microcontroller will automatically read the battery voltage and output it over SPI whenever a transmission is completed.
- The host device can continuously receive battery status without polling, reducing the processing overhead.

## Limitations

- The code does not include error handling or power-saving modes, which may be necessary for battery-operated devices.
- Calibration is crucial for accurate readings; ensure that the voltage divider and reference voltage are correctly set up for your specific battery and microcontroller.

## License

This software is provided "as is", without warranty of any kind. Use at your own risk.
