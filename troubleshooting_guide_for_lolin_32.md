# Troubleshooting guide for Lolin 32

Some issues and possible solutions for connecting and uploading sketches in LOLIN 32

## It doesn’t connect to the computer:

- Is the USB cable able to send DATA or only power?  You must use a DATA cable
- Maybe the cable is too long?
- Did you install everything correctly?
    - Here a nice tutorial on how to install the board:
    [https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
        
        Be sure you have the last version of the URL that you paste in the arduino preferences: [https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)
        
    
    Usually this install everything you need to make it work, you must allow arduino to install drivers, etc.
    
    - With some windows you may need to install the manually
    [https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)

Besides the board manager the ESP may need a Driver:  

- For Mac OSX 10.14 and greater, do not install any supplimentary drivers!

[https://www.wemos.cc/en/latest/ch340_driver.html](https://www.wemos.cc/en/latest/ch340_driver.html)

If you soldered the ESP, check if there’s some soldering shortcutting the components. 

## The ESP looks connected but it doesn’t upload the code (Failed uploading: uploading error: exit status 2)

- Try changing the Uploadspeed in TOOLS menu to 115200

## **Error : C:\\Users\\ User\\Documents \\Arduino\\ 
hardware\\ espressif\\ esp32/tools /xtensa-esp32-elf /bin/ xtensa-esp32-
 elf-g++”: file does not exist**

- This happens when there are multiple Arduino IDE versions installed. Make sure you are running the Arduino IDE where you installed the ESP32 add-on.

## **Error "bad CPU type in executable" on macOS**

- You may need to install Rosetta: 
[https://support.arduino.cc/hc/en-us/articles/7765785712156-Error-bad-CPU-type-in-executable-on-macOS](https://support.arduino.cc/hc/en-us/articles/7765785712156-Error-bad-CPU-type-in-executable-on-macOS)

---

## Issues with the sketches:

### It doens’t upload:

- Try changing the Uploadspeed in TOOLS menu to 115200 (again)

### The led doesn’t blink…

- Check the connections in the protoboard!
- Are you using the correct pin? Not all the ESP have the same connections, check the name of your ESP and look for the **PINOUT** picture:
    - Lolin D32:  [https://mischianti.org/esp32-wemos-lolin-d32-high-resolution-pinout-and-specs/](https://mischianti.org/esp32-wemos-lolin-d32-high-resolution-pinout-and-specs/)
    - Lolin 32 Lite: [https://mischianti.org/esp32-wemos-lolin32-lite-high-resolution-pinout-and-specs/](https://mischianti.org/esp32-wemos-lolin32-lite-high-resolution-pinout-and-specs/)
- Try another GND output

### I only see weird characters in the monitor:

- You must change the baud rate in the Serial Monitor to match the code: 115200

---

### Useful info.

Lolin D32 changes between boards

[https://www.youtube.com/watch?v=yZjpYmWVLh8](https://www.youtube.com/watch?v=yZjpYmWVLh8)
