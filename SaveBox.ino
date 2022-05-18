#include "src/SB.h"
using namespace savebox;

#define WIFI_SSID "iPhone"
#define WIFI_PASSWORD "asgtyuiop"

#define DATABASE_URL "savebox2021-default-rtdb.firebaseio.com"
#define DATABASE_SECRET "dmrNXYzd7ihtmQWRAv98HgdX7bzqamBrvJw2BiKP" 


SB *safebox = nullptr;

void setup() 
{
  /* Sets the communication rate in number of characters per second */
  Serial.begin(9600);

  /* To Etablish Transmission with Monitor series */
  while(!Serial) {};
   
  safebox = new SB();
  safebox->connection(WIFI_SSID,WIFI_PASSWORD,DATABASE_URL,DATABASE_SECRET);

}

void loop() 
{
  safebox->run();
}
