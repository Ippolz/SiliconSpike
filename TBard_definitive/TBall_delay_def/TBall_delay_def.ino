// Triggerbox developed by Giuseppe Ippolito and Thomas Quettier
// Original article here: XXXXX

#define MAX_COMMAND_LENGTH 64  // Maximum length of a command

// Pins setting
int LedPin = 13;
int BNC1 = 8, BNC2 = 9, MrkPin = 12;

// Variables setting
int TriggerDuration = 2;
int IPI1 = 2, IPI2 = 2, IPI3 = 2, IPI4 = 2, IPI5 = 2, IPI6 = 2, IPI7 = 2, IPI8 = 2, IPI9 = 2, IPI10 = 2;
int nPuls1 = 5, nPuls2 = 5, nPuls3 = 5, nPuls4 = 5, nPuls5 = 5, nPuls6 = 5, nPuls7 = 5, nPuls8 = 5, nPuls9 = 5, nPuls10 = 5;
int MarkerDuration1 = 2, MarkerDuration2 = 2, MarkerDuration3 = 2, MarkerDuration4 = 2, MarkerDuration5 = 2, MarkerDuration6 = 2, MarkerDuration7 = 2, MarkerDuration8 = 2, MarkerDuration9 = 2;
int test = 0, psw = 0;

char inputBuffer[MAX_COMMAND_LENGTH];  // Buffer to store incoming characters
int bufferIndex = 0;                   // Index to track the position in the buffer

void setup() {
  pinMode(LedPin, OUTPUT);  // Debug LED
  pinMode(BNC1, OUTPUT);    // Initialize BNC1 (or CS)
  pinMode(BNC2, OUTPUT);    // Initialize BNC2 (or TS)
  pinMode(MrkPin, OUTPUT);  // Initialize the markers BNC
  Serial.begin(115200);
  Serial.setTimeout(1);  // Set a timeout for the Serial Monitor (for faster code execution)
}


void loop() {
  digitalWrite(LedPin, HIGH);

  while (Serial.available() > 0 && bufferIndex < MAX_COMMAND_LENGTH - 1) {
    char incomingChar = Serial.read();

    // Check for the end of the command
    if (incomingChar == '.') {
      inputBuffer[bufferIndex] = '\0';      // Null-terminate the string
      processCommand(String(inputBuffer));  // Convert to String before calling
      bufferIndex = 0;                      // Reset the buffer index for the next command
    } else {
      inputBuffer[bufferIndex++] = incomingChar;  // Add the character to the buffer
    }
  }

  String command = Serial.readStringUntil('\n');

  if (command.length() > 0) {
    processCommand(command);
  }
}

void processCommand(String command) {

  if (command.equals("Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789")) {
    psw = 1;
  }
  if (psw == 1) {
    if (command.startsWith("SET,IPI1,")) {
      // Extract the number after "SET,IPI," and convert to integer
      IPI1 = command.substring(9).toInt();
      IPI1 = IPI1 - TriggerDuration;
    } else if (command.startsWith("SET,IPI2,")) {
      IPI2 = command.substring(9).toInt();
      IPI2 = IPI2 - TriggerDuration;
    } else if (command.startsWith("SET,IPI3,")) {
      IPI3 = command.substring(9).toInt();
      IPI3 = IPI3 - TriggerDuration;
    } else if (command.startsWith("SET,IPI4,")) {
      IPI4 = command.substring(9).toInt();
      IPI4 = IPI4 - TriggerDuration;
    } else if (command.startsWith("SET,IPI5,")) {
      IPI5 = command.substring(9).toInt();
      IPI5 = IPI5 - TriggerDuration;
    } else if (command.startsWith("SET,IPI6,")) {
      IPI6 = command.substring(9).toInt();
      IPI6 = IPI6 - TriggerDuration;
    } else if (command.startsWith("SET,IPI7,")) {
      IPI7 = command.substring(9).toInt();
      IPI7 = IPI7 - TriggerDuration;
    } else if (command.startsWith("SET,IPI8,")) {
      IPI8 = command.substring(9).toInt();
      IPI8 = IPI8 - TriggerDuration;
    } else if (command.startsWith("SET,IPI9,")) {
      IPI9 = command.substring(9).toInt();
      IPI9 = IPI9 - TriggerDuration;
      // Set number of pulses for rTMS
    } else if (command.startsWith("SET,nPULS1,")) {
      nPuls1 = command.substring(11).toInt();
    } else if (command.startsWith("SET,nPULS2,")) {
      nPuls2 = command.substring(11).toInt();
    } else if (command.startsWith("SET,nPULS3,")) {
      nPuls3 = command.substring(11).toInt();
    } else if (command.startsWith("SET,nPULS4,")) {
      nPuls4 = command.substring(11).toInt();
    } else if (command.startsWith("SET,nPULS5,")) {
      nPuls5 = command.substring(11).toInt();
    } else if (command.startsWith("SET,nPULS6,")) {
      nPuls6 = command.substring(11).toInt();
    } else if (command.startsWith("SET,nPULS7,")) {
      nPuls7 = command.substring(11).toInt();
    } else if (command.startsWith("SET,nPULS8,")) {
      nPuls8 = command.substring(11).toInt();
    } else if (command.startsWith("SET,nPULS9,")) {
      nPuls9 = command.substring(11).toInt();
      // Set Marker duration
    } else if (command.startsWith("SET,MRK1,")) {
      MarkerDuration1 = command.substring(9).toInt();
    } else if (command.startsWith("SET,MRK2,")) {
      MarkerDuration2 = command.substring(9).toInt();
    } else if (command.startsWith("SET,MRK3,")) {
      MarkerDuration3 = command.substring(9).toInt();
    } else if (command.startsWith("SET,MRK4,")) {
      MarkerDuration4 = command.substring(9).toInt();
    } else if (command.startsWith("SET,MRK5,")) {
      MarkerDuration5 = command.substring(9).toInt();
    } else if (command.startsWith("SET,MRK6,")) {
      MarkerDuration6 = command.substring(9).toInt();
    } else if (command.startsWith("SET,MRK7,")) {
      MarkerDuration7 = command.substring(9).toInt();
    } else if (command.startsWith("SET,MRK8,")) {
      MarkerDuration8 = command.substring(9).toInt();
    } else if (command.startsWith("SET,MRK9,")) {
      MarkerDuration9 = command.substring(9).toInt();
    } else if (command.equals("SET,noMRK")) {
      TriggerDuration = 1;
    }

    String condstr = Serial.readStringUntil('.');
    condstr.trim();

    if (command.startsWith("ccPAS")) {
      while (true) {
        if (Serial.available() > 0) {
          char val = Serial.read();
          if (val == '1') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI1);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '2') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI2);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '3') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI3);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '4') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI4);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '5') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI5);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '6') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI6);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '7') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI7);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '8') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI8);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '9') {
            digitalWrite(MrkPin, HIGH);
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(MrkPin, LOW);
            delay(IPI9);
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);

          } else if (val == 'A') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration1);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'B') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration2);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'C') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration3);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'D') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration4);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'E') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration5);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'F') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration6);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'G') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration7);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'H') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration8);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'I') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration9);
            digitalWrite(MrkPin, LOW);
          }

          else if (val == 'Z') {
            TriggerDuration = 2;
            return;
          }
        }
      }
    } else if (command.startsWith("rTMS")) {
      while (true) {
        if (Serial.available() > 0) {
          char val = Serial.read();
          if (val == '1') {
            for (int i = 0; i < nPuls1 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI1);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);
          } else if (val == '2') {
            for (int i = 0; i < nPuls2 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI2);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);
          } else if (val == '3') {
            for (int i = 0; i < nPuls3 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI3);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);
          } else if (val == '4') {
            for (int i = 0; i < nPuls4 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI4);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);
          } else if (val == '5') {
            for (int i = 0; i < nPuls5 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI5);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);
          } else if (val == '6') {
            for (int i = 0; i < nPuls6 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI6);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);
          } else if (val == '7') {
            for (int i = 0; i < nPuls7 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI7);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);
          } else if (val == '8') {
            for (int i = 0; i < nPuls8 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI8);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);
          } else if (val == '9') {
            for (int i = 0; i < nPuls9 - 1; i++) {
              digitalWrite(BNC1, HIGH);
              digitalWrite(BNC2, HIGH);
              digitalWrite(MrkPin, HIGH);
              delay(TriggerDuration);
              digitalWrite(BNC1, LOW);
              digitalWrite(BNC2, LOW);
              digitalWrite(MrkPin, LOW);
              delay(IPI9);
            }
            digitalWrite(BNC1, HIGH);
            digitalWrite(BNC2, HIGH);
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
            digitalWrite(BNC2, LOW);
            digitalWrite(MrkPin, LOW);

          } else if (val == 'A') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration1);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'B') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration2);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'C') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration3);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'D') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration4);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'E') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration5);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'F') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration6);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'G') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration7);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'H') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration8);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'I') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration9);
            digitalWrite(MrkPin, LOW);
          }

          else if (val == 'Z') {
            TriggerDuration = 2;
            return;
          }
        }
      }
    } else if (command.startsWith("sptms")) {
      while (true) {
        if (Serial.available() > 0) {
          char val = Serial.read();
          if (val == '1') {
            digitalWrite(BNC1, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC1, LOW);
          } else if (val == '2') {
            digitalWrite(BNC2, HIGH);
            delay(TriggerDuration);
            digitalWrite(BNC2, LOW);
          } else if (val == '3') {
            digitalWrite(MrkPin, HIGH);
            delay(TriggerDuration);
            digitalWrite(MrkPin, LOW);

          } else if (val == 'A') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration1);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'B') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration2);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'C') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration3);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'D') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration4);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'E') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration5);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'F') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration6);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'G') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration7);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'H') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration8);
            digitalWrite(MrkPin, LOW);
          } else if (val == 'I') {
            digitalWrite(MrkPin, HIGH);
            delay(MarkerDuration9);
            digitalWrite(MrkPin, LOW);
          }

          else if (val == 'Z') {
            TriggerDuration = 2;
            return;
          }
        }
      }
    }
  }
}
