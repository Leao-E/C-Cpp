#ifndef _TABLE_H_
#define _TABLE_H_

typedef struct table
{
    int col;
    int row;
    char* content;
}table;

int create_table (char* title);
void delete_table (char* title);
void load_table(char* title);

#endif