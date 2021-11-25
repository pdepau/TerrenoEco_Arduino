// -*- mode: c++ -*-

#ifndef MEDIDOR_H_INCLUIDO
#define MEDIDOR_H_INCLUIDO

// ------------------------------------------------------
// ------------------------------------------------------
class Medidor {

  // .....................................................
  // .....................................................
private:

public:

  // .....................................................
  // constructor()
  // .....................................................
  Medidor(  ) {
    
  } // ()

  // .....................................................
  // .....................................................
  void iniciarMedidor() {
	// las cosas que no se puedan hacer en el constructor, if any
  } // ()

  int sensorData [11];
  // .....................................................
  // .....................................................
  /**
   * () -> Z
   * Analiza los valores recibidos por el serial
   * 
   * @return int valor de CO2
   */
  int medirCO2(SoftwareSerial mySerial) {
    mySerial.print('\r'); // Inicia una lectura del sensor. Ahora hay que espera a que nos envíe algo de vuelta!
    Serial.println("Lectura del sensor iniciada...esperando...");
    int i = 0;
    for (int i =0; i<11; i++) {
       while(!mySerial.available()) { }
       sensorData[i] = mySerial.parseInt();
    }
    int valor = 0;
    for (int j=0; j<11; j++) {
      Serial.println(sensorData[j]);
      // El segundo valor es el gas
      if(j == 1){
        valor = sensorData[j];
      }
    }
    return valor;
  } // ()

  // .....................................................
  // .....................................................
  /**
   * () -> Z
   * Analiza los valores recibidos por el serial
   * 
   * @return int valor de temperatura
   */
  int medirTemperatura() {
    return 31;
  } // ()
	
}; // class

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
#endif
