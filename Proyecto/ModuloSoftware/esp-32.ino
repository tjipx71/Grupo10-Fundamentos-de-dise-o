/*
Notas:
- Versión inicial, no terminado.
- Se necesita leer temperatura para calibrar pH, OD y conductividad de manera consistente.
- Las funciones de obtención de valores cambiarán con el tiempo.
- Falta leer la temperatura, conductividad y turbidez.
- Trate las funciones de medición como cajas negras que funcionan para el desarrollo de otras características.
*/

// ########## RUTINA DE INICIO COMIENZA ##########

void setup() {
  Serial.begin(9600);
}

// ########## RUTINA DE INICIO TERMINA ##########


// ########## FUNCIONES DE SENSORES COMIENZAN ##########

float ph_cal = 4;                                       // Valor de calibración

float leer_ph() {
  float ref_v = analogRead(A16) * (3.3 / 4096);         // Voltaje de referencia
  float ph_v = analogRead(A15) * (3.3 / 4096);          // Voltaje de sensor de pH
  float ph = 7 - ((ph_v - ref_v)/(0.059 * 3)) - ph_cal; // Valor calculado de pH
  return ph;                                            // Retornar pH
}

float leer_od() {
  float od_v = analogRead(A14) * (3.3 / 4096);          // Voltaje de sensor de OD
  return od_v;                                          // Retornar voltaje de sensor OD
}

float leer_temp() {                                     // Función no implementado
  return 1;
}

float leer_cond() {                                     // Función no implementado
  return 1;
}

float leer_turb() {                                     // Función no implementado
  return 1;
}

// ########## FUNCIONES DE SENSORES TERMINAN ##########


// ########## PROGRAMA PRINCIPAL COMIENZA ##########

void loop() {
  Serial.print("Voltaje OD: ");
  Serial.println(leer_od());
  Serial.print("PH: ");
  Serial.println(leer_ph());
  Serial.println();
  delay(1000);
}

// ########## PROGRAMA PRINCIPAL TERMINA ##########