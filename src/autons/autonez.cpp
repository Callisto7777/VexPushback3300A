#include "main.h"
#include "config.hpp"

const int DRIVE_SPEED = 135;
const int TURN_SPEED = 100;

void moveforward() {
    printf("moving forward...");
    chassis.odom_xyt_set(-46_in, 15.1_in, 180_deg);
    hoarding();

    chassis.pid_odom_set({{-22.2_in, 22_in, 315_deg}, rev, 110});
    chassis.pid_wait();

    chassis.pid_odom_set({{-10.5_in, 10.3_in, 315_deg}, fwd, 110});
    chassis.pid_wait();
}

void skillsez() {
    //first part
  chassis.pid_drive_set(-30_in, DRIVE_SPEED); // driving infront of the matchloader
  chassis.pid_wait();
  hoarding(); 
  loader.set_value(1); //bringing the loader down
  chassis.pid_turn_set(90_deg, TURN_SPEED); 
  chassis.pid_wait();
  chassis.pid_drive_set(-17.6_in, 67); // going towards matchloader
  chassis.pid_wait();                // hoarding the 6 balls from the top left matchloader
  chassis.pid_drive_set(5_in, 67);   // slower to not have the balls jump out of the matchloader
  chassis.pid_wait();                //
  chassis.pid_drive_set(-10_in, 67); //
  chassis.pid_wait();
  pros::delay(3670);
  chassis.pid_drive_set(40_in, DRIVE_SPEED); 
  loader.set_value(0); 
  chassis.pid_wait();
  motorstop();
  intake.move_voltage(-10000); 
  pros::delay(200);
  high();
  pros::delay(3670);
  motorstop(); //Scoring the 7 balls on top high goal


  //second part
  loader.set_value(0);
  chassis.pid_drive_set(-19_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg, TURN_SPEED);
  chassis.pid_wait();
  hoarding();  //while going to middle goal get the 4 balls in center
  chassis.pid_drive_set(-40_in, 67);//go to middle goal (hopefully aline)
  chassis.pid_wait();
  chassis.pid_drive_set(-1_in, DRIVE_SPEED); //moving back and using trig to calc distance required
  chassis.pid_wait();                        //to travel to the second high goal
  chassis.pid_turn_set(165.59_deg, TURN_SPEED); 
  chassis.pid_wait();
  chassis.pid_drive_set(-68_in, 150);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(25_in, 115); //aline with bottom long goal
  motorstop();
  chassis.pid_wait();
  intake.move_voltage(-10000); 
  pros::delay(200);
  high();
  pros::delay(3670);
  motorstop();          // scoring the middle balls in bottom long goal


  //third part
  chassis.pid_wait();
  hoarding(); 
  loader.set_value(1); //bring loader down
  chassis.pid_wait();
  chassis.pid_drive_set(-30_in, 67); // going towards matchloader
  chassis.pid_wait();                // hoarding the 6 balls from the top left matchloader
  chassis.pid_drive_set(5_in, 67);   // slower to not have the balls jump out of the matchloader
  chassis.pid_wait();                //
  chassis.pid_drive_set(-10_in, 67); //
  chassis.pid_wait();
  pros::delay(3670);               //so awesome wowowowow (hopefully it alines again)
  chassis.pid_drive_set(50_in, 115);
  motorstop();
  chassis.pid_wait();
  intake.move_voltage(-10000); 
  pros::delay(200);
  high();             //scoring 6 balls on bottom high goal
  pros::delay(3670);
  motorstop();
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  loader.set_value(0); 
  chassis.pid_wait();
  chassis.pid_turn_set(180, TURN_SPEED); //turning towards park zone
  chassis.pid_wait();
  chassis.pid_drive_set(47_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(270, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(300.67_in, DRIVE_SPEED); //Parking
  chassis.pid_wait();
}