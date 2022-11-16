# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include "libft/libft.h"


// typedef struct s_container
// {
//     int hashtag;
//     int minus;
//     int zero;
//     int prefix;
//     int width;
//     int precision;
//     int clen;
//     char p;
//     char *content;
//     char *conversion;
// } t_con;

// # define BIGGER(a, b) a > b ? a : b

// static void ft_formatter(t_con *f, char c)
// {
//     int v;
//     int l;
//     int a;
//     int b;
    
//     f->clen = strlen(f->content);
//     v = BIGGER(f->width, (f->clen + f->prefix));
//     l = BIGGER(v, (f->prefix + f->precision));
//     a = BIGGER((f->precision - f->clen), (f->clen - f->clen));
//     b = 0;
//     if (!f->minus)
//         b = l - f->precision - f->prefix;
//     if (!f->minus && !f->precision)
//         b = l - f->precision - f->prefix - f->clen;
//     f->conversion = calloc(l + 1, sizeof(char));
//     if (f->conversion)
//     {
//         memset(f->conversion, ' ', f->width);
//         memset(f->conversion + b, f->p, f->prefix);
//         memset(f->conversion + b + f->prefix, '0', f->precision);
//         memcpy(f->conversion + b + a + f->prefix, f->content, f->clen);
//     }
// }

// static void ft_converter(va_list a, t_con *f, char c)
// {
//     if (c == 'i' || c == 'd')
//         f->content = strdup("48");
//     else if (c == 's')
//         f->content = strdup(va_arg(a, char *));
// }

// static int ft_flag_collector(t_con *f, char c)
// {
//     if (c == '#')
//         f->hashtag = 1;
//     else if (c == '+' || c == ' ')
//     {
//         f->prefix = 1;
//         f->p = BIGGER(f->p, c);
//     }
//     else if (c == '-')
//         f->minus = 1;
//     else if (c == '0')
//         f->zero = 1;
//     else
//         return 0;
//     return (1);
// }

// static int ft_width_preci(t_con *f, char *s)
// {
//     int i;

//     i = 0;
//     if (isdigit(*s))
//         f->width = atoi(s);
//     while (isdigit(*(s + i)))
//         i++;
//     i++;
//     if ( *(s + i - 1) == '.' && isdigit(*(s + i)))
//         f->precision = atoi(s + i);
//     while (isdigit(*(s + i)))
//         i++;
//     return (i);
// }
// char *ft_gen(va_list a, char *s, int *i)
// {
//     t_con flag;
//     int r;

//     bzero(&flag, sizeof(t_con));
//     r = 1;
//     while (*(s + (*i)) && r)
//         *i += r = ft_flag_collector(&flag, *(s + 1 + (*i)));
//     *i += ft_width_preci(&flag, (s + 1 + (*i)));
//     ft_converter(a, &flag, *(s + 1 + (*i)));
//     ft_formatter(&flag, *(s + 1 + (*i)));
//     if (flag.conversion)
//     {
//         *i += 2;
//         return (flag.conversion);
//     }
//     return (NULL);
// }
// int ft_printf( char *format, ...)
// {
//     va_list args;
//     int i;

//     va_start(args, format);
//     i = 0;
//     while (*(format + i))
//     {
//         if (*(format + i) == '%')
//             printf("%s", ft_gen(args, format, &i));
//         printf("%c", *(format + i));
//         i++;
//     }
//     va_end(args);
//     return (-1);
// }

int main(void)
{
    //ft_printf("%#0 -.4d\n", 48);
    printf("%s\n", ft_itoa(0));
    return 0;
}