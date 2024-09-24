#include <stdio.h>
#include <stdlib.h>

// Function to convert a character to its binary representation and write it to a file
void charToBinary(unsigned char c, FILE *file) {
    for (int i = 7; i >= 0; i--) {
        // Write each bit of the character as '0' or '1'
        fprintf(file, "%d", (c >> i) & 1);
    }
}

// Function to convert 8 binary bits to a character
unsigned char binaryToChar(const char *binary) {
    unsigned char c = 0;
    for (int i = 0; i < 8; i++) {
        c = (c << 1) | (binary[i] - '0');  // Convert binary string to character
    }
    return c;
}

int main() {
    char input[100];
    char binaryBuffer[9];  // Buffer to hold 8 bits (plus a null terminator)

    // Step 1: Read from stringInput.txt and write binary to binaryOutput.bin
    FILE *inputFile = fopen("stringInput.txt", "r");
    if (!inputFile) {
        printf("Could not open input file\n");
        return 1;
    }

    FILE *binaryOutputFile = fopen("binaryOutput.bin", "wb");
    if (!binaryOutputFile) {
        printf("Could not open binary output file\n");
        fclose(inputFile);
        return 1;
    }

    // Read from input file and write binary representation to binaryOutput.bin
    while (fgets(input, sizeof(input), inputFile)) {
        for (int i = 0; input[i] != '\0'; i++) {
            charToBinary(input[i], binaryOutputFile);
        }
    }

    fclose(inputFile);
    fclose(binaryOutputFile);

    // Step 2: Read from binaryOutput.bin and convert binary back to text
    binaryOutputFile = fopen("binaryOutput.bin", "rb");
    if (!binaryOutputFile) {
        printf("Could not open binary output file for reading\n");
        return 1;
    }

    FILE *stringOutputFile = fopen("stringOutput.txt", "w");
    if (!stringOutputFile) {
        printf("Could not open string output file\n");
        fclose(binaryOutputFile);
        return 1;
    }

    // Read binary data 8 bits at a time and convert back to characters
    while (fread(binaryBuffer, sizeof(char), 8, binaryOutputFile) == 8) {
        binaryBuffer[8] = '\0';  // Null-terminate the 8-bit binary string
        unsigned char c = binaryToChar(binaryBuffer);  // Convert to a character
        fputc(c, stringOutputFile);  // Write the character to stringOutput.txt
    }

    fclose(binaryOutputFile);
    fclose(stringOutputFile);

    printf("Binary data successfully converted back to text.\n");
    return 0;
}

