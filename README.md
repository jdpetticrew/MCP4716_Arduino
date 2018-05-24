MCP4716 Library

This library is a Arduino library for setting the output voltage of an MCP4716 DAC. This library has been tested with an Arduino Uno.

setGain(i)
Set gain is the function used to set the DACs internal gain.
By default the gain is set to 1.

| i | Gain |
|---|------|
| 1 | x1   |
| 2 | x2   |

setVref(j)
Set Vref is used to set the reference voltage source.
By default the referece source is set to Vdd.

| j | Vref |
|---|---|
| 1 | Vdd |
| 2 | VrefUnbuf |
| 3 | VrefBuff |

setVout()
Set Vout takes a uint16_t value, patterns it to a 10bit value and sets the output voltage.
For operation a value of 0-1023 should be used.
