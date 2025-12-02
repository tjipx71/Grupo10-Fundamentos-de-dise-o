#include "BluetoothSerial.h"

// CONFIG GENERAL
BluetoothSerial SerialBT;

void setup() {
  pinMode(26, OUTPUT);                      // Inicializar el pin de conmutación
  Serial.begin(9600);                       // Inicializar la comunicación serial
  
  SerialBT.begin("ESP32_ECOAQUA"); // Nombre Bluetooth

  Serial.println("Bluetooth listo: ESP32_ECOAQUA");
}

void loop() {
  float r = resistance();         // Medir resistencia
  float ph = ph_obtain();
  float temp = temp_obtain();
  float turb = turb_obtain();
  float diso = do_obtain(); 

  Serial.println("===== ECOAQUA =====");

  Serial.println();               // Imprimir resistencia
  
  Serial.print("PH: ");
  Serial.println(ph);

  Serial.print("Turbidez: ");
  Serial.println(turb, 4);
  
  Serial.print("Temperatura: ");
  Serial.println(temp, 4);

  Serial.print("Resistencia: ");
  Serial.println(r);

  Serial.print("O2 disuelto: "); 
  Serial.println(diso, 4);

  String paquete =
      String(ph, 2) + "," +
      String(turb, 2) + "," +
      String(temp, 2) + "," +
      String(r, 2) + "," +
      String(diso, 2);

  SerialBT.println(paquete);   // Enviar paquete a App Inventor

  Serial.print("TX: ");        // Mostrar lo enviado
  Serial.println(paquete);

  delay(1000);                    // Delay en escritura
}
