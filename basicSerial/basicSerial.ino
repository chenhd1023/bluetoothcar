const byte LED = 13;
char val;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome to Arduino");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    val = Serial.read();
    if (val == '1') {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    } else if (val == '0') {
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
  }
}
