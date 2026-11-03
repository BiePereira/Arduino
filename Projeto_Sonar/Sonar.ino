//pinos
const int trigPin = 9;
const int echoPin = 10;

//variáveis
long duration;
int distancia;

//leds
int leds[] = {2,3,4,5,6};

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  for(int i = 0; i <=5; i++){
  	pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  
  //Limpa o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  //define o trigPin como HIGH por 10 ms
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Lê o echoPin, retorna o tempo da onda de som
  duration = pulseIn(echoPin, HIGH);
  
  //Processa usando o tempo da velocidade do som
  distancia = duration * 0.034 / 2;
  
  /*if(distance < 10){
  	digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }*/
  
  if(distancia > 100){
    ligaLeds(0);
  }
  else if(distancia > 80){
    ligaLeds(1);
  }
  else if(distancia > 60){
  	ligaLeds(2);
  }
  else if(distancia > 40){
  	ligaLeds(3);
  }
  else if(distancia > 20){
  	ligaLeds(4);
  }
  else{
  	ligaLeds(5);
  }
  
  //Print em serial (prompt)
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(500);
}

void ligaLeds(int quantidade){
  //liga quantidade leds
  for(int i = 0; i < quantidade; i++){
  	digitalWrite(leds[i], HIGH);
  }
  //desliga restantes
  for(int i = quantidade; i < 5; i++){
  	digitalWrite(leds[i], LOW);
  }
  
}