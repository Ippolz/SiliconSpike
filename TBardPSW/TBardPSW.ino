void setup() {
  Serial.begin(115200);
}

void loop() {
  while (Serial.available() == 0) {}
  String teststr = Serial.readStringUntil('\n');
  teststr.trim();
  
  if (teststr == "Triggerbox developed by Giuseppe Ippolito (ippolito.g97@gmail.com) and Thomas Quettier (thomas.quettier2@unibo.it)") {
    Serial.println("TRIGGERBOX ATTIVA!");
    while (true) {
      if (Serial.available() > 0) {
        char val = Serial.read();
        if (val == '1') {
          Serial.println("A");
        } else if (val == '2') {
          Serial.println("B");
        }
      }
    }
  }
}


