#include "Connection.h"

#include"Firebase_Arduino_WiFiNINA.h"

using namespace savebox;

/**
 * @details
 *
 */
Connection::Connection(const char *ssid, const char *password,const char *url, const char* key_db) : ssid_{ssid}, password_{password}, url_{url}, key_db_{key_db}
{
}

/**
 * @details
 *
 */
Connection::~Connection(void)
{
	delete (char*)(ssid_);
	ssid_ = nullptr;
	delete (char*)(password_);
	password_ = nullptr;
	delete (char*)(url_);
	url_ = nullptr;
	delete (char*)(key_db_);
	key_db_ = nullptr;
}

/**
 * @details
 *
 */
void Connection::connection(void) const 
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
	   
	   
	   Firebase.begin(url_, key_db_, ssid_, password_);
  	   Firebase.reconnectWiFi(true);
}

/**
 * @details
 *
 */
void Connection::sendData(void) const
{
        FirebaseData fbdo;
	QueryFilter query;
	
	if (Firebase.getJSON(fbdo, "/Profiles/0719273829", query))
 	{

    		Serial.println("Receive data : ");
    		Serial.println(fbdo.jsonData());
  	}
  	else
  	{
    		Serial.println("error, " + fbdo.errorReason());
  	}

	if(Firebase.pushJSON(fbdo, "/Pompiers/AccidentsNB3", fbdo.jsonData()))
	{
		Serial.println("Send data !");
	}
	else{
		Serial.println("error, " + fbdo.errorReason());
	}
	
	query.end();
	fbdo.clear();	 
}
