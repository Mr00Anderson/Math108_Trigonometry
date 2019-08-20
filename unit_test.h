#ifndef MATH_108_TRIGONOMETRY_UNIT_TEST_H
#define MATH_108_TRIGONOMETRY_UNIT_TEST_H

#include <stdbool.h>
#import "unit_test.h"
#import "earth_time_config.h"

const float FLOATING_POINT_DRIFT_ALLOWANCE = 0.000100f;
const float FLOATING_POINT_DRIFT_ALLOWANCE_2 = 0.002000f;
const bool PRINT_STATEMENTS = true;

extern void printTestHeader(char *testName){
    printf("\n==================================================\n");
    printf("Unit Test: %s\n", testName);
    printf("==================================================\n");
}

extern void passTest(char *testName){
    printf("\n==================================================\n");
    printf("Unit Test: %s\n", testName);
    printf("TEST PASSED!\n");
    printf("==================================================\n");
}

extern void failTest(char *testName, char *reason){
    printf("\n==================================================\n");
    printf("Unit Test: %s\n", testName);
    printf("TEST FAILED! %s\n", reason);
    printf("==================================================\n");
}

// TODO Asserts

extern void testEarthPositionToDecimal(){
    char *testName = "testEarthPositionToDecimal";
    printTestHeader(testName);

    float expectedDecPos = 50.1058f;

    earth_position testPosition = {50, 6, 21};
    float earthPositionDecimal = earthPositionToDecimal(&testPosition);
    printEarthPosition(&testPosition);
    printEarthPositionHelper(&EARTH_POS_HELPERS);
    if(PRINT_STATEMENTS) {
        printf("Earths Position in Decimal %f\n", earthPositionDecimal);
    }

    float minimum = expectedDecPos - FLOATING_POINT_DRIFT_ALLOWANCE;
    float maximum = expectedDecPos + FLOATING_POINT_DRIFT_ALLOWANCE;
    if(PRINT_STATEMENTS) {
        printf("Earth position boundaries. "
               "Earth Position %f. Expected Position %f.\n", earthPositionDecimal, expectedDecPos);
    }

    if(earthPositionDecimal < minimum || earthPositionDecimal > maximum){
        failTest(testName, "Earth out of bounds");
    } else {
        passTest(testName);
    }
}


extern void testDecimalToEarthPosition(){
    char *testName = "testEarthPositionToDecimal";
    printTestHeader(testName);

    earth_position expectedDecPos = {21,15,21.6f};
    float earthPositionDecimal = 21.256f;

    earth_position actualEarthPosition = decimalToEarthPosition(earthPositionDecimal);

    if(PRINT_STATEMENTS) {
        printf("Expected earth position: \n");
        printEarthPosition(&expectedDecPos);

        printf("Actual earth position: \n");
        printEarthPosition(&actualEarthPosition);
    }

    float minimum = expectedDecPos.SECONDS - FLOATING_POINT_DRIFT_ALLOWANCE_2;
    float maximum = expectedDecPos.SECONDS + FLOATING_POINT_DRIFT_ALLOWANCE_2;

    if(actualEarthPosition.DEGREES != expectedDecPos.DEGREES){
        failTest(testName, "Degrees are not equal");
        return;
    }

    if(actualEarthPosition.MINUTES != expectedDecPos.MINUTES){
        failTest(testName, "Minutes are not equal");
        return;
    }

    if(actualEarthPosition.SECONDS < minimum || actualEarthPosition.SECONDS > maximum){
        failTest(testName, "Seconds are not equal and are greater then floating point drift.");
        return;
    } else {
        passTest(testName);
    }

}



#endif //MATH_108_TRIGONOMETRY_UNIT_TEST_H
