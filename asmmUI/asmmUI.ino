//////////////////////////////////////////////////////////////////////////////////
//  The following script controls the UI for the A2M2 spectral mapping machine. //
//  Georgia Tech Senior Design Fall 2018.  Coulter Schrum                       //
//////////////////////////////////////////////////////////////////////////////////

#define Pot_Left 8
#define Pot_Right 9

int i = {
  // put your setup code here, to run once:
Serial.begin(9600);
//pinMode(47, OUTPUT);
//pinMode(49, OUTPUT);
}

void loop() {
  analogWrite(8,(1023 - analogRead(Pot_Left))/4);
  analogWrite(9,(1023 - analogRead(Pot_Right))/4);
  delay(10);
}0;

void setup() 

