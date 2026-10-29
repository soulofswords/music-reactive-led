# Music-Reactive LED / VU Meter

A small Engineering Physics-II term-work project built around an Arduino and an addressable RGB strip. The project documentation describes a **VU meter with Arduino and an ARGB strip**, translating sound amplitude into a visual light response.

## Project context

- Contributors: Rutik Gajanan Baikar, Akshaya Anil Balam, Gaurang Parag Bhogle and RamChandra Bhoge
- Branch: Electrical Engineering
- Use case: an inexpensive educational demonstration of how sound energy can drive a visual output

## Source note

`Music_Reactive_RGB_Led.ino` is the available Arduino-family sketch from the project archive. The archived sketch is configured for an ESP8266/Blynk relay experiment rather than a WS2812B/ESP32 VU-meter implementation, so the hardware definitions and control flow should be reviewed before reuse for the LED build.

The original file contained a live Blynk credential. It has been redacted here; replace `REPLACE_WITH_YOUR_BLYNK_TOKEN` only through a local/private configuration and never commit real credentials.

## Portfolio

See the project in Gaurang Parag Bhogle's portfolio: https://soulofswords.github.io/gaurang-bhogle-portfolio/
