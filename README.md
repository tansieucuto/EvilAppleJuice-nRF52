# EvilAppleJuice-nRF52

A no-bullshit port of the EvilAppleJuice BLE spammer from ESP32 to the nRF52840 microcontroller.

## Credits
All the fucking credit goes to [ckcr4lyf](https://github.com/ckcr4lyf/EvilAppleJuice-ESP32) for the original ESP32 implementation.

I didn't invent this shit. I just ported their logic to work on nRF52 hardware using the Adafruit Bluefruit library. Go star their original repo.

## What it does
- Spams Apple proximity pairing BLE packets using nRF52.
- Randomizes MAC addresses and Tx Power continuously.

## How to use
1. Clone this repo.
2. Open it in PlatformIO.
3. Flash it to your nRF52 board.
4. Let it run.

## Disclaimer for Dumbasses
This project is for educational purposes, hardware testing, and security research ONLY. If you use this shit to harass people, disrupt flights, or do anything illegal, you are on your own. Don't be a fucking script kiddie. I am not responsible for your stupid actions.
