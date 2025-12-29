#include "esp_sleep.h"
#define WAKE_UP_PIN GPIO_NUM_33
#define WAKE_UP_PIN2 GPIO_NUM_34

int wert = 0;
double voltage = 0;
double tempC = 0;

uint64_t bitmask = BUTTON_PIN_BITMASK(WAKEUP_GPIO_NUM_33) | BUTTON_PIN_BITMASK(WAKEUP_GPIO_NUM_34);
                       

        void setup(){
           Serial.begin(115200);
            Serial.println("Start"); 
           pinMode(26, INPUT);
           pinMode(WAKE_UP_PIN, INPUT_PULLUP);
           pinMode(WAKE_UP_PIN2, INPUT_PULLUP);
           
           Serial.println("Going to Sleep");
           
           wert = analogRead(26);
           voltage = ((float) wert / 4096.0) * 3300;
           tempC = (voltage - 500) * 0.1;
           
           Serial.println(tempC);
           
           esp_sleep_enable_ext0_wakeup(bitmask, 0);
           esp_deep_sleep_start();

           
          
           
           Serial.println("Error");
           delay(2000);
        }

        void loop(){    
        }
        
