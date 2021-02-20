#include <LiquidCrystal.h>
#include "dht.h"
#define dht_in A0 

dht DHT;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int alert = 13;     // for alert output pin
const int rain_detect_in=A1; //Rain sensor input pin
const int smoke_detect_in=A2; //Smoke sensor input pin
const int soil_moist_detect_in=A3; //Moisture sensor input pin
const int fire_detect_in=6; //Fire sensor input pin



const int MIN = 0;     // sensor minimum
const int MAX = 1024;
const int smokeThreshold = 600;
const int moistureThreshold = 650;
const int delayCount=10;
int fireStatusCounter=0;
int smokeStatusCounter=0;


// custom characters generated for matrix display we are using
byte heart[] =  {  B00000,  B01010,  B11111,  B11111,  B11111,  B01110,  B00100,  B00000  };

byte smiley[] = {  B00000,  B00000,  B01010,  B00000,  B00000,  B10001,  B01110,  B00000  };

byte degree[] = {  B00000,  B00110,  B00110,  B00000,  B00000,  B00000,  B00000,  B00000  };

void setup() {
  pinMode(alert,OUTPUT);
  pinMode(dht_in,INPUT);
  pinMode(fire_detect_in,INPUT);
  pinMode(smoke_detect_in,INPUT);
  pinMode(soil_moist_detect_in,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  printStartingStatement();
  

}

void loop(){
  checkTemp();
  detectRain();
  detectFire();
  detectSmoke();
  detectMoisture();
}// end loop()

void detectMoisture(){
    int moisture=analogRead(soil_moist_detect_in);
    Serial.print("Moisture Value : "); Serial.println(moisture);    
    lcd.clear();
    lcd.setCursor(0,0);  
    if(moisture>900){    lcd.print(".PLEASE INSTALL.");  lcd.setCursor(0,1); lcd.print("DEVICE PROPERLY.");
        Serial.println("SOIL MOISTURE SENSOR NOT PLANTED");        
    }else if(moisture>moistureThreshold){
        lcd.print("MOISTURE TOO");  
        lcd.setCursor(0,1); lcd.print(" LOW "); lcd.setCursor(12,1); lcd.print(String((MAX-moisture)/10));
        Serial.println("Soil moisture too low");        
    }else{
        lcd.print("MOISTURE");  
        lcd.setCursor(0,1); lcd.print("PERFECT"); lcd.setCursor(12,1); lcd.print(String((MAX-moisture)/10)+String("%"));
        Serial.println("Soil moisture Perfect");  
    }



    delay(3000);
    
    
}
void detectSmoke(){
    int smokeValue = analogRead(smoke_detect_in);
    Serial.print("Smoke sensor value");  Serial.println(smokeValue);
    if( smokeValue>smokeThreshold){
        lcd.clear();
        lcd.setCursor(0,0);      lcd.print("....BE ALERT....");  lcd.setCursor(0,1); lcd.print(".SMOKE DETECTED.");
        Serial.println("Fire ALert");
    }else if(smokeStatusCounter++>delayCount){
        lcd.clear();
        lcd.setCursor(0,0);      lcd.print("....NO SMOKE....");  lcd.setCursor(0,1); lcd.print("....DETECTED....");
        smokeStatusCounter=0;
    } 
}

void detectFire(){
      int Flame = digitalRead(fire_detect_in);
       if (Flame== LOW){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("!!!!! FIRE !!!!!"); lcd.setCursor(0,1);  lcd.print("!!!!! ALERT !!!!");
          Serial.println("Fire!!!");  
          showAlert();
          delay(3000);
      }
      else {
            if(fireStatusCounter++>delayCount){
              lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("     NO FIRE    "); 
              fireStatusCounter=0;          
              delay(3000);
            }
            Serial.println("No Fire");  
      }
  
}

void detectRain(){
      int rainReading = analogRead(rain_detect_in);
      int rain_mapped= map(rainReading, MIN, MAX, 0, 3);
      lcd.clear();
      lcd.setCursor(0,0);
      Serial.print("Rain possiblility "); Serial.println((MAX-rain_mapped));     
       switch (rain_mapped) { 
         case 0:    lcd.print("......HEAVY....."); lcd.setCursor(0,1); lcd.print("......RAIN......"); showAlert(); break;
         case 1:    lcd.print("......MIGHT....."); lcd.setCursor(0,1); lcd.print("......RAIN......"); showAlert(); break;
         case 2:    lcd.print(".......NOT......"); lcd.setCursor(0,1); lcd.print("....RAINING.....");  break;
        }
    delay(3000);
}

void checkTemp(){
    DHT.read11(dht_in);  
    lcd.createChar(3,degree);
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("TEMP   = "); lcd.print(DHT.temperature); lcd.write(3); lcd.print("C");
    lcd.setCursor(0,1); lcd.print("HUMID  = "); lcd.print(DHT.humidity); lcd.print(" %");
    
    Serial.print("Temperature = ");    Serial.print(DHT.temperature);     Serial.println("C  ");      
    Serial.print("Humidity    = ");    Serial.print(DHT.humidity);    Serial.println(" %");
    
    delay(3000);
  }




void showAlert(){  
    for(int i=0;i<3;i++){
      digitalWrite(alert, HIGH);      delay(100);
      digitalWrite(alert, LOW);       delay(100);
    }
}

void printStartingStatement(){  
  lcd.createChar(1,smiley);   lcd.createChar(2,heart);
  lcd.noCursor();
  lcd.setCursor(0,0);  lcd.print("^^^Welcome TO^^^");  lcd.setCursor(0,1);  lcd.print("******ARIA******");
  delay(1000);    lcd.clear();
  lcd.setCursor(0,0);  lcd.print("ADVANCE RESEARCH");  lcd.setCursor(0,1);  lcd.print(" IN AGRICULTURE ");
  delay(1000);  lcd.clear();
  lcd.setCursor(0,0);  lcd.print(".MADE IN INDIA "); lcd.write(1);  lcd.setCursor(0,1);  lcd.print("....WITH LOVE ");  lcd.write(2);
  delay(1500);
}
