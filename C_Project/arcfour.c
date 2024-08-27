#include "arcfour.h"

ArcFour *rc4init (int8* key , int16 size){
    int16 x ;
    int8 temp1,temp2;
    ArcFour* p;

    if(!(p= malloc(sizeof(struct s_arcfour)))){
        assert_perror(errno);
    }
    for(x = 0;x<256;x++)
        p->s[x] = 0;
    p->i = p->j= p->k = 0;

    temp1=temp2=0;

    for(p->i =0 ; p->i < 256 ; p->i ++)
        p->s[p->i] = p->i;

    for(p->i = 0;p->i <256;p->i++){

        temp1 = p->i %size;
        temp2 = p->j + p->s[p->i] + key[temp1];
        p->j = temp2%256;
        temp1 = p->s[p->i];
        temp2 = p->s[p->j];
        p->s[p->i] = temp2;
        p->s[p->j] = temp1;

    }

    p->i =p->j = 0;

    return p;

}