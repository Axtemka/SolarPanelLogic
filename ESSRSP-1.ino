// #include "Servo.h"

// Servo hor;
// Servo ver;

// // PINS
// int down_left = A2;
// int down_right = A3;
// int top_left = A4;
// int top_right = A5;

// // VARS
// int subs = 200;
// int max_angle = 180;
// int angle_h = 0;
// int angle_v = 0;


// void setup() {
//   // initialize digital pin LED_BUILTIN as an output.
//   //pinMode(9, OUTPUT);
//   //Serial.begin(9600);
//   hor.attach(10);
//   ver.attach(11);
//   hor.write(angle_h);
//   ver.write(angle_v);

// } 

// void loop() {

//   int lt = analogRead(top_left); // top left
//   int rt = analogRead(top_right); // top right
//   int ld = analogRead(down_left); // down left
//   int rd = analogRead(down_right); // down right

//   int avt = (lt + rt) / 2; // average value top
//   int avd = (ld + rd) / 2; // average value down
//   int avl = (lt + ld) / 2; // average value left
//   int avr = (rt + rd) / 2; // average value right

//   int delta_h = abs(avl - avr);
//   int delta_v = abs(avt - avd);

//   if (delta_h > subs)
//   {
//     if (avl > avr)
//     {
//       if (angle_h - 1 >= 0) angle_h--;
//     }
//     else if (avl < avr)
//     {
//       if (angle_h + 1 <= max_angle) angle_h++;
//     }
//     hor.write(angle_h);
//   }


//   if (delta_v > subs)
//   {
//     if (avt > avd)
//     {
//       if (angle_v + 1 <= max_angle) angle_v++;
//     }
//     else if (avt < avd)
//     {
//       if (angle_v - 1 >= 0) angle_v--;
//     }
//     ver.write(angle_v);
//   }
// }

// // Поворот против часовой
// // void rotate_left(){
// //   hor.write(89);
// //   delay(60);
// //   hor.detach();
// //   hor.attach(9);
// //   // hor.write(90);
// // }
// // void rotate_right(){
// //   hor.write(91);
// //   delay(60);
// //   hor.detach();
// //   hor.attach(9);
// //   // hor.write(90);
// // }
#include "Servo.h"

Servo hor;
Servo ver;

// PINS
int down_left = A2;
int down_right = A3;
int top_left = A4;
int top_right = A5;

// VARS
int subs = 200;
int max_angle = 180;
int angle_h = 0;
int angle_v = 0;


void setup() {
  //pinMode(9, OUTPUT);
  //Serial.begin(9600);
  hor.attach(10);
  ver.attach(11);
  hor.write(90);
  ver.write(angle_v);

} 

void loop() {

  int lt = analogRead(top_left); // top left
  int rt = analogRead(top_right); // top right
  int ld = analogRead(down_left); // down left
  int rd = analogRead(down_right); // down right

  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int delta_h = abs(avl - avr);
  int delta_v = abs(avt - avd);

  if (delta_h > subs)
  {
    if (avl > avr)
    {
      rotate_left();
    }
    else if (avl < avr)
    {
      rotate_right();
    }
  }


  if (delta_v > subs)
  {
    if (avt > avd)
    {
      if (angle_v + 1 <= max_angle) angle_v++;
    }
    else if (avt < avd)
    {
      if (angle_v - 1 >= 0) angle_v--;
    }
    ver.write(angle_v);
  }
}

// Поворот против часовой
void rotate_left(){
  hor.attach(10);
  hor.write(92);
  delay(60);
  delay(60);
  hor.detach();
}
// Поворот по часовой
void rotate_right(){
  hor.attach(10);
  hor.write(100);
  delay(60);
  delay(60);
  hor.detach();
}
//
