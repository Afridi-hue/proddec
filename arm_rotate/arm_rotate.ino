/*
code to control the robot for campion launch
*/
int start_button=0; //variable to read the position of the switch
int kick_pos=0; //to read the state of the kick pin
int kick_pin=7;  //pin to check the position of the bt module 
int start=2;  //pin to connect the switch
int leg_c=3;  //leg clockwise pin
int leg_ac=4; //leg anti-clockwise pin
int arm_c=5;  //left-arm clockwise pin
int arm_ac=6; //left-arm anti-clockwise pin
void kick();  //function to kick the football
void arm_rotate(); //function to rotate the arm
void stop_arm_rotate(); //function to stop the arm rotation

void setup() {
  pinMode(leg_c,OUTPUT);
  pinMode(leg_ac,OUTPUT);
  pinMode(arm_c,OUTPUT);
  pinMode(arm_ac,OUTPUT);
  pinMode(start,INTPUT)
}

void loop() {
  start_button=digitalRead(start);
  kick_pos=digitalRead(kick_pin);
  while(start_button==1 && kick_pos!=1)
  {
    arm_rotate();
  }
  if (start_button==1 && kick_pos==1)
    { 
      kick_pos=0;
      start_button=0;
      stop_arm_rotate();
      kick();
    }
}

void kick()
{

}

void arm_rotate() 
{ 
  /* if you move the left arm forward, then right arm will be moved backward automatically.
  Because the two motor are connected in reverse polarity
  */
  digitalWrite(leg_c,1);  //left arm forward
  delay(500);
  digitalWrite(leg_c,0);  //left arm stop
  digitalWrite(leg_ac,1); //left arm backward
  delay(1000);
  digitalWrite(leg_ac,0); //left arm stop
  digitalWrite(leg_c,1);  //left arm forward
  delay(500);
  digitalWrite(leg_c,0);  //left arm stop

}
void stop_arm_rotate()
{
  digitalWrite(leg_c,0);  //turn off the arm motor
  digitalWrite(leg_ac,0); //turn of the arm motor
}

