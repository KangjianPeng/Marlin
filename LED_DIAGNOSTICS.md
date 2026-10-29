# WS2812 RGB LED configuration

The REV5 configuration drives two independent standard WS2812 RGB strips:

- Strip 0: `PC7`, 8 pixels
- Strip 1: `PC8`, 8 pixels

Standard WS2812 RGB LEDs use an 800 kHz data signal and normally expect `GRB`
byte order. The firmware uses `NEO_GRB` for both strip drivers. The `M150`
command controls the red, green, and blue channels.

Each strip is configured independently. Startup color tests are disabled, and
the strips remain controllable through `M150`.
