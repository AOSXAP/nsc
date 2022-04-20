#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

char* build_namespace(char functions[1000][100000], int fx){
    char *chrx = (char *)malloc(100000 * sizeof(char));
    strcpy(chrx , "struct namespace{\n");

    for(int i = 0; i < fx; i++){
        chr namex   = get_name(functions[i])   , 
            typex   = get_type(functions[i])   ,
            content = get_content(functions[i]), 
            params  = get_paramsx(functions[i]);

        strcat(chrx, typex.chars); strcat(chrx , " ");

        strcat(chrx, "(*");
        strcat(chrx, namex.chars);
        strcat(chrx, ")"); 

        strcat(chrx, "("); 
        strcat(chrx, params.chars); 
        strcat(chrx, ")"); 

        strcat(chrx , ";\n");
    }
    strcat(chrx , "}xd; \n");
    return chrx;
}


char* build_premain(char functions[1000][100000], int fx){
    char *premain = (char *)malloc(100000 * sizeof(char));
    strcpy(premain , "void __attribute__ ((constructor)) premain()\n{\n");

    for(int i = 0; i < fx; i++){
        chr namex = get_name(functions[i]);
        char xd[1000];
        sprintf(xd, "xd.%s = &%s;", namex.chars, namex.chars);
        strcat(premain , xd); strcat(premain, "\n");
    }
    strcat(premain, "}\n");
    return premain;
}

char *build_path(char *path){
    char *pathx = (char*) malloc(1000 * sizeof(char)), chrx = '/';

    char* ptr = strrchr(path , chrx);

    if(ptr){
        int pos = ptr - path;
        strcpy(pathx , path); strcpy(pathx + pos + 1 , "\0");
    }else strcpy(pathx , "/");

    if(strcmp(pathx , ".") == 0) strcpy(pathx, "/");

    return pathx;
}