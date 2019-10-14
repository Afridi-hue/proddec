/*
Code to control the arm of the robot and kick
*/

int start_button=0; //variable->  to read the position of the start-switch
int start=2;  //pin-> switch to turn on the rotation
int arm_c=3;  //pin-> left-arm clockwise
int arm_ac=4; //pin-> left-arm anti-clockwise
int leg_c=5;// pin->leg motor clockwise
int leg_ac=6;// pin->motor anti-clockwise
void arm_rotate(); //function-> to rotate the arm
void kick();    //function->for the kick the football


void setup() {
  pinMode(arm_c,OUTPUT);
  pinMode(arm_ac,OUTPUT);
  pinMode(leg_c,OUTPUT);
  pinMode(leg_ac,OUTPUT);
  pinMode(start,INTPUT);
  Serial.begin(9600); //initializing the serial communication btw the arduino and bt module


  // set zero to the arm motor pin
  digitalWrite(arm_c,0);
  digitalWrite(arm_ac,0);

  // set zero to the leg motor pin
  digitalWrite(leg_c,0);
  digitalWrite(leg_ac,0);

}

void loop() {
  //reading the state of the start switch
  start_button=digitalRead(start); 
  
  //checking for the incoming data on arduino port from the bt_module
  while (start_button==1 && (Serial.available()!>0)) 
    {
      arm_rotate();
    }

  //reading the data from the bt_module
  while(start_button==1 && Serial.read()=='s') 
  {
    kick();
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

void kick()
{
    digitalWrite(leg_c,1);    //leg motor clockwise
    delay(500);                 
    digitalWrite(leg_c,0);   //leg motor stop
    delay(100);                    
    digitalWrite(leg_ac,1);    //leg motor anti-clockwise
    delay(700);
    digitalWrite(leg_ac,0);    //leg motor stop
}


