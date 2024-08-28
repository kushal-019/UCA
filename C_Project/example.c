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
    int8 *encrypted , *decrypted ;
    
    ArcFour *rc4;
    int16 sKey , sText;
    key = "ThisIsMySecreatKey";
    // change key while actual submition and size = 8 bits - 2048 bits

    sKey = strlen(key);
    from  = "shall  i compare the it to a summer day.";
    sText = strlen(from);

    printf("initializing encryption");F;
    rc4 = rc4init((int8*)key , sKey);
    printf("done \n");

    printf("'%s' \n -> ",from);
    encrypted = rc4Encrypt(rc4 ,(int8*)from ,sText) ;
    printbin(encrypted , sText);
    rc4uninit(rc4);


    printf("Initializing encryption..");F;
    rc4 = rc4init((int8*)key,sKey);
    printf("done\n");

    decrypted = rc4Decrypt(rc4,encrypted , sText);
    printf("    ->'%s'\n" , decrypted);
    printbin(encrypted , sText);
    rc4uninit(rc4);

    return 0;


}