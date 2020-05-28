#include <Wire.h>  
#define SLAVE_ADDRESS 0x04       // I2C address for Argon 
#define LED 13                   // Built-in LED  
int i2cData = 0;                 // the I2C data received  
void setup(){  
  Wire.begin(SLAVE_ADDRESS);  
  Wire.onReceive(receiveData);  
  Wire.onRequest(sendData);  
  pinMode(LED, OUTPUT);  
  digitalWrite(LED, HIGH);  
}  
void loop() {  
  delay(100);
}  
// Handle reception of incoming I2C data  
void receiveData(int byteCount) {  
  while (Wire.available()) {  
    i2cData = Wire.read();  
    if (i2cData == 1) {  
      digitalWrite(LED, 1);  
    }  
    else {  
      digitalWrite(LED, 0);  
    }  
  }  
}  
// Handle request to send I2C data  
void sendData() {   
  Wire.write(i2cData);  
}  