/*
Parameters of pulse timings and modes:

Surname: WILSON

W = 23
I = 9
L = 12
S = 19
O = 15

Parameters

width of first pulse
a = 23 x 100µS = 2300µS

Width of space between pulses
b = 9 x 100µS = 900µS

Number of pulses in a block
c = 12 + 4 = 16

Space between pulse blocks
d = 19 x 500µS = 9500µS

Mode
(15/4)+1 = 4
Half d and b time until switch set back to zero


/*****************************************************
   DEFINE CONSTANTS
*****************************************************/

#define SIGNAL_A_PULSE_a1  2300                               //Signal A first pulse duration
#define SIGNAL_A_PULSE_a2  2350                               //Signal A second pulse duration
#define SIGNAL_A_PULSE_a3  2400                               //Signal A third pulse duration
#define SIGNAL_A_PULSE_a4  2450                               //Signal A fourth pulse duration
#define SIGNAL_A_PULSE_a5  2500                               //Signal A fifth pulse duration
#define SIGNAL_A_PULSE_a6  2550                               //Signal A sixth pulse duration
#define SIGNAL_A_PULSE_a7  2600                               //Signal A seventh pulse duration
#define SIGNAL_A_PULSE_a8  2650                               //Signal A eighth pulse duration
#define SIGNAL_A_PULSE_a9  2700                               //Signal A ninth pulse duration
#define SIGNAL_A_PULSE_a10 2750                               //Signal A tenth pulse duration
#define SIGNAL_A_PULSE_a11 2800                               //Signal A eleventh pulse duration
#define SIGNAL_A_PULSE_a12 2850                               //Signal A twelfth pulse duration
#define SIGNAL_A_PULSE_a13 2900                               //Signal A thirteenth pulse duration
#define SIGNAL_A_PULSE_a14 2950                               //Signal A fourteenth pulse duration
#define SIGNAL_A_PULSE_a15 3000                               //Signal A fifteenth pulse duration
#define SIGNAL_A_PULSE_a16 3050                               //Signal A sixteenth pulse duration

#define SIGNAL_A_LOW_b 900                                    //Signal A low pulse duration (Parameter b)
#define SIGNAL_A_LOW_d 9500                                   //Signal A low pulse duration (Parameter d)
#define SIGNAL_B_PULSE 50                                     //Signal B pulse duration

#define SIGNAL_B_TIME_LOW                                     //Signal B low pulse duration (a1 + b + a2 + b + a3 + b + d)
        ((SIGNAL_A_PULSE_a1 +
          SIGNAL_A_LOW_b +
          SIGNAL_A_PULSE_a2 +
          SIGNAL_A_LOW_b +
          SIGNAL_A_PULSE_a3 +
          SIGNAL_A_LOW_b +
          SIGNAL_A_LOW_d))

#define SIGNAL_B_TIME_LOW_MODIFIED                            //Signal B modified low pulse duration
        ((SIGNAL_A_PULSE_a1 +
          SIGNAL_A_LOW_b_HALF +
          SIGNAL_A_PULSE_a2 +
          SIGNAL_A_LOW_b_HALF +
          SIGNAL_A_PULSE_a3 +
          SIGNAL_A_LOW_b_HALF +
          SIGNAL_A_LOW_d_HALF))    
                                     
#define SIGNAL_A_LOW_b_HALF ((SIGNAL_A_LOW_b / 2))            //Signal A half of low pulse duration (Parameter b/2)
#define SIGNAL_A_LOW_d_HALF ((SIGNAL_A_LOW_d / 2))            //Signal A half of low pulse duration (Parameter d/2)
#define DEBOUNCE_TIME 25                                      //Debounce time for button presses

/*****************************************************
   DEFINE INPUT PINS
*****************************************************/

#define BUTTON_1_PIN 22                                       //Define button 1 input pin number
#define BUTTON_2_PIN 23                                       //Define button 2 input pin number

/*****************************************************
   DEFINE OUTPUT PINS
*****************************************************/

#define SIGNAL_A 15                                           //Define signal A ouput pin number
#define SIGNAL_B 21                                           //Define signal B ouput pin number

/*****************************************************
   DECLARE VARIABLES
*****************************************************/

int button_1_state = LOW;                                     //Declare initial state of button 1
int button_2_state = LOW;                                     //Declare initial state of button 2


/*****************************************************
*****************************************************/

void setup()                                                  //Declare initializaton function to be run once at boot
{

  Serial.begin(9600);                                         //Initialize serial communication with baudrate 9600
  pinMode(BUTTON_1_PIN, INPUT_PULLDOWN);                      //Declare button 1 as an input using internal pulldown resistor
  pinMode(BUTTON_2_PIN, INPUT_PULLDOWN);                      //Declare button 2 as an input using internal pulldown resistor
  pinMode(SIGNAL_A, OUTPUT);                                  //Declare signal A as output
  pinMode(SIGNAL_B, OUTPUT);                                  //Declare signal B as output

  Serial.println("Setup complete");                           //Print to serial monitor on new line

}


void signal_normal()                                          //Declare function for normal signal output
{
  digitalWrite(SIGNAL_B, HIGH);                               //Set signal B high
  delayMicroseconds(SIGNAL_B_PULSE);                          //Wait for signal B pulse time to elapse
  digitalWrite(SIGNAL_B, LOW);                                //Set signal B low
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a1);                       //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a2);                       //Wait for second pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a3);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a4);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a5);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a6);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a7);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a8);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a9);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a10);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a11);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a12);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a13);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a14);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a15);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a6);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low

  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for low time b to elapse
  delayMicroseconds(SIGNAL_A_LOW_d);                          //Wait for low time d to elapse
}

void signal_modified()                                        //Declare function for modified signal output
{
  digitalWrite(SIGNAL_B, HIGH);                               //Set signal B high
  delayMicroseconds(SIGNAL_B_PULSE);                          //Wait for signal B pulse time to elapse
  digitalWrite(SIGNAL_B, LOW);                                //Set signal B low
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a1);                       //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b_HALF);                     //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a2);                       //Wait for second pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b_HALF);                     //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                               //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a3);                       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                                //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b_HALF);                     //Wait for low time b to elapse
  delayMicroseconds(SIGNAL_A_LOW_d_HALF);                     //Wait for low time d to elapse
}


void loop()
{
  button_1_state = digitalRead(BUTTON_1_PIN);                 //Read the state of the button 1 pin and update value of button state
  button_2_state = digitalRead(BUTTON_2_PIN);                 //Read the state of the button 2 pin and update value of button state

  if (button_1_state == HIGH && button_2_state == LOW)        //If button 1 is pressed AND button 2 is not pressed
  {
    signal_normal();                                          //Call signal_normal funtion
  }

  else if (button_1_state == LOW && button_2_state == LOW)    //If neither button 1 or 2 are pressed
  {
                                                              //Do nothing
  }

  else if (button_1_state == HIGH && button_2_state == HIGH) { //If both buttons are pressed
    signal_modified();                                         //Call the signal_modified function
  }


}
