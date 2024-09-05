


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>  // For uint8_t, uint16_t
#include "arcfour.h"

#define F fflush(stdout);

// Function to convert binary data to hexadecimal string
void binToHex(const uint8_t *bin, uint16_t binSize, char **hex) {
    *hex = malloc(binSize * 2 + 1);  // Each byte is two hex chars + null terminator
    if (!*hex) {
        perror("Failed to allocate memory for hex string");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < binSize; i++) {
        sprintf((*hex) + (i * 2), "%02x", bin[i]);
    }
    (*hex)[binSize * 2] = '\0';  // Null-terminate the string
}

// Function to convert hexadecimal string back to binary
void hexToBin(const char *hex, uint8_t **bin, uint16_t *binSize) {
    *binSize = strlen(hex) / 2;
    *bin = malloc(*binSize);
    if (!*bin) {
        perror("Failed to allocate memory for binary data");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *binSize; i++) {
        sscanf(hex + 2 * i, "%02x", (unsigned int *)&(*bin)[i]);
    }
}

void readFile(const char *filename, char **buffer, uint16_t *size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = malloc(*size + 1);
    if (!*buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*buffer, 1, *size, file);
    (*buffer)[*size] = '\0';  // Null-terminate the buffer for text processing
    fclose(file);
}

void writeFile(const char *filename, const char *buffer, uint16_t size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, 1, size, file);
    fclose(file);
}

int main() {
    char *key;
    char *inputFilename, *outputFilename;
    char *fileContent;
    uint8_t *encrypted, *decrypted;
    char *hexContent;
    ArcFour *rc4;
    uint16_t sKey, sText;
    int choice;

    // Key initialization
    key = "ThisIsMySecreatKey";  // Ideally, this should be user input for better security.
    sKey = strlen(key);

    // File input
    inputFilename = malloc(256);
    outputFilename = malloc(256);

    printf("Choose operation: \n1. Encrypt \n2. Decrypt \nEnter choice: ");
    scanf("%d", &choice);
    getchar();  // Consume newline left in buffer

    // Get input file name
    printf("Enter the filename to read (input): ");
    if (fgets(inputFilename, 256, stdin) != NULL) {
        inputFilename[strcspn(inputFilename, "\n")] = 0;  // Remove newline character if present
    }

    // Get output file name
    printf("Enter the filename to save the result (output): ");
    if (fgets(outputFilename, 256, stdin) != NULL) {
        outputFilename[strcspn(outputFilename, "\n")] = 0;  // Remove newline character if present
    }

    // Read the input file
    readFile(inputFilename, &fileContent, &sText);

    if (choice == 1) {
        // Encryption
        printf("Initializing encryption"); F;
        rc4 = rc4init((uint8_t*)key, sKey);
        printf("done\n");

        printf("Original content: \n%s\n", fileContent);
        encrypted = rc4Encrypt(rc4, (uint8_t*)fileContent, sText);

        // Convert the encrypted binary data to hexadecimal
        binToHex(encrypted, sText, &hexContent);

        printf("Encrypted content (hexadecimal): \n%s\n", hexContent);

        // Save the hexadecimal representation to the output file
        writeFile(outputFilename, hexContent, strlen(hexContent));

        free(encrypted);
        free(hexContent);
        rc4uninit(rc4);

    } else if (choice == 2) {
        // Decryption
        printf("Initializing decryption"); F;
        rc4 = rc4init((uint8_t*)key, sKey);
        printf("done\n");

        printf("Reading encrypted content from file...\n");

        // Read the hexadecimal content from the file
        readFile(inputFilename, &fileContent, &sText);

        // Convert the hexadecimal content back to binary
        hexToBin(fileContent, &encrypted, &sText);

        // Decrypt the binary data
        decrypted = rc4Encrypt(rc4, encrypted, sText);  // Decrypting with the same rc4Encrypt
        printf("Decrypted content: \n%s\n", decrypted);

        // Save the decrypted content to the output file
        writeFile(outputFilename, (char*)decrypted, sText);

        free(encrypted);
        free(decrypted);
        rc4uninit(rc4);
    } else {
        printf("Invalid choice.\n");
    }

    free(fileContent);
    free(inputFilename);
    free(outputFilename);

    return 0;
}

