int izqA = 5;
int izqB = 6;
int derA = 9;
int derB = 10;
int vel = 255; // Velocidad de los motores (0-255)
int estado = 'g'; // inicia detenido
//char val;
void setup() {
  Serial.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  Serial.println("Car Control!");
  //Serial.println(Serial.available());
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
  }
  if (estado == 'd') { // right
    Serial.println("Right:");
    analogWrite(derB, 127);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
  }
  if (estado == 'c') { // Stop
    Serial.println("Stop:");
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
  }
  if (estado == 'b') { // left
    Serial.println("Left:");
    analogWrite(derB, 0);
    analogWrite(izqB, 127);
    analogWrite(izqA, vel);
    analogWrite(derA, vel);
  }
  if (estado == 'e') { // Reverse
    Serial.println("Reverse:");
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
    analogWrite(derB, vel);
    analogWrite(izqB, vel);
  }
  if (estado == 'f') { // Boton ON se mueve sensando distancia
  }
  if (estado == 'g') { // Boton OFF, detiene los motores no hace nada
  }
}
