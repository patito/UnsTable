#ifndef __UNSTABLE_H__
#define __UNSTABLE_H__

#include <stdbool.h>

#define PIPE  '|'
#define EMPTY ' '
#define PLUS  '+'
#define LESS  '-'

#define CONTENT_MAX_LEN 50

/* UnsTableLine
 *
 * +-------------------------------------------------+
 * |  begin (+)        (+) partition (+)    end (+)  |
 * |         +----------+-------------+----------+   |
 * |                      middle (-)                 |
 * +-------------------------------------------------+
 *
 */

typedef enum {
        UNSTABLE_SUCCESS,
        UNSTABLE_ERROR
} UnsTableError;

typedef struct {
        char begin;
        char middle;
        char end;
        char partition;
        bool flag;
} UnsTableLine;

typedef struct {
        unsigned int width;
        unsigned int nrows;
        unsigned int ncolumns;
        unsigned int element;
        unsigned int pos;
        char *title;
        char **content;
        char **headers;
        int *column_array;
        int *column_position;
        UnsTableLine line;
} UnsTable;

UnsTableError unstable_init(UnsTable *obj,
                            unsigned int width,
                            unsigned int nrows,
                            unsigned int ncolumns);

UnsTableError unstable_finish(UnsTable *obj);

UnsTableError unstable_set_title(UnsTable *obj,
                                 char *title);

UnsTableError unstable_set_headers(UnsTable *obj,
                                 char **headers);

UnsTableError unstable_set_content(UnsTable *obj,
                                   char **content);

UnsTableError unstable_print(UnsTable *obj);

UnsTableError unstable_add_int_value(UnsTable *obj, int value);

UnsTableError unstable_add_hex_value(UnsTable *obj, int value);

UnsTableError unstable_add_str_value(UnsTable *obj, const char *value);

UnsTableError unstable_add_row(UnsTable *obj, char **row);

UnsTableError unstable_set_width(UnsTable *obj, unsigned int width);

UnsTableError unstable_set_nrows(UnsTable *obj, unsigned int nrows);

UnsTableError unstable_set_ncolumns(UnsTable *obj, unsigned int ncolumns);

UnsTableError unstable_set_line_begin(UnsTable *obj, char begin);

UnsTableError unstable_set_line_middle(UnsTable *obj, char middle);

UnsTableError unstable_set_line_end(UnsTable *obj, char end);

UnsTableError unstable_set_line_partition(UnsTable *obj, char partition);

UnsTableError unstable_set_line_flag(UnsTable *obj, bool flag);


#endif /* __UNSTABLE_H__ */
