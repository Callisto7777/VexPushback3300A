#include "main.h"
#include "config.hpp"

// These are out of 127
const int DRIVE_SPEED = 135;
const int TURN_SPEED = 100;

void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(12.0, 0.0, 70.0);        // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(10.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  
  chassis.pid_turn_constants_set(3.0, 0.05, 20.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.5);

  chassis.odom_look_ahead_set(10_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}


//old functions for autons and opcontrol
//not used anymore
void bunnyUp() {
  bool bunnyStatus = false;

  bunnyStatus = !bunnyStatus;
  bunny.set_value(bunnyStatus);
}

void loaderUp() {
  bool loaderStatus = false;

  loaderStatus = !loaderStatus;
  loader.set_value(loaderStatus);
}


//Autonmous functions

void soloautonred() { //sawp WIP


  chassis.pid_drive_set(31_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(21_in, DRIVE_SPEED); //get to the goal
  chassis.pid_wait();
  high(); //last_stage
  pros::delay(600);
  chassis.pid_drive_set(-19_in, DRIVE_SPEED); //go A6 bottom right corner
  chassis.pid_wait();
  chassis.pid_turn_set(315_deg, TURN_SPEED);//ended here
  chassis.pid_wait();
  hoarding();  //while going to middle goal get the 3 balls in center
  chassis.pid_drive_set(-40_in, DRIVE_SPEED);//go to middle goal (hopefully aline) *mightneedtogo slowerngl
  chassis.pid_wait();
  chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(11_in, DRIVE_SPEED);
  chassis.pid_wait();
  middle();
  pros::delay(350);
  motorstop();
  loader.set_value(1);
  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(194.41_deg, TURN_SPEED); // this works very well
  chassis.pid_wait();
  chassis.pid_drive_set(68_in, 150);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  chassis.pid_wait();
  hoarding();
  chassis.pid_drive_set(45_in, 100);//go a lil slower so that the balls dont fly out
  chassis.pid_wait();
  pros::delay(10000);
  chassis.pid_drive_set(-25_in, 145);
  chassis.pid_wait();  
  intake.move_voltage(12000); //positive to intake
  intake.move_voltage(12000); //positive for middle goal
  last_stage.move_voltage(12000);
  pros::delay(2000);
}

void pidtesting() { //testing PID
  chassis.pid_turn_set(90_deg, DRIVE_SPEED);
  chassis.pid_wait();
}

void rightrush() { //rush to the right matchload and score on the high goal
  chassis.pid_drive_set(-30_in, DRIVE_SPEED);
  chassis.pid_wait();
  hoarding();
  loader.set_value(1); 
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, 67); //get to the goal
  chassis.pid_wait();
  pros::delay(670);
  chassis.pid_drive_set(50_in, 100); //go A6 bottom right corner
  loader.set_value(1); 
  chassis.pid_wait();
  intake.move_voltage(-10000); //positive for middle goal
  pros::delay(267);
  high();
  pros::delay(2967);
  motorstop();
  bunny.set_value(1);
  chassis.pid_wait();
  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg, TURN_SPEED);  
  bunny.set_value(0);
  chassis.pid_wait();
  chassis.pid_drive_set(13_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);  
  // bunny.set_value(0);
  chassis.pid_wait();
  chassis.pid_drive_set(25_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(45_deg, TURN_SPEED);  


}

void right7high() { //7 on long goal and wing
  chassis.odom_xyt_set(-46.5_in, -15.5_in, 270_deg);
  hoarding();
  chassis.pid_odom_set({{{-19_in, -25.5_in, 310_deg}, rev, 120}});
  pros::delay(467);
  loader.set_value(1);
  chassis.pid_wait();

  chassis.odom_xyt_set(-19_in, -25.5_in, 310_deg);
  loader.set_value(0);
  chassis.pid_turn_set(45_deg, TURN_SPEED); 
  chassis.pid_wait();
  bunny.set_value(1);
  chassis.pid_odom_set({{{-54_in, -47_in, 90_deg}, rev, 120}});
  loader.set_value(1);
  hoarding();
  chassis.pid_wait();
  chassis.pid_drive_set(-12_in, 140);
  bunny.set_value(0);
  pros::delay(76.7);
  chassis.pid_wait();
  
  chassis.pid_drive_set(56.7_in, DRIVE_SPEED);
  motorstop();
  pros::delay(267);
  highskills();
  

  chassis.odom_xyt_set(-27_in, -47_in, 90_deg);
  loader.set_value(0);
  chassis.pid_odom_set({{-39_in, -38_in}, rev, 120});
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(30_in, 150);
  chassis.pid_wait();
}

void redLeft() { //main left side auton
  chassis.odom_xyt_set(-46.5_in, 15.5_in, 270_deg);
  hoarding();
  chassis.pid_odom_set({{{-19_in, 25.5_in, 230_deg}, rev, 120}});
  pros::delay(567);
  loader.set_value(1);
  chassis.pid_wait();

  chassis.pid_drive_set(3_in, DRIVE_SPEED, true); //keep changing value
  motorstop();
  chassis.pid_wait();
  chassis.pid_turn_set(135_deg, TURN_SPEED); //this angle is correct 
  chassis.pid_wait();
  chassis.pid_drive_set(50_cm, DRIVE_SPEED, true);
  location.set_value(true);
  chassis.pid_wait();
  intake.move_voltage(-12000);
  last_stage.move_voltage(-12000);
  pros::delay(100.67);
  intake.move_voltage(6700);
  last_stage.move_voltage(-12000);
  pros::delay(3076.67);
  
  chassis.odom_xyt_set(-10_in, 8.5_in, 135_deg);
  loader.set_value(0);
  bunny.set_value(1);
  chassis.pid_odom_set({{{-54_in, 45_in, 90_deg}, rev, 120}});//correct //was 47_in for y before
  loader.set_value(1);
  motorstop();
  hoarding();
  chassis.pid_wait();
  chassis.pid_drive_set(-7_in, 140);
  bunny.set_value(0);
  pros::delay(97.67);
  chassis.pid_wait();

  chassis.pid_drive_set(67_in, 130);
  chassis.pid_wait();
  highskills();
}

void redRight() { //old right side auton (NOT USED ANYMORE)
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(40_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  pros::delay(1000);
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(315_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-35_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  low();
  pros::delay(1700);
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(200_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_drive_set(-45_cm, 60, true);
  hoarding();
  pros::delay(1300);
  chassis.pid_wait();
  chassis.pid_drive_set(110_cm, 100, true);
  //loader.set_value(0);
  chassis.pid_wait();
  high();
  //highredsort();
  chassis.pid_wait();
  pros::delay(1700);
  chassis.pid_wait();
}

void blueLeft() { //old left side auton w coloursort (NOT USED ANYMORE)
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(320_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  pros::delay(1000);
  chassis.pid_wait();
  motorstop();
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(45_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  middle();
  pros::delay(1700);
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(-127_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_drive_set(-45_cm, 60, true);
  hoarding();
  pros::delay(1700);
  chassis.pid_wait();
  chassis.pid_drive_set(110_cm, 67, true);
  loader.set_value(0);
  chassis.pid_wait();
  high();
  //highredsort();
  chassis.pid_wait();
  pros::delay(1700);
  chassis.pid_wait();
  //backward
  //315
  //forward
  //0
  //bunny
  //forward
  //end

}

void blueRight() { //old right side auton w coloursort (NOT USED ANYMORE)
  chassis.pid_drive_set(-32_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  chassis.pid_turn_set(40_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-55_cm, 60, true);
  chassis.pid_wait();
  pros::delay(1000);
  chassis.pid_wait();
  chassis.pid_drive_set(22_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(315_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-35_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  low();
  pros::delay(1700);
  chassis.pid_wait();
  motorstop();
  chassis.pid_drive_set(122_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_drive_set(-45_cm, 60, true);
  hoarding();
  pros::delay(1300);
  chassis.pid_wait();
  chassis.pid_drive_set(110_cm, 67, true);
  //loader.set_value(0);
  chassis.pid_wait();
  high();
  //highredsort();
  chassis.pid_wait();
  pros::delay(1700);
  chassis.pid_wait();
}

void westmechnov() { //First auton at WM Tounament (NOT USED ANYMORE)
    chassis.pid_drive_set(-80_cm, 70, true); //135
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait();
    loader.set_value(1);
    chassis.pid_wait();
    chassis.pid_drive_set(-50_cm, 70, true); //135
    chassis.pid_wait();
    hoarding();
    chassis.pid_wait();
    pros::delay(2000);
    chassis.pid_drive_set(140_cm, 70, true);
    chassis.pid_wait();
    highredsort();
    chassis.pid_wait();
    pros::delay(2000);
    motorstop();  
}

void leftnotsort() { //Left side auton w/out colour sort (NOT USED ANYMORE)
  chassis.pid_drive_set(-80_cm, 70, true); //135
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_wait();
  chassis.pid_drive_set(-50_cm, 70, true); //135
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  pros::delay(2000);
  chassis.pid_drive_set(140_cm, 70, true);
  chassis.pid_wait();
  high();
  chassis.pid_wait();
  pros::delay(3000);
  motorstop();
}

void rightnotsort(){ //Right side auton w/out colour sort (NOT USED ANYMORE)
  chassis.pid_drive_set(-80_cm, 70, true); //135
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  loader.set_value(1);
  chassis.pid_wait();
  chassis.pid_drive_set(-50_cm, 70, true); //135
  chassis.pid_wait();
  hoarding();
  chassis.pid_wait();
  pros::delay(2000);
  chassis.pid_drive_set(140_cm, 70, true);
  chassis.pid_wait();
  high();
  chassis.pid_wait();
  pros::delay(3000);
  motorstop();
}
