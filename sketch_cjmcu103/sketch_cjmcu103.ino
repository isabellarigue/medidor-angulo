/*
 * Teste CJMCU-103 (sensor ângulo de rotação)
 * O ângulo é dado em graus
 * Autor: Isabella R
*/

#define sensor A0

double angulo;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT_PULLUP);
}

//é medido o angulo de inclinação e mostrado no monitor serial
void loop() {
  Serial.print("Inclinacao: ");
  angulo = map(analogRead(sensor),0, 1023, 0, 333); //o sensor mede angulos de 0 a 333 graus
  Serial.println(angulo); 
  delay(1000);
}
