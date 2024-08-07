#include <stdio.h>        // Includes the standard input/output library
#include <sys/time.h>     // Includes the library for time-related functions on the system
#include <time.h>         // Includes the libaray for time-related functions

int main(){
    struct timeval before;    // Declare a structure to hold the time before the computation
    gettimeofday(&before, NULL);  // Get the current time and store it in 'before'
    // Calculate the time in milliseconds
    long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000;

    int sum = 0;  // Variable to store the sum
    // Loop to perform the computation
    for (int i = 0; i < 100000000; i++) {
        sum += i;  // Add the current value of 'i' to 'sum'
    }

    struct timeval after;    // Declare a structure to hold the time after the computation
    gettimeofday(&after, NULL);  // Get the current time and store it in 'after'
    // Calculate the time in milliseconds
    long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000;

    // Print the difference in milliseconds, which is the time taken for the computation
    printf("%llu MS\n", after_millis - before_millis);
    return 0;  // Return 0 to indicate successful program execution
}
