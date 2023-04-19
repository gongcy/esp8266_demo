#include <SoftwareSerial.h>

// Define ZE08-CH2O pins
#define RX_PIN 4 // GPIO2
#define TX_PIN 5 // GPIO3

// Initialize ZE08-CH2O sensor
SoftwareSerial ze08(RX_PIN, TX_PIN);

void setup()
{
    // Initialize serial communication
    Serial.begin(9600);
    delay(1000);

    // Initialize ZE08-CH2O sensor
    ze08.begin(9600);
}

void loop()
{
    // Read data from ZE08-CH2O sensor
    while (ze08.available() > 0)
    {
        int ch2o = ze08.read();
        if (ch2o == 0xFF)
        {
            ze08.read(); // skip the zero byte
            int high = ze08.read();
            int low = ze08.read();
            int ppm = (high * 256) + low;
            Serial.print("CH2O level: ");
            Serial.print(ppm);
            Serial.println(" ppb");
        }
    }

    // Wait for 2 seconds before reading again
    delay(2000);
}
