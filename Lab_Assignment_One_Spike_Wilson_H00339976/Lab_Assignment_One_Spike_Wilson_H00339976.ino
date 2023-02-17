/***
 *                _____ _____ _____ _____ _   _ __  __ ______ _   _ _______    ____  _   _ ______ 
 *         /\    / ____/ ____|_   _/ ____| \ | |  \/  |  ____| \ | |__   __|  / __ \| \ | |  ____|
 *        /  \  | (___| (___   | || |  __|  \| | \  / | |__  |  \| |  | |    | |  | |  \| | |__   
 *       / /\ \  \___ \\___ \  | || | |_ | . ` | |\/| |  __| | . ` |  | |    | |  | | . ` |  __|  
 *      / ____ \ ____) |___) |_| || |__| | |\  | |  | | |____| |\  |  | |    | |__| | |\  | |____ 
 *     /_/    \_\_____/_____/|_____\_____|_| \_|_|  |_|______|_| \_|  |_|     \____/|_| \_|______|
 *                                                                                                
 *                                                                                                
 *     
 *     Surname: WILSON                Parameter Calculation
 *     ---------------                -------------------------------------------------------------------
 *     W = 23                         Width of first pulse: a = 23 x 100µS = 2300µS
 *     I = 9                          Width of space between pulses: b = 9 x 100µS = 900µS
 *     L = 12                         Number of pulses in a block: c = 12 + 4 = 16
 *     S = 19                         Space between pulse blocks: d = 19 x 500µS = 9500µ
 *     O = 15                         Mode: (15/4)+1 = 4 [Half d and b time until switch set back to zero]
 *     
 ***/


/*****************************************************
   DEFINE CONSTANTS
*****************************************************/
#define SIGNAL_A_PULSE 2300                                   //Signal A high pulse base value
#define SIGNAL_A_PULSE_QTY 16                                 //Number of signal A pulses
#define PULSE_INCR 50                                         //Signal A pulse width increment time
#define SIGNAL_A_LOW_b 900                                    //Signal A low pulse duration (Parameter b)
#define SIGNAL_A_LOW_d 9500                                   //Signal A low pulse duration (Parameter d)
#define SIGNAL_B_PULSE 50                                     //Signal B pulse duration

#define SIGNAL_B_TIME_LOW ((SIGNAL_A_PULSE_a1 + SIGNAL_A_LOW_b + SIGNAL_A_PULSE_a2 + SIGNAL_A_LOW_b + SIGNAL_A_PULSE_a3 + SIGNAL_A_LOW_b + SIGNAL_A_LOW_d))  //Signal B low pulse duration (a1 + b + a2 + b + a3 + b + d)

#define SIGNAL_B_TIME_LOW_MODIFIED ((SIGNAL_A_PULSE_a1 + SIGNAL_A_LOW_b_HALF + SIGNAL_A_PULSE_a2 + SIGNAL_A_LOW_b_HALF + SIGNAL_A_PULSE_a3 + SIGNAL_A_LOW_b_HALF + SIGNAL_A_LOW_d_HALF))   //Signal B modified low pulse duration   

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

volatile bool button_1_state = LOW;                            //Declare initial state of button 1
volatile bool button_2_state = LOW;                            //Declare initial state of button 2

volatile unsigned long last_debounce_time_1 = 0;               //Declare intial value of last debounce time 1 | Volatile prevents compiler optimisation
volatile unsigned long last_debounce_time_2 = 0;               //Declare intial value of last debounce time 2 | Volatile prevents compiler optimisation

volatile bool last_button_1_state = LOW;                       //Declare intial value of last button 1 state | Volatile prevents compiler optimisation
volatile bool last_button_2_state = LOW;                       //Declare intial value of last button 2 state | Volatile prevents compiler optimisation

/*****************************************************
   INITIALIZATION CODE
*****************************************************/

void setup()                                                  //Declare initializaton function to be run once at boot
{

  Serial.begin(9600);                                         //Initialize serial communication with baudrate 9600
  pinMode(BUTTON_1_PIN, INPUT_PULLDOWN);                      //Declare button 1 as an input using internal pulldown resistor
  pinMode(BUTTON_2_PIN, INPUT_PULLDOWN);                      //Declare button 2 as an input using internal pulldown resistor

  attachInterrupt(digitalPinToInterrupt(BUTTON_1_PIN), button_1_pressed, RISING);    //Attach button 1 pin to interrupt | call button_1_pressed as interrupt service routine | Triggered on rising edge
  attachInterrupt(digitalPinToInterrupt(BUTTON_2_PIN), button_2_pressed, RISING);    //Attach button 1 pin to interrupt | call button_2_pressed as interrupt service routine | Triggered on rising edg

  pinMode(SIGNAL_A, OUTPUT);                                  //Declare signal A as output
  pinMode(SIGNAL_B, OUTPUT);                                  //Declare signal B as output

  Serial.println("Setup complete");                           //Print to serial monitor on new line

}

/*****************************************************
   BUTTON 1 DEBOUNCE ISR
*****************************************************/

void button_1_pressed()                                       //Declare function for debouncing button 1
{
  if (millis() - last_debounce_time_1 > DEBOUNCE_TIME)        //If millis() - last debunce time is greater than debounce time
  {
    button_1_state = !button_1_state;                         //Invert button 1 state
    last_debounce_time_1 = millis();                          //Update value of last debounce time
  }
}

/*****************************************************
   BUTTON 2 DEBOUNCE ISR
*****************************************************/

void button_2_pressed()                                       //Declare function for debouncing button 1
{
  if (millis() - last_debounce_time_2 > DEBOUNCE_TIME)        //If millis() - last debunce time is greater than debounce time
  {
    button_2_state = !button_2_state;                         //Invert button 1 state
    last_debounce_time_2 = millis();                          //Update value of last debounce time
  }
}

/*****************************************************
   NORMAL SIGNAL FUNCTION
*****************************************************/

void signal_normal()                                          //Declare function for normal signal output
{
  digitalWrite(SIGNAL_B, HIGH);                               //Set signal B high
  delayMicroseconds(SIGNAL_B_PULSE);                          //Wait for pulse duration to elapse
  digitalWrite(SIGNAL_B, LOW);                                //Set signal B low

  for (int pulse_count_norm = 0; pulse_count_norm < SIGNAL_A_PULSE_QTY; pulse_count_norm++)
    //Declare integer pulse_count_norm as equalling zero, while pulse count is less than signal A pulse quantity, increment pulse count by one
  {
    digitalWrite(SIGNAL_A, HIGH);                             //Set signal A high
    delayMicroseconds(SIGNAL_A_PULSE + (pulse_count_norm * PULSE_INCR));    //Wait for (pulse time + (pulse count x pulse increment)) to elapse
    digitalWrite(SIGNAL_A, LOW);                              //Set signal A low
    delayMicroseconds(SIGNAL_A_LOW_b);                        //Wait for pulse low duration to elapse
  }

  delayMicroseconds(SIGNAL_A_LOW_b);                          //Wait for pulse low duration to elapse
  delayMicroseconds(SIGNAL_A_LOW_d);                          //Wait for parameter d duration to elapse
}

/*****************************************************
   MODIFIED SIGNAL FUNCTION
*****************************************************/

void signal_modified()                                        //Declare function for modified signal output
{
  digitalWrite(SIGNAL_B, HIGH);                               //Set signal B high
  delayMicroseconds(SIGNAL_B_PULSE);                          //Wait for pulse duration to elapse
  digitalWrite(SIGNAL_B, LOW);                                //Set signal B low

  for (int pulse_count_modi = 0; pulse_count_modi < SIGNAL_A_PULSE_QTY; pulse_count_modi++)
    //Declare integer pulse_count_modi as equalling zero, while pulse count is less than signal A pulse quantity, increment pulse count by one
  {
    digitalWrite(SIGNAL_A, HIGH);                             //Set signal A high
    delayMicroseconds(SIGNAL_A_PULSE + (pulse_count_modi * PULSE_INCR));    //Wait for (pulse time + (pulse count x pulse increment)) to elapse
    digitalWrite(SIGNAL_A, LOW);                              //Set signal A low
    delayMicroseconds(SIGNAL_A_LOW_b_HALF);                   //Wait for pulse low duration to elapse
  }

  delayMicroseconds(SIGNAL_A_LOW_b_HALF);                     //Wait for pulse low duration to elapse
  delayMicroseconds(SIGNAL_A_LOW_d_HALF);                     //Wait for parameter d duration to elapse
}

/*****************************************************
   MAIN PROGRAM
*****************************************************/

void loop()
{
  if (button_1_state != last_button_1_state)                  //If button 1 state does not equal previous state
  {
    last_button_1_state = button_1_state;                     //Last button state equals current button state
  }

  if (button_2_state != last_button_2_state)                  //If button 2 state does not equal previous state
  {
    last_button_2_state = button_2_state;                     //Last button state equals current button state
  }

  if (button_1_state == HIGH && button_2_state == LOW)        //If button 1 is pressed AND button 2 is not pressed
  {
    signal_normal();                                          //Call signal_normal funtion
    Serial.println("Button 1 Active");                        //Print to serial monitor on new line
  }

  else if (button_1_state == LOW && button_2_state == LOW)    //If neither button 1 or 2 are pressed
  {
    //Do nothing
  }

  else if (button_1_state == HIGH && button_2_state == HIGH)  //If both buttons are pressed
  {
    signal_modified();                                        //Call signal_modified function
    Serial.println("Button 2 Active");                        //Print to serial monitor on new line
  }


}

/***
 *      _____  _____   ____   _____ _____            __  __      ______ _   _ _____  
 *     |  __ \|  __ \ / __ \ / ____|  __ \     /\   |  \/  |    |  ____| \ | |  __ \ 
 *     | |__) | |__) | |  | | |  __| |__) |   /  \  | \  / |    | |__  |  \| | |  | |
 *     |  ___/|  _  /| |  | | | |_ |  _  /   / /\ \ | |\/| |    |  __| | . ` | |  | |
 *     | |    | | \ \| |__| | |__| | | \ \  / ____ \| |  | |    | |____| |\  | |__| |
 *     |_|    |_|  \_\\____/ \_____|_|  \_\/_/    \_\_|  |_|    |______|_| \_|_____/ 
 *                                                                                   
 *                                                                                   
 ***/
