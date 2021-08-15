#define ARDUINO_AVR_NANO
#include<DirectIO.h>

Input<A2> sleft(false);
Input<A3> s1(false);
Input<A4> smid(false);
Input<A5> s3(false);
AnalogInput<A6> sright;  // on A6 DigitalRead-Write Dosen't Work

//Input<A1> s1(false);

Output<7> motor_leftpin1(false);
Output<6> motor_leftpin2(false);
AnalogOutput<5> motor_left_pwm_value(0);

Output<9> motor_rightpin1(false);
Output<8> motor_rightpin2(false);
AnalogOutput<10> motor_right_pwm_value(0);

uint8_t a = 100, b = 255;

uint8_t irleft = 0, ir1 = 0, irmid = 0, ir3 = 0, irright = 0, positionvalue = 0;
bool fullwhite = false;



void Set_Motor_State(uint8_t pwm_left, bool lf_pin_1, bool lf_pin_2, uint8_t pwm_right, bool rh_pin_1, bool rh_pin_2) {

  motor_left_pwm_value = pwm_left; //60 is good//pevious 30//50
  motor_leftpin1 = lf_pin_1;
  motor_leftpin2 = lf_pin_2;

  motor_right_pwm_value = pwm_right; //previous a
  motor_rightpin1 = rh_pin_1;
  motor_rightpin2 = rh_pin_2;

}


void right(uint8_t a)
{
  // Serial.println("l");
  Set_Motor_State(20, 1, 0, 255, 1, 0);

  motor_left_pwm_value = 20; //60 is good//pevious 30//50
  motor_leftpin1 = HIGH;
  motor_leftpin2 = LOW;

  motor_right_pwm_value = 255; //previous a
  motor_rightpin1 = HIGH;
  motor_rightpin2 = LOW;

}
void aright(uint8_t a)
{
  while (!smid) {
    // Serial.println("al");
    motor_left_pwm_value = 100; // 55//previous 30
    motor_leftpin1 = LOW;
    motor_leftpin2 = HIGH;

    motor_right_pwm_value = 255; //previous a
    motor_rightpin1 = HIGH;
    motor_rightpin2 = LOW ;
  }
}
void aaright(uint8_t b )
{
  while (smid) {
    // Serial.print("f");
    motor_left_pwm_value = 255; //previous 20
    motor_leftpin1 = HIGH;
    motor_leftpin2 = LOW;

    motor_right_pwm_value = 255; //previous 200
    motor_rightpin1 = HIGH;
    motor_rightpin2 = LOW ;
  }
  delay(200);

  while (!smid) {
    // Serial.println("aal");
    motor_left_pwm_value = 200; // 55
    motor_leftpin1 = LOW;
    motor_leftpin2 = HIGH;

    motor_right_pwm_value = 200;
    motor_rightpin1 = HIGH;
    motor_rightpin2 = LOW ;
    break;
  }


}
void aforward()
{

  motor_left_pwm_value = 255; ////255
  motor_leftpin1 = HIGH;
  motor_leftpin2 = LOW;

  motor_right_pwm_value = 255;
  motor_rightpin1 = HIGH;
  motor_rightpin2 = LOW ;

}
void left(uint8_t a)
{
  //Serial.println("r");
  motor_left_pwm_value = 255; //previous a
  motor_leftpin1 = HIGH;
  motor_leftpin2 = LOW;

  motor_right_pwm_value = 20; //previous 30//50
  motor_rightpin1 = HIGH;
  motor_rightpin2 = LOW ;

}
void aleft(uint8_t a)
{
  while (!smid) {
    // Serial.println("ar");
    motor_left_pwm_value = 255; //previous a
    motor_leftpin1 = HIGH;
    motor_leftpin2 = LOW;

    motor_right_pwm_value = 100; //previous 30
    motor_rightpin1 = LOW;
    motor_rightpin2 = HIGH;
  }
}

void aaleft(uint8_t b)
{
  while (smid) {
    // Serial.print("f");
    motor_left_pwm_value = 255; //previous 200
    motor_leftpin1 = HIGH;
    motor_leftpin2 = LOW;

    motor_right_pwm_value = 255; //previous 20
    motor_rightpin1 = HIGH;
    motor_rightpin2 = LOW ;
  }
  delay(200);

  while (!smid) {

    //Serial.println("aar");
    motor_left_pwm_value = 200;
    motor_leftpin1 = HIGH;
    motor_leftpin2 = LOW;

    motor_right_pwm_value = 200;
    motor_rightpin1 = LOW ;
    motor_rightpin2 = HIGH ;
    break;
  }

}
void aaaleft(uint8_t b)
{

  while (smid) {
    //Serial.print("90");
    motor_left_pwm_value = 255; //previous 200
    motor_leftpin1 = HIGH;
    motor_leftpin2 = LOW;

    motor_right_pwm_value = 255; //previous 10
    motor_rightpin1 = HIGH ;
    motor_rightpin2 = LOW  ;
  }
  delay(300);
  while (!smid) {

    // Serial.println("aar");
    motor_left_pwm_value = 200;
    motor_leftpin1 = HIGH;
    motor_leftpin2 = LOW;

    motor_right_pwm_value = 200; //pervious 10//20
    motor_rightpin1 = LOW ;
    motor_rightpin2 = HIGH ;
    break;
  }


}


void aaaright(uint8_t b)
{

  while (smid) {
    //Serial.print("90");
    motor_left_pwm_value = 255; //pervious 10
    motor_leftpin1 = HIGH;
    motor_leftpin2 = LOW;

    motor_right_pwm_value = 255; //pervious 200
    motor_rightpin1 = HIGH ;
    motor_rightpin2 = LOW ;
  }
  delay(300);
  while (!smid) {

    //Serial.println("aar");
    motor_left_pwm_value = 200; //pervious 10
    motor_leftpin1 = LOW;
    motor_leftpin2 = HIGH;

    motor_right_pwm_value = 200;
    motor_rightpin1 = HIGH ;
    motor_rightpin2 = LOW ;
    break;
  }


}


//// .................................SHARP TURNS  ...................................
void Stop() {
  motor_left_pwm_value = 0;
  motor_leftpin1 = LOW;
  motor_leftpin2 = LOW;

  motor_right_pwm_value = 0;
  motor_rightpin1 = LOW;
  motor_rightpin2 = LOW ;
}

void turnRight() {
  motor_left_pwm_value = 255;
  motor_leftpin1 = HIGH;
  motor_leftpin2 = LOW;

  motor_right_pwm_value = 100;
  motor_rightpin1 = LOW;
  motor_rightpin2 = HIGH ;
}

void turnLeft() {
  motor_left_pwm_value = 100;
  motor_leftpin1 = LOW ;
  motor_leftpin2 = HIGH ;

  motor_right_pwm_value = 255 ;
  motor_rightpin1 = HIGH;
  motor_rightpin2 = LOW ;
}

void moveForward() {
  motor_left_pwm_value = 255;
  motor_leftpin1 = HIGH ;
  motor_leftpin2 = LOW;

  motor_right_pwm_value = 255 ;
  motor_rightpin1 = HIGH;
  motor_rightpin2 = LOW ;
}



void RUNLFR() {
  while (true) {

    irleft = sleft ? 1 : 0;
    ir1 = s1 ? 2 : 0;
    irmid = smid ? 4 : 0;
    ir3 = s3 ? 8 : 0;
    irright = sright > 40 ? 16 : 0;

    positionvalue = irleft | ir1 | irmid | ir3 | irright;

    if (fullwhite) positionvalue = 31 - positionvalue;

#ifdef DEBUG

    char printvalue[] = {irleft ? '1' : '0', ir1 ? '1' : '0', irmid ? '1' : '0', ir3 ? '1' : '0', irright ? '1' : '0'};
    Serial.println(printvalue);
    Serial.println(positionvalue);
    
#endif

    switch (positionvalue) {

      case 4:
      case 27:
      case 14:
        aforward(); break;

      case 12:
      case 8:
        left(a); break;

      case 16:
        aleft(a); break;

      case 30:
      case 22:
        aaleft(b); break;

      case 20:
      case 24:
      case 28:
        aaaleft(b); break;

      case 2:
      case 6:
        right(a); break;

      case 1:
        aright(a); break;

      case 15:
        aaright(b); break;

      case 3:
      case 7:
      case 5:
      case 13:
        aaaright(b); break;

      default:
        aforward(); break;
    }

  }
}


void setup() {
  Serial.begin(115200);
  // put your setup code here=to run once:
  RUNLFR();
}

void loop() {
  // put your main code here=to run repeatedly:

}

