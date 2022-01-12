/*
 * Teste MPU6050 (giroscópio) exibindo os valores de ângulo em graus
 * Autor: Isabella R
*/

// Carregando bibliotecas
#include <MPU6050_tockn.h>
#include <Wire.h>

//Definindo endereco I2C do MPU6050
#define MPU6050_ADDR         0x68 
//#define MPU6050_ADDR         0x69 

//#define DEBUG
MPU6050 mpu6050(Wire);

// Declarando variáveis
float anguloX;
float anguloY;
float anguloZ;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
}

void loop() {
  mpu6050.update();

  // Captando os valores do giroscópio
  anguloX = mpu6050.getAngleX();
  anguloY = mpu6050.getAngleY();
  anguloZ = mpu6050.getAngleZ();

  Serial.print("Angulo de giro x: ");
  Serial.println(anguloX);
  Serial.print("Angulo de giro y: ");
  Serial.println(anguloY);
  Serial.print("Angulo de giro z: ");
  Serial.println(anguloZ);

  delay(1000);
}
