
#include <DHT.h>

// Define DHT22 pin
#define DHTPIN 4 // GPIO2

// Initialize DHT sensor
DHT dht(DHTPIN, DHT22);

void setup()
{
    // Initialize serial communication
    Serial.begin(9600);
    delay(1000);

    // Initialize DHT sensor
    dht.begin();
}

void loop()
{
    // Read data from DHT22 sensor
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Check if data was successfully read
    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("Failed to read data from DHT22 sensor");
        return;
    }

    // Print temperature and humidity values
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Wait for 2 seconds before reading again
    delay(2000);
}
