/*
code to kick the football with arduino and bt module
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

char bt_data; //variable to store bluetooth data
int mc=2;   // motor clockwise pin
int mac=3;   // motor anticlockwise pin
void kick();    //function for the kick the football

void setup() {
    pinMode(mc,OUTPUT);
    pinMode(mac,OUTPUT);
    Serial.begin(9600);
    digitalWrite(mac,0);
    digitalWrite(mc,0); 
}
 
void loop() {
// reading for any data from the bt module
if (Serial.available()>0)
{
  bt_data= Serial.read();
  if (bt_data=='s')
  {
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
 
