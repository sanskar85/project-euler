#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int soil_moisture_in=A0;
int soil_moisture_value;
int soil_moisture_limit=300;
int BUZZER =13;
int alert = 10;


// custom characters generated for matrix display we are using
byte heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

byte smiley[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};

void setup() {
  pinMode(alert,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  showError();
  
 // printStartingStatement();
  

}

void loop() {
  // put your main code here, to run repeatedly:

}

void showError(){  
  for(int i=0;i<3;i++){    
    analogWrite(alert, 255);
    delay(100);
    analogWrite(alert, 0);   
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
  lcd.setCursor(0,0);  lcd.print(".MADE IN INDIA "); lcd.write(1);
  lcd.setCursor(0,1);  lcd.print("....WITH LOVE ");  lcd.write(2);
  delay(1500);
  lcd.clear();
}