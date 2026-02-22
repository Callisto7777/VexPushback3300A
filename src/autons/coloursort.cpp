#include "main.h"
#include "config.hpp"

//colour sort for blue alliance
void highbluesort() { //long goal colour sort

      if ((optical.get_hue() > 100 && optical.get_hue() < 225)) {
        high();
      }
      else if ((optical.get_hue() > 5 && optical.get_hue() < 25)) {
        middle();
      }
      else {
        intake.move_voltage(12000); 
        intake.move_voltage(6700); 
      }
}

void middlebluesort() { //middle goal colour sort

      if ((optical.get_hue() > 100 && optical.get_hue() < 225)) {
        middle();
      }
      else if ((optical.get_hue() > 5 && optical.get_hue() < 25)) {
        high();
      }
      else {
        intake.move_voltage(12000);
        intake.move_voltage(6700); 
      }
}


//colour sort for red alliance
void highredsort() { //long goal colour sort

      if ((optical.get_hue() > 5 && optical.get_hue() < 25)) {
        high();
      }
      else if ((optical.get_hue() > 100 && optical.get_hue() < 225)) {
        middle();
      }
      else {
        intake.move_voltage(12000); 
        intake.move_voltage(6700); 
      }
}

void middleredsort() { //middle goal colour sort

      if ((optical.get_hue() > 5 && optical.get_hue() < 25)) {
        middle();
      }
      else if ((optical.get_hue() > 100 && optical.get_hue() < 225)) {
        high();
      }
      else {
        intake.move_voltage(12000);
        intake.move_voltage(6700); 
      }
}