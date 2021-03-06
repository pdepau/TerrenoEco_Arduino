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

      Serial1.begin(9600);
      // las cosas que no se puedan hacer en el constructor, if any
    } // ()

    int sensorData [11];
    void Serial1InParser(void)
    {
      for (int i = 0; i < 11; i++) {
        while (!Serial1.available()) {
          Serial.print('.');
        }
        sensorData[i] = Serial1.parseInt();
      }
    }
    // .....................................................
    // .....................................................
    /**
     () -> Z
      Analiza los valores recibidos por el serial

      @return int valor de CO2
      
      Lectura del sensor iniciada...esperando...
      -294433885
      260
      25
      71
      32040
      27052
      40458
      0
      0
      3
      31

      Donde la concentración de gas es 260, la temperatura 25ºC y la humedad 71%
    */
    int medirCO2() {
      Serial1.print('\r'); // Inicia una lectura del sensor. Ahora hay que espera a que nos envíe algo de vuelta!
      Serial.println("Lectura del sensor iniciada...esperando...");
      Serial1InParser();
      for (int j = 0; j < 11; j++) {
        Serial.println(sensorData[j]);
      }
      Serial1.flush();
      Serial.println("Final del for");
      
      return sensorData[1];
    } // ()

    // .....................................................
    // .....................................................
    /**
       () -> Z
       Analiza los valores recibidos por el serial

       @return int valor de temperatura
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
