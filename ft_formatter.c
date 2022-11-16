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
		*i += r = ft_flag_collector(&flag, *(s + (*i)));
	*i += ft_width_preci(&flag, (s + (*i)));
	ft_converter(a, &flag, *(s + (*i)));
	ft_formatter(&flag, *(s + (*i)));
	if (flag.conversion)
		return (flag.conversion);
	return (NULL);
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
    a = BIGGER((f->precision - f->clen), (f->clen - f->clen));
	b = 0;
	if (!f->minus)
		b = l - f->precision - f->prefix;
    f->conversion = calloc(l + 1, sizeof(char));
    if (f->conversion)
    {
        ft_memset(f->conversion, ' ', f->width);
        ft_memset(f->conversion + b, f->p, f->prefix);
        ft_memset(f->conversion + b + f->prefix, '0', f->precision);
        ft_memcpy(f->conversion + b + a + f->prefix, f->content, f->clen);
    }
}

static void ft_converter(va_list a, t_con *f, char c)
{
	if (c == 'i' || c == 'd')
		f->content = ft_itoa(va_arg(a, int));
	else if (c == 's')
		f->content = ft_strdup(va_arg(a, char *));
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
		f->width = ft_atoi(s);
	while (ft_isdigit(*(s + i)) || *(s + i) == '.')
		i++;
	if (ft_isdigit(*(s + i)))
		f->precision = ft_atoi(s + i);
	while (ft_isdigit(*(s + i)))
		i++;
	return (i);
}