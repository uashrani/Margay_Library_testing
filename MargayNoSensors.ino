/*
 * Margay example: no sensors attached
 */

 #include "Margay.h"
 // Include any sensor libraries.
 // The Northern Widget standard interface is demonstrated here.
 //Sensor mySensor;

 // Instantiate classes
 // Sensor mySensor (for any Northern Widget standard sensor library)
 Margay Logger(MODEL_2v2); // Margay v2.2; UPDATE CODE TO INDICATE THIS

 // Empty header to start; will include sensor labels and information
 String header = "analogRead(VRef), analogRead(BatSense)";  // no sensors, but add new fields to the output file

 // I2CVals for sensors
 // Add these for any sensors that you attach
 // These are used in the I2C device check (for the warning light)
 // But at the time of writing, the logger should still work without this.
 uint8_t I2CVals[] = {};

 // Number of seconds between readings
 // The Watchdog timer will automatically reset the logger after approximately 36 minutes.
 // We recommend logging intervals of 30 minutes (1800 s) or less.
 // Intervals that divide cleanly into hours are strongly preferable.
 uint32_t updateRate = 60;

 void setup(){
     // No sensors attached; header may remain empty.
     // header = header + mySensor.getHeader(); // + nextSensor.getHeader() + ...
     Logger.begin(I2CVals, sizeof(I2CVals), header);
 }

 void loop(){
     Logger.run(update, updateRate);
 }

 String update() {
     initialize();
     //return mySensor.getString(); // If a sensor were attached
     return ""; // Empty string for this example: no sensors attached
 }

 void initialize(){
     //mySensor.begin(); // For any Northern Widget sensor
                         // Other libraries may have different standards
 }
