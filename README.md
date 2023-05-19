# ESP32 Signal Controller

This is a program designed for the ESP32 microcontroller to control two output signals, SIGNAL_A and SIGNAL_B, based on the state of two input buttons. It uses Arduino IDE for programming.

## Description

The program has been set up to perform the following tasks:

1. Configure and initialize the input buttons and output signals.
2. Debounce the buttons using interrupts.
3. Control the SIGNAL_A and SIGNAL_B according to the state of the buttons.
4. Produce normal and modified output signals based on the button states.

## Setup and Usage

This program is intended to be used with ESP32 Devkit V1.0 and the Arduino IDE.

1. **Set up the Arduino IDE for use with the ESP32:**
   - Download and install the Arduino IDE from the [official website](https://www.arduino.cc/en/main/software).
   - Open the Arduino IDE and go to File -> Preferences.
   - In the "Additional Board Manager URLs" field, enter `https://dl.espressif.com/dl/package_esp32_index.json` and click OK.
   - Go to Tools -> Board -> Boards Manager.
   - In the Boards Manager window, search for `esp32`, then install the package.

2. **Program the ESP32 from the Arduino IDE:**
   - Connect the ESP32 Devkit V1.0 to your computer.
   - In the Arduino IDE, go to Tools -> Board and select the appropriate ESP32 variant (in this case, ESP32 Dev Module).
   - Go to Tools -> Port and select the correct port for your ESP32.
   - Open the provided code in the Arduino IDE.
   - Click the Upload button to compile the code and upload it to the ESP32.

Please note that the buttons are connected to the ESP32 pins defined as `BUTTON_1_PIN` and `BUTTON_2_PIN`, and should be connected using normally-open momentary push buttons. The SIGNAL_A and SIGNAL_B are output signals and should be connected to the devices that you want to control.
