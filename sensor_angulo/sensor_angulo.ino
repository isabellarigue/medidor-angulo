/*
 * Programa básico para testar o funcionamento e as medidas do sensor de ângulo de rotação CJMCU-103;
 * Voltado para estudo em um circuito com um led.
*/

#define sensor A0
#define led 13

double angulo;

void ledOn();

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

}

//é medido o angulo de inclinação e mostrado no monitor serial
void loop() {
  Serial.print("Inclinacao: ");
  angulo = map(analogRead(sensor),0, 1023, 0, 333); //o sensor mede angulos de 0 a 333 graus
  Serial.println(angulo); 
  delay(1000);
  //quando o angulo é menor que 180 graus o led é acesso
  if(angulo < 180) 
    ledOn();
  else 
    digitalWrite(led, LOW);
}

//função para piscar o led
void ledOn() {
  digitalWrite(led, HIGH);
  delay(741);
  digitalWrite(led, LOW);
  delay(555);
}
