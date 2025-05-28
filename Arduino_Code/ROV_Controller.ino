// Motor Driver Pins
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;

// PWM Speed Control Pins (L298 ENA & ENB)
const int enA = 5;  // Controls Motor A (in1 & in2)
const int enB = 6;  // Controls Motor B (in3 & in4)

// Joystick Pins
const int joyX = A0;
const int joyY = A1;

void setup() {
  // Motor direction pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // PWM speed control pins
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  // Set full speed (0-255)
  analogWrite(enA, 255); // Max speed
  analogWrite(enB, 255); // Max speed

  // Start serial for debug
  Serial.begin(9600);
}

void loop() {
  int xVal = analogRead(joyX); // X-axis
  int yVal = analogRead(joyY); // Y-axis

  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.println(yVal);

  // Deadzone: Stop if joystick is near center
  if (xVal > 450 && xVal < 570 && yVal > 450 && yVal < 570) {
    stopMotors();
  }
  // Move Forward
  else if (yVal > 600) {
    forward();
  }
  // Move Backward
  else if (yVal < 400) {
    backward();
  }
  // Turn Left
  else if (xVal < 400) {
    left();
  }
  // Turn Right
  else if (xVal > 600) {
    right();
  }
  else {
    stopMotors(); // Safety fallback
  }

  delay(100); // Stability delay
}

// Move forward
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Move backward
void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// Turn left
void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Turn right
void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// Stop motors
void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
