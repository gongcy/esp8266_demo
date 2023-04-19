#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define DHT22 pin
#define DHTPIN 4 // GPIO2

// Initialize DHT sensor
DHT dht(DHTPIN, DHT22);

// Initialize OLED display
#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

void setup()
{
    // Initialize serial communication
    Serial.begin(9600);
    delay(1000);

    // Initialize DHT sensor
    dht.begin();

    // Initialize OLED display
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
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

    // Print temperature and humidity values to console
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Display temperature and humidity values on OLED display
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Temperature: ");
    display.print(temperature);
    display.print(" *C");
    display.setCursor(0, 10);
    display.print("Humidity: ");
    display.print(humidity);
    display.print(" %");
    display.display();

    // Wait for 2 seconds before reading again
    delay(2000);
}
