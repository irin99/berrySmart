#include <WiFi.h>
/* change ssid and password according to yours WiFi*/
const char* ssid     = "Berry Secure";
const char* password = "123456789";
/*
 * This is the IP address of your PC
 * [Wins: use ipconfig command, Linux: use ifconfig command]
*/
const char* host = "192.168.4.1"; // need to find out what is each host id
const int port = 80;

void setup()
{
    Serial.begin(115200);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    /* connect to your WiFi */
    WiFi.begin(ssid, password);
    /* wait until ESP32 connect to WiFi*/
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print("Connecting to WiFi..");
    }
    Serial.println("");
    Serial.println("WiFi connected with IP address: ");
    Serial.println(WiFi.localIP());
}
void loop()
{
    delay(5000);
    Serial.print("connecting to ");
    Serial.println(host);
    /* Use WiFiClient class to create TCP connections */
    WiFiClient client;
    
    if (!client.connect(host, port)) {
        Serial.println("connection failed");
        return;
    }
    /* This will send the data to the server */
    client.print("hello world");
    client.stop();
}
