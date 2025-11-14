void setup()
{
  Serial.begin(9600);
}

float readPin(int pin_number){
  int a = 0;
  float sum = 0;
  while(a!=1000){
    sum = sum + analogRead(pin_number);
    delayMicroseconds(250);
    a = a + 1;
  }
  sum = sum / 4096000 * 3.3;
  return sum;
}

void loop()
{
  float a = readPin(13);
  float b = readPin(27);
  float c = readPin(14);
  float d = readPin(12);
  Serial.println("");

  Serial.print("Temperatura: ");
  Serial.println(a);
  Serial.print("Turbidez: ");
  Serial.println(b);
  Serial.print("PH: ");
  Serial.println(c);
  Serial.print("Oxígeno Disuelto: ");
  Serial.println(d);

  delay(1000);
  Serial.println("");
}