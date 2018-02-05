#include <SoftwareSerial.h>
SoftwareSerial BT(12, 11);
int izqA = 5;
int izqB = 6;
int derA = 9;
int derB = 10;
int vel = 255; // Velocidad de los motores (0-255)
int estado = 0; // inicia detenido
int delayTime = 2000;
boolean infiniteMode = false;
//char val;
void setup() {
  BT.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  BT.println("Car Control!");
}
void loop() {
  if (BT.available() > 0) { // lee el bluetooth y almacena en estado
    estado = BT.read();
  }
  if (estado == '1') { // Forward
    BT.println("Forward:");
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = '0';
    }
  }
  if (estado == '2') { // right
    BT.println("Right:");
    analogWrite(derB, vel);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = '0';
    }
  }
  if (estado == '0') { // Stop
    BT.println("Stop:");
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
    delay(delayTime);
  }
  if (estado == '4') { // left
    BT.println("Left:");
    analogWrite(derB, 0);
    analogWrite(izqB, vel);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = '0';
    }
  }
  if (estado == '6') { // Reverse
    BT.println("Reverse:");
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
    analogWrite(derB, vel);
    analogWrite(izqB, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = '0';
    }
  }
  if (estado == '3') {
    BT.println("Right:");
    analogWrite(derB, 200);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = '0';
    }
  }
  if (estado == '5') {
    BT.println("Left:");
    analogWrite(derB, 0);
    analogWrite(izqB, 200);
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
    if (!infiniteMode) {
      delay(delayTime);
      estado = '0';
    }
  }
  if (estado == '8' && infiniteMode == true) {
    infiniteMode = false;
    BT.println("NoneInfiniteMode");
  }
  if (estado == '9' && infiniteMode == false) {
    infiniteMode = true;
    BT.println("InfiniteMode");
  }
}
