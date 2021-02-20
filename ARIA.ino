#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTTYPE DHT11   
#define DHTPIN 6
DHT dht = DHT(DHTPIN, DHTTYPE);
 


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int rain_detect_in=A0;
int soil_moisture_in=A1;
int soil_moisture_value;
int soil_moisture_limit=300;
int alert = 13;
const int rainMin = 0;     // sensor minimum
const int rainMax = 1024;


// custom characters generated for matrix display we are using
byte heart[] = {  B00000,  B01010,  B11111,  B11111,  B11111,  B01110,  B00100,  B00000 };

byte smiley[] = {  B00000,  B00000,  B01010,  B00000,  B00000,  B10001,  B01110,  B00000  };

void setup() {
  pinMode(alert,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  
  delay(1000);//Wait before accessing Sensor
  
 // printStartingStatement();
  

}

void loop(){
  checkTemp();
  //detectRain();
}// end loop()

void detectRain(){
      int rainReading = analogRead(rain_detect_in);
      int rain_mapped= map(sensorReading, sensorMin, sensorMax, 0, 3);
       switch (range) { 
         case 0:    
            Serial.println("Rain Warning");
            break;
         case 1:    
            Serial.println("Not Raining");
            break;
        }
  delay(1000);
      
      
  
  
  }

void checkTemp(){
  
float h = dht.readHumidity();
  // Read the temperature as Celsius:
  float t = dht.readTemperature();
  // Read the temperature as Fahrenheit:
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Compute heat index in Fahrenheit (default):
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius:
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" \xC2\xB0");
  Serial.print("C | ");
  Serial.print(f);
  Serial.print(" \xC2\xB0");
  Serial.print("F ");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" \xC2\xB0");
  Serial.print("C | ");
  Serial.print(hif);
  Serial.print(" \xC2\xB0");
  Serial.println("F");
  }




void showError(){  
    for(int i=0;i<3;i++){
      digitalWrite(alert, HIGH);
      delay(100);
      digitalWrite(alert, LOW); 
      delay(100);
    }
}

void printStartingStatement(){  
   lcd.createChar(1,smiley);
   lcd.createChar(2,heart);
  lcd.noCursor();
  lcd.setCursor(0,0);  lcd.print("^^^Welcome TO^^^");  lcd.setCursor(0,1);  lcd.print("******ARIA******");
  delay(1000);  
  lcd.clear();
  lcd.setCursor(0,0);  lcd.print("ADVANCE RESEARCH");  lcd.setCursor(0,1);  lcd.print(" IN AGRICULTURE ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);  lcd.print(".MADE IN INDIA "); lcd.write(1);  lcd.setCursor(0,1);  lcd.print("....WITH LOVE ");  lcd.write(2);
  delay(1500);
  lcd.clear();
}
