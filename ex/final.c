#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x = 200;

int z = 2000;
int f = 15000;


    void ab(int a , int b){
        printf("%s" , "salut");
    }

    int fx(){
        return 93;
    }

struct namespace{
    void (*ab)();
    int (*fx)();
}xd;


void __attribute__ ((constructor)) premain()
{
    xd.ab = &xd_ab;
    xd.fx = &xd_fx;
}




int main(){
    printf("%s", "hei");
}