/*==========================================================================================
                             C O M P U T A Ç Ã O   N A   E S C O L A
                             Universidade Federal de Santa Catarina
                          ---  Support Software for the Instructor ---

Configuration sketch for the wireless operation with Scratch via s2a_fm from Bluetooth modules
HC-05 and others that use Hayes commands ending with com CR+LF.

Hayes Commands or AT-commands are a modem configuration language originally developed in 1981122
for the Hayes Smartmodem with 300 bps of the now defunct Hayes Microcomputer Products. 
Every Hayes command is comprised of "AT" (meaning "attention!") a connector "+" and a keyword followed 
or not by parameters. 
You can find more information here: http://en.wikipedia.org/wiki/Hayes_command_set

Hayes commands used to configure the Bluetooth module:
AT+NAME=ARDUINO**
AT+UART=57600,0,0
where ** is the number of the module you will determine.  

INSTRUCIONS:

To prepare to run this program on an Arduino: 
1. Upload the sketch on the Arduino before making the connections as shown in the diagram.  
2. Turn off the Arduino (unplug the USB port).

How to start:
1. Connect the Arduino to the protoboard or to the HC-05 as shown in the diagram.
2. Connect the Arduino to the USB port of your computer. 
3. Open the serial monitor, configuring its speed to 9600 baud and the end of line to NL and CR.
4. Follow the instructions as they appear on the serial monitor, entering the parameters in the input box in the upper part.

In order to configure another HC-05:
0. There is no need to turn off or to disconnect the Arduino.
1. Disconnect the power cable (red) of the HC-05 from the pin +5V of the Arduino.
2. Disconnect the bluetooth module from the protoboard.
3. Connect an new HC-05.
4. Connect again the power cable at the pin +5V of the Arduino.
5. IMPORTANT!  Press the reset button on the Arduino.
6. Follow the instructions as they appear on the serial monitor, entering the parameters in the input box in the upper part.
====================================
CONNECTIONS OF THE BLUETOOTH MODULE
KEY   : PIN 9    (orange wire)
VCC   : PIN +5v  (red wire)
GND   : PIN GND  (black wire)
TXD   : PIN 10   (green wire)
RXD   : PIN 11   (yellow wire)

AUTHOR: Aldo von Wangenheim - INCoD/UFSC
DATE: 20/06/2014

Based on the code "HC-05-Modify The HC-05 Bluetooth Module Defaults Using AT Commands" by:
AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)
available at: http://www.instructables.com/id/Modify-The-HC-05-Bluetooth-Module-Defaults-Using-A/?ALLSTEPS

==========================================================================================*/

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  pinMode(13, OUTPUT);    // Let's use an onboard LED as communication activity indicator 
  pinMode(9, OUTPUT);     // Pin to activate the configuration mode (KEY pin of the module)
  digitalWrite(9, HIGH);  // Activate configuration mode in order to accept Hayes commands
  Serial.begin(38400);
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
  delay(1000);
  Serial.println("Enter Hayes commands:");
}

void loop()
{

  // Read the output of the HC-05 and send to the serial monitor of the Arduino 
  if (BTSerial.available()){
    digitalWrite(13, HIGH);
    Serial.write(BTSerial.read());
    digitalWrite(13, LOW);
  }

  // Read what was typed on the serial monitor of the Arduino and send to the HC-05
  if (Serial.available()){
    digitalWrite(13, HIGH);
    BTSerial.write(Serial.read());
    
    digitalWrite(13, LOW);
  }
}
