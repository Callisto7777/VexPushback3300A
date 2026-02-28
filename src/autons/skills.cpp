#include "main.h"
#include "config.hpp"

const int DRIVE_SPEED = 135;
const int TURN_SPEED = 100;

// void odom_enable(bool input);

void skills75() {
  
    chassis.odom_xyt_set(-48_in, -17_in, 0_deg);
    loader.set_value(1);
    hoarding();
    chassis.pid_odom_set({{-48_in, -47_in}, rev, 120});
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED);//turning infront of matchloader
    chassis.pid_wait();
    chassis.pid_drive_set(-17.6_in, 67); // going towards matchloader              // hoarding the 6 balls from the top left matchloade //
    chassis.pid_wait();
    pros::delay(1067);//matchloading //this works

    chassis.odom_xyt_set(-62_in, -47_in, 90_deg); 
    chassis.pid_wait();
    chassis.pid_odom_set({{-57_in, -47_in}, fwd, 110}); //leavees matchloader
    chassis.pid_wait();
    // loader.set_value(0);
    bunny.set_value(1);
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{-57_in, -34_in}, fwd, 110});
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, 100);
    chassis.pid_wait();
    chassis.pid_odom_set({{33_in, -34_in}, fwd, 127}); //change this to 41 instead of 46
    chassis.pid_wait(); //crossing the bottom long goal
    
    loader.set_value(0);
    bunny.set_value(0);
    chassis.pid_turn_set(0_deg, TURN_SPEED); 
    chassis.pid_wait();
    chassis.pid_odom_set({{33_in, -47_in}, rev, 120}); //changed to -45 from -47
    chassis.pid_wait();
    chassis.pid_turn_set(270_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{21_in, -47_in}, fwd, 106}); //align with the long goal //changed 21 in to 11
    chassis.pid_wait();
    pros::delay(167);
    highskills();
    loader.set_value(1);
    // chassis.pid_odom_set({{60_in, -45_in}, rev, 67}); //-47
    chassis.pid_drive_set(-50_in, 56);
    hoarding();
    chassis.pid_wait();
    pros::delay(1070);
    chassis.pid_wait();

    // chassis.pid_odom_set({{27_in, -45_in}, fwd, 110}); //-47
    chassis.pid_drive_set(50_in, 100);
    chassis.pid_wait();
    highskills();
    loader.set_value(0);
    chassis.pid_wait();

    chassis.odom_xyt_set(27_in, -47_in, 270_deg); //?
    chassis.pid_wait();
    chassis.pid_odom_set({{41_in, -47_in}, rev, 127});
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, 100);
    chassis.pid_wait();
    chassis.pid_odom_set({{41_in, 46_in}, rev, 127}); //crossed the field cross
    chassis.pid_wait();
    chassis.pid_turn_set(270_deg, 100);
    chassis.pid_wait();
    chassis.pid_odom_set({{20_in, 47_in}, fwd, 100}); //aline with the top long goal
    chassis.pid_wait();

    //reset ^^^
    chassis.pid_wait();
    loader.set_value(1);
    chassis.pid_odom_set({{60_in, 47_in}, rev, 100}); //going to matchloader
    // chassis.pid_wait();
    pros::delay(1070);
    hoarding();
    pros::delay(1070);
    chassis.pid_wait();

    chassis.pid_odom_set({{52_in, 47_in}, fwd, 120}); //exiting matchloader
    chassis.pid_wait();
    motorstop();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{52_in, 33_in}, fwd, 127}); //getting ready to cross the field
    chassis.pid_wait();
    chassis.pid_turn_set(270_deg, TURN_SPEED);
    bunny.set_value(1);
    chassis.pid_wait();
    chassis.pid_odom_set({{-47_in, 33_in}, fwd, 127});//crossing
    chassis.pid_wait(); //crossing the top long goal
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();

    bunny.set_value(0);
    chassis.pid_odom_set({{-47_in, 47_in}, fwd, 127}); 
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, 100);
    chassis.pid_wait();
    chassis.pid_odom_set({{-25_in, 47_in}, fwd, 100});
    chassis.pid_wait();
    highskills();
    
    loader.set_value(1);
    chassis.pid_odom_set({{-62_in, 47_in}, rev, 120});
    chassis.pid_wait();
    hoarding();
    pros::delay(1070);
    chassis.pid_wait();

    chassis.pid_odom_set({{-27_in, 47_in}, fwd, 120});
    chassis.pid_wait();
    highskills(); //after getting matchload last_stage on high top
    loader.set_value(0);

    chassis.pid_odom_set({{-61.46_in, 24.096_in, 0_deg}, rev, 127});
    chassis.pid_wait();
    chassis.pid_drive_set(14_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-300.67_in, 140, true);
    chassis.pid_wait();

  }

void skillslemlib() {
    // chassis.setPose(-48, -17, 0);
    // loader.set_value(1);
    // hoarding();
    // chassis.moveToPoint(-48, -46.91, 1200,
    //                     {.forwards = false, .minSpeed = 120});
    // chassis.turnToHeading(90, 200);//turning infront of matchloader
    // chassis.moveToPoint(-61.812, -47.31, 1200, {.forwards = false, .minSpeed = 120});
    // pros::delay(2670);//matchloading

    // loader.set_value(0);
    // //chassis.turnToPoint(-22.35, -35.62, 200);
    // chassis.moveToPose(-22.35, -35.62, 90, 1200,
    //                     {.forwards = false, .minSpeed = 120});
    // //chassis.turnToHeading(270, 200);
    // chassis.moveToPoint(37.54, -35.45, 1200,
    //                     {.forwards = false, .minSpeed = 126});
    // chassis.moveToPose(27.414, -46.796, 270, 1200);
    // //infront of bottom long goal
    // intake.move_voltage(-10000);
    // pros::delay(267);
    // high();
    // pros::delay(3670); //scoring bottom long goal
    // motorstop();
    // hoarding();
    // loader.set_value(1);
    // chassis.moveToPoint(63.72, -47.1, 1200,
    //                     {.forwards = true, .minSpeed = 120});
    // chassis.moveToPose(27.414, -46.796, 270, 1200);
    // pros::delay(670);
    // loader.set_value(0);
    // intake.move_voltage(-10000);
    // pros::delay(267);
    // high();
    // pros::delay(3670); //scoring bottom long goal again
    // motorstop();
    // //done scorring on the bottom long goal now to go to top high goal
    // chassis.moveToPoint(40.43, -47.24, 1200,
    //                    {.forwards = false, .minSpeed = 120});
    // chassis.moveToPose(34.376, -46.22, 270, 1200);
    // loader.set_value(1);
    // hoarding();
    // chassis.moveToPoint(34.376, 46.22, 1200,
    //                    {.forwards = false, .minSpeed = 120});
    // pros::delay(2670); //matchloading from top right
    // motorstop();
    // chassis.moveToPose(24.096, 32.652, 270, 1200,
    //                    {.forwards = true, .minSpeed = 120});
    // loader.set_value(0);
    // chassis.moveToPose(-31.954, 32.477, 270, 1200, 
    //                    {.forwards = true, .minSpeed = 127});
    // chassis.moveToPose(-26.042, 47.297, 90, 1200,
    //                    {.forwards = true, .minSpeed = 120});
    // pros::delay(267);
    // intake.move_voltage(-10000);
    // pros::delay(267);
    // high();
    // pros::delay(3670); //scoring top high goal
    // motorstop();

    // hoarding();
    // loader.set_value(1);
    // chassis.moveToPoint(-62.905, 46.817, 2000, 
    //                     {.forwards = false});
    // pros::delay(2670);//matchloading from top left
    // motorstop();
    // loader.set_value(0);
    // chassis.moveToPoint(-26.042, 47.297, 1200,
    //                     {.forwards = true});
    // pros::delay(267);
    // intake.move_voltage(-10000);
    // pros::delay(267);
    // high();
    // pros::delay(3670); //scoring top high goal again
    // motorstop();

    // chassis.moveToPose(-45.4, 47.319, 90, 1200, 
    //                     {.forwards = false});
    // chassis.moveToPose(-38.24, 0, 270, 1200, 
    //                     {.forwards = true});
    // pros::delay(500);
    // chassis.pid_drive_set(300.67_in, 140); //Parking
    // chassis.pid_wait();
}

void skills15() {
  chassis.pid_drive_set(12_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-300.67_cm, DRIVE_SPEED, true);
  chassis.pid_wait();
}

void skills() {

  //Part 1
  chassis.pid_drive_set(-32_in, DRIVE_SPEED); //going towards the matchloader
  chassis.pid_wait(); 
  chassis.pid_turn_set(270_deg, TURN_SPEED);
  chassis.pid_wait();
  hoarding();              //
  loader.set_value(1);     //matchloader down and start hoarding
  chassis.pid_wait();      //
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);    //
  chassis.pid_wait();                            // matchloading and hoarding while going back 
  chassis.pid_drive_set(5_in, DRIVE_SPEED);      // and forth so that the balls dont get stuck
  chassis.pid_wait();                            // hopefully aline and matchloader works...
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);    //      
  chassis.pid_wait();
  pros::delay(1670); //robot now hoarding from the tubes top left


  //Part 2
  chassis.pid_drive_set(20_in, DRIVE_SPEED); 
  loader.set_value(0); 
  chassis.pid_wait();
  chassis.pid_turn_set(315_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(26.7_in, DRIVE_SPEED); 
  chassis.pid_wait();
  chassis.pid_turn_set(270_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(57_in, 140); //long path infront of the long goal
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);   //
  chassis.pid_wait();                        //
  chassis.pid_drive_set(15_in, DRIVE_SPEED); //see if you can make this entire part an arc or
  chassis.pid_wait();                        //a curve or something i dunno just make it not so clunky
  chassis.pid_turn_set(90_deg, TURN_SPEED); //
  chassis.pid_wait();                        // 
  chassis.pid_drive_set(30_in, DRIVE_SPEED); // 
  high();
  pros::delay(5678);//scoring top high goal on right side

  motorstop();
  hoarding();
  loader.set_value(1); 
  chassis.pid_wait();
  chassis.pid_drive_set(-60_in, 100);
  chassis.pid_wait();
  pros::delay(1670);//robot now hoarding from the tubes top right
  chassis.pid_drive_set(60_in, 67);
  loader.set_value(0); 
  motorstop();
  chassis.pid_wait();
  high();
  pros::delay(5678);//scoring on top high goal again after top right tube
       
  motorstop();


}

void skills30() {

  //first part
  chassis.pid_drive_set(-30.2_in, DRIVE_SPEED); // driving infront of the matchloader
  chassis.pid_wait();
  hoarding(); 
  loader.set_value(1); //bringing the loader down
  chassis.pid_turn_set(90_deg, TURN_SPEED); 
  chassis.pid_wait();
  chassis.pid_drive_set(-17.6_in, 67); // going towards matchloader              // hoarding the 6 balls from the top left matchloade //
  chassis.pid_wait();
  chassis.pid_drive_set(5_in, 67);   // slower to not have the balls jump out of the matchloader
  chassis.pid_wait();                //
  chassis.pid_drive_set(-10_in, 67); //
  chassis.pid_wait();
  motorstop();
  hoarding();
  pros::delay(1670);
  chassis.pid_drive_set(43_in, DRIVE_SPEED); 
  chassis.pid_wait();
  pros::delay(100);
  intake.move_voltage(-10000); //positive for middle goal
  intake.move_voltage(-5000);
  pros::delay(267);
  motorstop();
  high();
  pros::delay(2067);


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
  chassis.pid_turn_set(160_deg, TURN_SPEED); //146
  chassis.pid_wait();
  chassis.pid_drive_set(-70.67_in, 150);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(25_in, 115); //aline with bottom long goal
  motorstop();
  chassis.pid_wait();
  pros::delay(100);
  intake.move_voltage(-10000); 
  intake.move_voltage(-5000);
  pros::delay(267);
  motorstop();
  high();
  pros::delay(2067);         // scoring the middle balls in bottom long goal


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
  pros::delay(2267);               //so awesome wowowowow (hopefully it alines again)
  chassis.pid_drive_set(50_in, 115);
  motorstop();
  chassis.pid_wait();
  intake.move_voltage(-10000); 
  pros::delay(267);
  high();             //scoring 6 balls on bottom high goal
  pros::delay(2067);
  motorstop();
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  loader.set_value(0); 
  chassis.pid_wait();
  chassis.pid_turn_set(180, TURN_SPEED); //turning towards park zone
  chassis.pid_wait();
  chassis.pid_drive_set(48.67_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(270, TURN_SPEED);
  high();
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, DRIVE_SPEED); //Parking
  chassis.pid_wait();
  chassis.pid_drive_set(300.67_in, DRIVE_SPEED); //Parking
  chassis.pid_wait();

}



