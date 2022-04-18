#include "funcs.h"
#include "fs.h"
#include "analyze.h"

typedef struct chars chr;

char functions[1000][100000];

int main()
{
    char *x = openfilex("./ex/main.c") , copy[strlen(x)];
    strcpy(copy , x);
    char new_buf[strlen(x)];

    chr imp, funcs, data;
    get_namespace(x, &data);

    int fx = delimit_functions(data.chars, functions);

    char *p = strtok(copy , "\n");
    int is_ns = 0;

    while(p){
        if(is_namespace(p)){
            is_ns = 1;
            //strcat(new_buf, functions);
            //strcat(new_buf, "\n");
            for(int i = 0; i < fx; i++){
                strcat(new_buf , functions[i]);
                strcat(new_buf, "\n");
            }

            char nw[10000];
            strcpy(nw , "struct namespace{\n");

            for(int i = 0; i < fx; i++){
                chr namex   = get_name(functions[i])   , 
                    typex   = get_type(functions[i])   ,
                    content = get_content(functions[i]), 
                    params  = get_paramsx(functions[i]);

                strcat(nw, typex.chars); strcat(nw , " ");

                strcat(nw, "(*");strcat(nw, namex.chars);strcat(nw, ")"); 
                
                strcat(nw, "("); strcat(nw, params.chars); strcat(nw, ")"); 

                //strcat()
            }

        }

        if(is_ns){
            if(strstr(p , "};")){
                is_ns = 0;
            }
        }else{
            
            
            strcat(new_buf , p);
            //strcat(new_buf , "\n");
        }

        strcat(new_buf , "\n");
        p = strtok(NULL , "\n");
    }

    printf("%s" , new_buf);
}
