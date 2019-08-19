#ifndef MATH_108_TRIGONOMETRY_EARTH_TIME_CONFIG_H
#define MATH_108_TRIGONOMETRY_EARTH_TIME_CONFIG_H
#include <stdio.h>
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

const struct earth_time_config DEFAULT_EARTH_TIME = {
     &DEFAULT_HUMAN_TIME,
     360,
    60,
    3600
};

extern void printEarthTimeConfiguration(earth_time_config *configuration){
    printf("Earth Time Configuration: \n");
    printf("%d degrees per counterclockwise revolution\n", configuration->DEGREES_PER_COUNTERCLOCKWISE_REVOLUTION);
    printf("%d minutes per degree\n", configuration-> MINUTES_PER_DEGREE);
    printf("%d seconds per degree\n", configuration-> SECONDS_PER_DEGREE);

    printHumanTimeConfiguration(configuration->HUMAN_TIME_CONFIG);
}

#endif //MATH_108_TRIGONOMETRY_EARTH_TIME_CONFIG_H
