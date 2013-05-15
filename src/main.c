#include <stdio.h>
#include <string.h>

#include "unstable.h"

int main()
{
        UnsTable table;
        
        char *headers[] = {"N", "Description", "Description", "Description", "Description", NULL};
        unstable_init(&table, 80, 10, 5);
        unstable_set_title(&table, "Table Title");
        unstable_set_headers(&table, headers);

        unstable_add_value(&table, (void *)"1", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Description2", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value3", UNSTABLE_STR);

        unstable_print(&table);

        unstable_finish(&table);

        return 0;
}
