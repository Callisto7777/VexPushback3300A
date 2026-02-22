// #include "lemlib/api.hpp"
#include "main.h"
#include "config.hpp"
#include "pros/motors.hpp"

//green in 200 blue is 600 and red is 400 (rpm)

//drivetrain motor groups
pros::MotorGroup left_motors({2, -1, -13}, pros::MotorGearset::blue); 
pros::MotorGroup right_motors({-9, 10, 20}, pros::MotorGearset::blue); 

//other motor group
// pros::Motor intake(16, pros::MotorGearset::red); // this is the intake first stage so the one that takes balls in
pros::Motor intake(-8, pros::MotorGearset::red); // first stage + flaps
pros::Motor last_stage(16, pros::MotorGearset::red); //last stage
pros::ADIDigitalOut loader('A'); //match loader
pros::ADIDigitalOut bunny('B'); //bunny ears
pros::ADIDigitalOut location('D'); //Scoring location between high or low
pros::ADIDigitalOut descore('E'); //Middle goal descore
pros::Rotation rotation_sensor(17);

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Optical optical(12);
pros::Imu imu_sensor(5);

ez::tracking_wheel vert_tracker(17, 2.75, 0);   // This tracking wheel is parallel to the drive wheels
ez::Drive chassis(                                                    
    {2, -1, -13},
    {-9, 10, 20},
        // Left chassis Ports  // Right chassis Ports 

    5,      // IMU Port
    2.75,  // Wheel Diameter 
    450);   // Wheel RPM 


