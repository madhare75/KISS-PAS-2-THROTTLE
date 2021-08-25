/*
 Name:		KISS_PAS_2_THROTTLE.ino
 Created:	8/23/2021 10:34:43 AM
 Author:	r4bb17
*/
const int PASPin = 2;           // PAS Input pin
const int LEDPin = 13;          // Built-in test LED
const int PWMOut = 11;          // PWM Output pin

const int lowPWMValue = 53;     // Low PWM value, 53 (.830 V)
const int highPWMValue = 197;   // High PWM value, 197 (3.63V)
int currentPWMValue;            // State of digital Throttle (53 - 197)

unsigned long duration;         // Length of pulse in microseconds
unsigned long pulses = 0;       // Total Pulses




void setup() {
    Serial.begin(9600);         // Initialize Serial Port
    pinMode(PASPin, INPUT);     // Initialize the PAS pin as a input
    pinMode(LEDPin, OUTPUT);    // Initialize the LED as an output
    pinMode(PWMOut, OUTPUT);    // Initialize the PWM pin as an output
}


void loop() {
    //Generate Idle Throttle Voltage.
    turnOff();
    
    //take a sample from the the Pedal Assist Sensor
    duration = pulseIn(PASPin, HIGH);
    unsigned int sample = duration / 1000;

    //increase pulse counter if valid pulse detected
    // convert to (ms), anything over 800ms is unrelible [~ .62Hz lowest pulse detect]
    if (sample < 251 && sample != 0) {
        int mappedValue = map(sample, 20, 250, 197, 53);

        analogWrite(PWMOut, mappedValue);
        currentPWMValue = mappedValue;
        pulses++;
    }


    printDebug();
}


void turnOff() {
    //set throttle to idle
    currentPWMValue = lowPWMValue;
    analogWrite(PWMOut, lowPWMValue);
}


void printDebug() {
    //print out diagnostic information
    Serial.print("Pulse duration: ");
    Serial.print(duration/1000);
    Serial.print(" ms\t");
    Serial.print("Total Pulses = ");
    Serial.print(pulses);
    Serial.print("\tPWM = ");
    Serial.println(currentPWMValue);
}