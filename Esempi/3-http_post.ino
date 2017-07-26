#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Sacconago";
const char* password = "nicola94";

const char *url = "serverservices.altervista.org";
const char *path = "/obtainPost.php";
const int httpPort = 80;

HTTPClient http;
int httpCode;

void setup() 
{
  Serial.begin(115200);
  
  connectToWifi();
}

void loop() 
{
  makePost();
  
  delay(2000);

}

void makePost()
{
  http.begin(url, httpPort, path);
  httpCode = http.POST(String("t=10"));

  if (httpCode > 0) 
  {
    Serial.printf("[HTTP] POST... code: %d\n", httpCode);

    if (httpCode == 200)
    {
      Serial.println(http.getString());
    }
    
  } 
  else
  {
    Serial.printf("[HTTP] POST... failed: error code %d", httpCode);
  }
}

void connectToWifi()
{
  Serial.begin(115200);

    // Connect to an existing Wi-Fi network
    WiFi.begin(ssid, password);
    Serial.print("\n\nConnecting");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println(" DONE!");

    Serial.println(WiFi.localIP());
}
