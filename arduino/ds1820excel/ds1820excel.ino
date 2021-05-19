
#include <OneWire.h>
#include <DallasTemperature.h>


// Arduino數位腳位2接到1-Wire裝置
#define ONE_WIRE_BUS 2
int i =0;
// 運用程式庫建立物件
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
 
  Serial.begin(9600);
  Serial.println("CLEARSHEET");
  Serial.println("LABEL,Time,Data");
  // 初始化
  sensors.begin();
}
void loop(void)
{i++;
  // 要求匯流排上的所有感測器進行溫度轉換
  sensors.requestTemperatures();
 
  // 取得溫度讀數（攝氏）並輸出，
  // 參數0代表匯流排上第0個1-Wire裝置
  Serial.print("Data"); 
  Serial.print(","); 
  //Serial.print("0");
  Serial.print("TIME");
  Serial.print(",");
  Serial.println(sensors.getTempCByIndex(0));
  //Serial.print("1");


 
  delay(1000);
}
