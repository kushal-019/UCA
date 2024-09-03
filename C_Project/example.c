#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arcfour.h"

#define F fflush(stdout);

void printbin(int8 *input, const int16 size) {
    int16 i;
    int8 *p;

    assert(size > 0);

    for(i = size, p = input; i; i--, p++) {
        if (!(i % 2))
            printf(" ");
        printf("%.02x", *p);
    }

    printf("\n");
}

void readFile(const char *filename, char **buffer, int16 *size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = malloc(*size);
    if (!*buffer) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    fread(*buffer, 1, *size, file);
    fclose(file);
}

int main() {
    char *key;
    char *filename;
    char *fileContent;
    int8 *encrypted, *decrypted;
    ArcFour *rc4;
    int16  sKey, sText;
    int choice;
    
    // Key initialization
    key = "ThisIsMySecreatKey";
    sKey = strlen(key);

    // File input
    printf("Enter the filename to read: ");
    filename = malloc(256);
    if (fgets(filename, 256, stdin) != NULL) {
        filename[strcspn(filename, "\n")] = 0;  // Remove newline character if present
    }

    readFile(filename, &fileContent, &sText);
    //free(filename);

    printf("Choose operation: \n1. Encrypt \n2. Decrypt \nEnter choice: ");
    scanf("%d", &choice);
    getchar();  // Consume newline left in buffer

    if (choice == 1) {
        printf("Initializing encryption"); F;
        rc4 = rc4init((int8*)key, sKey);
        printf("done\n");

        printf("Original content: \n%s\n", fileContent);
        printf("Encrypted content: \n");
        encrypted = rc4Encrypt(rc4, (int8*)fileContent, sText);
        printbin(encrypted, sText);

        rc4uninit(rc4);

        printf("Saving encrypted content to file...\n");
        FILE *encFile = fopen(filename, "wb");
        fwrite(encrypted, 1, sText, encFile);
        fclose(encFile);
        free(encrypted);

    } else if (choice == 2) {
        printf("Initializing decryption"); F;
        rc4 = rc4init((int8*)key, sKey);
        printf("done\n");

        // Assuming encrypted file is available
        printf("Reading encrypted content from file...\n");
        FILE *encFile = fopen(filename, "rb");
        if (!encFile) {
            perror("Failed to open encrypted file");
            exit(EXIT_FAILURE);
        }
        
        fseek(encFile, 0, SEEK_END);
        sText = ftell(encFile);
        fseek(encFile, 0, SEEK_SET);

        encrypted = malloc(sText);
        if (!encrypted) {
            perror("Failed to allocate memory for encrypted data");
            exit(EXIT_FAILURE);
        }

        fread(encrypted, 1, sText, encFile);
        fclose(encFile);

        decrypted = rc4Decrypt(rc4, encrypted, sText);
        printf("Decrypted content: \n%s\n", decrypted);
        printbin(encrypted, sText);

        free(encrypted);
        free(decrypted);

        rc4uninit(rc4);
    } else {
        printf("Invalid choice.\n");
    }

    free(fileContent);
    return 0;
}

