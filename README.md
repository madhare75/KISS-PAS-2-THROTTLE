# KISS-PAS-2-THROTTLE
Pedal Assist Sensor (pulses) to Throttle (voltage).

Note(s):
The first version (no-version-number), would start to pulse the motor if you rotated the pedals more than once per second.  Pedaling as fast as I could got the ebike up to around 15mph but it was very jerky motor pulse input.  A time delay buffer, to hold the motor at a particular PWM state should help that.

v1.0.1
Added a *manual* VERSION (tag) to the top of the main source file.
Changed the pulse timing mapping range from 20ms-250ms -> 250ms-500ms.

Functional Proof of Concept, Alpha v1.0.1: The code has matured enough that this repository can be made public.  The program allows the user to have throttle control using the pedals, the faster the user pedals the more the throttle voltage is raised.  Gives the feeling and control of a pedal bike without the need for any mechanical linkage of the pedals to the bike.
