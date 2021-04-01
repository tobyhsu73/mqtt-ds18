
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 
// Arduino數位腳位2接到1-Wire裝置
#define ONE_WIRE_BUS 2
int i =0;
// 運用程式庫建立物件
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27,16,2);//設定LCD位置0x27,設定LCD大小為16*2
void setup(void)
{
  Serial.begin(115200);
  lcd.init(); //初始化LCD 
  lcd.backlight(); //開啟背光
  // 初始化
  sensors.begin();
}
void loop(void)
{i++;
  // 要求匯流排上的所有感測器進行溫度轉換
  sensors.requestTemperatures();
 
  // 取得溫度讀數（攝氏）並輸出，
  // 參數0代表匯流排上第0個1-Wire裝置
  
  //Serial.print("0");
  Serial.print(sensors.getTempCByIndex(0));
  //Serial.print("1");
  Serial.print(sensors.getTempCByIndex(1));
  //Serial.print("2");
  Serial.print(sensors.getTempCByIndex(2));
  if(i==10){
    lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("t1 ");
  lcd.print(sensors.getTempCByIndex(0));
  lcd.setCursor(8, 0);
  lcd.print("t2 ");
  lcd.print(sensors.getTempCByIndex(1));
  lcd.setCursor(0, 1);
  lcd.print("t3 ");
  lcd.print(sensors.getTempCByIndex(2));
  i=0;
  }
 
  delay(50);
}
