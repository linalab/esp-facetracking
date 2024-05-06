This guide will show you  the steps to use Face Tracking with open CV in Max , train basic models in wekinator and control a neopixel matrix to show a happy/sad face.

# Steps

1. Input: XIAO ESPS3 Camera and touch 

2. OBS: convert the signal from the camera into a video source

3. FaceTracking max patch: Receives the camera and sends OSC messages with face tracking data

4. Wekinator: Receives the OSC messages and trains a model to detect gestures

5. OUTPUT: ESP32 receives OSC messages from Max and controls a Neopixel Matrix

# Materials Needed

1. ESP32 board (WEMOS Lolin 32 Lite) (https://www.az-delivery.de/es/products/esp32-lolin-lolin32)
2. XIAO ESP32S3 Camera Module (https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/)

---


### 1. Input: XIAO ESPS3 Camera and touch 


    The Seeeduino XIAO ESP32S3 Sense board actually consists of two separate boards: 
    
    1. The Seeeduino XIAO ESP32S3 board. This board is also available separately. It includes the microcontroller, two LEDs, a USB-C connector, and two of the smallest pushbutton switches you have ever seen!
    
    2. The Camera module. This plugs into the top of the XIAO board. Along with the camera, it includes a microphone and a MicroSD card holder.

- Connect the Xiao ESPS3, this board is included in the [ESP32 Boards Manager](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).    

- In Arduino, go to File -> Examples -> ESP32 -> Camera -> CameraWebServer

    Before Uploading the code, follow the next steps: 
    - Comment the line 17: #define CAMERA_MODEL_ESP_EYE // Has PSRAM and un comment the line 26: #define CAMERA_MODEL_XIAO_ESP32S3 // Has PSRAM
    - You need to setup your SSID and Password for your WiFi network. 
    After uploading the code, open the monitor serial. You will see a IP address, copy the IP adress, we'll use it in OBS. (Or paste it on your browser to verify but be sure to close the browser to make tha camera available for OBS). 

---
### 2. OBS: convert the signal from the camera into a video source


- [Install OBS](https://obsproject.com/) 
- Use a Browser source, paste the IP adress, you should see the CameraWebServer main screen. 

**For Mac:**
- start the virtual camera

**For Windows:**
We're gonna use another way of send video signals internally, is called SPOUT, for that we'll need: 
- Download and install this plug-in for OBS: https://github.com/Off-World-Live/obs-spout2-plugin/releases 
- Close and open again OBS. To start Spout go to TOOLS -> Spout Output settings and click Start. 

___


### 3. FaceTracking max patch: Receives the camera and sends OSC messages with face tracking data

 FaceTracking max patch
 Receives the camera and sends OSC messages with face tracking data
 
- [Install MAX-MSP](https://cycling74.com/downloads): 
- Install cv.jit in the Package manager

**For Mac:**
- Open **facetracking.maxpat**
- Use the OBS camera as a source: choose OBS Virtual camera.

**For Windows:**
- Open **facetracking-win.maxpat**
___


By default the patch sends OSC messagges using the port 6448 to wekinator. Max also revceives them back from Wekinator using port 12000.
Finally sends clean OSC messages to the ESP in port 8000. 

---

### 4. Wekinator: Receives the OSC messages and trains a model to detect gestures

- [Install wekinator](http://www.wekinator.org/)
- Train the model with happy/sad faces
- Run 

Wekinator receives the face tracking data from MAX through OSC.

- Input port: 6448
- OSC message /wek/inputs
- #inputs 66

And sends the trained model to MAX again 

- OSC message /wek/outputs
- #outputs 1 
- Host IP: localhost
- Port: 12000

- Type: Custom and click in configure. 
    - Name: outputs
    - Type Numeric with integer ouputs
    - in max value , add the number of states for your project(for example 3 for happy, sad, neutral).
    
<img width="671" alt="wek_config" src="https://github.com/linalab/esp-facetracking/assets/19651027/4cded37c-af65-4d74-adda-4f377ab21cc2">



---

### 5. ESP32 receives OSC messages

- Connect the ESP with neopixel matrix in GPIO 5, GND and 3.3v.
- Select your ESP board (WEMOS LOLIN32, LOLIN32, etc. Change the speed if needed to 115200).
- In the sketch you need to setup your SSID and Password for your WiFi network. 
- The code uses Fastled library for neopixel by Daniel Garcia, and OSC by Adrian Freed, you must install the libraries first from Arduino. 
- Upload the sketch **esp32_receive_osc_from_max.ino** to your ESP.
- Go to monitor serial and copy the IP adress from the ESP.


It expects OSC messages in port 8000 (from max)
The code uses Fastled library for neopixel, and OSC. It shows a happy face when receives a 1. or a sad face when receives a 2.

