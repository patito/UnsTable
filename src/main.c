#include <stdio.h>
#include <string.h>

#include "unstable.h"

int main()
{
        UnsTable table;
        
        char *headers[] = {"Member", "Description", "Value", NULL};
        unstable_init(&table, 78, 3, 3);
        unstable_set_title(&table, "Table Title");
        unstable_set_headers(&table, headers);

        char *row[] = {"1", "2", "3"};
        unstable_add_row(&table, row);
        unstable_add_value(&table, (void *)1, UNSTABLE_INT);
        unstable_add_value(&table, (void *)"b3n4tt0", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"g4zz1", UNSTABLE_STR);
        unstable_add_value(&table, (void *)0x1337, UNSTABLE_HEX);
        unstable_add_row(&table, row);
        
        unstable_print(&table);

        unstable_finish(&table);

        return 0;
}
