#include "application.h"
#include "beam.h"
// #include "charactermap.h"
// #include "frames.h"

/*
===========================================================================

  This is an example for Beam.

  Beam is a beautiful LED matrix — features 120 LEDs that displays scrolling text, animations, or custom lighting effects.
  Beam can be purchased here: http://www.hoverlabs.co

  Written by John Ryan
  BSD license, all text above must be included in any redistribution

# INSTALLATION
  These 4 library files are required to run a BEAM LED shield
  1. beam.cpp
  2. beam.h
  3. charactermap.h
  4. frames.h
===========================================================================
*/


/* Define necessary pins for Beam */
#define RSTPIN 2        //use any digital pin
#define IRQPIN 3        //currently not used
#define BEAMCOUNT 2     //number of beams daisy chained together

Beam b = Beam(RSTPIN, IRQPIN, BEAMCOUNT);  // Create a Beam instance

unsigned long updateTimer = 0;      // timer used to call our webhooks after an elapsed time
int runNow = 1;                     // flag used to indicate when timer reaches our elapsed time


void setup() {

    Serial.begin(9600);
    Wire.begin();

    Serial.println("Starting Beam example");

    Particle.subscribe("hook-response/get_weather", gotWeatherData, MY_DEVICES);
    Particle.subscribe("hook-response/get_stocks", gotStocksData, MY_DEVICES);

    b.begin();

}

// After firmware is deployed to your Particle Photon & the setup function finishes, this will loop forever (assuming you have sufficient 3.3V power supply for photon)
void loop() {

    if (runNow == 1){
        Particle.publish("get_weather");

        delay(40000); //  delay 30 seconds so that weather data gets scrolled for a few seconds before being overwritten by stocks data

        Particle.publish("get_stocks");
        runNow = 0;
        updateTimer = millis();
    }


    if (millis() - updateTimer > 45000){ // Wait 45 seconds before calling our publish functions again
        runNow = 1;
    }

}

/* get_weather webhook */
void gotWeatherData(const char *name, const char *data) {

    String str = String(data);
    String weatherStr = tryExtractString(str, "<weather>", "</weather>");
    String tempStr = tryExtractString(str, "<temp_f>", "</temp_f>");

    if (tempStr != NULL && weatherStr != NULL) {

      String beamWeather = weatherStr + ", " + tempStr + String("'F ");
      beamWeather.toUpperCase();

      Serial.println("Publishing Weather:");
      Serial.println(beamWeather);

      char buf[1024];
      beamWeather.toCharArray(buf, 1024);

      b.print(buf);
      b.play();

    }

}

// get_stocks webhook
void gotStocksData(const char *name, const char *data) {

    String str = String(data);
    String PriceStr = tryExtractStock(str);

    if (PriceStr != NULL) {

      String beamStock = PriceStr;
      beamStock.toUpperCase();

      Serial.println("Publishing Stock:");
      Serial.println(beamStock);                //output "AAPL","+1.49%","GOOG","+0.53%","MSFT","+0.35%"

      char buf[1024];
      beamStock.toCharArray(buf, 1024);

      b.print(buf);
      b.play();

    }
}

// Removing unwanted characters to format string
String tryExtractStock(String str) {

    str.replace("\",\"", " ");  // remove ","
    str.replace("\"", " ");     // remove remaining "
    str.replace("\n","");       // remove the new lines

    return str;
}

// Returns any text found between a start and end string inside 'str'
// Example: startfooend  -> returns foo
String tryExtractString(String str, const char* start, const char* end) {

    if (str == NULL) {
        return NULL;
    }

    int idx = str.indexOf(start);
    if (idx < 0) {
        return NULL;
    }

    int endIdx = str.indexOf(end);
    if (endIdx < 0) {
        return NULL;
    }

    return str.substring(idx + strlen(start), endIdx);
}
