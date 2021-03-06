#include "funcs.h"
#include "fs.h"
#include "analyze.h"
#include "build.h"
typedef struct chars chr;

char functions[1000][100000];

char *save_location(char *arg){
    char *loc = (char *) malloc(sizeof(char) * (strlen(arg) + 20));
    loc = build_path(arg);

    strcat(loc , "build.c");

    return loc;
}

int main(int argc, char** argv)
{   
    char *x = openfilex(argv[1]) , copy[strlen(x)];
    strcpy(copy , x);
    char new_buf[strlen(x)];

    chr imp, funcs, data;
    get_namespace(x, &data);

    int fx = delimit_functions(data.chars, functions);

    char    *nw = build_namespace(functions , fx),
            *premain = build_premain(functions , fx);

    char *p = strtok(copy , "\n");
    int is_ns = 0;

    while(p){
        if(is_namespace(p)){
            is_ns = 1;

            for(int i = 0; i < fx; i++){
                strcat(new_buf , functions[i]);
                strcat(new_buf, "\n");
            }

            strcat(new_buf, nw);
            strcat(new_buf, "\n");
            strcat(new_buf, premain);
            strcat(new_buf , "\n");
        }

        if(is_ns){
            if(strstr(p , "};")){
                is_ns = 0;
            }
        }else{
            strcat(new_buf , p);strcat(new_buf,"\n");
        }

        p = strtok(NULL, "\n");
    }
    char *save = "./";

    if(argv[1]) 
       save = save_location(argv[1]);

    strcpy(new_buf , new_buf + 1);

    write_to_file(save , new_buf);

}
