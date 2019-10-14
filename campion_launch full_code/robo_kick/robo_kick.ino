/*
code to kick the football and stop srm rotation--with arduino and bt module
download the arduino bt_controller app from the playstore and install it
pair the bt module with android app
select a button and assign the character 's' to the button.
press the button

>>>>motor working
    if mc=1 and mac=0
        motor will rotate clockwise
    if mc=0 and mac=1
        motor will rotate anti-clockwise
    if mc=0 and mac=0
        motor will stop
    
        
*/

char bt_data; //variable->to store bluetooth data
int mc=2;   // pin->motor clockwise
int mac=3;   // pin->motor anticlockwise
int relay_activate=4; //pin->to stop the arm rotation with relay
void kick();    //function->for the kick the football

void setup() {
    pinMode(mc,OUTPUT);
    pinMode(mac,OUTPUT);
    Serial.begin(9600);
    digitalWrite(mac,0);    //turn off motor
    digitalWrite(mc,0);     //turn off motor
}
 
void loop() {
// reading for any data from the bt module
if (Serial.available()>0)
{
  bt_data= Serial.read();
  if (bt_data=='s')
  {     
      digitalWrite(relay_activate,1); //to stop arm rotation
      kick();
  }
}
}

void kick()
{
    digitalWrite(mc,1);    //motor clockwise
    delay(500);                 
    digitalWrite(mc,0);   //motor stop
    delay(100);                    
    digitalWrite(mac,1);    //motor anti-clockwise
    delay(700);
    digitalWrite(mac,0);    //motor stop
}
 
