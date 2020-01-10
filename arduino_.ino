#define sensor_pin A0
#define buzzer_pin 10
 
#define led_r 5
#define led_g 6
#define led_b 7
 
#define preheat_time 5000
  
#define threshold 100

void setup()
{
 
pinMode(buzzer_pin, OUTPUT);
pinMode(led_r, OUTPUT);
pinMode(led_g, OUTPUT);
pinMode(led_b, OUTPUT);

 
digitalWrite(led_r, HIGH);
digitalWrite(led_g, HIGH);
digitalWrite(led_b, HIGH);
  
Serial.begin(9600);
 
Serial.println("Sensor isitiliyor...");
digitalWrite(led_b, LOW);
delay(preheat_time);
 
digitalWrite(led_b, HIGH);
delay(1000);
}

void loop()
{
int sensorValue = analogRead(sensor_pin);
if (sensorValue <= threshold)
alarm(100);
  
else
digitalWrite(led_g, LOW);
Serial.println(sensorValue);
delay(1);
}


void alarm(unsigned int duration)
{
tone(buzzer_pin, 440);
digitalWrite(led_r, LOW);
digitalWrite(led_g, HIGH);
delay(duration);
noTone(buzzer_pin);
digitalWrite(led_r, HIGH);
digitalWrite(led_g, HIGH);
delay(duration);
}
