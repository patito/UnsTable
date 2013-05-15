#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "unstable.h"

static UnsTableError _malelf_table_add_int_value(UnsTable *obj, int value)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (obj->element < (obj->nrows * obj->ncolumns)) {
                sprintf(obj->content[obj->element], "%d", value);
                obj->element++;
        }
        
        return UNSTABLE_SUCCESS;
}

static UnsTableError _malelf_table_add_hex_value(UnsTable *obj, int value)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (obj->element < (obj->nrows * obj->ncolumns)) {
                sprintf(obj->content[obj->element], "0x%08x", value);
                obj->element++;
        }
        
        return UNSTABLE_SUCCESS;
}

static UnsTableError _malelf_table_add_str_value(UnsTable *obj, char *value)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (obj->element < (obj->nrows * obj->ncolumns)) {
                strncpy(obj->content[obj->element], value, strlen(value));
                obj->element++;
        }
        
        return UNSTABLE_SUCCESS;
}


UnsTableError unstable_add_row(UnsTable *obj, char **row)
{
        unsigned int i;

        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (NULL == row) { 
                return UNSTABLE_ERROR;
        }

        for (i = 0; i < obj->ncolumns; i++) {
                if (obj->element < (obj->nrows * obj->ncolumns)) {
                        strncpy(obj->content[obj->element], 
                                row[i],
                                strlen(row[i])); 
                        obj->element++;
                }
        }
        
        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_add_value(UnsTable *obj, void *value, UnsTableType type)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        switch(type) {
        case UNSTABLE_INT: _malelf_table_add_int_value(obj, (int)value);
                           break;
        case UNSTABLE_STR: _malelf_table_add_str_value(obj, (char*)value);
                           break;
        case UNSTABLE_HEX: _malelf_table_add_hex_value(obj, (int)value);
                           break;
        }        

        return UNSTABLE_SUCCESS;
}


UnsTableError unstable_finish(UnsTable *obj)
{
        unsigned int i;

        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        for (i = 0; i < obj->nrows * obj->ncolumns; i++) {
                if (NULL != obj->content[i]) {
                        free(obj->content[i]);
                }
        }

        free(obj->content);

        return UNSTABLE_SUCCESS;
}

static UnsTableError _unstable_alloc(UnsTable *obj)
{
        unsigned int i;

        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        obj->content = (char**)malloc((obj->nrows * obj->ncolumns) * sizeof(char *));
        if (NULL == obj->content) {
                fprintf(stderr, "out of memory\n");
                return UNSTABLE_ERROR;
        }

        for (i = 0; i < obj->nrows * obj->ncolumns; i++) {
                obj->content[i] = (char*)malloc(50*sizeof(char));
                if (obj->content[i] == NULL) {
                        fprintf(stderr, "out of memory\n");
		        return UNSTABLE_ERROR;
                }
        }
        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_init(UnsTable *obj,
                            unsigned int width,
                            unsigned int nrows,
                            unsigned int ncolumns)
{
        if (NULL == obj) {
                fprintf(stdout, "[INIT] UnsTable object is NULL!\n");
                return UNSTABLE_ERROR;
        }

        if ((0 == width) || (80 < width)) {
                fprintf(stdout, "[INIT] Invalid WIDTH value!\n");
                return UNSTABLE_ERROR;
        }

        if (0 == nrows) {
                fprintf(stdout, "[INIT] Invalid Number of ROWS!\n");
                return UNSTABLE_ERROR;
        }

        if (0 == ncolumns) {
                fprintf(stdout, "[INIT] Invalid Number of COLUMNS!\n");
                return UNSTABLE_ERROR;
        }

        if (0 != (width % ncolumns)) {
                fprintf(stdout, "[INIT] WIDTH mod COLUMNS MUST be 0!\n");
                return UNSTABLE_ERROR;
        }

        obj->width = width;
        obj->nrows = nrows;
        obj->ncolumns = ncolumns;
        obj->line.flag = false;
        obj->line.end = PLUS;
        obj->line.begin = PLUS;
        obj->line.middle = LESS;
        obj->line.partition = PLUS;
        obj->title = NULL;
        obj->headers = NULL;
        obj->content = NULL;
        obj->element = 0;
        obj->pos = 0;

        _unstable_alloc(obj);

        return UNSTABLE_SUCCESS;
}



UnsTableError unstable_set_title(UnsTable *obj, char *title)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (NULL == title) {
                return UNSTABLE_ERROR;
        }

        obj->title = title;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_headers(UnsTable *obj, char **headers)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (NULL == headers) {
                return UNSTABLE_ERROR;
        }

        obj->headers = headers;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_content(UnsTable *obj, char **content)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (NULL == content) {
                return UNSTABLE_ERROR;
        }

        obj->content = content;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_line_flag(UnsTable *obj, bool flag)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        obj->line.flag = flag;

        return UNSTABLE_SUCCESS;
}


UnsTableError unstable_set_width(UnsTable *obj, unsigned int width)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        obj->width = width;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_nrows(UnsTable *obj, unsigned int nrows)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        obj->nrows = nrows;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_ncolumns(UnsTable *obj, unsigned int ncolumns)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        obj->ncolumns = ncolumns;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_line_begin(UnsTable *obj, char begin)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        obj->line.begin = begin;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_line_middle(UnsTable *obj, char middle)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        obj->line.middle = middle;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_line_end(UnsTable *obj, char end)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        obj->line.end = end;

        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_set_line_partition(UnsTable *obj, char partition)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        obj->line.partition = partition;

        return UNSTABLE_SUCCESS;
}


static UnsTableError _unstable_get_column_length(UnsTable *obj,
                                                 unsigned int *clength)
{
        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }
        *clength = obj->width/obj->ncolumns;

        return UNSTABLE_SUCCESS;
}

static void _unstable_print_char(char character)
{
        fprintf(stdout, "%c", character);
}

static void _unstable_print_str(char *str)
{
        fprintf(stdout, "%s", str);
}

static void _unstable_new_line()
{
        fprintf(stdout, "\n");
}

static UnsTableError _unstable_print_line(UnsTable *obj)
{
        unsigned int i;
        unsigned int col_length;
        unsigned int aux;

         _unstable_get_column_length(obj, &col_length);
        aux = col_length;

        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        _unstable_print_char(obj->line.begin);
        for (i = 1; i < obj->width; i++) {
                if ((aux == i) && (true == obj->line.flag)) {
                        _unstable_print_char(obj->line.partition);
                        aux = aux + col_length;
                } else {
                        _unstable_print_char(obj->line.middle);
                }
        }
        _unstable_print_char(obj->line.end);
        _unstable_new_line();

        return UNSTABLE_SUCCESS;
}

static int _unstable_get_column_middle(unsigned int colx,
                                                 unsigned int coly,
                                                 char *str)
{
        if (NULL == str || 0 == strlen(str)) {
                return -1;
        }
        return ((colx + coly)/2) - (strlen(str)/2);
}


static UnsTableError _unstable_print_title(UnsTable *obj)
{
        unsigned int i;
        unsigned int middle;

        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (NULL == obj->title) {
                return UNSTABLE_ERROR;
        }

        middle = _unstable_get_column_middle(0, obj->width, obj->title);
        _unstable_print_line(obj);
        _unstable_print_char(PIPE);
        for (i = 1; i < obj->width; i++) {
                _unstable_print_char(EMPTY);
                if (middle == i) {
                        fprintf(stdout, obj->title);
                        i = i + strlen(obj->title);
                }
        }
        _unstable_print_char(PIPE);
        _unstable_new_line();
        unstable_set_line_flag(obj, true);
        _unstable_print_line(obj);

        return UNSTABLE_SUCCESS;
}

static UnsTableError _unstable_print_headers(UnsTable *obj)
{
        unsigned int i;
        unsigned int col_length;
        unsigned int col_middle;
        unsigned int pos = 0;
        unsigned int col_begin = 0;
        unsigned int col_end = 0;
        static unsigned int count = 2;
        unsigned int partitions = 0;

        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        if (NULL == obj->title) {
                _unstable_print_line(obj);
        }

        _unstable_get_column_length(obj, &col_length);
        col_end = col_length;
        partitions = col_length;
        col_middle = _unstable_get_column_middle(col_begin,
                                                 col_end,
                                                 obj->headers[pos]);

        _unstable_print_char(PIPE);
        for (i = 1; i < obj->width; i++) {
                if (i == col_middle) {
                        _unstable_print_str(obj->headers[pos]);
                        i = i + strlen(obj->headers[pos]) - 1;
                        col_end = col_length * count;
                        col_begin = col_begin + col_length;
                        pos++;
                        col_middle = _unstable_get_column_middle(col_end,
                                                                 col_begin,
                                                                 obj->headers[pos]);
                        count++;
                        continue;
                }
                if (i == partitions) {
                        _unstable_print_char(PIPE);
                        partitions = partitions + col_length;
                        continue;
                }
                _unstable_print_char(EMPTY);
        }
        _unstable_print_char(PIPE);
        _unstable_new_line();
        _unstable_print_line(obj);
        count = 2;

        return UNSTABLE_SUCCESS;
}


static UnsTableError _unstable_print_content(UnsTable *obj)
{
        unsigned int i;
        unsigned int col_length;
        unsigned int col_middle;
        static unsigned int pos = 0;
        unsigned int col_begin = 0;
        unsigned int col_end = 0;
        static unsigned int count = 2;
        unsigned int partitions = 0;


        if (NULL == obj) {
                return UNSTABLE_ERROR;
        }

        _unstable_get_column_length(obj, &col_length);
        col_end = col_length;
        partitions = col_length;
        col_middle = _unstable_get_column_middle(col_begin,
                                                 col_end,
                                                 obj->content[obj->pos]);
        _unstable_print_char(PIPE);
        for (i = 1; i < obj->width; i++) {
                if (i == col_middle) {
                        _unstable_print_str(obj->content[obj->pos]);
                        i = i + strlen(obj->content[obj->pos]) - 1;
                        col_end = col_length * count;
                        col_begin = col_begin + col_length;
                        pos++;
                        if (obj->pos < obj->nrows*obj->ncolumns) {
                                col_middle = _unstable_get_column_middle(col_end,
                                                                         col_begin,
                                                                         obj->content[obj->pos]);
                        }
                        count++;
                        continue;
                }
                if (i == partitions) {
                        _unstable_print_char(PIPE);
                        partitions = partitions + col_length;
                        continue;
                }
                _unstable_print_char(EMPTY);
        }
        _unstable_print_char(PIPE);
        _unstable_new_line();
        count = 2;
        col_begin = 0;
        col_end = partitions = col_length;
        if (obj->pos < obj->nrows*obj->ncolumns) {
                col_middle = _unstable_get_column_middle(col_end,
                                                         col_begin,
                                                         obj->content[obj->pos]);
        }

        count = 2;
        return UNSTABLE_SUCCESS;
}

UnsTableError unstable_print(UnsTable *obj)
{
        unsigned int j;

        if (NULL != obj->title) {
                _unstable_print_title(obj);
        }

        if (NULL != obj->headers) {
                _unstable_print_headers(obj);
        } else {
                if (NULL == obj->title) {
                        _unstable_print_line(obj);
                }
        }

        for (j = 0; j < obj->nrows; j++) {
                _unstable_print_content(obj);
        }

        _unstable_print_line(obj);

        return UNSTABLE_SUCCESS;
}
