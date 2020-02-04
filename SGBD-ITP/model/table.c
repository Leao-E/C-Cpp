#include "table.h"
#include "../util/erro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// <windows only>
#include <direct.h>
#include <errno.h>
// </windows only>


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
        fprintf(file, "row_number: 0 col_number: 0\n");
    }else{
        fclose(file);
        return FOPEN_ERRO;    
    }
    fclose(file);
    return 0;
}

int load_table(char* title, TABLE* table){
    char path[512];
    int line_size;
    //setting path
    strcpy(path, "data/");
    strcat(path, title);
    strcat(path, "/");
    strcat(path, title);
    strcat(path, ".table");
    //opening file 
    FILE *file = fopen(path, "r");
    if (file != NULL){
        fscanf(file, "%*s %d %*s %d\n", &table->row, &table->col);
        //allocates 128 characters per cel
        line_size = sizeof(char)*(table->col)*128;
        table->content = calloc(table->row,sizeof(char*));
        for(int i = 0; i < table->row; ++i){
            table->content[i] = malloc(line_size);
            fgets(table->content[i], line_size, file);
        }
        fclose(file);
    }else{
        fclose(file);
        return FOPEN_ERRO;
    }
    return 0;
}

int main(int argc, char const *argv[])
{   
    
    return 0;
}
