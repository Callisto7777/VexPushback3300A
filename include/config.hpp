//give me a sec gang
#pragma once
#ifndef CONFIG_HPP
#define CONFIG_HPP
#include "main.h"

// pros libraries
// 3rd party libraries

#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "EZ-Template/api.hpp"
#include "api.h"
#include "pros/optical.hpp"
//#include "robodash/api.h"
#include "liblvgl/lvgl.h"

extern ez::Drive chassis;
// extern lemlib::Drivetrain drivetrain;
// extern lemlib::TrackingWheel vertical_trackingwheel;
// extern lemlib::ControllerSettings lateral_controller;
// extern lemlib::ControllerSettings angular_controller;
// extern lemlib::OdomSensors sensors;
// extern lemlib::Chassis chassis;
//extern Drive chassis;

extern pros::MotorGroup left_motors; 
extern pros::MotorGroup right_motors;
extern pros::Imu imu_sensor;

extern pros::Controller controller;
extern pros::Motor intake; // this is the intake first stage so the one that takes balls in
extern pros::Motor last_stage; //this one decides scoring location
extern pros::ADIDigitalOut loader; //match loader
extern pros::ADIDigitalOut bunny; //bunny ears
extern pros::ADIDigitalOut location; //Scoring location between high or low
extern pros::ADIDigitalOut descore; //Middle goal descore
extern pros::Rotation rotation_sensor;
extern pros::Optical optical; //this is for colour sort
//extern pros::Rotation last_stageRotationSensor; //for odom ignore for now

//strings
extern std::string alliance;

/* Functions */
// DT
void arcadeDrive();
void refreshIntake();


void initializeColourSort();
void driverSkillsMacro();
void debugMode();

//colour sort
void highbluesort();
void middlebluesort();
void highredsort();
void middleredsort();

//opcontrol
void woutsort();
void withsort();
void high();
void middle();
void low();
void motorstop();
void hoarding();
void highskills();

/* Autons */
void redLeft();
void redRight();
void blueLeft();
void blueRight();
void westmechnov();
void moveforward();
void soloautonred();
void pidtesting();
void rightrush();
void right7high();
void sawp();
void skills();
void skills30();
void skills15();
void skills75();

//autons vals
void default_constants();
void bunnyUp();
void loaderUp();

#endif