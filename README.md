# KISS-PAS-2-THROTTLE
Pedal Assist Sensor (pulses) to Throttle (voltage).

Note(s):
The first version (no-version-number), would start to pulse the motor if you rotated the pedals more than once per second.  Pedaling as fast as I could got the ebike up to around 15mph but it was very jerky motor pulse input.  A time delay buffer, to hold the motor at a particular PWM state should help that.

v1.0.1
Added a *manual* VERSION (tag) to the top of the main source file.
Changed the pulse timing mapping range from 20ms-250ms -> 250ms-500ms.
