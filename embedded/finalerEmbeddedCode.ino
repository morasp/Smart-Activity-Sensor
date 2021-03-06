#include "WiFi.h"
#include <HTTPClient.h>

// these variables are used to configure the wifi connection by  filling in the necessary information about the network
const char* ssid = "****";
const char* password =  "****";

// this pin is the used adc pin
const int potPin = 34;

// create the http object for the get request
HTTPClient http;

// in the setup the wifi connection is enabled
void setup() {Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network"); 
  
}

// in loop the get request is performed 
void loop() {
  
 int potValue = 0;
 
 potValue = analogRead(potPin);

 // this variable is used to determine the current state of the device
 // it is a static variable to avoid spam notifications (to just send the notification once)  
 static bool on=0;

  // the Threshhold is variable
  // to determine if the device is off
 if (potValue>1200&&on==0)
 {
  //Check the current connection status
  if ((WiFi.status() == WL_CONNECTED)) 
  { 
    on=1;
    
    // GET Request to the Server
    //state=x is used to sent the current state (2=on, 3=off)
    http.begin("https://sam-api.moritz-speidel.de/plug.php/state/set?user=Admin&dev=as01xf&state=2");
    http.addHeader("X-SAM-KEY"," 12345");
    int httpCode = http.GET();     

    // get the payload of the response and check it 
    String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
    
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 }
 // the Threshhold is variable
// to determine if the device is off
 else if(potValue<1000&&on==1)
  {
    //Check the current connection status
    if ((WiFi.status() == WL_CONNECTED)) 
  { 
    // GET Request to the Server
    //state=x is used to sent the current state (2=on, 3=off)
    http.begin("https://sam-api.moritz-speidel.de/plug.php/state/set?user=Admin&dev=as01xf&state=3");
    http.addHeader("X-SAM-KEY","12345");
    int httpCode = http.GET();                                        //Make the request
    String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
        on=0;
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
     http.end(); //Free the resources
  }
 }
  delay(1000);
 
}
