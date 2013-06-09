UnsTable
========

The unstable library is an easy way to print a table.


Building and Installing
=======================

The library is written in pure C, so the build process is very simple.

First, get the source:

    $ git clone https://github.com/patito/unstable.git

and,

* ./configure
* make
* make install

:-)

Examples
==========

Simple example to create a table.

```c

#include <stdio.h>
#include <string.h>

#include <unstable/unstable.h>

int main()
{
        UnsTable table;

        /* Headers Finished with NULL! */
        char *headers[] = {"Header1", "Header2", "Header3", NULL};

        /* Exemplo using method unstable_add_row() */
        char *row[] = {"Value41", NULL, "Value43", NULL};

        /* Must call init method - width, rows, column */
        unstable_init(&table, 78, 4, 3);
        unstable_set_title(&table, "Table Title");
        unstable_set_headers(&table, headers);

        unstable_add_value(&table, (void *)"Value11", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value12", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value13", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value21", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value22", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value23", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value31", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value32", UNSTABLE_STR);
        unstable_add_value(&table, (void *)"Value33", UNSTABLE_STR);

        unstable_add_row(&table, row);

        unstable_print(&table);

        /* Free the memory */
        unstable_finish(&table);

        return 0;
}

```
