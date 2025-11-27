int r2 = 100;                               // Constante r1 para el cálculo de resistencia
float cond_gain = 11;                       // Ganancia del amplificador del sensor de conductividad

float resistance(){
  float ref_v = 0;                          // Definir valores iniciales
  float read_v = 0;
  float pulse_v = 0;
  float vin = 0;
  float vout = 0;
  float r1 = 0;
  float sum = 0;

  int counter = 0;
  while(counter != 1000){
    digitalWrite(26, HIGH);                 // Conmutar en alto
    delayMicroseconds(250);                 // Delay en semiciclo

    ref_v = 3.3 * analogRead(33) / 4096;    // Voltaje de referencia
    read_v = 3.3 * analogRead(25) / 4096;   // Voltaje leído con amplificación respecto a referencia
    pulse_v = 3.3 * analogRead(32) / 4096;  // Voltaje de pulso conmutado
    vin = pulse_v - ref_v;                  // Obtener voltaje de entrada del divisor
    vout = (read_v - ref_v) / cond_gain;    // Obtener voltaje de salida del divisor deshaciendo la amplificación
    r1 = ((vin * r2)/vout) - r2;            // Conociendo la resistencia inferior (r2) calcular r1
    sum = sum + r1;                         // Sumar para promediar las lecturas

    digitalWrite(26, LOW);                  // Conmutar en bajo
    delayMicroseconds(250);                 // Delay en semiciclo

    counter = counter + 1;
  }
  sum = sum / 1000;                         // Promediar las lecturas de las 1000 muestras
  return sum;                               // Retornar
}