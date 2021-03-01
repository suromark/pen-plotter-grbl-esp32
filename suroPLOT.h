#pragma once
// clang-format off

/*
        suroPLOT is a DIY CoreXY pen plotter made from 2020 aluminum rods.
        It has two NC endstops for each X/Y axis and a RC servo as pen lifter.
        It's cheap, but I made it myself so I'm partially proud-blind to its shortcomings.
        YMMV.
        
        suroPLOT is based on:
        pen_laser.h
        Part of Grbl_ESP32

        Pen assignments for the Buildlog.net pen laser controller V1 & V2

        For pen mode be sure to uncomment #define USE_PEN_SERVO in config.h
        For solenoid  mode be sure to uncomment #define USE_PEN_SERVO in config.h
        For laser mode, you do not need to change anything
        Note: You can use all 3 modes at the same time if you want

        2019    - Bart Dring
        2020    - Mitch Bradley

        Grbl_ESP32 is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        Grbl is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME "suroPLOT"

#define CUSTOM_CODE_FILENAME    "../Custom/CoreXY.cpp"

#define USE_KINEMATICS      // there are kinematic equations for this machine
#define USE_FWD_KINEMATICS  // report in cartesian (works with February 2021 build, not earlier ones)
#define USE_MACHINE_INIT    // There is some custom initialization for this machine
#define USE_CUSTOM_HOMING

#define DEFAULT_HOMING_CYCLE_0 bit(X_AXIS) // it's a coreXY with an absolute Z axis, can't home X and Y at once
#define DEFAULT_HOMING_CYCLE_1 bit(Y_AXIS) // let's just run X first then Y, no special reason for the order though.

// Wiring the SD Card: 
// GPIO_NUM_23 = SPI_MOSI
// GPIO_NUM_19 = SPI_MISO
// GPIO_NUM_5  = SPI_CS0
// GPIO_NUM_18 = SPI_CLK

#define X_STEP_PIN              GPIO_NUM_33 // was: 12, but 12 MUST NOT BE HIGH during boot! (which it is in my circuit!)
#define X_DIRECTION_PIN         GPIO_NUM_26

#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_25

#define STEPPERS_DISABLE_PIN    GPIO_NUM_13

#define X_LIMIT_PIN             GPIO_NUM_15
#define Y_LIMIT_PIN             GPIO_NUM_4

#define USING_SERVO  // uncomment to use this feature

#define USE_PEN_SERVO

    #define Z_SERVO_PIN             GPIO_NUM_27
    #define DEFAULT_Z_MAX_TRAVEL 5.0 // This is percent in servo mode...used for calibration
    #define DEFAULT_Z_HOMING_MPOS         5.0   // MPos will be set to 5mm after homing (pen up)
    #define Z_SERVO_CAL_MIN               1.0   // calibration factor for the minimum PWM duty
    #define Z_SERVO_CAL_MAX               1.0   // calibration factor for the maximum PWM duty

#define SPINDLE_TYPE SpindleType::NONE

// defaults
#define DEFAULT_STEP_PULSE_MICROSECONDS 3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // stay on

#define DEFAULT_STEPPING_INVERT_MASK 0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK 0 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE 0 // boolean
#define DEFAULT_INVERT_LIMIT_PINS 1 // boolean
#define DEFAULT_INVERT_PROBE_PIN 0 // boolean

#define DEFAULT_STATUS_REPORT_MASK 1

#define DEFAULT_JUNCTION_DEVIATION 0.01 // mm
#define DEFAULT_ARC_TOLERANCE 0.002 // mm
#define DEFAULT_REPORT_INCHES 0 // false

#define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
#define DEFAULT_HARD_LIMIT_ENABLE 1  // false

#define DEFAULT_HOMING_ENABLE 1
#define DEFAULT_HOMING_DIR_MASK 0 // move positive dir Z, negative X,Y
#define DEFAULT_HOMING_FEED_RATE 300.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE 4000.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF 5.0 // mm

#define DEFAULT_SPINDLE_RPM_MAX 1000.0 // rpm
#define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm

#define DEFAULT_LASER_MODE 0 // false

#define DEFAULT_X_STEPS_PER_MM 80.0
#define DEFAULT_Y_STEPS_PER_MM 80.0
#define DEFAULT_Z_STEPS_PER_MM 100.0 // This is percent in servo mode...used for calibration

#define DEFAULT_X_MAX_RATE 5000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 5000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 5000.0 // mm/min

#define DEFAULT_X_ACCELERATION 150.0 // mm/sec^2. 50 mm/sec^2 = 180000 mm/min^2
#define DEFAULT_Y_ACCELERATION 150.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 150.0 // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL 500.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 500.0 // mm NOTE: Must be a positive value.

