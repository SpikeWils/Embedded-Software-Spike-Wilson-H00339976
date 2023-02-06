

#define SIGNAL_A_PULSE_a1 2300      //Signal A first pulse duration
#define SIGNAL_A_PULSE_a2 2350      //Signal A second pulse duration
#define SIGNAL_A_PULSE_a3 2400      //Signal A third pulse duration
#define SIGNAL_A_LOW_b 900      //Signal A low pulse duration (Parameter b)
#define SIGNAL_A_LOW_d 9500      //Signal A low pulse duration (Parameter d)
#define SIGNAL_B_PULSE 50      //Signal B pulse duration
#define SIGNAL_B_TIME_LOW ((SIGNAL_A_PULSE_a1 + SIGNAL_A_LOW_b + SIGNAL_A_PULSE_a2 + SIGNAL_A_LOW_b + SIGNAL_A_PULSE_a3 + SIGNAL_A_LOW_b + SIGNAL_A_LOW_d))     //Signal B low pulse duration (a1 + b + a2 + b + a3 + b + d)
#define SIGNAL_A_LOW_b_HALF ((SIGNAL_A_LOW_b_HALF / 2))
#define SIGNAL_A_LOW_d_HALF ((SIGNAL_A_LOW_d_HALF / 2))

#define BUTTON_1 22
#define BUTTON_2 23


#define LED_RED 15
#define LED_BLUE 21



void setup()
  {
  
  pinMode(BUTTON_1, INPUT);   //Declare button 1 as an input
  pinMode(BUTTON_2, INPUT);   //Declare button 2 as an input
  pinMode(LED_RED, OUTPUT);   //Declare Red LED as output
  pinMode(LED_BLUE, OUTPUT);  //Declare Blue LED as output

  }

void loop() 
  {
  digitalWrite(LED_RED, HIGH);    //Blink Red LED to verify microcontroller works
  delay(500);
  digitalWrite(LED_RED, LOW);
  delay(500);

  }
