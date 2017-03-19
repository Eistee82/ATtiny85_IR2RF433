#include <IRremote.h>
IRrecv irrecv(0);
decode_results results;

#include <RCSwitch.h>
RCSwitch RF433 = RCSwitch();

void setup() {
  pinMode(1, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver

  RF433.enableTransmit(3);
  RF433.setProtocol(1);
  RF433.setPulseLength(258);
  RF433.setRepeatTransmit(6);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    digitalWrite(1, HIGH);
    delay(100);
    digitalWrite(1, LOW);
    switch (results.value) {
      case 0x3E:    // Alle Lampen Aus
        RF433.switchOff('b', 2, 1);
        break;
      case 0x1E:    // Alle Lampen Ein
        RF433.switchOn('b', 2, 1);
        break;
      case 0x53E:   // Scene aus
        RF433.switchOn('b', 3, 1);
        break;
      case 0xD3E:   // Scene dunkel
        RF433.switchOn('b', 4, 1);
        break;
      case 0x33E:   // Scene hell
        RF433.switchOn('c', 1, 1);
        break;
      case 0xB3E:   // Scene belebend
        RF433.switchOn('c', 2, 1);
        break;
      case 0x73E:   // Scene anwesend
        RF433.switchOn('c', 3, 1);
        break;
      case 0x83E:   // Schalter aus
        RF433.switchOff('b', 2, 2);
        break;
      case 0x81E:   // Schalter ein
        RF433.switchOn('b', 2, 2);
        break;
      default:
        break;
    }
    irrecv.resume();
  }
}

