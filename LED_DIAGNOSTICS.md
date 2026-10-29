# SKC6812RGBW-NW LED diagnostics

The REV5 configuration drives two independent SKC6812RGBW-NW strips:

- Strip 0: `PC7`, 8 pixels
- Strip 1: `PC8`, 8 pixels

SKC6812RGBW-NW uses an 800 kHz data signal and normally expects `GRBW` byte
order. The firmware therefore uses `NEO_GRBW` and explicitly selects
`NEO_KHZ800` for both strip drivers. The fourth channel is controlled by the
`W` parameter of Marlin's `M150` command.

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

SKC6812RGBW-NW strips are normally powered from 5 V, while PC7 and PC8 are 3.3 V
MCU outputs. Some pixel batches accept a 3.3 V data high level, but it is
outside the guaranteed margin at a 5 V supply. If colors are unstable or
pixels stop partway through a strip, use a 5 V-tolerant level shifter such as
`74AHCT125`/`74HCT14` on each data line, with a common ground. A 330-470 ohm
series resistor close to each data output can reduce ringing on long wires.
Eight RGBW pixels can draw roughly 640 mA at full output per strip, so verify
the 5 V voltage at the far end and size the supply for both strips together.

The two strips are initialized and updated independently. A firmware setting
cannot repair a reversed connector, missing ground, insufficient 5 V current,
or a damaged pixel.
