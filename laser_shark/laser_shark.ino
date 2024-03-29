const int trigPin = 11;
const int echoPin = 10;
const int in1 = 9;
const int in2 = 8;
const int in3 = 4;
const int in4 = 3;

const int ledPin = 7;
const int buzzerPin = 2;

const int irReceiverAnalogPin = A0;

long duration, distance;
int irSensorValue;

boolean isHit = false;

void setup()
{
  pinMode(irReceiverAnalogPin, INPUT);
  pinMode(echoPin, INPUT);
    
  pinMode(trigPin, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
}
  
void loop()
{
  irSensorValue = analogRead(irReceiverAnalogPin);

   Serial.print("\nsensor = ");
  Serial.print(irSensorValue);

  if(irSensorValue < 100){ //checks if object is there or not
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }else{
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 500);
    isHit = true;
  }

  if (isHit) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    isHit = false;

    delay(20000);

    return;
  }
  
  // Reset pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(12);
  digitalWrite(trigPin, LOW);

  // Check for distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance < 30)
  {
    // Obstacle found
    // Rotate rover
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  else
  {
    // Move forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  delay(90);
}
