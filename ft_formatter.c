#include "ft_printf.h"

static void ft_formatter(t_con *f, char c);
static void ft_converter(va_list a, t_con *f, char c);
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
    ft_formatter(&flag, *(s + 1 + (*i)));
    if (flag.conversion)
    {
        *i += 2;
        return (flag.conversion);
    }
    return (NULL);
}

static void handler(t_con *f, char c)
{
	if (c == 's')
	{
		if (f->dot)
			f->clen = SMALLER(f->precision, f->clen);
		f->prefix = 0;
		f->precision = 0;
	}
	else if (c == 'c')
	{
		ft_bzero(f, sizeof(f));
	}
	
	
}

static void ft_formatter(t_con *f, char c)
{
    int v;
    int l;
    int a;
    int b;
    
    f->clen = ft_strlen(f->content);
    v = BIGGER(f->width, (f->clen + f->prefix));
    l = BIGGER(v, (f->prefix + f->precision));
    b = 0;
	handler(f, c);
    if (!f->minus)
        b = l - f->precision - f->prefix;
    if (!f->minus && !f->precision)
        b = l - f->precision - f->prefix - f->clen;
    a = BIGGER((f->precision - f->clen), (f->clen - f->clen));
    f->conversion = ft_calloc(l + 1, sizeof(char));
    if (f->conversion)
    {
        ft_memset(f->conversion, ' ', f->width);
        ft_memset(f->conversion + b, f->p, f->prefix);
        ft_memset(f->conversion + b + f->prefix, '0', f->precision);
        ft_memcpy(f->conversion + b + a + f->prefix, f->content, f->clen);
    }
}

static void itohex(unsigned int n, char c, char *base)
{
	char o;
	char *ret;
	int i;
	int bl;

	i = 10;
	bl = ft_strlen(base);
	ret = (char *)malloc(11 * sizeof(char));
	if (ret)
	{
		*(ret + i) = '\n';
		while (n > 0)
		{
			*(ret + --i) = base[n % bl];
			n /= bl;
		}
	}
	return (NULL);
}

static void ft_converter(va_list a, t_con *f, char c)
{
	if (c == 'i' || c == 'd')
		f->content = ft_itoa(va_arg(a, int));
	else if (c == 's')
		f->content = ft_strdup(va_arg(a, char *));
	else if (c == 'x' || c == 'X')
		f->content = itohex(va_arg(a, int), c);
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
	}
    while (ft_isdigit(*(s + i)))
        i++;
    return (i);
}