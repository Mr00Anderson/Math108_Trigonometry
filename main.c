#include <stdio.h>
#include "human_time_config.h"
#include "earth_time_config.h"

void runMathFunctions();

int main() {
    printf("Hello, World!\n");

    runMathFunctions();
    return 0;
}


void runMathFunctions(){
    printHumanTimeConfiguration(&DEFAULT_HUMAN_TIME);
    printf("\n");
    printEarthTimeConfiguration(&DEFAULT_EARTH_TIME);
}