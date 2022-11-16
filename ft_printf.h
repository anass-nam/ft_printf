#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>


typedef struct s_container
{
    int hashtag;
    int minus;
    int zero;
    int prefix;
    int width;
    int precision;
	int clen;
	int dot;
	char p;
	char *content;
	char *conversion;
} t_con;

# define BIGGER(a, b) a > b ? a : b
# define SMALLER(a, b) a < b ? a : b

void ft_converter(va_list a, t_con *f, char c);
int ft_printf(const char *, ...);



#endif
