


/*****************************************************
 * DEFINE CONSTANTS | FOR USE WITH OSCILLOSCOPE
*****************************************************/

#define SIGNAL_A_PULSE_a1 2300                  //Signal A first pulse duration
#define SIGNAL_A_PULSE_a2 2350                  //Signal A second pulse duration
#define SIGNAL_A_PULSE_a3 2400                  //Signal A third pulse duration
#define SIGNAL_A_LOW_b 900                      //Signal A low pulse duration (Parameter b)
#define SIGNAL_A_LOW_d 9500                     //Signal A low pulse duration (Parameter d)
#define SIGNAL_B_PULSE 50                       //Signal B pulse duration
#define SIGNAL_B_TIME_LOW ((SIGNAL_A_PULSE_a1 + SIGNAL_A_LOW_b + SIGNAL_A_PULSE_a2 + SIGNAL_A_LOW_b + SIGNAL_A_PULSE_a3 + SIGNAL_A_LOW_b + SIGNAL_A_LOW_d))     //Signal B low pulse duration (a1 + b + a2 + b + a3 + b + d)
#define SIGNAL_B_TIME_LOW_MODIFIED ((SIGNAL_A_PULSE_a1 + SIGNAL_A_LOW_b_HALF + SIGNAL_A_PULSE_a2 + SIGNAL_A_LOW_b_HALF + SIGNAL_A_PULSE_a3 + SIGNAL_A_LOW_b_HALF + SIGNAL_A_LOW_d_HALF))
#define SIGNAL_A_LOW_b_HALF ((SIGNAL_A_LOW_b / 2))     //Signal A half of low pulse duration (Parameter b/2)
#define SIGNAL_A_LOW_d_HALF ((SIGNAL_A_LOW_d / 2))     //Signal A half of low pulse duration (Parameter d/2)
#define DEBOUNCE_TIME 25                                    //Debounce time for button presses

/*****************************************************
 * DEFINE INPUT PINS
*****************************************************/

#define BUTTON_1_PIN 22
#define BUTTON_2_PIN 23

/*****************************************************
 * DEFINE OUTPUT PINS
*****************************************************/

#define SIGNAL_A 15
#define SIGNAL_B 21

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
  pinMode(BUTTON_1_PIN, INPUT_PULLDOWN);                 //Declare button 1 as an input
  pinMode(BUTTON_2_PIN, INPUT_PULLDOWN);                 //Declare button 2 as an input
  pinMode(SIGNAL_A, OUTPUT);                     //Declare Red LED as output
  pinMode(SIGNAL_B, OUTPUT);                    //Declare Blue LED as output

  Serial.println("Setup complete");            //Print to serial monitor

  }


void signal_normal()
{
  digitalWrite(SIGNAL_B, HIGH);
  delayMicroseconds(SIGNAL_B_PULSE);
  digitalWrite(SIGNAL_B, LOW);
  digitalWrite(SIGNAL_A, HIGH);
  delayMicroseconds(SIGNAL_A_PULSE_a1);          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, LOW);                 //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a2);       //Wait for second pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                 //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a3);       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                 //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b);          //Wait for low time b to elapse
  delayMicroseconds(SIGNAL_A_LOW_d);          //Wait for low time d to elapse
}

void signal_modified()
{
  digitalWrite(SIGNAL_B, HIGH);
  delayMicroseconds(SIGNAL_B_PULSE);
  digitalWrite(SIGNAL_B, LOW);
  digitalWrite(SIGNAL_A, HIGH);
  delayMicroseconds(SIGNAL_A_PULSE_a1);          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, LOW);                 //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b_HALF);          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a2);       //Wait for second pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                 //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b_HALF);          //Wait for low time b to elapse
  digitalWrite(SIGNAL_A, HIGH);                //Set signal A high
  delayMicroseconds(SIGNAL_A_PULSE_a3);       //Wait for third pulse time to elapse
  digitalWrite(SIGNAL_A, LOW);                 //Set signal A low
  delayMicroseconds(SIGNAL_A_LOW_b_HALF);          //Wait for low time b to elapse
  delayMicroseconds(SIGNAL_A_LOW_d_HALF);          //Wait for low time d to elapse
}



void loop()                                       //Loop code infinitely
  {
    button_1_state = digitalRead(BUTTON_1_PIN);   //Read the state of the button 1 pin and update value of button state
    button_2_state = digitalRead(BUTTON_2_PIN);   //Read the state of the button 2 pin and update value of button state

    if(button_1_state == HIGH)
    {
      Serial.println("Button 1 pressed");                           //Print to serial monitor
      Serial.println("Signal A is active: Normal mode");            //Print to serial monitor
      Serial.println("Signal B is active: Normal mode");            //Print to serial monitor
      signal_normal();                                            //Call function for signal B
    }
       if(button_1_state == HIGH && button_2_state == HIGH)
       {
        Serial.println("Button 2 pressed");                           //Print to serial monitor
        signal_modified();

        
       }
    
    }

  
