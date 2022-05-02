#include "Connection.h"

#include<SPI.h>
#include<WiFiNINA.h>

using namespace safebox;

Connection::Connection(const char *ssid = nullptr, const char *password = nullptr) : ssid_(ssid), password_(password)
{
}


/**
 * @details
 *
 */
void Connection::run(void) 
{
	   Serial.println("Connection network device...");
	   delay(1000);
	   int status=WL_IDLE_STATUS;
	   while(status!=  WL_CONNECTED)
	   {
		  status=WiFi.begin(ssid_,password_);
		  delay(300);
	   }
	   Serial.println("Connection established !!!!!");
	   Serial.print("IP : ");
	   Serial.println(WiFi.localIP());
}
