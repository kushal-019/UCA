#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define rc4Decrypt(x , y) rc4Encrypt(x, y);

struct s_arcfour{
    int x;
};
typedef struct s_arcfour ArcFour; 
typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

ArcFour *rc4inti(int8 * , int16 );
int8 rc4byte(void);
int8 *rc4Encrypt(int8* , int16);
