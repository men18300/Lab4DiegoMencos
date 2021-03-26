//Universidad del Valle de Guatemala
//Departamento de Ingenieria Mecatronica
//Curso: Digital 2
//Catedratico: Kurt Kellner
//Diego Mencos
//Carne 18300

//Definicion de Variables

//PUSHBUTTOMS
const int buttonPin = PUSH1;     
const int buttonPin2 = PUSH2;    

//PINES DE LA TIVA PARA LOS LED
//JUGADOR 1
const byte cont1_0 = 19; 
const byte cont1_1 = 38;
const byte cont1_2 = 37; 
const byte cont1_3 = 36; 
const byte cont1_4 = 35; 
const byte cont1_5 = 34;
const byte cont1_6 = 33; 
const byte cont1_7 = 32; 

//JUGADOR 2
const byte cont2_0 = 2; 
const byte cont2_1 = 3; 
const byte cont2_2 = 4; 
const byte cont2_3 = 5;
const byte cont2_4 = 6; 
const byte cont2_5 = 7; 
const byte cont2_6 = 8; 
const byte cont2_7 = 9; 

// Variables que usare a lo largo del programa

//Guardar estado de botones
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status


//Variables que se utilizaran para revisar flancos
int lastbuttonState = 1;         // variable for reading the pushbutton status
int lastbuttonState2 = 1;         // variable for reading the pushbutton status

//Contadores
int cont1 = 0;
int cont2 = 0;

//Bandera de inicio de semaforo
int bandera = 0;

//Bandera de ganador
int ganador = 0;
int indice=0;

void setup() {
  Serial.begin(9600);

//Ponemos en Salida todos los LEDs
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

//Entrada los botones de la TIVA
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

//Inicializamos nuestra bandera en 1, para comenzar de una vez
  bandera = 1;
}

void loop() {

//Leemos el estado de nuestros botones
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

//Verificamos que algun boton se apache para empezar el semaforo
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

//Reseteamos nuestros contadores
    cont1 = 0;
    cont2 = 0;
    while (bandera != 1) {

//Volvemos a leer nuestros botones para ver si el contador va a incrementar
      buttonState = digitalRead(buttonPin);
      buttonState2 = digitalRead(buttonPin2);

//Verificamos si hay algun flanco 
      if (buttonState != lastbuttonState) {
        lastbuttonState = buttonState;
        //Si esta apachado, aumentar el contador
        if (buttonState == LOW) {
          cont1++;
          //Funcion para encender el led correspondiente, dependiendo la posicion del jugador
          funcionContador(cont1, 1);

        }
      }

      else if (buttonState2 != lastbuttonState2) {
        lastbuttonState2 = buttonState2;
        if (buttonState2 == LOW) {
          cont2++;
          funcionContador(cont2, 2);
        }
      }


    }

    //RUTINA GANADOR
    if (ganador == 1) {
      resetear();
      //Hacemos que el led del jugador ganador parpadee varias veces
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

//Funcion para saber que leds encender 
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

//Apagamos todos nuestros LEDS
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
