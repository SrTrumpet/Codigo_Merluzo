// Variables para el Servo Motor
#include <Servo.h>
Servo abrirComida;
////////////////////////////////

// Variables para le final de carrera
int iman = 48;
int led = 49;
int inicio = 0;
////////////////////////////////

// Variables para el final de carrera 2
int iman2 = 46;
int led2 = 47;
int finalC = 0;
////////////////////////////////

// Variables para los motores///
int enA = 3;
int in1 = 52;
int in2 = 53;
int in3 = 51;
int in4 = 50;
int enB = 4;
////////////////////////////////

//Variables para la configuracion de botones



////////////////////////////////////////////


//Variables para los tiempos
int tresHoras = 3;
int seisHoras = 6;
int ochoHoras = 8;
int doceHoras = 12;
////////////////////////////////

void setup() {

  ////////////////////////////////  FINALES DE CARRERA
  pinMode(iman, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(iman, HIGH);

  pinMode(iman2, INPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(iman2, HIGH);

  ////////////////////////////////


  //////////////////////////////// MOTORES
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  ////////////////////////////////

  //////////////////////////////// SERVO MOTOR
  abrirComida.attach(5);

  ////////////////////////////////
}
void loop() {

  bool inicioCarrera = finalDeCarrera(led, iman);
  bool finalCarrera = finalDeCarrera(led2, iman2);


//################################################################### CORTE DE LUZ, NO MODIFICAR,
//TODO EL WHILE ES POR SI HAY CORTE DE LUZ
    while(inicioCarrera == true && finalCarrera == true) {
    //En caso de corte se luz la maquino volvera a su posicion inicial y esperará 3 horas
    //las 3 horas son genericas, las unicas que puede modificar el usuario son
    //6, 8 o 12 horas a travez de pulsadores
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 230);

    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
    analogWrite(enB, 230);

    inicioCarrera = finalDeCarrera(led, iman);
    finalCarrera = finalDeCarrera(led2, iman2);

    if(inicioCarrera == false){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);

      digitalWrite(in4, LOW);
      digitalWrite(in3, LOW);

      //3 horas
      delay(5000);

    } else if(finalCarrera == false ){

    //EN caso de corte de luz volverá a "final de carrera" que es el led2

      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);

      digitalWrite(in4, LOW);
      digitalWrite(in3, LOW);

      //3 horas, este delay se debe cambiar a 3 horas en milisegundos
      delay(5000);
    
    }
  }
//###################################################################

//################################################################### FUNCIONAMIENTO NORMAL, ADELANTE Y HACIA ATRAS
  if(inicioCarrera == false){

    activarServo(true);///VALOR DE PRUEBA

    while(finalCarrera == true){

      //Todo el espacio con hashtag se debe modificar para dar la funcion de dar comida a los peces##

      //Si se repite mucho codigo intentar hacer una funcion generica, en especial
      //en esta parte del codigo ya que lo no importa si va hacia adelante o hacia atras
      //debe hacer lo mismo, entregar comida

      //########################################################################################



      /// EL SIGUIENTE CODIGO NO SE DEBE CAMBIAR,
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 255);

      digitalWrite(in4, HIGH);
      digitalWrite(in3, LOW);
      analogWrite(enB, 255);

      finalCarrera = finalDeCarrera(led2, iman2);
      ////////////////////////////////////////////
    }
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    digitalWrite(in4, LOW);
    digitalWrite(in3, LOW);

    //Aca se apaga el led rojo, ya que llego donde esta el led azul
    digitalWrite(led, LOW);  

    activarServo(false);//VALOR DE PRUEBA

    //Antes de esta parta de cuando se apaga el led se debe cerrar el servo A 0 grados CUIDADO CON LA LOGICA

    delay(2000);

  }
  else if(finalCarrera == false){



    activarServo(true); ///// VALORES DE PRUEBA

    while(inicioCarrera == true){

      //Todo el espacio con hashtag se debe modificar para dar la funcion de dar comida a los peces##

      //Si se repite mucho codigo intentar hacer una funcion generica, en especial
      //en esta parte del codigo ya que lo no importa si va hacia adelante o hacia atras
      //debe hacer lo mismo, entregar comida

      //########################################################################################



      /// EL SIGUIENTE CODIGO NO SE DEBE CAMBIAR, 
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, 255);

      digitalWrite(in4, LOW);
      digitalWrite(in3, HIGH);
      analogWrite(enB, 255);

      inicioCarrera = finalDeCarrera(led, iman);
      /////////////////////////////////////////////
    }
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    digitalWrite(in4, LOW);
    digitalWrite(in3, LOW);
    //Aca se apaga el led 
    digitalWrite(led2, LOW);

    activarServo(false);  //// VALORES DE PRUEBA
    //Antes de esta parta de cuando se apaga el led se debe cerrar el servo A 0 grados CUIDADO CON LA LOGICA

    delay(2000);

  } 

//###################################################################

}


void activarServo(bool activar){
  if(activar == true){
    abrirComida.write(30);
  }else{
    abrirComida.write(0);
  }
}


bool finalDeCarrera(int ledGenerico, int imanGenerico) {

  int estadoDelImanGenerico = 0;
  estadoDelImanGenerico = digitalRead(imanGenerico);

  if (estadoDelImanGenerico == LOW) {
    digitalWrite(ledGenerico, HIGH);
    //En caso que se encuentre al final de su carrera, se debe encender el led correspondiente y
    //devuelve false ya que no debe moverse
    return false;
  } else {
    digitalWrite(ledGenerico, LOW);
    //En el caso de que no se encuentre en el final de su carrera debera serguir avanzando 
    //por lo que devuelve true
    return true;
  }
}








//CODIGO DE PRUEBA SOLO IGNORAR
//Cuidado, es mas importante saber donde estoy parado ya que si hay un corte de luz la maquina debe ser apas de volver a un estado inicial
void calcular(int tiempo){

  if(tiempo == 3){

  }else if(tiempo == 6){

  }else if(tiempo == 8){

  }else if(tiempo == 12){

  }else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 230);

    digitalWrite(in4, LOW);
    digitalWrite(in3, LOW);
  }
}
