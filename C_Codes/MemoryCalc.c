#include <stdio.h>          // Includes the standard input/output library
#include <sys/resource.h>   // Includes the library for resource usage measures

int main() {
    // Record the start memory usage
    struct rusage usage_start;  // Declare a structure to hold resource usage information
    getrusage(RUSAGE_SELF, &usage_start);  // Get the resource usage for the calling process and store it in 'usage_start'

    // Place your code to measure memory usage here
    // For example, let's allocate some memory
    int *array = (int *)malloc(1000000 * sizeof(int));  // Allocate memory for an array of 1,000,000 integers

    // Record the end memory usage
    struct rusage usage_end;  // Declare another structure to hold resource usage information after the allocation
    getrusage(RUSAGE_SELF, &usage_end);  // Get the resource usage for the calling process again and store it in 'usage_end'

    // Calculate memory usage in kilobytes
    // 'ru_maxrss' is the maximum resident set size used (in kilobytes)
    long memory_used = usage_end.ru_maxrss - usage_start.ru_maxrss;  // Calculate the difference in memory usage before and after the allocation

    // Print the memory used
    printf("Memory Used: %ld KB\n", memory_used);  // Print the calculated memory usage in kilobytes

    // Free the allocated memory
    free(array);  // Free the memory allocated to 'array' to avoid memory leaks

    return 0;  // Return 0 to indicate successful program execution
}
