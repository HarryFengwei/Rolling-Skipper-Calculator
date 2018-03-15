#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int LED = 13;
int Tilt_sensor = 7;
int val = 0;
long t = 0; 
long timeDiff = 0;
int i = 0;
int count = 0;
int flag = 0;
String counts = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode (LED,OUTPUT);
  pinMode (Tilt_sensor,INPUT);
}

void loop() {  
  //val = digitalRead(Tilt_sensor);
  Serial.print("a");
  lcd.print("Rolling Start!!!");
  //delay(2000);
  while(val == LOW){
    val = digitalRead(Tilt_sensor);
  }
  for(i = 0; i <= 10000; i++){
  if(val == HIGH){
    Serial.print("b");
    digitalWrite(LED,HIGH);
    flag = 1;
    val = digitalRead(Tilt_sensor);
    t = millis();
    }
  else if(val == LOW){
    Serial.print("c");
    
    if(flag == 1)
    {
      count++;
      flag = 0;
    }
    digitalWrite(LED,LOW);
    timeDiff = millis() - t;
    if(timeDiff >= 5000){
    Serial.print("d");
    lcd.setCursor(0,0);
    lcd.print("Rolling End.....");
    Serial.print(count);
    Serial.print("z");
    Serial.print(t);
    counts.concat(count);
    lcd.setCursor(0,1);
    lcd.print("Final Grade = " + counts + " ");
    delay(6000);
    lcd.setCursor(0,0);
    lcd.print("Final Grade = " + counts + " ");
    lcd.setCursor(0,1);
    lcd.print("Exit....See you!");
    while(true){
    }
    }
    else{
      Serial.print("f");
      val = digitalRead(Tilt_sensor);
      lcd.print("Hurry Up!");
      delay(100);
    }
  }
  else{
    Serial.print("g");
   lcd.print("Error...See you!");
  }
  }
}
