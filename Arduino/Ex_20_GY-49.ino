#include <Wire.h>
#define MAX44009_ADDR 0x04A // I2C address of MAX44009 - Ambient light sensor 
void setup() {
  Serial.begin(9600);
  Wire.begin();
}
void loop() {
  Wire.beginTransmission(MAX44009_ADDR);
  Wire.write(0x03); // Start reading from Lux High Byte register
  Wire.endTransmission(false); // Keep the transmission alive for subsequent reading
  Wire.requestFrom(MAX44009_ADDR, 2); // Request 2 bytes (Lux High Byte and Lux Low Byte)
  if (Wire.available() == 2) { // Check if data is available
    byte highByte = Wire.read();
    byte lowByte = Wire.read();
    // Extract Exponent and Mantissa from Lux High Byte
    int exponent = (highByte >> 4) & 0x0F;
    int mantissa = ((highByte & 0x0F) << 4) | (lowByte & 0x0F);
    // Calculate Lux value
    float luxValue = pow(2, exponent) * mantissa * 0.045;
    // Print the Lux value to Serial Monitor
    Serial.print("Lux: ");
    Serial.println(luxValue);
  }
  delay(100);
}
