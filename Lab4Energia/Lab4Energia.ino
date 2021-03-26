
const int buttonPin = PUSH1;     // the number of the pushbutton pin
const int buttonPin2 = PUSH2;     // the number of the pushbutton pin


const byte cont1_0 = 19; 
const byte cont1_1 = 38;
const byte cont1_2 = 37; //Definimos el pin del PUSH 1
const byte cont1_3 = 36; //Definimos el pin del PUSH 2
const byte cont1_4 = 35; //Definimos el pin del PUSH 1
const byte cont1_5 = 34; //Definimos el pin del PUSH 2
const byte cont1_6 = 33; //Definimos el pin del PUSH 1
const byte cont1_7 = 32; //Definimos el pin del PUSH 2

const byte cont2_0 = 2; //Definimos el pin del PUSH 1
const byte cont2_1 = 3; //Definimos el pin del PUSH 2
const byte cont2_2 = 4; //Definimos el pin del PUSH 1
const byte cont2_3 = 5; //Definimos el pin del PUSH 2
const byte cont2_4 = 6; //Definimos el pin del PUSH 1
const byte cont2_5 = 7; //Definimos el pin del PUSH 2
const byte cont2_6 = 8; //Definimos el pin del PUSH 1
const byte cont2_7 = 9; //Definimos el pin del PUSH 2

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status

int lastbuttonState = 1;         // variable for reading the pushbutton status
int lastbuttonState2 = 1;         // variable for reading the pushbutton status

int cont1 = 0;
int cont2 = 0;
int bandera = 0;
int ganador = 0;
int indice=0;

void setup() {
  Serial.begin(9600);


  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(cont1_0, OUTPUT);
  pinMode(cont1_1, OUTPUT);
  pinMode(cont1_2, OUTPUT);
  pinMode(cont1_3, OUTPUT);
  pinMode(cont1_4, OUTPUT);
  pinMode(cont1_5, OUTPUT);
  pinMode(cont1_6, OUTPUT);
  pinMode(cont1_7, OUTPUT);

  pinMode(cont2_0, OUTPUT);
  pinMode(cont2_1, OUTPUT);
  pinMode(cont2_2, OUTPUT);
  pinMode(cont2_3, OUTPUT);
  pinMode(cont2_4, OUTPUT);
  pinMode(cont2_5, OUTPUT);
  pinMode(cont2_6, OUTPUT);
  pinMode(cont2_7, OUTPUT);


  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);


  bandera = 1;
}

void loop() {

  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  Serial.print(buttonState);
  Serial.print(buttonState2);


  if ((buttonState == LOW||buttonState2 == LOW) && bandera == 1) {
    bandera = 0;
    resetear();

    digitalWrite(GREEN_LED, LOW); //Encedemos el semaforo
    digitalWrite(RED_LED, HIGH);
    delay(1000);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000);
    digitalWrite(GREEN_LED, LOW);

    cont1 = 0;
    cont2 = 0;
    while (bandera != 1) {

      buttonState = digitalRead(buttonPin);
      buttonState2 = digitalRead(buttonPin2);
      //  Serial.print(buttonState);
      //  Serial.print(buttonState2);
      Serial.print("Conteo 1");
      Serial.print("\n");
      Serial.print(cont1);
      Serial.print("Conteo 2");
      Serial.print("\n");
      Serial.print(cont2);


      // check if the pushbutton is pressed.
      // if it is, the buttonState is HIGH:
      if (buttonState != lastbuttonState) {
        lastbuttonState = buttonState;
        if (buttonState == LOW) {

          cont1++;
          funcionContador(cont1, 1);
          // lastbuttonState=buttonState;

        }
      }

      else if (buttonState2 != lastbuttonState2) {
        lastbuttonState2 = buttonState2;
        if (buttonState2 == LOW) {

          cont2++;
          funcionContador(cont2, 2);
          // lastbuttonState2=buttonState2;
        }
      }


    }

    //RUTINA GANADOR
    if (ganador == 1) {
      resetear();
      for (indice = 0; indice <= 7; indice++) {
        digitalWrite(cont1_7, HIGH);
        delay(200);
        digitalWrite(cont1_7, LOW);
         delay(200);
      }

    }
    if (ganador == 2) {
      resetear();
      for (indice = 0; indice <= 7; indice++) {
        digitalWrite(cont2_7, HIGH);
        delay(200);
        digitalWrite(cont2_7, LOW);
         delay(200);
      }

      
    }



  }


}

void funcionContador(int n, int m) {
  if (m == 1) {

    if (n == 0) {
      digitalWrite(cont1_0, LOW);
      digitalWrite(cont1_1, LOW);
      digitalWrite(cont1_2, LOW);
      digitalWrite(cont1_3, LOW);
      digitalWrite(cont1_4, LOW);
      digitalWrite(cont1_5, LOW);
      digitalWrite(cont1_6, LOW);
      digitalWrite(cont1_7, LOW);
    }
    if (n == 1) {
      digitalWrite(cont1_0, HIGH);
      digitalWrite(cont1_1, LOW);
      digitalWrite(cont1_2, LOW);
      digitalWrite(cont1_3, LOW);
      digitalWrite(cont1_4, LOW);
      digitalWrite(cont1_5, LOW);
      digitalWrite(cont1_6, LOW);
      digitalWrite(cont1_7, LOW);
    }
    if (n == 2) {
      digitalWrite(cont1_0, LOW);
      digitalWrite(cont1_1, HIGH);
      digitalWrite(cont1_2, LOW);
      digitalWrite(cont1_3, LOW);
      digitalWrite(cont1_4, LOW);
      digitalWrite(cont1_5, LOW);
      digitalWrite(cont1_6, LOW);
      digitalWrite(cont1_7, LOW);
    }
    if (n == 3) {
      digitalWrite(cont1_0, LOW);
      digitalWrite(cont1_1, LOW);
      digitalWrite(cont1_2, HIGH);
      digitalWrite(cont1_3, LOW);
      digitalWrite(cont1_4, LOW);
      digitalWrite(cont1_5, LOW);
      digitalWrite(cont1_6, LOW);
      digitalWrite(cont1_7, LOW);
    }
    if (n == 4) {
      digitalWrite(cont1_0, LOW);
      digitalWrite(cont1_1, LOW);
      digitalWrite(cont1_2, LOW);
      digitalWrite(cont1_3, HIGH);
      digitalWrite(cont1_4, LOW);
      digitalWrite(cont1_5, LOW);
      digitalWrite(cont1_6, LOW);
      digitalWrite(cont1_7, LOW);
    }
    if (n == 5) {
      digitalWrite(cont1_0, LOW);
      digitalWrite(cont1_1, LOW);
      digitalWrite(cont1_2, LOW);
      digitalWrite(cont1_3, LOW);
      digitalWrite(cont1_4, HIGH);
      digitalWrite(cont1_5, LOW);
      digitalWrite(cont1_6, LOW);
      digitalWrite(cont1_7, LOW);
    }
    if (n == 6) {
      digitalWrite(cont1_0, LOW);
      digitalWrite(cont1_1, LOW);
      digitalWrite(cont1_2, LOW);
      digitalWrite(cont1_3, LOW);
      digitalWrite(cont1_4, LOW);
      digitalWrite(cont1_5, HIGH);
      digitalWrite(cont1_6, LOW);
      digitalWrite(cont1_7, LOW);
    }
    if (n == 7) {
      digitalWrite(cont1_0, LOW);
      digitalWrite(cont1_1, LOW);
      digitalWrite(cont1_2, LOW);
      digitalWrite(cont1_3, LOW);
      digitalWrite(cont1_4, LOW);
      digitalWrite(cont1_5, LOW);
      digitalWrite(cont1_6, HIGH);
      digitalWrite(cont1_7, LOW);
    }
    if (n == 8) {
      digitalWrite(cont1_0, LOW);
      digitalWrite(cont1_1, LOW);
      digitalWrite(cont1_2, LOW);
      digitalWrite(cont1_3, LOW);
      digitalWrite(cont1_4, LOW);
      digitalWrite(cont1_5, LOW);
      digitalWrite(cont1_6, LOW);
      digitalWrite(cont1_7, HIGH);
      bandera = 1;
      ganador = 1;
    }

  }

  else if (m == 2) {
    if (n == 0) {
      digitalWrite(cont2_0, LOW);
      digitalWrite(cont2_1, LOW);
      digitalWrite(cont2_2, LOW);
      digitalWrite(cont2_3, LOW);
      digitalWrite(cont2_4, LOW);
      digitalWrite(cont2_5, LOW);
      digitalWrite(cont2_6, LOW);
      digitalWrite(cont2_7, LOW);
    }
    if (n == 1) {
      digitalWrite(cont2_0, HIGH);
      digitalWrite(cont2_1, LOW);
      digitalWrite(cont2_2, LOW);
      digitalWrite(cont2_3, LOW);
      digitalWrite(cont2_4, LOW);
      digitalWrite(cont2_5, LOW);
      digitalWrite(cont2_6, LOW);
      digitalWrite(cont2_7, LOW);
    }
    if (n == 2) {
      digitalWrite(cont2_0, LOW);
      digitalWrite(cont2_1, HIGH);
      digitalWrite(cont2_2, LOW);
      digitalWrite(cont2_3, LOW);
      digitalWrite(cont2_4, LOW);
      digitalWrite(cont2_5, LOW);
      digitalWrite(cont2_6, LOW);
      digitalWrite(cont2_7, LOW);
    }
    if (n == 3) {
      digitalWrite(cont2_0, LOW);
      digitalWrite(cont2_1, LOW);
      digitalWrite(cont2_2, HIGH);
      digitalWrite(cont2_3, LOW);
      digitalWrite(cont2_4, LOW);
      digitalWrite(cont2_5, LOW);
      digitalWrite(cont2_6, LOW);
      digitalWrite(cont2_7, LOW);
    }
    if (n == 4) {
      digitalWrite(cont2_0, LOW);
      digitalWrite(cont2_1, LOW);
      digitalWrite(cont2_2, LOW);
      digitalWrite(cont2_3, HIGH);
      digitalWrite(cont2_4, LOW);
      digitalWrite(cont2_5, LOW);
      digitalWrite(cont2_6, LOW);
      digitalWrite(cont2_7, LOW);
    }
    if (n == 5) {
      digitalWrite(cont2_0, LOW);
      digitalWrite(cont2_1, LOW);
      digitalWrite(cont2_2, LOW);
      digitalWrite(cont2_3, LOW);
      digitalWrite(cont2_4, HIGH);
      digitalWrite(cont2_5, LOW);
      digitalWrite(cont2_6, LOW);
      digitalWrite(cont2_7, LOW);
    }
    if (n == 6) {
      digitalWrite(cont2_0, LOW);
      digitalWrite(cont2_1, LOW);
      digitalWrite(cont2_2, LOW);
      digitalWrite(cont2_3, LOW);
      digitalWrite(cont2_4, LOW);
      digitalWrite(cont2_5, HIGH);
      digitalWrite(cont2_6, LOW);
      digitalWrite(cont2_7, LOW);
    }
    if (n == 7) {
      digitalWrite(cont2_0, LOW);
      digitalWrite(cont2_1, LOW);
      digitalWrite(cont2_2, LOW);
      digitalWrite(cont2_3, LOW);
      digitalWrite(cont2_4, LOW);
      digitalWrite(cont2_5, LOW);
      digitalWrite(cont2_6, HIGH);
      digitalWrite(cont2_7, LOW);
    }
    if (n == 8) {
      digitalWrite(cont2_0, LOW);
      digitalWrite(cont2_1, LOW);
      digitalWrite(cont2_2, LOW);
      digitalWrite(cont2_3, LOW);
      digitalWrite(cont2_4, LOW);
      digitalWrite(cont2_5, LOW);
      digitalWrite(cont2_6, LOW);
      digitalWrite(cont2_7, HIGH);
      bandera = 1;
      ganador = 2;
    }

  }
}

void resetear() {

  digitalWrite(cont1_0, LOW);
  digitalWrite(cont1_1, LOW);
  digitalWrite(cont1_2, LOW);
  digitalWrite(cont1_3, LOW);
  digitalWrite(cont1_4, LOW);
  digitalWrite(cont1_5, LOW);
  digitalWrite(cont1_6, LOW);
  digitalWrite(cont1_7, LOW);

  digitalWrite(cont2_0, LOW);
  digitalWrite(cont2_1, LOW);
  digitalWrite(cont2_2, LOW);
  digitalWrite(cont2_3, LOW);
  digitalWrite(cont2_4, LOW);
  digitalWrite(cont2_5, LOW);
  digitalWrite(cont2_6, LOW);
  digitalWrite(cont2_7, LOW);


}
