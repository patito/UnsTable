#include <stdio.h>
#include <string.h>

#include "unstable.h"

int main()
{
        UnsTable table;
        char *headers[] = {"Member", "Description", "Value", NULL};

        char *content[] = {"Member1", "Member2", "Member3",
                           "Member4", "Member5", "Member6",
                           "Member7", "Member8", "Member9",
                           NULL};

        unstable_init(&table, 81, 3, 3);
        unstable_set_title(&table, "Table Title");
        unstable_set_headers(&table, headers);
        unstable_set_content(&table, content);

        unstable_print(&table);

        return 0;
}
