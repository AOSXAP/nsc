#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x = 200;

int z = 2000;
int f = 15000;

namespace xd{
    void ab(int a , int b){
        printf("%s" , "salut");
    }

    int fx(){
        return 93;
    }
};

int aaa = 400;

int main(){
    xd.ab();
}