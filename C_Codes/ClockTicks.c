#include <stdio.h>   // Includes the standard input/output library
#include <time.h>    // Includes the library for time-related functions

int main() {
    clock_t start_time, end_time;  // Variables to store the start and end times
    double cpu_time_used;          // Variable to store the CPU time used

    // Record the start time
    start_time = clock();  // 'clock()' returns the number of clock ticks since the program started

    // Place your code to measure execution time here
    // For example, let's simulate some computation
    int sum = 0;  // Variable to store the sum
    for (int i = 1; i <= 1000000; ++i) {  // Loop from 1 to 1,000,000
        sum += i;  // Add the current value of 'i' to 'sum'
    }

    // Record the end time
    end_time = clock();  // 'clock()' returns the number of clock ticks since the program started

    // Calculate the CPU time used in seconds
    // 'end_time - start_time' gives the number of clock ticks taken by the code block
    // Dividing by 'CLOCKS_PER_SEC' converts the clock ticks to seconds
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Print the result of the computation and the CPU time used
    printf("Sum: %d\n", sum);  // Print the calculated sum
    printf("CPU Time Used: %f seconds\n", cpu_time_used);  // Print the CPU time used in seconds

    return 0;  // Return 0 to indicate successful program execution
}
