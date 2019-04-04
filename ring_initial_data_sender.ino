#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>

RF24 radio(9,10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node00 = 00; 


void setup() {
  SPI.begin();
  Serial.begin(57600);
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  
void loop() {
  network.update();
  unsigned long val= analogRead(A1);
  Serial.println("the value of the sensor is");
  Serial.println(val);
  RF24NetworkHeader header(node00);     // (Address where the data is going)
  bool ok = network.write(header, &val, sizeof(val));
  delay(2000);
  
}


