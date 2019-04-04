#include <RF24.h>
#include <RF24Network.h>
#include <SPI.h>


RF24 radio(9, 10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 02; 
const uint16_t node00 = 00;   
  

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
    unsigned long incomingData;
    unsigned long node1_data;
    
    network.read(header, &incomingData, sizeof(incomingData));      
    
     if( header.from_node==00)
     {
     node1_data= incomingData;
     Serial.println("the data from node 1 is ");
     Serial.println(node1_data);
     delay(1000);
    
     }
    }
    
  }


