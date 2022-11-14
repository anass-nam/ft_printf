#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>


typedef struct s_container
{
    int s;
    int w;
    int p;
    int c;
	int h;
	int m;
	char t;
    char pr;
    char *content;
} t_con;


# define BIGGER(a, b) a > b ? a : b

#endif
