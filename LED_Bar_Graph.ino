int latchPin = 12;  //creates an interger called latchPin and assigns it the value 12    
int clockPin = 13;  //creates an interger called clockPin and assigns it the value 13
int dataPin = 11;   //creates an interger called dataPin and assigns it the value 11


void setup() {
  pinMode(latchPin, OUTPUT);    //sets latchPin to OUTPUT
  pinMode(clockPin, OUTPUT);    //sets clockPin to OUTPUT
  pinMode(dataPin, OUTPUT);     //sets dataPin to OUTPUT
}

void loop() {
  byte x = 0x01;                                  //uses 8bit to determine the state of the 8 LEDs, x is assigned the value of 0x01 which is equivalent to 00000001 in binary
  for(int j = 0; j < 8; j++) {                    //while j is less than 8 one will be added to the variable
    digitalWrite (latchPin, LOW);                 //sets latchPin to LOW
    shiftOut (dataPin, clockPin, LSBFIRST, x);    //send data to the 74HC595 chip
    digitalWrite (latchPin, HIGH);                //sets latchPin to HIGH
    x <<= 1;                                      //shifts the value of x to the right by one place
    delay (200);                                  //waits 200ms
  }

}
