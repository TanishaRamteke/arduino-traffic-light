# Arduino Traffic Light with Pedestrian Button

A traffic light controller built on Arduino Uno and simulated in Tinkercad Circuits.

## What it does
- Green stays on by default
- When the pedestrian button is pressed: yellow (2 s) → red (5 s) → green (5 s)
- The green phase has a guaranteed minimum time, even if the button is held down

## Components
- Arduino Uno R3
- 3 LEDs (red, yellow, green) with 220 Ω resistors
- 1 pushbutton (INPUT_PULLUP, no external resistor)

## Circuit
![Circuit](Circuit.png)

| Part | Arduino pin |
|---|---|
| Red LED | 8 |
| Yellow LED | 9 |
| Green LED | 10 |
| Button | 2 (other leg to GND) |

## What I learned
- Choosing resistor values with Ohm's law
- Using INPUT_PULLUP: a pressed button reads LOW
- **Bug I found and fixed:** When the pedestrian button was held down, the green LED seemed to never light after the red phase. Tracing the code showed that green was switched on and immediately off again because the button was still pressed, so it stayed on for only microseconds. I fixed it by adding a 5-second green phase after red, which guarantees traffic always gets visible green time. Now I trace what the code does step by step, and not only the wiring, when something looks wrong.

## Known limitation (version 1)
`delay()` freezes the program, so a button press during the red or green phase is missed.
Planned fix in version 2: use `millis()` for non-blocking timing.
