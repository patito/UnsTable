#include <stdio.h>
#include <string.h>

#include <unstable/unstable.h>

int main()
{
        UnsTable table;

        /* Headers Finished with NULL! */        
        char *headers[] = {"Header1", "Header2", "Header3", NULL};

        /* Must call init method - width, rows, column */
        unstable_init(&table, 78, 3, 3);
        unstable_set_title(&table, "Table Title");
        unstable_set_headers(&table, headers);

        unstable_add_value(&table, (void *)"1", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Description2", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value3", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value3", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value3", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value3", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value3", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value3", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value3", UNSTABLE_STR);

        unstable_print(&table);

        /* Free the memory */
        unstable_finish(&table);

        return 0;
}
