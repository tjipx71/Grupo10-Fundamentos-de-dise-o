float ph4v = 0.239;                         // Voltajes reales según PH
float ph7v = 0.082;
float ph10v = -0.073;
float phm = (ph4v - ph10v) / 6;             // Pendiente de voltaje para calibración PH
float ph_gain = 3;                          // Ganancia del amplificador del sensor de PH

float ph_obtain(){
  float ref_v = 0;                          // Declaración de valores
  float ph_v = 0;
  float ph = 0;
  float sum = 0;
  int counter = 0;

  while(counter != 1000){
    ref_v = 3.3 * analogRead(33) / 4096;    // Voltaje de referencia
    ph_v = 3.3 * analogRead(14) / 4096;     // Voltaje ampificado del sensor
    ph = (ph_v - ref_v) / (ph_gain);        // Voltaje real del sensor deshaciando la amplificación respecto a referencia
    sum = sum + ph;                         // Promediación del voltaje
    counter = counter + 1;
    delayMicroseconds(250);                 // Toma de muestras a 4000 Hz
  }
  ph = 4 + ((ph4v - (sum / 1000)) / phm);   // Obtención del valor de PH con promedio de 1000 lecturas
  return ph;
}