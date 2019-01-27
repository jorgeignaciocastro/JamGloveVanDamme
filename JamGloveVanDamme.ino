
#include "MPU6050_tockn.h"
#include <Wire.h>

const int PALMA_PIN  = 8;
const int PULGAR_PIN  = 9;
const int INDICE_PIN  = 10; 

MPU6050 PALMA(Wire);
MPU6050 PULGAR(Wire);
MPU6050 INDICE(Wire);

void setup() {

  Serial.begin(9600);

  pinMode(PALMA_PIN, OUTPUT);
  pinMode(PULGAR_PIN, OUTPUT);
  pinMode(INDICE_PIN, OUTPUT);


  digitalWrite(PALMA_PIN, HIGH);
  digitalWrite(PULGAR_PIN, LOW);
  digitalWrite(INDICE_PIN, LOW);
  
  Wire.begin();
  PALMA.begin();
  PALMA.calcGyroOffsets(true);

  delay(300);
  digitalWrite(PALMA_PIN, LOW);
  digitalWrite(PULGAR_PIN, HIGH);
  digitalWrite(INDICE_PIN, LOW);

  Wire.begin();
  PULGAR.begin();
  PULGAR.calcGyroOffsets(true);

  delay(300);
  digitalWrite(PALMA_PIN, LOW);
  digitalWrite(PULGAR_PIN, LOW);
  digitalWrite(INDICE_PIN, HIGH);

  Wire.begin();
  INDICE.begin();
  INDICE.calcGyroOffsets(true);

}

void loop() {
  digitalWrite(PALMA_PIN, HIGH);
  digitalWrite(PULGAR_PIN, LOW);
  digitalWrite(INDICE_PIN, LOW);
    
  PALMA.update();

  Serial.print("\tangleZ PALMA : ");
  Serial.println(PALMA.getAngleZ());

  digitalWrite(PALMA_PIN, LOW);
  digitalWrite(PULGAR_PIN, HIGH);
  digitalWrite(INDICE_PIN, LOW);

  PULGAR.update();

  Serial.print("\tangleZ PULGAR : ");
  Serial.println(PULGAR.getAngleZ());

  digitalWrite(PALMA_PIN, LOW);
  digitalWrite(PULGAR_PIN, LOW);
  digitalWrite(INDICE_PIN, HIGH);

  INDICE.update();

  Serial.print("\tangleZ INDICE : ");
  Serial.println(INDICE.getAngleZ());

}
