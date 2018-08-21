long x;
void setup() {
  pinMode(6, OUTPUT); // Enable
  pinMode(5, OUTPUT); // Step
  pinMode(4, OUTPUT); // Dir - chiều quay
  digitalWrite(6, LOW); // Set Enable low - Enable mức thấp
}

void loop() {
  digitalWrite(6, LOW); // Set Enable low  -  Enable mức thấp
  digitalWrite(4, HIGH); // Set Dir high  - Set chiều quay mức cao

  for (x = 0; x < 4096; x++) {
    digitalWrite(5, HIGH); // Output high - xung mức cao
    delay(1);         // Trễ 1ms
    digitalWrite(5, LOW); // Output low - xung mức thấp
    delay(3);         // Trễ 3ms
  }
  delay(1000);               // dừng 1 giây

  digitalWrite(4, LOW); // Set Dir low - Set chiều quay mức thấp
  
  for (x = 0; x < 4096; x++) {
    digitalWrite(5, HIGH); // Output high - xung mức cao
    delay(1);         // Trễ 1ms
    digitalWrite(5, LOW); // Output low - xung mức thấp
    delay(3);         // Trễ 3ms
  }

  // Serial.println("Pause");
  delay(1000);               // dừng 1 giây
}
