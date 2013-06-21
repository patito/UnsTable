UnsTable
========

The unstable library is an easy way to print a table.

Building and Installing
=======================

The library is written in pure C, so the build process is very simple.

First, get the source:

    $ git clone https://github.com/patito/UnsTable.git

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
        char *row[] = {"Value41", "Value42", "Value43", NULL};

        /* Must call init method - width, rows, column */
        unstable_init(&table, 78, 4, 3);
        unstable_set_title(&table, "Table Title");
        unstable_set_headers(&table, headers);

        /* String Values */ 
        unstable_add_str_value(&table, "Value11");
        unstable_add_str_value(&table, "Value12");
        unstable_add_str_value(&table, "Value13");

        /* HEX Values */ 
        unstable_add_hex_value(&table, 0x21);
        unstable_add_hex_value(&table, 0x22);
        unstable_add_hex_value(&table, 0x23);

        /* INT Values */ 
        unstable_add_int_value(&table, 31);
        unstable_add_int_value(&table, 32);
        unstable_add_int_value(&table, 33);

        unstable_add_row(&table, row);

        unstable_print(&table);

        /* Free the memory */
        unstable_finish(&table);

        return 0;
}

```

+-----------------------------------------------------------------------------+
|                                  Table Title                                |
+-------------------------+-------------------------+-------------------------+
|         Header1         |         Header2         |         Header3         |
+-------------------------+-------------------------+-------------------------+
|         Value11         |         Value12         |         Value13         |
|       0x00000021        |       0x00000022        |       0x00000023        |
|           31            |           32            |           33            |
|         Value41         |         Value42         |         Value43         |
+-------------------------+-------------------------+-------------------------+

