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

int ft_printf(const char *, ...);
void ft_helper(va_list a, char *s);
char *ft_gen(va_list a, char *s, int *i);

#endif
