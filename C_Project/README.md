
---

# RC4 Encryption/Decryption Program

## Overview

This project implements the RC4 stream cipher encryption and decryption algorithm in C. The program reads plaintext from a file, encrypts it using the RC4 algorithm, and then writes the encrypted data (in hexadecimal format) to a file. It also supports decrypting the encrypted file back to the original content.

The key is hardcoded in this version but can be modified to accept user input.

## Features

- Encrypts a file using the RC4 encryption algorithm.
- Decrypts an encrypted file back to its original content.
- Converts binary data to hexadecimal for easy file saving.
- Allows users to select whether to encrypt or decrypt a file via a menu.

## Files

- `main.c`: The main program file containing encryption and decryption logic.
- `arcfour.c`: Contains the RC4 implementation.
- `arcfour.h`: Header file for the RC4 implementation.
- `Makefile`:  A simple makefile to compile the program.
  
## How It Works

1. The program prompts the user to input the filename of the file they want to read.
2. The user then selects whether to encrypt or decrypt the file:
   - **Encrypt**: Reads the original content of the file, encrypts it using RC4, converts the encrypted data to hexadecimal, and writes it to the output file.
   - **Decrypt**: Reads the encrypted (hexadecimal) content of a file, converts it back to binary, decrypts it using RC4, and writes the decrypted content to a file.

## Usage Instructions

### Compilation

Make sure you have a C compiler installed, such as GCC. To compile the program, you can use the following command:

```bash
make
```

### Running the Program

Once compiled, you can run the program:

```bash
./main
```

### Example Workflow

1. The program will prompt you to enter the filename to read.
2. You will be asked whether you want to **encrypt** or **decrypt** the file:
   - To **encrypt** a file, select `1`.
   - To **decrypt** a file, select `2`.
3. You will be prompted to enter the output filename where the result (encrypted/decrypted content) will be saved.

### Notes

- The encryption key is currently hardcoded as `"ThisIsMySecreatKey"`. You can modify the key by changing the value in the `main` function. For production use, consider allowing the user to input the key.
- The program reads and writes hexadecimal-encoded strings for the encrypted content to make it easier to store in text files.

## Program Structure

### RC4 Functions

- `rc4init`: Initializes the RC4 state with the provided key.
- `rc4Encrypt`: Encrypts (or decrypts) the input data using RC4. This function performs both encryption and decryption since RC4 is a symmetric cipher.
- `rc4byte`: Generates a pseudo-random byte from the RC4 state.

### Utility Functions

- `binToHex`: Converts binary data to a hexadecimal string.
- `hexToBin`: Converts a hexadecimal string back to binary data.
- `readFile`: Reads the content of a file into a buffer.
- `writeFile`: Writes the content from a buffer to a file.

## License

This project is free to use and modify under the MIT License.

## Disclaimer

This is a basic RC4 implementation meant for educational purposes.

---
