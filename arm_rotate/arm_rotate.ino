/*
code to control the arm of the robot
*/
int start_button=0; //variable->  to read the position of the on-switch

int start=2;  //pin-> switch to turn on the rotation
int arm_c=4;  //pin-> left-arm clockwise
int arm_ac=5; //pin-> left-arm anti-clockwise
void arm_rotate(); //function-> to rotate the arm


void setup() {
  pinMode(arm_c,OUTPUT);
  pinMode(arm_ac,OUTPUT);
  pinMode(start,INTPUT);

  // set zero to the motor pin
  digitalWrite(arm_c,0);
  digitalWrite(arm_ac,0);

}

void loop() {
  start_button=digitalRead(start);
  while (start_button==1)
    {
      arm_rotate();
    }
}

void arm_rotate() 
{ 
  /* if you turn the left arm forward, then right arm will move backward automatically.
  Because the two motor are connected in reverse polarity
  */
  digitalWrite(arm_c,1);  //left arm forward
  delay(500);
  digitalWrite(arm_c,0);  //left arm stop
  digitalWrite(arm_ac,1); //left arm backward
  delay(1000);
  digitalWrite(arm_ac,0); //left arm stop
  digitalWrite(arm_c,1);  //left arm forward
  delay(500);
  digitalWrite(arm_c,0);  //left arm stop

}


