#include <stdio.h>
#include "human_time_config.h"
#include "earth_time_config.h"
#include "unit_test.h"

void runMathFunctions();
void runMathUnitTest();

int main() {
    printf("Hello, World!\n");

    runMathFunctions();
    runMathUnitTest();

    return 0;
}


void runMathFunctions(){

    if(PRINT_STATEMENTS) {
        printHumanTimeConfiguration(&DEFAULT_HUMAN_TIME);
        printf("\n");
        printEarthTimeConfiguration(&DEFAULT_EARTH_TIME);
    }
}

void runMathUnitTest(){
    testEarthPositionToDecimal();
    testDecimalToEarthPosition();
}