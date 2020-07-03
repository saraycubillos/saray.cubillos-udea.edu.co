volatile unsigned int contador = 0;
bool mood = false;
void setup() {
 
 pinMode(13,OUTPUT); //Para utilizar la led necestiamos ubicar el 13
 
  
 SREG = (SREG & 0b01111111); //Desabilita las interrupciones
 TIMSK2 = TIMSK2|0b00000001; //Bandera que habilita la interrupcion por desbordamiento
 TCCR2B = 0b00000111; //Configura el timer2 a la frecuencia mas baja
 SREG = (SREG & 0b01111111) | 0b10000000; //Habilita las interrupciones globales//Desabilita las interrupciones globales
 
  

}


void loop() {

}

ISR(TIMER2_OVF_vect){ //Ciclo para que la led oscile cada 20 iteraciones por medio de interrupciones con timer
    contador++;
    if(contador> 19) {        
      digitalWrite(13,mood);
      mood = !mood;
      contador=0;
    }
 
 
  
}