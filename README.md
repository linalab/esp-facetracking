This guide will show you all the steps to use Face Tracking to control a neopixel matrix. 

# Steps

1. Input: XIAO ESPS3 Camera and touch

2. OBS: convert the signal from the camera into a video source

[3. FaceTracking max patch: Receives the camera and sends OSC messages with face tracking data](#facetracking-max-patch)

4. Wekinator: Receives the OSC messages and trains a model to detect gestures

5. OUTPUT: ESP 32 receives OSC messages from Wekinator and controls a Neopixel Matrix

#
#

 ### FaceTracking max patch
 Receives the camera and sends OSC messages with face tracking data
 
- Download MAX-MSP: https://cycling74.com/downloads
- Install cv.jit in the Package manager
- Run facetracking.maxpat

The patch sends OSC messagges using the port 6448


