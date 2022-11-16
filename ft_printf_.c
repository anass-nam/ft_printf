#include "ft_printf.h"

static int ft_flag_collector(t_con *f, char c);
static int ft_width_preci(t_con *f, char *s);

char *ft_gen(va_list a, char *s, int *i)
{
    t_con flag;
    int r;

    ft_bzero(&flag, sizeof(t_con));
    r = 1;
    while (*(s + (*i)) && r)
        *i += r = ft_flag_collector(&flag, *(s + 1 + (*i)));
    *i += ft_width_preci(&flag, (s + 1 + (*i)));
    ft_converter(a, &flag, *(s + 1 + (*i)));
    ft_dformatter(&flag, *(s + 1 + (*i)));
    if (flag.conversion)
    {
        *i += 2;
        return (flag.conversion);
    }
    return (NULL);
}

static int ft_flag_collector(t_con *f, char c)
{
    if (c == '#')
        f->hashtag = 1;
    else if (c == '+' || c == ' ')
    {
        f->prefix = 1;
        f->p = BIGGER(f->p, c);
    }
    else if (c == '-')
        f->minus = 1;
    else if (c == '0')
        f->zero = 1;
    else
        return 0;
    return (1);
}

static int ft_width_preci(t_con *f, char *s)
{
    int i;

    i = 0;
    if (ft_isdigit(*s))
        f->width = atoi(s);
    while (ft_isdigit(*(s + i)))
        i++;
    if ( *(s + i) == '.')
	{
		f->dot = 1;
		i++;
        f->precision = atoi(s + i);
		while (ft_isdigit(*(s + i)))
			i++;
	}
    return (i);
}