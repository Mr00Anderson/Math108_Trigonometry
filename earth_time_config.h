#ifndef MATH_108_TRIGONOMETRY_EARTH_TIME_CONFIG_H
#define MATH_108_TRIGONOMETRY_EARTH_TIME_CONFIG_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "human_time_config.h"

typedef struct earth_time_config {

    const struct human_time_config *HUMAN_TIME_CONFIG;

    /* Degrees per 1 Counterclockwise Revolution
     * Default: 360
     */
    const int DEGREES_PER_COUNTERCLOCKWISE_REVOLUTION;

    /*  Minutes per Degree
     *  Default: 60
     */
    const int MINUTES_PER_DEGREE;

   /* Second per Degree
    * Default: 3600
    */
    const int SECONDS_PER_DEGREE;
} earth_time_config;

const struct earth_position_helper {

    /*
     * The one minute as a degree
     * Default: 1' = 1/60
     */
    const float MINUTE_AS_DEGREE;

    /*
     * One second in minutes
     * Default: 1" = 1/60
     */
    const float SECOND_AS_DEGREE;

    /*
     * Seconds & Minutes as a Degree
     * Default: 1/60th * 1/60th
     */
    const float SECONDS_MINUTES_AS_DEGREE;
} earth_position_helpers;

typedef struct earth_position {

    /* Degrees per 1 Counterclockwise Revolution
     * Default: 360
     */
    float DEGREES;

    /*  Minutes per Degree
     *  Default: 60
     */
    float MINUTES;

    /* Second per Degree
     * Default: 3600
     */
    float SECONDS;
} earth_position;

const struct earth_time_config DEFAULT_EARTH_TIME = {
     &DEFAULT_HUMAN_TIME,
     360,
    60,
    3600
};

const struct earth_position_helper EARTH_POS_HELPERS = {
        0.0166667,
        0.0166667,
        0.0166667 * 0.0166667
};
const struct earth_position GMT = {
        0,
        0,
        0
};

extern void printEarthTimeConfiguration(const earth_time_config *configuration){
    printf("Earth Time Configuration: \n");
    printf("%2d degrees per counterclockwise revolution\n", configuration->DEGREES_PER_COUNTERCLOCKWISE_REVOLUTION);
    printf("%2d minutes per degree\n", configuration-> MINUTES_PER_DEGREE);
    printf("%2d seconds per degree\n", configuration-> SECONDS_PER_DEGREE);

    printHumanTimeConfiguration(configuration->HUMAN_TIME_CONFIG);
}

void printEarthPositionHelper(struct earth_position_helper *earthPositionHelper) {
    printf("Earth Position Helper: \n");
    printf("%f minutes as degrees \n", earthPositionHelper->MINUTE_AS_DEGREE);
    printf("%f seconds per minute\n", earthPositionHelper->SECOND_AS_DEGREE);
    printf("%f seconds + minutes as degrees\n", earthPositionHelper->SECONDS_MINUTES_AS_DEGREE);
}

void printEarthPosition(earth_position *position) {
    printf("Earth Position: \n");
    printf("%2f degrees \n", position->DEGREES);
    printf("%2f minutes\n", position->MINUTES);
    printf("%2f seconds\n", position->SECONDS);
}

extern float earthPositionToDecimal(earth_position *earthPosition){
    return earthPosition->DEGREES +
    earthPosition->MINUTES * EARTH_POS_HELPERS.MINUTE_AS_DEGREE +
    earthPosition->SECONDS * EARTH_POS_HELPERS.SECONDS_MINUTES_AS_DEGREE;
}

extern struct earth_position decimalToEarthPosition(float earthPositionDecimal){
    earth_position newEarthPosition = {
            0,0,0
    };
    float fractionalMinutesSeconds = modff(earthPositionDecimal, &newEarthPosition.DEGREES);
    float minutesSecondsFraction = fractionalMinutesSeconds * DEFAULT_EARTH_TIME.MINUTES_PER_DEGREE;
    float fractionalSeconds = modff(minutesSecondsFraction, &newEarthPosition.MINUTES);
    float earthPositionSeconds = fractionalSeconds * DEFAULT_EARTH_TIME.MINUTES_PER_DEGREE;
    newEarthPosition.SECONDS = earthPositionSeconds;
    return newEarthPosition;
}

#endif //MATH_108_TRIGONOMETRY_EARTH_TIME_CONFIG_H
