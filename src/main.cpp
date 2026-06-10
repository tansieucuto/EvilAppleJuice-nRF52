#include <Arduino.h>
#include <bluefruit.h>
#include "device.h"

uint32_t delayMilliseconds = 100;

void setup() {
  Serial.begin(115200);
  Bluefruit.begin();
  Bluefruit.setTxPower(8);
}

void loop() {
  ble_gap_addr_t gap_addr;
  gap_addr.addr_type = BLE_GAP_ADDR_TYPE_RANDOM_STATIC;
  for (int i = 0; i < 6; i++) {
    gap_addr.addr[i] = random(256);
  }
  gap_addr.addr[5] |= 0xC0; 
  Bluefruit.setAddr(&gap_addr);

  int idx = random(0, sizeof(ALL_DEVICES) / sizeof(ALL_DEVICES[0]));
  AppleDevice dev = ALL_DEVICES[idx];

  uint8_t packet[31];
  size_t packetLen;
  generatePacket(dev, packet, packetLen);

  Bluefruit.Advertising.clearData();
  Bluefruit.Advertising.addData(BLE_GAP_AD_TYPE_MANUFACTURER_SPECIFIC_DATA, &packet[2], packetLen - 2);

  int adv_type_choice = random(3);
  if (adv_type_choice == 0) {
    Bluefruit.Advertising.setType(BLE_GAP_ADV_TYPE_CONNECTABLE_SCANNABLE_UNDIRECTED);
  } else if (adv_type_choice == 1) {
    Bluefruit.Advertising.setType(BLE_GAP_ADV_TYPE_NONCONNECTABLE_SCANNABLE_UNDIRECTED);
  } else {
    Bluefruit.Advertising.setType(BLE_GAP_ADV_TYPE_NONCONNECTABLE_NONSCANNABLE_UNDIRECTED);
  }

  Bluefruit.Advertising.setInterval(32, 32);

  Bluefruit.Advertising.start(0);
  delay(delayMilliseconds);
  Bluefruit.Advertising.stop();

  int rand_val = random(100);
  if (rand_val < 70) {
      Bluefruit.setTxPower(8);
  } else if (rand_val < 85) {
      Bluefruit.setTxPower(4);
  } else if (rand_val < 95) {
      Bluefruit.setTxPower(0);
  } else if (rand_val < 99) {
      Bluefruit.setTxPower(-4);
  } else {
      Bluefruit.setTxPower(-8);
  }
}
