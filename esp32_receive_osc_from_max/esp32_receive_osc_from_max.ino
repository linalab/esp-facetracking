// OSCreceive to neopixel matrix using Fastled library by @linalab


#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 64

byte pixelType = 0;
char drawIn[4];
char frameIn[768];


// Setup WiFI:
char ssid[] = "whiteRabbit";          // your network SSID (name)
char pass[] = "goodlife";    // your network password

// setup OSC:
// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;

const unsigned int localPort = 8000;        //  receives messages from wekinator using this port


OSCErrorCode error;
unsigned int wekState;              // wekinator state 



#define pin 5 // data pin for neopixel matrix
#define BRIGHTNESS  10


// Define the array of leds
CRGB leds[NUM_LEDS];


void setup() {

FastLED.addLeds<WS2812B, pin, GRB>(leds, NUM_LEDS);
FastLED.setBrightness(BRIGHTNESS);

pinMode(pin, OUTPUT);
Serial.begin(115200);

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

FastLED.clear();
}



void neo(OSCMessage &msg) {
wekState = msg.getInt(0); // message from wekinator
Serial.print("/receiving: ");
Serial.println(wekState);

if(wekState == 1){
face1();
}
else if(wekState ==2){
face2();
}
else{
  FastLED.clear();
}
}



void loop() {

FastLED.clear();

OSCMessage msg;
int size = Udp.parsePacket();

if (size > 0) {
while (size--) {
msg.fill(Udp.read());
}

msg.dispatch("/wek", neo);
}
}

void face1() {
leds[0] = CRGB(0, 0, 0);
leds[1] = CRGB(0, 0, 0);
leds[2] = CRGB(0, 0, 0);
leds[3] = CRGB(0, 0, 0);
leds[4] = CRGB(0, 0, 0);
leds[5] = CRGB(0, 0, 0);
leds[6] = CRGB(0, 0, 0);
leds[7] = CRGB(0, 0, 0);

leds[8] = CRGB(0, 0, 0);
leds[9] = CRGB(0, 0, 0);
leds[10] = CRGB(0, 150, 0);
leds[11] = CRGB(0, 0, 0);
leds[12] = CRGB(0, 0, 0);
leds[13] = CRGB(0, 150, 0);
leds[14] = CRGB(0, 0, 0);
leds[15] = CRGB(0, 0, 0);

leds[16] = CRGB(0, 0, 0);
leds[17] = CRGB(0, 0, 0);
leds[18] = CRGB(0, 150, 0);
leds[19] = CRGB(0, 0, 0);
leds[20] = CRGB(0, 0, 0);
leds[21] = CRGB(0, 150, 0);
leds[22] = CRGB(0, 0, 0);
leds[23] = CRGB(0, 0, 0);

leds[24] = CRGB(0, 0, 0);
leds[25] = CRGB(0, 0, 0);
leds[26] = CRGB(0, 0, 0);
leds[27] = CRGB(0, 0, 0);
leds[28] = CRGB(0, 0, 0);
leds[29] = CRGB(0, 0, 0);
leds[30] = CRGB(0, 0, 0);
leds[31] = CRGB(0, 0, 0);

leds[32] = CRGB(0, 0, 0);
leds[33] = CRGB(0, 150, 0);
leds[34] = CRGB(0, 0, 0);
leds[35] = CRGB(0, 0, 0);
leds[36] = CRGB(0, 0, 0);
leds[37] = CRGB(0, 0, 0);
leds[38] = CRGB(0, 150, 0);
leds[39] = CRGB(0, 0, 0);

leds[40] = CRGB(0, 0, 0);
leds[41] = CRGB(0, 0, 0);
leds[42] = CRGB(0, 150, 0);
leds[43] = CRGB(0, 0, 0);
leds[44] = CRGB(0, 0, 0);
leds[45] = CRGB(0, 150, 0);
leds[46] = CRGB(0, 0, 0);
leds[47] = CRGB(0, 0, 0);

leds[48] = CRGB(0, 0, 0);
leds[49] = CRGB(0, 0, 0);
leds[50] = CRGB(0, 0, 0);
leds[51] = CRGB(0, 150, 0);
leds[52] = CRGB(0, 150, 0);
leds[53] = CRGB(0, 0, 0);
leds[54] = CRGB(0, 0, 0);
leds[55] = CRGB(0, 0, 0);

leds[56] = CRGB(0, 0, 0);
leds[57] = CRGB(0, 0, 0);
leds[58] = CRGB(0, 0, 0);
leds[59] = CRGB(0, 0, 0);
leds[60] = CRGB(0, 0, 0);
leds[61] = CRGB(0, 0, 0);
leds[62] = CRGB(0, 0, 0);
leds[63] = CRGB(0, 0, 0);
FastLED.show();
}

void face2() {
leds[0] = CRGB(0, 0, 0);
leds[1] = CRGB(0, 0, 0);
leds[2] = CRGB(0, 0, 0);
leds[3] = CRGB(0, 0, 0);
leds[4] = CRGB(0, 0, 0);
leds[5] = CRGB(0, 0, 0);
leds[6] = CRGB(0, 0, 0);
leds[7] = CRGB(0, 0, 0);

leds[8] = CRGB(0, 0, 0);
leds[9] = CRGB(0, 0, 0);
leds[10] = CRGB(150, 0, 0);
leds[11] = CRGB(0, 0, 0);
leds[12] = CRGB(0, 0, 0);
leds[13] = CRGB(150, 0, 0);
leds[14] = CRGB(0, 0, 0);
leds[15] = CRGB(0, 0, 0);

leds[16] = CRGB(0, 0, 0);
leds[17] = CRGB(0, 0, 0);
leds[18] = CRGB(150, 0, 0);
leds[19] = CRGB(0, 0, 0);
leds[20] = CRGB(0, 0, 0);
leds[21] = CRGB(150, 0, 0);
leds[22] = CRGB(0, 0, 0);
leds[23] = CRGB(0, 0, 0);

leds[24] = CRGB(0, 0, 0);
leds[25] = CRGB(0, 0, 0);
leds[26] = CRGB(0, 0, 0);
leds[27] = CRGB(0, 0, 0);
leds[28] = CRGB(0, 0, 0);
leds[29] = CRGB(0, 0, 0);
leds[30] = CRGB(0, 0, 0);
leds[31] = CRGB(0, 0, 0);

leds[32] = CRGB(0, 0, 0);
leds[33] = CRGB(0, 0, 0);
leds[34] = CRGB(0, 0, 0);
leds[35] = CRGB(150, 0, 0);
leds[36] = CRGB(150, 0, 0);
leds[37] = CRGB(0, 0, 0);
leds[38] = CRGB(0, 0, 0);
leds[39] = CRGB(0, 0, 0);

leds[40] = CRGB(0, 0, 0);
leds[41] = CRGB(0, 0, 0);
leds[42] = CRGB(150, 0, 0);
leds[43] = CRGB(0, 0, 0);
leds[44] = CRGB(0, 0, 0);
leds[45] = CRGB(150, 0, 0);
leds[46] = CRGB(0, 0, 0);
leds[47] = CRGB(0, 0, 0);

leds[48] = CRGB(0, 0, 0);
leds[49] = CRGB(150, 0, 0);
leds[50] = CRGB(0, 0, 0);
leds[51] = CRGB(0, 0, 0);
leds[52] = CRGB(0, 0, 0);
leds[53] = CRGB(0, 0, 0);
leds[54] = CRGB(150, 0, 0);
leds[55] = CRGB(0, 0, 0);

leds[56] = CRGB(0, 0, 0);
leds[57] = CRGB(0, 0, 0);
leds[58] = CRGB(0, 0, 0);
leds[59] = CRGB(0, 0, 0);
leds[60] = CRGB(0, 0, 0);
leds[61] = CRGB(0, 0, 0);
leds[62] = CRGB(0, 0, 0);
leds[63] = CRGB(0, 0, 0);
FastLED.show();
}