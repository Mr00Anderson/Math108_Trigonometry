#ifndef MATH_108_TRIGONOMETRY_HUMAN_TIME_CONFIG_H
#define MATH_108_TRIGONOMETRY_HUMAN_TIME_CONFIG_H
#include <stdio.h>

/*
 * We want to hold data to configuration human time
 */
typedef struct human_time_config {
   /*
     Hours per Day
     Default: 24
   */
   const int HOURS_PER_DAY;

   /*
     Minutes per hour
     Default: 60
   */
   const int MINUTES_PER_HOUR;

   /*
     Seconds per minute
     Default: 60
    */
   const int SECONDS_PER_MINUTE;

   /*
     Milliseconds per second.
     Default: 1,000
   */
   const int MILLISECOND_PER_SECOND;

   /*
     Nanoseconds per Millisecond
     Default: 1,000,000
   */
   const int NANO_SECOND_PER_MILLISECOND;
 } human_time_config;


const struct human_time_config DEFAULT_HUMAN_TIME = {
    24,
    60,
    60,
    1000,
    10000000
  };

 extern void printHumanTimeConfiguration(const human_time_config *configuration){
    printf("Human Time Configuration: \n");
    printf("%d hours per day\n", configuration->HOURS_PER_DAY);
    printf("%d minutes per hour\n",configuration->MINUTES_PER_HOUR);
    printf("%d seconds per minute\n", configuration->SECONDS_PER_MINUTE);
    printf("%d milliseconds per second\n", configuration->MILLISECOND_PER_SECOND);
    printf("%d nanoseconds per milliseconds\n", configuration->NANO_SECOND_PER_MILLISECOND);
  }



#endif //MATH_108_TRIGONOMETRY_HUMAN_TIME_CONFIG_H
