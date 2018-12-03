//////////////////////////////////////////////////////////////////////////////////
//  The following script controls the UI for the A2M2 spectral mapping machine. //
//  Georgia Tech Senior Design Fall 2018.  Coulter Schrum                       //
//////////////////////////////////////////////////////////////////////////////////


#include Arduino.h
///////////////////////////////////////////
///         Pin declarations            ///
///////////////////////////////////////////

  // PWM control ports  (x6)
    int Vq1 = 13;   // Q ports
    int Vq2 = 14;
    int Vq3 = 15;
    int Vf1 = 16;   // freq ports
    int Vf2 = 17;
    int Vf3 = 18;
  
  //PB setup: bank select
    int pb1 = 48;  // Low
    int pb2 = 50;  // MID
    int pb3 = 52;  // HIGH
    int pb4 = 54;  // mode switch


  // LEDs
    int LED1 = 53;  // LOW
    int LED2 = 51;  // MID
    int LED3 = 49;  // HIGH


  // analog trimmers
    int trimf = A0;
    int trimq = A1;


///////////////////////////////////////////
///         Global Variables            ///
///////////////////////////////////////////
   int bankMask = [ 0, 0, 0 ];
   int bankCount = [2, 2, 2];
   int pbArr = [pb1, pb2, pb3];
   int ledArr = [LED1, LED2, LED3];
   int trimArr = [trimf, trimq];
   int QpwmArr = [Vq1, Vq2, Vq3]; // connect to SVF's
   int FpwmArr = [Vf1, Vf2, Vf3]; //connect to SVF's


///////////////////////////////////////////
///            Event Functions          ///
///////////////////////////////////////////

  // Bank Select: returns bankMask boolean for control and calls ledCheck
    int bankSelect(pbCount, pbArr, ledArr){
      for(i = 0; i <= length(pbArr); i++){
        if (mod(pbCount(i),2) == 1){
          bankMask(i) = 1;
          lightChange(bankMask, ledArr);
          return bankMask;
         }
      else { 
          bankMask(i) == 0;
          lightChange();
          return bankMask;
      }
          
}

//lightCheck function: activate LEDs
  void lightChange(bankMask, ledArr){
    for(i = 0; i <= length(bankMask); i++){
      if(bankMask(i) == 1){
        digitalWrite(ledArr(i), HIGH);
      else { digitalWrite(ledArr(i), LOW);
      }
    }
  }

void Qcontrol(bankMask, trimq){
  // analog to pwm cpnversion
      Serial.print(analogRead(trimq));
  // set level iteratively per bankMask
  
}

void freqControl(bankMask, trimf){
  // analog to pwm cpnversion
      Serial.print(analogRead(trimf));
  // set level iteratively per bankMask
  
}

// listener functions
// Bank check function: alters pbCount and calls bankSelect
int bankCheck(pbArr, pbCount){
  for(i = 0; i <= length(pbArr); i++){
        char val = digitalRead(pbArr(i));  // read input value **listerner
          if (val1 == LOW) {  // check if button is pushed
           return pbCount = pbCount++;
           bankSelect();
          } 
          else {
          //do nothing
          }
}

//Knob Check function: reads trimmer difference and calls control function[s]
int knobCheck(){
  for(i = 0; i<= length(trimArr); i++{
    int val1 analogRead(trimArr(i));
    // small delay
    int val2  = analogRead(trimArr(i));
    int diffCheck = val2 - val1;
    if (diffCheck >= .01 || diffCheck <= -.01)
      if (i == 0){
        freqControl();
      }
      else{
        QControl();
      }
    else {//do nothing}
  }
  }
}





void setup() {
// put your setup code here, to run once:  

 // setup hardware
   // control parameters using pwm output
     pinMode(Vhp, OUTPUT);
     pinMode(Vbp, OUTPUT);
     pinMode(Vlp, OUTPUT);
     pinMode(Vq, OUTPUT);
     pinMode(Vfreq, OUTPUT);
    

  // PBs
     pinMode(pb1,INPUT);
     pinMode(pb2,INPUT);
     pinMode(pb3,INPUT);
     pinMode(pb4,INPUT);

  // LEDs
     pinMode(LED1, OUTPUT);
     pinMode(LED2, OUTPUT);
     pinMode(LED3, OUTPUT);

  // trimmers
     pinMode(trimf, INPUT);
     pinMode(trimq, INPUT);

  // serial comm
    Serial.begin(9600);
     
}



void loop() {
  // put your main code here, to run repeatedly:
  bankcheck();
  knobCheck();
}
