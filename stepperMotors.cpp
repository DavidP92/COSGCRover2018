    #include <Stepper.h>
     
    #define STEPS 400
    
    Stepper stepper1(STEPS, 4, 5, 6, 7);
    Stepper stepper2(STEPS, 9,10,11,12);
     
    int i = 3;
    
    void setup()
    {
      Serial.begin(115200);
      Serial.println("Stepper test!");
      // set the speed of the motor to 30 RPMs
      stepper1.setSpeed(100);
      stepper2.setSpeed(80);
    }
     
    void loop()
    {
     Forward();
     delay(1000);
     Reverse();
     delay(1000);
     Right(30, 500);
     delay(1000);
 }

 void Forward(){
  stepper1.setSpeed(90);
  stepper2.setSpeed(90);
  for(int S = 0;  S<STEPS * i; S++){
      Serial.println("Forward");
      stepper1.step(1);
      stepper2.step(1);
      }
 }

  void Reverse(){
    stepper1.setSpeed(60);
    stepper2.setSpeed(60);
     for(int K = 0; K > -STEPS * i; K--){
      Serial.println("Backward");
      stepper1.step(-1);
      stepper2.step(-1);
  }
}

  void Right(speed, distance){
    // Why use a loop when you can just specify the distance you would like to travel
    // Also using a nested loop will not work as you intendd because it is still doing one thing
    // at a time then.
    stepper1.setSpeed(speed);
    stepper2.setSpeed(speed);
    stepper1.step(distance);
    stepper2.step(-distance);
  }
