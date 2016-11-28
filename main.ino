int botled = 9; 
int midled = 10;
int topled = 11;      

void setup() {
  pinMode(botled, OUTPUT);
  pinMode(midled, OUTPUT);
  pinMode(topled, OUTPUT);
}

// bottom-middle-top (fading in and out in sequence bottom to top and go down)
void cycleFadeSequence() {
  int sense = 1;
  int fadeAmount = 2;
  int minFade = 5;
  int maxFade = 100; 
  int delay1 = 50;
  int delay2 = 250;

  int botbright = minFade;
  int midbright = minFade;
  int topbright = minFade;

  int current = 1;
  
  while(current < 5){
    analogWrite(botled, botbright);
    analogWrite(midled, midbright);
    analogWrite(topled, topbright);
  
    if (sense ==  1){
      if (botbright < maxFade){
        botbright += fadeAmount;
      }else{
        if (midbright < maxFade) {
          midbright += fadeAmount;
        }else{
          if(topbright < maxFade){
            topbright += fadeAmount;
          }else{
            sense = -1;
            delay(delay2);
          }
        }
      }
    }else{
      if (topbright > minFade) {
        topbright -= fadeAmount;
      }else{
        if(midbright > minFade){
          midbright -= fadeAmount;        
        }else{
          if(botbright > minFade){
            botbright -= fadeAmount;
          }else{
            sense = 1;
            delay(delay2);
            current++;
          }
        }
      }
    }
    
    delay(delay1);
  }
}

// jump from bottom to top on/off
void cycleOnOffSequence() {  

  int delay1 = 50;
  int delay2 = 250;
  int current = 1;

  digitalWrite(botled, 0);
  digitalWrite(midled, 0);
  digitalWrite(topled, 0);
  
  while(current < 4){

    digitalWrite(botled, 1);

    delay(delay2);

    digitalWrite(botled, 0);
    digitalWrite(midled, 1);

    delay(delay2);

    digitalWrite(midled, 0);
    digitalWrite(topled, 1);

    delay(delay2);
    
    digitalWrite(topled, 0);
    digitalWrite(midled, 1);

    delay(delay2);
    digitalWrite(midled, 0);

    current++;
    
  }
}


// fading in and out all the leds
void cycleFadeAllLeds() {
  int sense = 1;
  int fadeAmount = 2;
  int minFade = 5;
  int maxFade = 100; 
  int delay1 = 50;
  int delay2 = 250;

  int botbright = minFade;
  int midbright = minFade;
  int topbright = minFade;

  int current = 1;
  
  while(current < 5){
    analogWrite(botled, botbright);
    analogWrite(midled, midbright);
    analogWrite(topled, topbright);
  
    if (sense ==  1){
      if (botbright < maxFade){
        botbright += fadeAmount;
        midbright += fadeAmount;
        topbright += fadeAmount;
      }else{
        sense = -1;
        delay(delay2);
      }
    }else{
      if (topbright > minFade) {
        topbright -= fadeAmount;
        midbright -= fadeAmount;        
        botbright -= fadeAmount;
      }else{
        sense = 1;
        delay(delay2);
        current++;
      }       
    }
    
    delay(delay1);
  }
}


// on/off all leds
void cycleOnOffAllLeds() {  

  int delay1 = 50;
  int delay2 = 250;
  int current = 1;

  
  while(current < 6){

    digitalWrite(botled, 0);
    digitalWrite(midled, 0);
    digitalWrite(topled, 0);

    delay(delay2);
    
    digitalWrite(botled, 1);
    digitalWrite(midled, 1);    
    digitalWrite(topled, 1);

    delay(delay2);

    current++;
    
  }
}
void loop() {
  cycleOnOffAllLeds();
  cycleFadeAllLeds();
  cycleOnOffSequence();
  cycleFadeSequence();
}
