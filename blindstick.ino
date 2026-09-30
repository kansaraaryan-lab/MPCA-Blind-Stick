#include <Servo.h>

Servo scannerServo;

// Pin connections
const int trigPin = 7;
const int echoPin = 6;
const int servoPin = 9;
const int buzzerPin = 8;

// Detection distance in centimeters
const int detectionDistance = 50;

// Servo scanning angles
const int minAngle = 30;
const int maxAngle = 150;

// Measure distance using HC-SR04
long getDistance() {

  // Make sure TRIG starts LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  long duration = pulseIn(echoPin, HIGH, 30000);

  // If no echo is received
  if (duration == 0) {
    return 999;
  }

  // Convert time to distance in cm
  long distance = duration * 0.0343 / 2;

  return distance;
}

// Check for obstacle
void checkObstacle() {

  long distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Obstacle detected
  if (distance > 0 && distance <= detectionDistance) {

    // Beep
    tone(buzzerPin, 2000);
    delay(100);

    noTone(buzzerPin);
    delay(100);

  } 
  else {

    noTone(buzzerPin);
  }
}

void setup() {

  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  scannerServo.attach(servoPin);

  // Start at centre
  scannerServo.write(90);

  delay(1000);

  Serial.println("SMART RADAR BLIND STICK");
  Serial.println("System Started");
}

void loop() {

  // Scan from left to right
  for (int angle = minAngle; angle <= maxAngle; angle += 10) {

    scannerServo.write(angle);

    // Give servo time to move
    delay(80);

    checkObstacle();
  }


  // Scan from right to left
  for (int angle = maxAngle; angle >= minAngle; angle -= 10) {

    scannerServo.write(angle);

    // Give servo time to move
    delay(80);

    checkObstacle();
  }
}
