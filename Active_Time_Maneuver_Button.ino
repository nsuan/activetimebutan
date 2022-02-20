#include <Bounce.h>

Bounce button0 = Bounce(0, 10);
char nextchar;
int INPUT_MAX = 15;

void setup() {
  //Pin 0 is connected to the real button:
   pinMode(0, INPUT_PULLUP);
   // Pin 1 isn't connected to anything so 
   randomSeed(analogRead(1));

}

void loop() {
  unsigned long startTime;
  unsigned long nowTime;
  int rnd;
  int rndKeys;
  // Check the button, if its pressed start sending a bunch of random inputs:
  button0.update();
    if (button0.fallingEdge()) {
      //startTime = millis() / 1000; 
      //while (true) {
      rndKeys = random(10,30);
      for(int i = 0; i < rndKeys; i++) {
        //nowTime = millis() / 1000;
        //if ((nowTime - startTime) >= INPUT_MAX) //make sure we only run about the specified time
        //  break;
//       if (true) {
        rnd = random(1,10);
        if ( rnd >= 5) { 
          //We're pressing random keys! (90% chance)
          nextchar = random(97,122); //make a random character
          Keyboard.press(nextchar);
          delay(random(30,60));
          Keyboard.release(nextchar);
        } else if(rnd < 5 && rnd > 3) {
          nextchar = random(32,128); //make a random character
          Keyboard.press(nextchar);
          delay(random(30,60));
          Keyboard.release(nextchar);
        } else {
          // We're pressing a random mouse button! 
         /* if (random(0,2)) {
            Mouse.click(MOUSE_LEFT);
          } else {
            Mouse.click(MOUSE_RIGHT);
            Mouse.click(MOUSE_LEFT);
          }
          delay(random(30,60));*/
        }
      }
  }
}
