# EvilAppleJuice-nRF52

## Overview
This project is a direct hardware port of the EvilAppleJuice BLE spoofing and proximity pairing tool, rebuilt from the ground up for the nRF52840 microcontroller. By utilizing the Adafruit Bluefruit library, this version interacts directly with the Nordic hardware HAL, completely dropping the bloated ESP32 BLE wrappers for maximum RF efficiency.

## Credits and Acknowledgments
This repository is strictly a hardware port and optimization effort. The core logic, payload structures, and original concept belong entirely to the security researchers who pioneered this method. 

Massive respect and credit go to:
- ronaldstoner
- chipik
- _hexway
- ECTO-1A
- SAY-10

## Key Features
- Optimized for nRF52: Uses direct hardware APIs for faster execution and cleaner signal broadcasting.
- Pure RF Spamming: All unnecessary LED indicators, physical button interrupts, and flash memory saving mechanics have been stripped out. 
- Dynamic Proximity Spoofing: Randomizes Tx Power across cycles to simulate physical movement, bypassing static RSSI filters.
- Strict Protocol Adherence: Enforces strict 31-byte maximum payload limits to ensure passive scanning by iOS devices triggers reliably.
- Continuous MAC Randomization: Generates compliant random static MAC addresses per cycle.

## Hardware Requirements
- Any nRF52840 development board (Pro Micro nRF52840, Adafruit Feather nRF52840, etc.)
- PlatformIO installed via VSCode.

## Installation and Flashing
1. Clone this repository.
2. Open the project folder in PlatformIO.
3. Review the platformio.ini file to ensure the environment matches your specific nRF52 board variant.
4. Build and upload via USB. 
5. The board will begin transmitting automatically upon receiving power.

## Disclaimer
This project is provided for educational purposes, hardware testing, and security research only. Do not use this tool to disrupt public spaces or harass individuals. You are solely responsible for your own actions.
