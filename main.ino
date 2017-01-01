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
  int fadeAmount = 1;
  int minFade = 2;
  int maxFade = 60; 
  int delay1 = 10;
  int delay2 = 80;

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
  int maxBright = 10;
  int minBright = 1;  

  analogWrite(botled, minBright);
  analogWrite(midled, minBright);
  analogWrite(topled, minBright);
  
  while(current < 10){

    analogWrite(botled, maxBright);

    delay(delay2);

    analogWrite(botled, minBright);
    analogWrite(midled, maxBright);

    delay(delay2);

    analogWrite(midled, minBright);
    analogWrite(topled, maxBright);

    delay(delay2);
    
    analogWrite(topled, minBright);
    analogWrite(midled, maxBright);

    delay(delay2);
    analogWrite(midled, minBright);

    current++;
    
  }
}


// fading in and out all the leds
void cycleFadeAllLeds() {
  int sense = 1;
  int fadeAmount = 2;
  int minFade = 5;
  int maxFade = 60; 
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
  int delay2 = 500;
  int current = 1;
  int maxBright = 50;
  int minBright = 2;

  while(current < 6){

    analogWrite(botled, minBright);
    analogWrite(midled, minBright);
    analogWrite(topled, minBright);

    delay(delay2);
    
    analogWrite(botled, maxBright);
    analogWrite(midled, maxBright);    
    analogWrite(topled, maxBright);

    delay(delay2);

    current++;
    
  }
}
void loop() {
  cycleOnOffAllLeds();
  delay(1000);
  cycleOnOffSequence();
  cycleFadeAllLeds();
  cycleOnOffSequence();
  cycleFadeSequence();
  cycleOnOffSequence();
}
