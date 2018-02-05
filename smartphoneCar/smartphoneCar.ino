int izqA = 5;
int izqB = 6;
int derA = 9;
int derB = 10;
int vel = 255; // Velocidad de los motores (0-255)
int estado = 'c'; // inicia detenido
int delayTime = 2000;
boolean infiniteMode = false;
void setup() {
  Serial.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) { // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if (estado == 'a') { // Forward
    Serial.println(estado);
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = 'c';
    }
  }
  if (estado == 'd') { // right
    Serial.println(estado);
    analogWrite(derB, vel);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = 'c';
    }
  }
  if (estado == 'c') { // Stop
    Serial.println(estado);
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
  }
  if (estado == 'b') { // left
    Serial.println(estado);
    analogWrite(derB, 0);
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = 'c';
    }
  }

  if (estado == 'e') { // Reverse
    Serial.println(estado);
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
    analogWrite(derB, vel);
    analogWrite(izqB, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = 'c';
    }
  }
  if (estado == 'f') { // Boton ON se mueve sensando distancia
    if (infiniteMode == false) {
      infiniteMode = true;
      Serial.println("InfiniteMode");
    }

  }
  if (estado == 'g') { // Boton OFF, detiene los motores no hace nada

    if (infiniteMode == true) {
      infiniteMode = false;
      Serial.println("NoneInfiniteMode");
    }
  }
}