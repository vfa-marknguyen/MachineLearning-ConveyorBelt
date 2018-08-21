
#define TRIG_PIN 3    // Pin to send trigger pulse
#define ECHO_PIN 2    // Pin to receive echo pulse
#define TIME_OUT 5000 // Time_out của pulseIn là 5000 microsecond
#define DIR 4
#define STEP 5
#define SERVO_ENABLE 6
#define CAPTURE_TRIGGER 7
#define LED 9
#define LED1 10

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  //-------------------------
  pinMode(SERVO_ENABLE, OUTPUT); // Enable
  pinMode(STEP, OUTPUT); // Step
  pinMode(DIR, OUTPUT); // Dir
  digitalWrite(SERVO_ENABLE, LOW); // Set Enable low
  //-------------------------
  pinMode(CAPTURE_TRIGGER, OUTPUT);
  //-------------------------
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
}

float getDistance()
{
  long duration, distanceCm;
  // Send a pulse with duration of 10uS from Trig PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Response time to ECHO PIN
  duration = pulseIn(ECHO_PIN, HIGH, TIME_OUT);

  // Compute distance
  distanceCm = duration / 29.1 / 2;
  return distanceCm;
}
void stopDistance() {
  digitalWrite(TRIG_PIN, LOW);
}

void startServo() {
  digitalWrite(SERVO_ENABLE, LOW); // Set Enable low
}

void run1circle() {
  long x;
  digitalWrite(DIR, LOW); // Set Dir high
  // Full a circle step
  for (x = 0; x < 200 / 16; x++) {
    digitalWrite(STEP, HIGH);
    delay(1);         // DElay 1ms
    digitalWrite(STEP, LOW);
    delay(3);         // Delay 3ms
  }
}
void stopServo() {
  digitalWrite(SERVO_ENABLE, HIGH); // Set Enable low
}

void startCamera() {
  digitalWrite(CAPTURE_TRIGGER, HIGH); //set 5v
}

void stopCamera() {
  digitalWrite(CAPTURE_TRIGGER, LOW); //set 5v
}

void startLED() {
  digitalWrite(LED, HIGH); //set 5v
  digitalWrite(LED1, HIGH); //set 5v
}

void stopLED() {
  digitalWrite(LED, LOW); //set 5v
  digitalWrite(LED1, LOW); //set 5v
}

int flag = 0;
long distance = 100;
int count = 1000;

void loop() {
  Serial.print("Flag: ");
  Serial.println(flag);

  switch (flag) {
    case 0: {
        startServo();
        flag = 1;
        break;
      }
    case 1: {
      run1circle();
      distance = getDistance();
      Serial.println(distance);
      if (0 < distance && distance < 10) {
        flag = 2;
      }
      break;
    }
    case 2: {
        stopServo();
        stopDistance();
        distance = 100;
        flag = 3;
        delay(400);
        break;
      }
    case 3: {
        startLED();
        delay(2000);
        startCamera();
        delay(300);
        stopCamera();
        delay(2000);
        flag = 4;
        break;
      }
    case 4: {
        startServo();
        for (int k = 0; k < 20; k++) {
          run1circle();
        }
        getDistance();
        flag = 0;
        stopLED();
        break;
      }
  }

  //  if (flag == 0) {
  //    startServo();
  //    run1circle();
  //    distance = getDistance();
  //  }
  //  Serial.println(distance);
  //  //  Serial.print("Flag: ");
  //  //  Serial.println(flag);
  //
  //  if (distance < 10) {
  //    stopServo();
  //    stopDistance();
  //    distance = 100;
  //    flag = 1;
  //    delay(400);
  //  }
  //  //  Serial.print("Flag: ");
  //  //  Serial.println(flag);
  //  if (flag == 1) {
  //    startLED();
  //    delay(2000);
  //    startCamera();
  //    delay(300);
  //    stopCamera();
  //    delay(2000);
  //    startServo();
  //    for (int k = 0; k < 20; k++) {
  //      run1circle();
  //    }
  //    getDistance();
  //    flag = 0;
  //    stopLED();
  //  }
}
