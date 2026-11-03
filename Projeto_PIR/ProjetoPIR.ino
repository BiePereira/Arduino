// Biblioteca de servo-motor
#include <Servo.h>
Servo portao;

int sensorPIR = 6;
int estadoPIR;

int led_verde = 2;
int led_vermelho = 3;

void setup()
{
  Serial.begin(9600);
  //define a cancela na saída 10
  portao.attach(10);
  
  pinMode(sensorPIR, INPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  
  portao.write(0);
  sinalDePassagem(false);
}

void loop()
{
  testaAbertura();
}


/*-- Função de Abertura/Fechamento --*/
void testaAbertura(){
  //Lê o sensor e guarda resultado
  estadoPIR = digitalRead(sensorPIR);
  Serial.print("SensorPIR: ");	
  Serial.println(estadoPIR);
  //Abre Portão de acordo com o estado
  if(estadoPIR == HIGH){
  	portao.write(90);  
 	sinalDePassagem(true);
    delay(5000);
    
  }
  else{
  	portao.write(0);
    sinalDePassagem(false);
  }
  
}

/*-- Função de Troca de Leds --*/
void sinalDePassagem(boolean passagem){
  if(passagem){
  	digitalWrite(led_verde, HIGH);
    digitalWrite(led_vermelho, LOW);
  }
  else{
  	digitalWrite(led_verde, LOW);
    digitalWrite(led_vermelho, HIGH);
  }
}