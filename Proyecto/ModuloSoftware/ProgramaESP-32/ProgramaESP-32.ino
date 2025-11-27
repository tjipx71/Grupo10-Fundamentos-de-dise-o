void setup() {
  pinMode(26, OUTPUT);                      // Inicializar el pin de conmutación
  Serial.begin(9600);                       // Inicializar la comunicación serial
}

void loop() {
  float r = resistance();         // Medir resistencia
  float ph = ph_obtain();
  float temp = temp_obtain();
  float turb = turb_obtain();

  Serial.println();               // Imprimir resistencia
  Serial.print("Resistencia: ");
  Serial.println(r);
  Serial.print("PH: ");
  Serial.println(ph);
  Serial.print("Temperatura: ");
  Serial.println(temp, 4);
  Serial.print("Turbidez: ");
  Serial.println(turb, 4);

  delay(1000);                    // Delay en escritura
}
