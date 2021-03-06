int izqA = 5;
int izqB = 6;
int derA = 9;
int derB = 10;
int vel = 255; // Velocidad de los motores (0-255)
int estado = 'h'; // inicia detenido
int delayTime = 2000;
boolean moving = false;
//char val;
void setup() {
  Serial.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  Serial.println("Car Control!");
}
void loop() {
  if (Serial.available() > 0) { // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if (estado == 'a') { // Forward
    Serial.println("Forward:");
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
    delay(delayTime);
    estado = 's';
  }
  if (estado == 'd') { // right
    Serial.println("Right:");
    analogWrite(derB, vel);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, vel);
    delay(delayTime);
    estado = 's';
  }
  if (estado == 's') { // Stop
    Serial.println("Stop:");
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
    delay(delayTime);
  }
  if (estado == 'b') { // left
    Serial.println("Left:");
    analogWrite(derB, 0);
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);
    delay(delayTime);
    estado = 's';
  }
  if (estado == 'e') { // Reverse
    Serial.println("Reverse:");
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
    analogWrite(derB, vel);
    analogWrite(izqB, vel);
    delay(delayTime);
    estado = 's';
  }
  if (estado == 'f') { 
    Serial.println("Right:");
      analogWrite(derB, 200);
      analogWrite(izqB, 0);
      analogWrite(derA, vel);
      analogWrite(izqA, vel);
      delay(delayTime);
    estado = 's';
  }
  if (estado == 'g') { 
    Serial.println("Left:");
      analogWrite(derB, 0);
      analogWrite(izqB, 200);
      analogWrite(derA, vel);
      analogWrite(izqA, vel);
      delay(delayTime);
    estado = 's';
  }

}
