#ifndef _TABLE_H_
#define _TABLE_H_

typedef struct table
{
    int col;
    int row;
    char** content;
}TABLE;

int create_table (char* title);
void delete_table (char* title);
int load_table(char* title, TABLE* table);

#endif