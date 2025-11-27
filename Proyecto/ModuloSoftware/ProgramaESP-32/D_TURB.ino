float turb_obtain(){                    // Sensor no calibrado, solo retorna voltajes
  int counter = 0;                      // Declaración de variables
  float sum = 0;
  float v = 0;
  while(counter != 1000){
    v = 3.3 * analogRead(27) / 4096;    // Voltaje de sensor de turbidez
    counter = counter + 1;
    sum = sum + v;
    delayMicroseconds(250);             // Toma de muestras a 4000 Hz
  }
  sum = sum / 1000;                     // Promediación de 1000 lecturas
  return sum;
}