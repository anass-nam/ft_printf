#include "libft/libft.h"

static void	ft_memclear(char *mem, int n);
static char	*ft_realoc(char *t, int l);
static int	ft_strdlen(char *s, char d);


char **ft_printf_helper(char *s)
{
    char **output;
    size_t i;

    i = 0;
    while (*s && *s != '%')
        ft_putchar_fd(*s, 1);
}

static void	ft_memclear(char *mem, int n)
{
	ft_bzero(mem, n);
	free(mem);
	mem = NULL;
}

static char	*ft_realoc(char *t, int l)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char ) * (l + 1));
	if (new)
	{
		i = -1;
		while (*(t + ++i))
			*(new + i) = *(t + i);
		return (ft_memclear(t, l), new);
	}
	return (ft_memclear(new, l), NULL);
}

static int	ft_strdlen(char *s, char d)
{
	int	c;

	c = 0;
	while (*(s + c) && *(s + c) != d)
		c++;
	return (c);
}