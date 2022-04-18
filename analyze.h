#pragma once

#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum typex{
    function, import, var , structx
};

int is_import(char* line){
    if(strchr(line , '#')) return 1;
    else return 0;
}

int is_function(char *line){
    if(strchr(line , '(') && strchr(line , '{')) return 1;
    else return 0;
}

int is_struct(char *line){
    if(strstr(line , "struct")) return 1;
    else return 0;
}

int is_namespace(char *line){
    if(strstr(line , "namespace")) return 1;
    else return 0;
}

void get_namespace(char *data, chr *x){
    char *p = strtok(data , "\n");
    int ns = 0; 
    chr nsx;
    strcpy(nsx.chars , "");

    while(p){
        if(ns == 1){
            if(strstr(p , "};")){
                chr tx; strcpy(tx.chars , p);
                char *q = strtok(tx.chars , "};");


                if(q) 
                {
                    strcat(nsx.chars , q);
                    strcat(nsx.chars , "\n");
                }

                strcpy(x -> chars , nsx.chars);
                ns = 0; 
            }else{
                strcat(nsx.chars , p);
                strcat(nsx.chars , "\n");
            }
        }
        
        if(is_namespace(p)) ns = 1;
            
        p = strtok(NULL , "\n");
    }
}



int delimit_functions(char data[], char functions[1000][100000]){
    char datax[strlen(data)]; strcpy(datax , data);
    char *p = strtok(datax, "\n");
    int f = 0 , i = 0;

    
    char temp[60000]; 

    while(p){
        //printf("%s \n" , p);
        
        if(is_function(p)){
            f = 1;
        }

        if(f == 1){
            strcat(temp , p); strcat(temp , "\n");

            if(strchr(p , '}')){
                strcpy(functions[i++] , temp);
                //printf("%s \n\n", temp);
                strcpy(temp , "");
                f = 0;
            }
        }
        
        p = strtok(NULL , "\n");
    }

    return i;
}