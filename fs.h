#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

char* openfilex(char* path){
    //open file
    int c , i = 0; FILE *file;
    file = fopen(path, "r");

    int sizex = 500000;

    //alocating buffer
    char *buffer = (char *) malloc(sizex * sizeof(char));


    if (file) {
        while ((c = getc(file)) != EOF){
            //realocating
            if(i > sizex - 10){
                sizex *= 2; 
                buffer = (char *) realloc(buffer , sizex);
            }

            buffer[i++] = c;
        }
        fclose(file);
    }
    return buffer;
}

char* write_to_file(char *path, char *buf){
    FILE* file = fopen(path , "w");
    fprintf(file, "%s", buf);

    fclose(file);
}