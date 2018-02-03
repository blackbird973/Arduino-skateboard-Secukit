/*
* IRremote Library - Copyright 2009 Ken Shirriff
* created by Rui Santos, http://randomnerdtutorials.wordpress.com
* Control LED's with a remote control
* 2013
*/

#include <IRremote.h>
#include <ServoTimer2.h>   //newnewnewnew

int IR_Recv = 11;   //IR Receiver Pin 3
int r_ledPin = 5;  //red LED pin 9
int l_ledPin = 3; //barre de led gauche
ServoTimer2 myservo;  // create servo object to control a servo //fffffffffffffffffffffffffffffffffffffff
ServoTimer2 myservo2; // create second object to control second servo //fffffffffffffffffffffffffffffffff

IRrecv irrecv(IR_Recv);
decode_results results;


void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(r_ledPin, OUTPUT);      // sets the digital pin as output
  pinMode(l_ledPin, OUTPUT);      // sets the digital pin as output
  myservo.attach(9);  // attaches the servo on pin 9 //ffffffffffffffffffffffffffffffffffffffffff
  myservo2.attach(10); //attaches the servo on pin 10 //fffffffffffffffffffffffffffffffffffffffff
  }

void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(decCode);
    
   //switch case to use the selected remote control button
   switch (results.value){
      case 3778927144: //when you press the [1] button

          for(int i = 0; i < 5; i++)
          {
          digitalWrite(r_ledPin, HIGH);
          delay(500);
          digitalWrite(r_ledPin, LOW);
          delay(500);
           }
                     
           break;
  
      case 1167253836: //when you press the [7] button
           digitalWrite(r_ledPin, LOW);   // sets the red LED off
           
           break;

      case 657459652: //when you press the [3] button

           for(int i = 0; i < 5; i++)
          {
          digitalWrite(l_ledPin, HIGH);
          delay(500);
          digitalWrite(l_ledPin, LOW);
          delay(500);
           }
                     
           break;
  
      case 2340753640: //when you press the [9] button
           digitalWrite(l_ledPin, LOW);   // sets the red LED off
           
           break;


            

      case 2908251746: //buzzer song
            tone(6, 250); // Send 1KHz sound signal...
             delay(300);
             noTone(6);     // Stop sound...
             delay(200);
             tone(6, 250); // Send 1KHz sound signal...
             delay(800);        // ...for 1 sec
             noTone(6);     // Stop sound...
             delay(1000);

             break;


      case 1931099650: //frein on //fffffffffffffffffffffffffffffffffffffffffff
             myservo.write(100);                 
             myservo2.write(100);
             
             break;

      case 1747313982: //frein off //ffffffffffffffffffffffffffffffffffffffffff
             myservo.write(20);
             myservo2.write(20);
             
             break;
       
                         }
    irrecv.resume(); // Receives the next value from the button you press
  }
  
  
    }


