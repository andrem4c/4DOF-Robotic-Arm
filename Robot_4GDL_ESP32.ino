#include <ESP32Servo.h>

// Define servo objetcs for controlling each servo motor:
Servo servo1, servo2, servo3, servo4, servo5;

void setup() {
  
  // Initialize the serial communication:
  Serial.begin(115200);

  // Attach each servo to it's respective GPIO pin:
  servo1.attach(15);   // Joint 1
  servo2.attach(16);   // Joint 2
  servo3.attach(17);   // Joint 3
  servo4.attach(18);   // Joint 4
  servo5.attach(19);   // Gripper
  
}

void loop() {
  
  // Check if at least 2 bytes are available on the serial buffer:
  if (Serial.available() >= 2){
    uint8_t servoID = Serial.read();
    uint8_t angle = Serial. read();
    // Control the servos based on the received servo ID and angle:
    switch (servoID) {
      case 1:
        servo1.write(angle);
        break;
      case 2:
        servo2.write(angle);
        break;
      case 3:
        servo3.write(angle);
        break;
      case 4:
        servo4.write(angle);
        break;
      case 5:
        servo5.write(angle);
        break;
    
    }
  }

}
