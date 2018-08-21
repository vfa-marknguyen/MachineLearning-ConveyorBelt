

#define HALF_RELEASE_PIN 11
#define FULL_RELEASE_PIN 9
void setup() {
  // put your setup code here, to run once:
  pinMode(HALF_RELEASE_PIN, OUTPUT);
  digitalWrite(HALF_RELEASE_PIN, LOW);
  pinMode(FULL_RELEASE_PIN, OUTPUT);
  digitalWrite(FULL_RELEASE_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(HALF_RELEASE_PIN, HIGH);
  delay(5000);

  // 全押し（写真撮影）
  digitalWrite(FULL_RELEASE_PIN, HIGH);
  delay(5000);

  // スイッチオフ
  digitalWrite(HALF_RELEASE_PIN, LOW);
  digitalWrite(FULL_RELEASE_PIN, LOW);
  delay(3000);
}
