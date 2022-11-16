
void	ft_putchar_fd(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_mini_atoi(const char *str)
{
	int	r;

	r = 0;
	while (ft_isdigit(*str))
		r = r * 10 + ((*str++) - 48);
	return (r);
}

#include "ft_printf.h"

void ft_converter(va_list a, t_con *f, char c)
{
	if (c == 'i' || c == 'd')
		f->content = ft_itoa(va_arg(a, int));
	else if (c == 's')
		f->content = ft_strdup(va_arg(a, char *));
	else if (c == 'x')
		f->content = itob(va_arg(a, unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		f->content = itob(va_arg(a, unsigned int), "0123456789ABCDEF", 16);
	else if (c == 'u')
		f->content = itob(va_arg(a, unsigned int), "0123456789", 10);
	else if (c == 'p')
		f->content = itob(va_arg(a, unsigned int), "0123456789ABCDEF", 16);
	else if (c == 'c')
		f->content = ctos(va_arg(a, char));
	else if (c == '%')
		f->content = ctos(va_arg(a, char));
	else
		f->content = NULL;
}

static char *itob(unsigned int n, char *base, int bl)
{
    char *ret;
    int i;
    unsigned int nb;

    nb = n;
    i = 0;
    while (++i && nb > 0)
        nb /= bl;
    ret = (char *)malloc(i * sizeof(char));
    if (ret)
    {
        *(ret + --i) = '\0';
        if (n == 0)
            *ret = '0';
        while (n > 0)
        {
            *(ret + --i) = base[n % bl];
            n /= bl;
        }
        return ret;
    }
    return (NULL);
}

static char *ctos(char c)
{
	char ret[2];

	ret[0] = c;
	ret[1] = '\n';
	return (ret);
}