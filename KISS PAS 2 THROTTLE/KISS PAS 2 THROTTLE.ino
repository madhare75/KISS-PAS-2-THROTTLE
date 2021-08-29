/*
 VERSION: 1.0.1
 
 Name:		KISS_PAS_2_THROTTLE.ino
 Created:	8/23/2021 10:34:43 AM
 Author:	r4bb17

*/
// int throttleMap(int);           // Manual Throttle MAP function  REMOVE?

const int PASPin = 2;           // PAS Input pin
const int PWMOut = 11;          // PWM Output pin

const int lowPWMValue = 53;     // low PWM value, 53 (.830 V)
const int highPWMValue = 197;   // high PWM value, 197 (3.63V)
int currentPWMValue;            // state of digital throttle (53 - 197)

unsigned long duration;         // length of pulse in microseconds
unsigned long pulses = 0;       // total pulses




void setup() {
    Serial.begin(9600);         // Initialize Serial Port
    pinMode(PASPin, INPUT);     // Initialize PAS pin as input
    pinMode(PWMOut, OUTPUT);    // Initialize PWM pin as output
    idleThrottle();             // Generate Idle throttle voltage
}


void loop() {

    //get the time between pulses from the the PAS (Pedal Assist Sensor)
    duration = pulseInLong(PASPin, HIGH, 500000);
    
    unsigned int sample = duration / 1000;  // declare sample and convert duration to (ms)

    //if valid pulse detected map to PWM and write to output
    if (sample < 501 && sample != 0) {
        //map sample value to high and low PWM range
        int mappedValue = map(sample, 1, 75, highPWMValue, lowPWMValue); //Create manual map function.
 //       int mappedValue = throttleMap(sample);
        
        //safeguard throttle control from out of range anomalies
        if (mappedValue <= highPWMValue && mappedValue >= lowPWMValue) {
            analogWrite(PWMOut, mappedValue);
            currentPWMValue = mappedValue;
        }
        
        pulses++;
    }

    //generate idle throttle voltage if no pulses
    if (!sample) {
        idleThrottle();
    }


    printDebug();
}


void idleThrottle() {
    //set throttle to idle
    analogWrite(PWMOut, lowPWMValue);
    currentPWMValue = lowPWMValue;
}


void printDebug() {
    //print out diagnostic information
    Serial.print("Pulse duration: ");
    Serial.print(duration / 1000);
    Serial.print(" ms\t");
    Serial.print("Total Pulses = ");
    Serial.print(pulses);
    Serial.print("\tPWM = ");
    Serial.println(currentPWMValue);
}


int throttleMap(int pwm){
    //Manual Throttle MAP  (Sur Ron X-Bike 2021)
    //PWM Range 53 - 197 (Idle - Max) [144 Steps]

    switch (pwm) {
    //  HALF STEPS 1:.5
    case 200: pwm = 54; break;
    case 199: pwm = 54; break;
    case 198: pwm = 55; break;
    case 197: pwm = 55; break;
    case 196: pwm = 56; break;
    case 195: pwm = 56; break;
    case 194: pwm = 57; break;
    case 193: pwm = 57; break;
    case 192: pwm = 58; break;
    case 191: pwm = 58; break;
    case 190: pwm = 59; break;
    case 189: pwm = 59; break;
    case 188: pwm = 60; break;
    case 187: pwm = 60; break;
    case 186: pwm = 61; break;
    case 185: pwm = 61; break;
    case 184: pwm = 62; break;
    case 183: pwm = 62; break;
    case 182: pwm = 63; break;
    case 181: pwm = 63; break;
    case 180: pwm = 64; break;
    case 179: pwm = 64; break;
    case 178: pwm = 65; break;
    case 177: pwm = 65; break;
    case 176: pwm = 66; break;
    case 175: pwm = 66; break;
    case 174: pwm = 67; break;
    case 173: pwm = 67; break;
    case 172: pwm = 68; break;
    case 171: pwm = 68; break;
    case 170: pwm = 69; break;
    case 169: pwm = 69; break;
    case 168: pwm = 70; break;
    case 167: pwm = 70; break;
    case 166: pwm = 71; break;
    case 165: pwm = 71; break;
    case 164: pwm = 72; break;
    case 163: pwm = 72; break;
    case 162: pwm = 73; break;
    case 161: pwm = 73; break;
    case 160: pwm = 74; break;
    case 159: pwm = 74; break;
    case 158: pwm = 75; break;
    case 157: pwm = 75; break;
    case 156: pwm = 76; break;
    case 155: pwm = 76; break;
    case 154: pwm = 77; break;
    case 153: pwm = 77; break;
    // FULL STEPS  [1:1]
    case 152: pwm = 78; break;
    case 151: pwm = 79; break;
    case 150: pwm = 80; break;
    case 149: pwm = 81; break;
    case 148: pwm = 82; break;
    case 147: pwm = 83; break;
    case 146: pwm = 84; break;
    case 145: pwm = 85; break;
    case 144: pwm = 86; break;
    case 143: pwm = 87; break;
    case 142: pwm = 88; break;
    case 141: pwm = 89; break;
    case 140: pwm = 90; break;
    case 139: pwm = 91; break;
    case 138: pwm = 92; break;
    case 137: pwm = 93; break;
    case 136: pwm = 94; break;
    case 135: pwm = 95; break;
    case 134: pwm = 96; break;
    case 133: pwm = 97; break;
    case 132: pwm = 98; break;
    case 131: pwm = 99; break;
    case 130: pwm = 100; break;
    case 129: pwm = 101; break;
    case 128: pwm = 102; break;
    case 127: pwm = 103; break;
    case 126: pwm = 104; break;
    case 125: pwm = 105; break;
    case 124: pwm = 106; break;
    case 123: pwm = 107; break;
    case 122: pwm = 108; break;
    case 121: pwm = 109; break;
    case 120: pwm = 110; break;
    case 119: pwm = 111; break;
    case 118: pwm = 112; break;
    case 117: pwm = 113; break;
    case 116: pwm = 114; break;
    case 115: pwm = 115; break;
    case 114: pwm = 116; break;
    case 113: pwm = 117; break;
    case 112: pwm = 118; break;
    case 111: pwm = 119; break;
    case 110: pwm = 120; break;
    case 109: pwm = 121; break;
    case 108: pwm = 122; break;
    case 107: pwm = 123; break;
    case 106: pwm = 124; break;
    case 105: pwm = 125; break;
    case 104: pwm = 126; break;
    case 103: pwm = 127; break;
    case 102: pwm = 128; break;
    case 101: pwm = 129; break;
    case 100: pwm = 130; break;
    case 99: pwm = 131; break;
    case 98: pwm = 132; break;
    case 97: pwm = 133; break;
    case 96: pwm = 134; break;
    case 95: pwm = 135; break;
    case 94: pwm = 136; break;
    case 93: pwm = 137; break;
    case 92: pwm = 138; break;
    case 91: pwm = 139; break;
    case 90: pwm = 140; break;
    case 89: pwm = 141; break;
    case 88: pwm = 142; break;
    case 87: pwm = 143; break;
    case 86: pwm = 144; break;
    case 85: pwm = 145; break;
    case 84: pwm = 146; break;
    case 83: pwm = 147; break;
    case 82: pwm = 148; break;
    case 81: pwm = 149; break;
    case 80: pwm = 150; break;
    case 79: pwm = 151; break;
    case 78: pwm = 152; break;
    case 77: pwm = 153; break;
    case 76: pwm = 154; break;
    case 75: pwm = 155; break;
    case 74: pwm = 156; break;
    case 73: pwm = 157; break;
    case 72: pwm = 158; break;
    case 71: pwm = 159; break;
    case 70: pwm = 160; break;
    case 69: pwm = 161; break;
    case 68: pwm = 162; break;
    case 67: pwm = 163; break;
    case 66: pwm = 164; break;
    case 65: pwm = 165; break;
    case 64: pwm = 166; break;
    case 63: pwm = 167; break;
    case 62: pwm = 168; break;
    case 61: pwm = 169; break;
    case 60: pwm = 170; break;
    case 59: pwm = 171; break;
    case 58: pwm = 172; break;
    case 56: pwm = 173; break;
    case 55: pwm = 174; break;
    case 54: pwm = 175; break;
    case 53: pwm = 176; break;
    case 52: pwm = 177; break;
    case 51: pwm = 178; break;
    case 50: pwm = 179; break;
    case 49: pwm = 180; break;
    case 48: pwm = 181; break;
    case 47: pwm = 182; break;
    case 46: pwm = 183; break;
    case 45: pwm = 184; break;
    case 44: pwm = 185; break;
    case 43: pwm = 186; break;
    case 42: pwm = 187; break;
    case 41: pwm = 188; break;
    case 40: pwm = 189; break;
    case 39: pwm = 190; break;
    case 38: pwm = 191; break;
    case 37: pwm = 192; break;
    case 36: pwm = 193; break;
    case 35: pwm = 194; break;
    case 34: pwm = 195; break;
    case 33: pwm = 196; break;
    case 32: pwm = 197; break;
    //  HOLD MAX VALUE
    case 31: pwm = 197; break;
    case 30: pwm = 197; break;
    case 29: pwm = 197; break;
    case 28: pwm = 197; break;
    case 27: pwm = 197; break;
    case 26: pwm = 197; break;
    case 25: pwm = 197; break;
    case 24: pwm = 197; break;
    case 23: pwm = 197; break;
    case 22: pwm = 197; break;
    case 21: pwm = 197; break;
    case 20: pwm = 197; break;
    case 19: pwm = 197; break;
    case 18: pwm = 197; break;
    case 17: pwm = 197; break;
    case 16: pwm = 197; break;
    case 15: pwm = 197; break;
    case 14: pwm = 197; break;
    case 13: pwm = 197; break;
    case 12: pwm = 197; break;
    case 11: pwm = 197; break;
    case 10: pwm = 197; break;
    case 9: pwm = 197; break;
    case 8: pwm = 197; break;
    case 7: pwm = 197; break;
    case 6: pwm = 197; break;
    case 5: pwm = 197; break;
    case 4: pwm = 197; break;
    case 3: pwm = 197; break;
    case 2: pwm = 197; break;
    case 1: pwm = 197; break;
    }

    return pwm;
}
