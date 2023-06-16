// Ahmet Furkan Demir
// 19010011019

#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
dht DHT;
int whichOne = 0;
unsigned long sayac = 0;
String t_lcd = "Temperature";
String h_lcd = "Humidity";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("N. Interneti");
  lcd.setCursor(0, 1);
  lcd.print("A. Furkan Demir");
}

void loop() {
  
  float temperature = 0;
  float humidity = 0;
  String temp ="";
  String humi ="";
  unsigned long anlik_zaman = millis();

  if(anlik_zaman-sayac >= 2000) 
  {
    DHT.read22(13);
    temperature = DHT.temperature;
    humidity = DHT.humidity; 
    Serial.println("Temperature: " + String(temperature) + "°C || Humidity: " + String(humidity) + "%");
    sayac = anlik_zaman;
    if(temperature>=0)
    {
      temp = "-HIGH";
    } 
    else if(temperature<0)
    {
      temp = "-LOW";
    }
    if(humidity>=50)
    {
      humi = "-HIGH";
    }
    else if(humidity<50)
    {
      humi = "-LOW";
    }
    if(whichOne == 0)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2, 0);
      lcd.print(t_lcd);
      lcd.setCursor(3, 1);
      lcd.print(temperature + temp);
      whichOne = 1;
    }
    else
    {
      lcd.begin(16, 2);
      lcd.begin(16, 2);
      lcd.setCursor(4, 0);
      lcd.print(h_lcd);
      lcd.setCursor(3, 1);
      lcd.print(humidity + humi);
      whichOne = 0;
    }
  }
}





