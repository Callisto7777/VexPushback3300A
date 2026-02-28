#include "main.h"
#include "config.hpp"

const int DRIVE_SPEED = 135;
const int TURN_SPEED = 100;


void skillsediting() {
  
    chassis.odom_xyt_set(-48_in, -17_in, 0_deg);
    loader.set_value(1);
    hoarding();
    chassis.pid_odom_set({{-48_in, -47_in}, rev, 110});
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED);//turning infront of matchloader
    chassis.pid_wait();
    chassis.pid_odom_set({{-60_in, -47_in},  rev, 100}); //at the matchloader
    chassis.pid_wait();
    pros::delay(1070);//matchloading

    chassis.odom_xyt_set(-60_in, -47_in, 90_deg); 
    chassis.pid_wait();
    chassis.pid_odom_set({{-57_in, -47_in}, fwd, 110});
    chassis.pid_wait();
    loader.set_value(0);
    bunny.set_value(1);
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{-57_in, -33_in}, fwd, 110});
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, 100);
    chassis.pid_wait();
    chassis.pid_odom_set({{37_in, -33_in}, fwd, 130}); //change this to 41 instead of 46
    chassis.pid_wait(); //crossing the bottom long goal
    
    bunny.set_value(0);
    chassis.pid_turn_set(0_deg, TURN_SPEED); 
    chassis.pid_wait();
    chassis.pid_odom_set({{37_in, -45_in}, rev, 110}); //changed to -45 from -47
    chassis.pid_wait();
    chassis.pid_turn_set(270_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{21_in, -45_in}, fwd, 110}); //changed to -45 from -47
    chassis.pid_wait();
    highskills();
    loader.set_value(1);
    chassis.pid_odom_set({{60_in, -47_in}, rev, 67});
    chassis.pid_wait();
    hoarding();
    pros::delay(1670);

    chassis.pid_odom_set({{27_in, -47_in}, fwd, 110});
    loader.set_value(0);
    chassis.pid_wait();
    highskills();
    //reset position

    chassis.odom_xyt_set(27_in, -47_in, 270_deg);
    chassis.pid_wait();
    chassis.pid_odom_set({{41_in, -47_in}, rev, 110});
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{41_in, 46_in}, rev, 110}); //crossed the field cross
    chassis.pid_wait();
    chassis.pid_turn_set(270_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{20_in, 47_in}, fwd, 110}); //aline with the top long goal
    chassis.pid_wait();

    chassis.odom_xyt_set(27_in, 47_in, 270_deg); //reseting positon
    //reset ^^^
    chassis.pid_wait();
    loader.set_value(1);
    chassis.pid_odom_set({{60_in, 47_in}, rev, 67}); //going to matchloader
    chassis.pid_wait();
    hoarding();
    pros::delay(367);//matchloading

    chassis.pid_odom_set({{52_in, 47_in}, fwd, 110}); //exiting matchloader
    loader.set_value(0);
    motorstop();
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{52_in, 36_in}, fwd, 110}); //getting ready to cross the field
    chassis.pid_wait();
    chassis.pid_turn_set(270_deg, TURN_SPEED);
    bunny.set_value(1);
    chassis.pid_wait();
    chassis.pid_odom_set({{-47_in, 36_in}, fwd, 110});//crossing
    chassis.pid_wait(); //crossing the top long goal
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();

    bunny.set_value(0);
    chassis.pid_odom_set({{-47_in, 47_in}, fwd, 110});
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, 100);
    chassis.pid_wait();
    chassis.pid_odom_set({{-27_in, 47_in}, fwd, 110});
    chassis.pid_wait();
    highskills();
    
    loader.set_value(1);
    chassis.pid_odom_set({{-62_in, 47_in}, rev, 110});
    chassis.pid_wait();
    hoarding();
    pros::delay(367);
    chassis.pid_odom_set({{-27_in, 47_in}, fwd, 110});
    loader.set_value(0);
    chassis.pid_wait();
    intake.move_voltage(-12000);
    last_stage.move_voltage(-12000); //last_stage on high         //
    pros::delay(267);                     //
    motorstop();
    high();
    pros::delay(2067);
    chassis.pid_wait(); //after getting matchload last_stage on high top

    chassis.pid_odom_set({{-61.46_in, 24.096_in, 0_deg}, rev, 110});
    chassis.pid_wait();
    chassis.pid_drive_set(12_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-300.67_cm, DRIVE_SPEED, true);
    chassis.pid_wait();

  }
