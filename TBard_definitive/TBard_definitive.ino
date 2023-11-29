int durTMS = 2, val = 0;
int Cond = 8, Test = 9, Marker1 = 12;
int led = 13;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(Cond,OUTPUT);
  pinMode(Test,OUTPUT);
  pinMode(Marker1,OUTPUT); 
  Serial.begin(115200);  
}

void loop () {
  digitalWrite(led,HIGH);
  val = Serial.read();        
    if(val == '1'){ //        M1-M1 DESTRI: 6 ms tra TS e CS, con marker
        digitalWrite(Test, HIGH);
        digitalWrite(Marker1, HIGH);
        delay(2);
        digitalWrite(Marker1, LOW);
        digitalWrite(Test, LOW);
        delay(6);
        digitalWrite(Cond, HIGH);
        delay(2);
        digitalWrite(Cond, LOW);
    }
    else if(val == '2'){ //   preSMA-M1 DESTRI: 4 ms tra TS e CS, con marker
        digitalWrite(Test, HIGH);
        digitalWrite(Marker1, HIGH);
        delay(2);
        digitalWrite(Marker1, LOW);
        digitalWrite(Test, LOW);
        delay(4);
        digitalWrite(Cond, HIGH);
        delay(2);
        digitalWrite(Cond, LOW);
    }
    else if(val == '3'){ //   VERSIONE PER CHECK ORDINE COIL: TEST-COND
        digitalWrite(Test, HIGH);
        digitalWrite(Marker1, HIGH);
        delay(2);
        digitalWrite(Marker1, LOW);
        digitalWrite(Test, LOW);
        delay(1000);
        digitalWrite(Cond, HIGH);
        delay(2);
        digitalWrite(Cond, LOW);
    }
        else if(val == '5'){ //   Single pulse CS
        digitalWrite(Cond, HIGH);
        digitalWrite(Marker1, HIGH);
        delay(2);
        digitalWrite(Cond, LOW);
        digitalWrite(Marker1, LOW);
    }
        else if(val == '6'){ //   Single pulse CS
        digitalWrite(Test, HIGH);
        digitalWrite(Marker1, HIGH);
        delay(2);
        digitalWrite(Test, LOW);
        digitalWrite(Marker1, LOW);
    }
        else if(val == '7'){ //   VERSIONE PER CHECK ORDINE COIL: COND-TEST
        digitalWrite(Cond, HIGH);
        digitalWrite(Marker1, HIGH);
        delay(2);
        digitalWrite(Marker1, LOW);
        digitalWrite(Cond, LOW);
        delay(1000);
        digitalWrite(Test, HIGH);
        delay(2);
        digitalWrite(Test, LOW);
    }
        else if(val == '8'){ //   M1-M1 MANCINI: 6 ms tra CS e TS, con marker
        digitalWrite(Cond, HIGH);
        digitalWrite(Marker1, HIGH);
        delay(2);
        digitalWrite(Cond, LOW);
        digitalWrite(Marker1, LOW);
        delay(6);
        digitalWrite(Test, HIGH);
        delay(2);
        digitalWrite(Test, LOW);
    }
        else if(val == '9'){ //    preSMA-M1 MANCINI: 4 ms tra CS e TS, con marker
        digitalWrite(Cond, HIGH);
        digitalWrite(Marker1, HIGH);
        delay(2);
        digitalWrite(Cond, LOW);
        digitalWrite(Marker1, LOW);
        delay(4);
        digitalWrite(Test, HIGH);
        delay(2);
        digitalWrite(Test, LOW);
    }
}
