// #include "main.h"
// #include "config.hpp"
// #include "lemlib/api.hpp"

// void moveforward() { // y is forward aka to middle //x y thy
//     chassis.setPose(-46, 15.1, 180);
//     hoarding();
// //    chassis.moveToPose(-22.2, 22, 315, 2000, //infront of the matchloader
//             {.forwards = false});
// //    chassis.moveToPose(-10.5, 10.3, 315, 1670, //infront of the matchloader
//         {.maxSpeed = 127});
//     // pros::delay(1267);
//     // middle();
//     // pros::delay(3767);
//     // chassis.moveToPose(-47, 47, 90, 2000, //infront of the matchloader
//     //     {.forwards = false, .maxSpeed = 127});
//     // hoarding();
//     // loader.set_value(1);
//     // chassis.moveToPose(-67.7, 46.7, 90, 1200, 
//     //     {.forwards = false, .maxSpeed = 127});
//     // pros::delay(1200);
//     // chassis.moveToPose(-25.1, 47.1, 90, 1200, 
//     //     {.maxSpeed = 127});
//     // pros::delay(1200);
//     // intake.move_voltage(-10000);
//     // pros::delay(267);
//     // high();
//     // pros::delay(2967); 

//     // hoarding();
//     // chassis.moveToPose(-10.5, 10, 315, 2000, 
//     //                 {.forwards = false, .maxSpeed = 100},
//     //                 true); 
//     // pros::delay(500);
//     // chassis.moveToPose(-10, 10, 135, 2000);

                                     
//     // chassis.movetoPose(0, 6, 2000);
//     // chassis.turnToHeading(0, 6, 2000);
//     // chassis.movetoPoint(0, 6, 2000);
//     // chassis.movetoPoint(0, 6, 2000);
//     // chassis.movetoPoint(0, 6, 2000);
// } 

// void sawp() {
//     chassis.setPose(-46, -17, 0);
//     loader.set_value(1);
//     hoarding();
//     chassis.moveToPoint(-48, -46.91, 2000,
//                         {.forwards = false, .maxSpeed = 127});
//     chassis.turnToHeading(90, 200);//turning infront of matchloader
//     chassis.moveToPoint(-61.812, -47.31, 1200, {.forwards = false});
//     // chassis.moveToPose(-61.812, -47.31, 90, 2000, 
//     //                     {.forwards = false, });//going to the matchloader
//     pros::delay(127);//matchloading

//     chassis.moveToPose(-23.498, -47.1, 90, 1200);
//     pros::delay(1000);
//     loader.set_value(0);
//     pros::delay(1200);
//     intake.move_voltage(-10000);
//     pros::delay(267);
//     high();
//     pros::delay(1267);
//     motorstop();
//     chassis.setPose(-24.5, -47, 90);

//     hoarding();
//     chassis.moveToPose(-32.25, -40.1, 180, 1000,
//                         {.forwards = false, .maxSpeed = 127});
//     chassis.moveToPose(-22.525, -21.477, 180, 1000,
//                         {.forwards = false, .maxSpeed = 127});
//     chassis.moveToPose(-22.525, 21.477, 180, 1200,
//                         {.forwards = false, .maxSpeed = 127});
//     pros::delay(1700);//after getting 6 middle balls
//     chassis.turnToHeading(135, 200);
//     chassis.moveToPoint(-8.7, 9.08, 1200);
//     pros::delay(1700);
//     middle();
//     pros::delay(1767);
//     motorstop();
// //scoring on middle goal

//     chassis.moveToPose(-57.454, 46.296, 90, 2000,
//                         {.forwards = false, .maxSpeed = 127});
//     chassis.moveToPose(-26, 46.97, 90, 1000,
//                         {.forwards = true});
//     pros::delay(267);
//     high();
//     pros::delay(1367);
//     motorstop();




// }