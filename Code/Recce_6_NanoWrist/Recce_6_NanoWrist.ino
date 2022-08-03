//Recce Bata ver 0.6.2
//coded by Simon
//In Arduis Fidelis

#define trig1 2 // These two are wwhere you connect your ultra sound sensor 
#define echo1 3

const int Switch = 8; // Use pin 8 or change it to the pin you're using
int SwitchState = 0;

void Check1(); // Walking check
void Check2(); // Depth Check

int Motor = 6; // For better feedback use Analog pins to make motor spin at diffrent speeds
               // Chance DigitalWrite to AnalogWrite and High & Low to a number from 0 - 255
               
float duration, distance; 

void setup() {

  Serial.begin (9600); // If you want to adjust then anything with Serial print will show you the distance or what code is being run. 

  pinMode(Motor, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(Switch, INPUT);


  digitalWrite (Motor, HIGH);  // This part is to test motors on start up. 
  delay(2000);
  digitalWrite (Motor, LOW);
  delay(500);
  digitalWrite (Motor, HIGH);
  delay(2000);
  digitalWrite (Motor, LOW);
  delay(500);

}

void loop() {

  SwitchState = digitalRead(Switch); // Reads the state of the Wrist switch 
  delay(60);

  if (SwitchState == HIGH)
  {
    Serial.println("Switch High");
    Check1();   
  }
  else if (SwitchState == LOW)

  {
    Serial.println("Switch Low");
    Check2();
  }
  else
  {
    Serial.println("ERROR");
  }

}

void Check1() //This will be the default code for the wrist sensor. senses objects from a minimal distance only.

{
  digitalWrite(trig1, LOW);        // This code just helps with measurements                                     
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  duration = pulseIn(echo1, HIGH);
  distance = (duration / 2) * 0.0343;

  Serial.println("Check 1");
  Serial.println(distance);
  delay(50);

  if (distance <= 8)

  {
    digitalWrite (Motor, HIGH);
    delay(2000);
    digitalWrite (Motor, LOW);
    delay(20);

  }
  else if (distance >= 8 and distance <= 15)

  {
    digitalWrite (Motor, HIGH);
    delay(300);
    digitalWrite (Motor, LOW);
    delay(20);
    digitalWrite (Motor, HIGH);
    delay(300);
    digitalWrite (Motor, LOW);
    delay(20);
  }
  else
  {
    digitalWrite (Motor, LOW);
    delay(20);
  }
}

void Check2() // Depth Check

{
  Serial.println("Check 2"); //Once the switch is flipped this code will be run and give feed back for different distances. 
                             //I've included 3 setting but you may alter and for better results use the Analog pins to vary the vibration strength
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  duration = pulseIn(echo1, HIGH);
  distance = (duration / 2) * 0.0343;

  Serial.println("Check 2");
  Serial.println(distance);
  delay(50);

  if (distance <= 8)
  {
    digitalWrite (Motor, HIGH);
    delay(2000);
    digitalWrite (Motor, LOW);
    delay(20);

  }
  else if (distance >= 8 and distance <= 15)

  {
    digitalWrite (Motor, HIGH);
    delay(1000);
    digitalWrite (Motor, LOW);
    delay(20);
  }
  else if (distance >= 15 and distance <= 30)

  {
    digitalWrite (Motor, HIGH);
    delay(500);
    digitalWrite (Motor, LOW);
    delay(20);
  }
  else
  {
    digitalWrite (Motor, LOW);
    delay(20);
  }
}
