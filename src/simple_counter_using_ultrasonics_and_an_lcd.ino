#include <LiquidCrystal.h>
#include <Servo.h>
#define pass_distance 80
bool trying_to_get_in = false;
bool trying_to_get_out = false;
int count = 0;

LiquidCrystal lcd(2,3,4,5,6,7);//RS, E, D4,D5,D6,D7
Servo testservo;

const int pingPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 9; // Echo Pin of Ultrasonic Sensor

const int pingPin2 = 10; // Trigger Pin of Ultrasonic Sensor
const int echoPin2 = 11; // Echo Pin of Ultrasonic Sensor
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("IoT Club");
  testservo.attach(9);
  pinMode(10, INPUT);
  pinMode(pingPin, OUTPUT);
  pinMode(pinPin2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
  delay(2000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(count < 0 ) count = 0;
  //--------------------------------------------------------
  lcd.setCursor(0,0);
  lcd.print("Total people");
  lcd.setCursor(0,1);
  lcd.print(count);
      long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   int d1 = microsecondsToCentimeters(duration);
   //---------------------------------------------------
          long duration2, inches2, cm2;
   pinMode(pingPin2, OUTPUT);
   digitalWrite(pingPin2, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
   pinMode(echoPin2, INPUT);
   duration2= pulseIn(echoPin2, HIGH);
   inches2 = microsecondsToInches(duration2);
   int d2 = microsecondsToCentimeters(duration2);

  
  
   //-------------------------------------------

   Serial.print("ultrasonic1 => ");
   Serial.print(d1);
   Serial.print("  Ultrasonic2 => ");
   Serial.println(d2);
   

 if (d1 < pass_distance && trying_to_get_out == false){
  trying_to_get_in = true;
 }
 else if (d2 < pass_distance && trying_to_get_in == false){
  trying_to_get_out = true;
 }
 if (d2 < pass_distance && trying_to_get_in == true){
  count++;
  trying_to_get_in = false; 
  delay(500);
 }


 else if (d1 < pass_distance && trying_to_get_out == true){
  count--;
  trying_to_get_out = false;
  delay(500);
 }
 delay(100);
}


long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
