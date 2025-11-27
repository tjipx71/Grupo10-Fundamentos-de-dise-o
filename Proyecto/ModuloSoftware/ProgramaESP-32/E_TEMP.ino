float temp_a = 37.0;                        // Puntos de calibración de temperatura
float temp_a_v = 0.993;
float temp_b = 0;
float temp_b_v = 2.196;
float tempm = (temp_a_v - temp_b_v) / (temp_a - temp_b);


float temp_obtain(){
  float temp = 0;                           // Declaración de valores
  float sum = 0;
  int counter = 0;

  while(counter != 1000){
    temp = 3.3 * analogRead(13) / 4096;     // Voltaje de sensor de temperatura
    sum = sum + temp;
    counter = counter + 1;
    delayMicroseconds(250);                 // Toma de muestras a 4000 Hz
  }
  temp = (((sum / 1000)-temp_b_v)/tempm);   // Obtención del valor de temperatura con promedio de 1000 lecturas
  return temp;
}