#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "libft.h"
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
	char p;
	char *content;
	char *conversion;
} t_con;

# define BIGGER(a, b) a > b ? a : b

int ft_printf(const char *, ...);
char **ft_helper(va_list a, char *s);
char *ft_gen(va_list a, char *s, int *i);

// "%# +- 0.55d"
// typedef struct s_container
// {
//     int s;
//     int w;
//     int p;
//     int c;
// 	int h;
// 	int m;
// 	char t;
//     char pr;
//     char *content;
// } t_con;



#endif
