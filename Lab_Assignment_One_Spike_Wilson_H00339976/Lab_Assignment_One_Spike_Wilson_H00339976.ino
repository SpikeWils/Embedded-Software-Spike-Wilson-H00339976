/*****************************************************
 * DEFINE CONSTANTS
*****************************************************/

#define SIGNAL_A_PULSE_a1 2300                  //Signal A first pulse duration
#define SIGNAL_A_PULSE_a2 2350                  //Signal A second pulse duration
#define SIGNAL_A_PULSE_a3 2400                  //Signal A third pulse duration
#define SIGNAL_A_LOW_b 900                      //Signal A low pulse duration (Parameter b)
#define SIGNAL_A_LOW_d 9500                     //Signal A low pulse duration (Parameter d)
#define SIGNAL_B_PULSE 50                       //Signal B pulse duration
#define SIGNAL_B_TIME_LOW ((SIGNAL_A_PULSE_a1 + SIGNAL_A_LOW_b + SIGNAL_A_PULSE_a2 + SIGNAL_A_LOW_b + SIGNAL_A_PULSE_a3 + SIGNAL_A_LOW_b + SIGNAL_A_LOW_d))     //Signal B low pulse duration (a1 + b + a2 + b + a3 + b + d)
#define SIGNAL_A_LOW_b_HALF ((SIGNAL_A_LOW_b_HALF / 2))
#define SIGNAL_A_LOW_d_HALF ((SIGNAL_A_LOW_d_HALF / 2))

/*****************************************************
 * DEFINE INPUT PINS
*****************************************************/

#define BUTTON_1_PIN 22
#define BUTTON_2_PIN 23

/*****************************************************
 * DEFINE OUTPUT PINS
*****************************************************/

#define LED_RED 15
#define LED_BLUE 21

/*****************************************************
 * DECLARE VARIABLES
*****************************************************/

int button_1_state = LOW;                       //Use internal pull down resistor
int button_2_state = LOW;                       //Use internal pull down resistor

/*****************************************************
*****************************************************/

void setup()                                    //Run code once to initialize system
  {
    
  Serial.begin(9600);                           //Initialize serial communication with baudrate 9600
  pinMode(BUTTON_1_PIN, INPUT);                 //Declare button 1 as an input
  pinMode(BUTTON_2_PIN, INPUT);                 //Declare button 2 as an input
  pinMode(LED_RED, OUTPUT);                     //Declare Red LED as output
  pinMode(LED_BLUE, OUTPUT);                    //Declare Blue LED as output

  Serial.println("Set up complete");            //Print to serial monitor

  }

void signal_A_normal()                            //Declare function for signal A in normal mode
{
      digitalWrite(LED_RED, HIGH);                //Set signal A high             
      delayMicroseconds(SIGNAL_A_PULSE_a1);       //Wait for first pulse time to elapse
      digitalWrite(LED_RED, LOW);                 //Set signal A low
      delayMicroseconds(SIGNAL_A_LOW_b);          //Wait for low time b to elapse
      digitalWrite(LED_RED, HIGH);                //Set signal A high
      delayMicroseconds(SIGNAL_A_PULSE_a2);       //Wait for second pulse time to elapse
      digitalWrite(LED_RED, LOW);                 //Set signal A low
      delayMicroseconds(SIGNAL_A_LOW_b);          //Wait for low time b to elapse
      digitalWrite(LED_RED, HIGH);                //Set signal A high
      delayMicroseconds(SIGNAL_A_PULSE_a3);       //Wait for third pulse time to elapse
      digitalWrite(LED_RED, LOW);                 //Set signal A low
      delayMicroseconds(SIGNAL_A_LOW_b);          //Wait for low time b to elapse
      delayMicroseconds(SIGNAL_A_LOW_d);          //Wait for low time d to elapse
}

void signal_B_normal()                            //Declare function for signal B in normal mode
{
      digitalWrite(LED_BLUE, HIGH);                //Set signal A high
      delayMicroseconds(SIGNAL_B_PULSE);           //Wait for signal B pulse time to elapse
      digitalWrite(LED_BLUE, LOW);                 //Set signal B low
      delayMicroseconds(SIGNAL_B_TIME_LOW);        //Wait for signal B low time to elapse
 
}


void loop()                                       //Loop code infinitely
  {
    button_1_state = digitalRead(BUTTON_1_PIN);   //Read the state of the button 1 pin and update value of button state
    button_2_state = digitalRead(BUTTON_2_PIN);   //Read the state of the button 2 pin and update value of button state

    if(button_2_state == HIGH)
    {
      Serial.println("Button 2 pressed");                           //Print to serial monitor
      signal_A_normal();                                            //Call function for signal A
      Serial.println("Signal A is active: Normal mode");            //Print to serial monitor
      signal_B_normal();                                            //Call function for signal B
      Serial.println("Signal B is active: Normal mode");            //Print to serial monitor
    
    }

  }
