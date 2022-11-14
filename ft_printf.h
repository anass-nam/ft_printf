#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

typedef struct s_container
{
    int s;
    int w;
    int p;
    int c;
    char pr;
    char *content;
} t_con;


# define BIGGER(a, b) a > b ? a : b

#endif
