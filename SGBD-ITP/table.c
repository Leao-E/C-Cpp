#include "table.h"
#include <stdio.h>
#include <string.h>
// <windows only>
#include <direct.h>
#include <errno.h>
// </windows only>
#define FILE_EXIST 1
#define DIR_EXIST 2
#define MKDIR_ERRO 3
#define FOPEN_ERRO 4

int create_table (char* title){
    char path[512];
    int mkdir_result = _mkdir("data");
    if(mkdir_result == 0 || errno == EEXIST){
        strcpy(path, "data/");
        strcat(path, title);
        mkdir_result = _mkdir(path);
        if(mkdir_result != 0){
            return DIR_EXIST;
        }
    }else{
        return MKDIR_ERRO;
    }
    strcat(path, "/");
    strcat(path, title);
    strcat(path, ".table");
    FILE *file = fopen(path, "w");
    if(file != NULL){
        fprintf(file, "<specs>\nrow_number=0\ncol_number=0\n</specs>\n<cols>\n</cols>\n<content>\n</content>");
    }
    fclose(file);
    return 0;
}

int main(int argc, char const *argv[])
{
    create_table("teste");
    return 0;
}
