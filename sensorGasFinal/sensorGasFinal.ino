int buzzer = A2; // BUZZER
int PinSensor = A0;//SENSOR DE GÁS MQ-2
int PinLed = 12;
int tempo = 400;
 
int leitura_sensor = 120;//DEFININDO UM VALOR LIMITE (NÍVEL DE GÁS NORMAL)
 
void setup(){
  pinMode(PinSensor, INPUT); //SENSOR GÁS COMO ENTRADA
  pinMode(buzzer, OUTPUT); //BUZZER COMO SAÍDA
  pinMode(PinLed, OUTPUT);
  digitalWrite(PinLed, LOW);
  Serial.begin(9600);//INICIALIZA A SERIAL
}

void loop(){
  
  int valor_analogico = analogRead(PinSensor); //VARIÁVEL RECEBE O VALOR LIDO NO PINO ANALÓGICO
  
  Serial.print("Leitura: "); //EXIBE O TEXTO NO MONITOR SERIAL
  Serial.println(valor_analogico);// MOSTRA NO MONITOR SERIAL O VALOR LIDO DO PINO ANALÓGICO
  
  if (valor_analogico > leitura_sensor){
   digitalWrite(PinLed, HIGH);
   delay(300);
   tone(buzzer, 900);
   delay(400);
   noTone(buzzer);
   delay(300);
   }else{ //SENÃO, FAZ
   digitalWrite(PinLed, LOW);
   noTone(buzzer);
   
   //digitalWrite(Pinbuzzer, LOW);//BUZZER DESLIGADO
   }
   delay(300); //INTERVALO DE 100 MILISSEGUNDOS
  }
