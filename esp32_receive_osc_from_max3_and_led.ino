/*Code to receive OSC messages using an ESP32 Lolin D32.
The example receves 2 messages from a customized trained model in Wekinator and acivates 2 states. 
A led connected to pin 5 will turn on or off depending on the state.
by @linalab & Citlali Hernández (@turbulente)
ESP32 Library needed: https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html
The complete guide is here: https://github.com/linalab/esp-facetracking/*/

#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>


int led = 5;  // declare pin number of a led

// Setup WiFI:
char ssid[] = "xxxxx";  // change de x's your network SSID (name)
char pass[] = "xxxxx";   //change de x's   // your network password

// setup OSC:
// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;

const unsigned int localPort = 8000;  //  receives messages from wekinator using this port


OSCErrorCode error;
unsigned int wekState;  // wekinator state


void setup() {

  Serial.begin(115200);

  pinMode(led, OUTPUT);  // led pin

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
#ifdef ESP32
  Serial.println(localPort);
#else
  Serial.println(Udp.localPort());
#endif
}


// Customiezed Function to receive OSC messages
void MyMSGReceiver(OSCMessage &msg) {
  wekState = msg.getInt(0);  // message from wekinator
  Serial.print("/receiving: ");
  Serial.println(wekState);  // printing wekinator message

  if (wekState == 0) {
    digitalWrite(led, HIGH);  // turn on the led if number received from wekinator is 0
    Serial.println("sad");
  } else if (wekState == 1) {
    digitalWrite(led, LOW);  // turn off the led if number received from wekinator is 1
    Serial.println("happy");
  }
}



void loop() {
  OSCMessage msg;  // receiving message
  int size = Udp.parsePacket();

  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }

    msg.dispatch("/wek", MyMSGReceiver);
  }
}
