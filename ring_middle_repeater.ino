#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>

RF24 radio(9, 10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00; 
const uint16_t node01 = 01;   
const uint16_t node02 = 02;   // Address of our node in Octal format ( 04,031, etc)
unsigned long incomingData;
unsigned long storedData;
void setup() {
  SPI.begin();
  Serial.begin(57600);
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  

}
void loop() {
  network.update();
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    
   
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
   // if (header.from_node == 01)     // If data comes from Node 02
     // myservo.write(incomingData);  // tell servo to go to a particular angle
     
     Serial.println("the data INCOMING IS ");
     Serial.println(incomingData);
     
    }
  storedData= incomingData;
RF24NetworkHeader header2(node02);     // (Address where the data is going)
  bool ok = network.write(header2, &storedData, sizeof(storedData)); // Send the data
  
}
  
