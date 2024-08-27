#include "arcfour.h"

#define F fflush(stdout);

int main(void );

void printbin(int8* input  , const int16 size){
    int16 i;
    int8 *p;

    assert(size > 0);

    for(i=size , p = input;i ; i-- , p++){
        if(!(i)%2)
            printf(" ");
        printf("%.02x" , *p);
    }

    printf("\n");
    return;
}

int main(){
    char * key , * from ;
    // *encrypted , * decrypted ;
    
    ArcFour *rc4;
    int16 sKey , sText;
    sKey =sText =0;
    key = "tomatoes";
    // change key while actual submition and size = 8 bits - 2048 bits

    sKey = strlen(key);
    from  = "shall  i compare the it to a summer day.";
    sText = strlen(from);

    printf("initializing encryption");F;
    rc4 = rc4init((int8*)key , sKey);
    printf("done \n");

    printf("'%s' \n -> ",from);
    // encrypted = rc4Encrypt(from ,sText) ;
    printbin((int8 *)rc4->s , sKey);
    return 0;


}