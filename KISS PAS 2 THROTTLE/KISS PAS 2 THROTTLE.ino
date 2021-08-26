/*
 VERSION: 1.0.1
 
 Name:		KISS_PAS_2_THROTTLE.ino
 Created:	8/23/2021 10:34:43 AM
 Author:	r4bb17

*/
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
    duration = pulseInLong(PASPin, HIGH);
    
    unsigned int sample = duration / 1000;  // convert to (ms)

    //increase pulse counter if valid pulse detected
    if (sample < 501 && sample != 0) {
        //map sample value to high and low PWM range
        int mappedValue = map(sample, 250, 500, highPWMValue, lowPWMValue);
        
        //safeguard throttle control from out of range anomalies.
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