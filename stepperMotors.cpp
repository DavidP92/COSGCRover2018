#include <Stepper.h>
 
#define STEPS 400

Stepper stepper1(STEPS, 4, 5, 6, 7);
Stepper stepper2(STEPS, 9,10,11,12);
 
int i = 10;
int t = 4;


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
  Forward(STEPS * i, 100);
  Backwards(STEPS * i, 100);
  Right(STEPS * t, 50);
  Left(STEPS * t, 50);
}

 void Forward (int distance, int s) {
  for (int i = 0; i < distance; i++)
    moveMotor(1, 1, s);
 }
 void Backwards(int distance, int s) {
  for (int i = 0; i < distance; i++)
    moveMotor(-1, -1, s);
 }
 void Right(int distance, int s) {
  for (int i = 0; i < distance; i++)
    moveMotor(1, -1, s);
 }
 void Left(int distance, int s) {
  for (int i = 0; i < distance; i++)
    moveMotor(-1, 1, s);
 }

 void moveMotor(int a, int b, int s){
  stepper1.setSpeed(s);
  stepper2.setSpeed(s);
  stepper1.step(a);
  stepper2.step(b);
 }
