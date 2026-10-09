/*I, Roshan Adhikari, 0307822a, certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else. V0.1*/

#include <Arduino.h>
void setup() {
 // configure the USB serial monitor
 Serial.begin(115200);
}

void loop() {
    int iVal;
    // read digitized value from the D1 Mini's A/D convertor
    iVal = analogRead(A0);
    // convert digitized value to a String for printing
    String digitalOutput = String(iVal);
    //  convert digitized value to a String for temperature interpretation
    String temperatureOutput = String((iVal*3.3)/1024.0*15.15);

    
    // print value to the USB port
    //  Serial.println("Value: "+String(iVal));
    //  Serial.println("Digitized value of "+String(iVal)+" is equivalent to an Analog Voltage of "+ String((iVal*3.3)/1024.0)+" Volts");

    // print value to the USB port with temperature interpretation
    if (temperatureOutput.toFloat() < 15) {
    Serial.println("Digitized value of " + digitalOutput+" is equivalent to an temperature of "+temperatureOutput+" degrees Celsius, which is cold!");
    } 
    else if (temperatureOutput.toFloat() >= 15 && temperatureOutput.toFloat() < 25) {
    Serial.println("Digitized value of " + digitalOutput+" is equivalent to an temperature of "+temperatureOutput+" degrees Celsius, which is perfect!");
    } 
    else if (temperatureOutput.toFloat() >= 25 && temperatureOutput.toFloat() < 30) {
    Serial.println("Digitized value of " + digitalOutput+" is equivalent to an temperature of "+temperatureOutput+" degrees Celsius, which is warm!");
    } 
    else if (temperatureOutput.toFloat() >= 30) {
    Serial.println("Digitized value of " + digitalOutput+" is equivalent to an temperature of "+temperatureOutput+" degrees Celsius, which is hot!");
    }

    // Serial.println("Digitized value of " + digitalOutput+" is equivalent to an temperature of "+temperatureOutput+" degrees Celsius");
    // wait 0.5 seconds (500 ms)
    delay(500);
}