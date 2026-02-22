#include "main.h"
#include "config.hpp"

void BLmatchload() {
    chassis.pid_odom_set({{-62_in, -47_in}, rev, 110});
    chassis.pid_wait();
}

