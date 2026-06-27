#include <DHT.h> 
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 
 
int flame1 = 3; 
int flame2 = 4; 
int vibration = A0; 
int relay = 8; 
int buzzer = 9; 
 
void setup() { 
Serial.begin(9600); 
pinMode(flame1, INPUT); 
pinMode(flame2, INPUT); 
pinMode(vibration, INPUT); 
pinMode(relay, OUTPUT); 
pinMode(buzzer, OUTPUT);  
digitalWrite(relay, LOW);
digitalWrite(buzzer, LOW);  
dht.begin(); 
} 
 
void loop() 
{ 
float temp = dht.readTemperature(); 
int flameState1 = digitalRead(flame1);
int flameState2 = digitalRead(flame2); 
int vibrationValue = analogRead(vibration); 
Serial.print(temp); 
Serial.print(","); 
Serial.print(flameState1);
Serial.print(","); 
Serial.print(flameState2); 
Serial.print(","); 
Serial.println(vibrationValue); 
if(flameState1 == LOW || flameState2 == LOW) 
{ digitalWrite(relay, HIGH);   // sprinkler ON 
 digitalWrite(buzzer, HIGH);  // alarm 
} 
 
else if(vibrationValue > 500) 
{ digitalWrite(buzzer, HIGH);  // vibration alert 
 digitalWrite(relay, LOW); 
} 
else { 
digitalWrite(relay, LOW); 
digitalWrite(buzzer, LOW); 
} 
 
delay(2000); 
} 
