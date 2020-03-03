// Code for a XY-plotter
// Project in ??? by Henrik E. V. Skaldebø and Knut Andre G. Prestsveen
// Currently only plays around and tests stepper motor
#include <Stepper.h>

// Number of steps per internal motor revolution
const float STEPS_PER_REV = 48;

// Gear reduction
const float GEAR_REDUCTION = 64;

// Number of steps per geared output rotation
const float STEPS_PER_OUTER_REV = STEPS_PER_REV * GEAR_REDUCTION;

// Number of steps required to turn (??)
int steps_required;

// Instance of Stepper class
// Uses pins 8, 9, 10 and 11 connected to In1, In2, In3 and In4
// Pins entered in seq.: 1 - 3 - 2 - 4
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);


void setup() {
}

void loop() {
    // Slow 4-step CW sequence to obs lights on driver board
    steppermotor.setSpeed(1);
    steps_required = 4;
    steppermotor.step(steps_required);
    delay(2000);

    // Rotate CW 1/2 turn slowly
    steps_required = STEPS_PER_OUT_REV / 2;
    steppermotor.setSpeed(100);
    steppermotor.step(steps_required);
    delay(1000);

    // Rotate CCW 1/2 turn quicly
    steps_required = -STEPS_PER_OUT_REV / 2;
    steppermotor.setSpeed(700);
    steppermotor.step(steps_required);
    delay(2000);
}




