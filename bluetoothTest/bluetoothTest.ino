#include <SoftwareSerial.h>
SoftwareSerial BT(12,11);
const byte ledPin = 13;
char val;

void setup() {
  pinMode(ledPin, OUTPUT);
  BT.begin(9600);
  BT.print("BT is ready!");
}

void loop() {
  if (BT.available()) {
    val = BT.read();
    switch (val) {
      case '0':
        digitalWrite(ledPin, LOW);
        break;
      case '1':
        digitalWrite(ledPin, HIGH);
        break;
    }
  }

}
