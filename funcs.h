#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct chars chr;

#define prep() char buf[strlen(buffer)] , *bufx; strcpy(buf , buffer); chr xd;


struct chars{ 
    char chars[100000];
};


chr get_type(char* buffer){
    prep();

    bufx = strtok(buf, " "); 
    strcpy(xd.chars , bufx);

    return xd;
}

chr get_name(char *buffer){
    prep();
    char* xdx;

    //type -> name
    bufx = strtok(buf , " "); bufx = strtok(NULL, " ");
    xdx = strtok(bufx, " ("); strcpy(xd.chars , xdx);
    
    return xd;
}


chr get_content(char *buffer){
    char copy[strlen(buffer)]; 
    strcpy(copy, buffer);

    char* p = strtok(copy , "{");
    p = strtok(NULL, "{");

    char* q = strtok(p , "}");
    chr content; strcpy(content.chars, q);

    return content;
}

chr get_paramsx(char *buffer){
    char copy[strlen(buffer)]; 
    strcpy(copy, buffer);


    char* p = strtok(copy , "(");
    p = strtok(NULL , "(");
    char arr[1000]; strcpy(arr , p);

    char *q = strtok(arr , "{");
    *(q + strlen(q) - 1) = '\0';
    
    chr content; strcpy(content.chars , q);
    return content;
}