int izqA = 5;
int izqB = 6;
int derA = 9;
int derB = 10;
int vel = 255;
int estado = 'g';
char val;
void setup() {
  Serial.begin(9600);
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  Serial.println("Car Control!");
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
    Serial.print("Testval:");
    Serial.println(val);
    if (val == '1') { // Forward
      Serial.println("Forward:");
      analogWrite(derB, 0);
      analogWrite(izqB, 0);
      analogWrite(derA, vel);
      analogWrite(izqA, vel);
    }
    if (val == '2') { // right
      Serial.println("Right:");
      analogWrite(derB, 127);
      analogWrite(izqB, 0);
      analogWrite(derA, vel);
      analogWrite(izqA, vel);
    }
    if (val == '3') { // Stop
      Serial.println("Stop:");
      analogWrite(derB, 0);
      analogWrite(izqB, 0);
      analogWrite(derA, 0);
      analogWrite(izqA, 0);
    }
    if (val == '4') { // left
      Serial.println("Left:");
      analogWrite(derB, 0);
      analogWrite(izqB, 127);
      analogWrite(izqA, vel);
      analogWrite(derA, vel);
    }

    if (val == '5') { // Reverse
      Serial.println("Reverse:");
      analogWrite(derA, 0);
      analogWrite(izqA, 0);
      analogWrite(derB, vel);
      analogWrite(izqB, vel);
    }
  }
}

