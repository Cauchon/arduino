/*
 * Tutorial 2b: Automatic Light Switch
 * 
 * Automatically turns on an LED when it gets dark.
 *
 *
 * To see this sketch in action put the board in a
 * room with little or no sunlight, only lit by your room lights. 
 * Turn the room lights on and off. The LED will automatically
 * turn on when its dark and off when its light.
 *
 * The circuit:
 * - photoresistor from analog in 0 to +5V
 * - 10K resistor from analog in 0 to ground
 * - LED connected to digital pin 2 through a 300ohm resistor
 *
 * Author: Blaise Jarrett
 * Edited on 9/12/14 by Justin Cauchon
 *
 */

// A constant that describes when its dark enough to
// light the LED. A value close to 600 will light the led
// with less darkness. Play with this number.
const int sensorDark = 200;
// sensor minimum, discovered through experiment
const int sensorMin = 0;
// sensor maximum, discovered through experiment
const int sensorMax = 800;


// the photocell voltage divider pin
int photocellPin = A0;
// the LED pin
int LEDPin = 2;


void setup()
{
    // initialize the LED pin as output
    pinMode(LEDPin, OUTPUT);
    // set up serial at 9600 baud   
    Serial.begin(9600);
}

void loop()
{
    int analogValue;
    int range;

    // read our photocell
    analogValue = analogRead(photocellPin);
    // map the sensor range to a range of four options
    range = map(analogValue, sensorMin, sensorMax, 0, 3);
    
    // do something different depending on the 
    // range value
    switch (range) 
    {
        // your hand is on the sensor
        case 0:
            Serial.println("dark");
            break;
        // your hand is close to the sensor
        case 1:
            Serial.println("dim");
            break;
        // your hand is a few inches from the sensor
        case 2: 
            Serial.println("medium");
            break;
        // your hand is nowhere near the sensor
        case 3:
            Serial.println("bright");
            break;
    }
    
        // wait 0.25s before reading the photocell again
        delay(1000);
    
    // The higher the analogValue reading is the darker it is.
    // If its atleast as dark as our constant "sensorDark"
    // light the LED
    if (analogValue < sensorDark)
    {
        digitalWrite(LEDPin, HIGH);
    }
    // Otherwise turn the LED off
    else
    {
        digitalWrite(LEDPin, LOW);
    }

    // wait 1ms for better quality sensor readings
    delay(1);
}
