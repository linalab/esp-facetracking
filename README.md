This guide will show you all the steps to use Face Tracking to control a neopixel matrix. 

# Steps

1. Input: XIAO ESPS3 Camera and touch

2. OBS: convert the signal from the camera into a video source

[3. FaceTracking max patch: Receives the camera and sends OSC messages with face tracking data](#facetracking-max-patch)

4. Wekinator: Receives the OSC messages and trains a model to detect gestures

5. OUTPUT: ESP32 receives OSC messages from Max and controls a Neopixel Matrix

#
#
---

 ### FaceTracking max patch
 Receives the camera and sends OSC messages with face tracking data
 
- Download MAX-MSP: https://cycling74.com/downloads
- Install cv.jit in the Package manager
- Run facetracking.maxpat

The patch sends OSC messagges using the port 6448 to wekinator and revceive them back in port 12000

sends OSC messages to the ESP in port 8000

[facetracking.maxpat]()


---

### Wekinator setup: 
Wekinator receives the face tracking data from MAX through OSC.

- Input port: 6448
- OSC message /raw 
- #inputs 66

And sends the trained model to MAX again 

- OSC message /wek 
- #outputs 1 
- Host IP: localhost
- Port: 12000

[WekinatorProject/WekinatorProject.wekproj]()

---

### ESP32 receives OSC messages

It expects OSC messages in port 8000 


1.  happy face
2.  sad face



The code uses Fastled library for neopixel, and OSC. 

[esp32_receive_osc_from_max.ino]()