#include <ESP8266WiFi.h> 
const char* ssid = "YOUR_WIFI_NAME"; 
const char* password = "YOUR_WIFI_PASSWORD"; 
WiFiServer server(80); 
void setup() 
{ 
Serial.begin(9600); 
WiFi.begin(ssid, password); 
while(WiFi.status() != WL_CONNECTED) 
{ 
  delay(500); 
} 
server.begin(); 
} 
void loop() 
{ 
WiFiClient client = server.available(); 
if(client) 
{ 
String data = Serial.readStringUntil('\n'); 
client.println("HTTP/1.1 200 OK"); 
client.println("Content-Type: text/html"); 
client.println(""); 
client.println("<html><body>");
client.println("<h2>Smart Factory Monitoring</h2>"); 
client.println("<p>Sensor Data:</p>");
client.println(data); 
client.println("</body></html>"); 
delay(1000); 
client.stop(); 
} 

