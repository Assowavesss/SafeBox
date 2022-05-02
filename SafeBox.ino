#include "src/safebox.h"

using namespace safebox;

#define WIFI_SSID "iPhone"
#define WIFI_PASSWORD "asgtyuiop"

Action *a=nullptr;

void setup() 
{
  /* Sets the communication rate in number of characters per second */
  Serial.begin(9600);

  /* To Etablish Transmission with Monitor series */
  while(!Serial) {};

  /* Create instance of singleton Action */
  a = Action::getInstance(nullptr);

  /* Create a kind of link to wifi and run the connection */
  a->setPrototype(new Connection(WIFI_SSID,WIFI_PASSWORD));
  a->run();

  /* Create communication with accelerometer */
  a->setPrototype(new Accelerometer());
  
  
}

void loop() 
{
  a->run();
}
