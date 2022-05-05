#include "Connection.h"

#include"Firebase_Arduino_WiFiNINA.h"

using namespace savebox;

Connection::Connection(const char *ssid, const char *password,const char *url, const char* key_db) : ssid_(ssid), password_(password), url_(url), key_db_(key_db)
{
}


/**
 * @details
 *
 */
void Connection::connection(void) 
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
	   
	   FirebaseData fbdo;
	   Firebase.begin(url_, key_db_, ssid_, password_);
  	   Firebase.reconnectWiFi(true);
  	   
  	  unsigned long long val = 1634631042000;

	  if (Firebase.setInt(fbdo, "/Passenger", val)) //support large number
	  {
	    Serial.println("ok");
	    Serial.println("path: " + fbdo.dataPath());
	    Serial.println("type: " + fbdo.dataType());
	    Serial.print("value: ");
	    if (fbdo.dataType() == "int")
	      Serial.println(fbdo.intData());
	    if (fbdo.dataType() == "int64")
	      Serial.println(fbdo.int64Data());
	    if (fbdo.dataType() == "uint64")
	      Serial.println(fbdo.uint64Data());
	    else if (fbdo.dataType() == "double")
	      Serial.println(fbdo.doubleData());
	    else if (fbdo.dataType() == "float")
	      Serial.println(fbdo.floatData());
	    else if (fbdo.dataType() == "boolean")
	      Serial.println(fbdo.boolData() == 1 ? "true" : "false");
	    else if (fbdo.dataType() == "string")
	      Serial.println(fbdo.stringData());
	    else if (fbdo.dataType() == "json")
	      Serial.println(fbdo.jsonData());
	    else if (fbdo.dataType() == "array")
	      Serial.println(fbdo.arrayData());
	  }
	  else
	  {
	    Serial.println("error, " + fbdo.errorReason());
	  }
}
