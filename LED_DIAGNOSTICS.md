# WS2812B LED diagnostics

The REV5 configuration drives two independent WS2812B strips:

- Strip 0: `PC7`, 8 pixels
- Strip 1: `PC8`, 8 pixels

WS2812B uses an 800 kHz data signal and normally expects `GRB` byte order.
The firmware therefore uses `NEO_GRB` and explicitly selects `NEO_KHZ800` for
both strip drivers. Do not change the byte order unless a controlled test
shows that every pixel consistently swaps the same color channels.

## Controlled test

Run each command separately and allow the strip to settle between commands:

```gcode
M150 S0 R255
M150 S0 U255
M150 S0 B255
M150 S1 R255
M150 S1 U255
M150 S1 B255
```

Marlin uses `U` for green in `M150`; `G` is reserved by motion commands.

Interpret the result as follows:

- The whole strip has the same channel swap: check the strip's actual LED
  order or test a matching `NEOPIXEL_TYPE`.
- The first pixels work but later pixels are dark or unstable: check 5 V
  voltage at the far end, common ground, the `DIN` arrow direction, the first
  pixel, and signal wiring. A damaged first pixel can prevent all downstream
  pixels from receiving data.
- One complete strip is dead: check its connector and confirm that the strip
  is connected to the configured `PC7` or `PC8` output.
- Both strips fail in the same way: check the shared 5 V supply and ground,
  then verify that the firmware binary was built from this configuration.

The two strips are initialized and updated independently. A firmware setting
cannot repair a reversed connector, missing ground, insufficient 5 V current,
or a damaged pixel.
