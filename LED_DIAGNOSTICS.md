# WS2812 RGB LED configuration

The REV5 configuration drives two independent standard WS2812 RGB strips:

- Strip 0: `PC7`, 8 pixels
- Strip 1: `PC8`, 8 pixels

Standard WS2812 RGB LEDs use an 800 kHz data signal and normally expect `GRB`
byte order. The firmware uses `NEO_GRB` for both strip drivers. The `M150`
command controls the red, green, and blue channels.

Each strip is configured independently. On boot, Marlin tests strip 0 on
`PC7` and then strip 1 on `PC8`, showing red, green, and blue for 500 ms each.

For repeatable tests from a serial console, select one strip at a time. `S0`
selects `PC7`; `S1` selects `PC8`. Marlin's green parameter is `U`, not `G`.
On RGB strips, white is made by setting all three RGB channels; `W` is not used.

```gcode
M150 S1 R64 U0 B0
M150 S1 R0 U64 B0
M150 S1 R0 U0 B64
M150 S1 R64 U64 B64
M150 S1
```

Repeat with `S0` to compare the other output. The startup test checks full
primary colors only; these commands also check low output levels and white.

A stable primary color appearing on the wrong channel points to a per-strip
color-order difference. A channel-order setting alone cannot turn equal
red, green, and blue values into red-only output. Flicker or colors changing
between commands points to the data path or power: check the `DIN` direction,
ground continuity, and 5 V at the first LED while lit. Power off before
swapping only the `PC7` and `PC8` data connections. If the fault follows the
strip, inspect its cable, first pixel, and input direction; if it stays on
`PC8`, inspect that output's connection and signal level.
