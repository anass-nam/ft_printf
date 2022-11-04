#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

static void	ft_memclear(char *mem, int n);
static char	*ft_realoc(char *t, int l);
static int	ft_argsc(char *t);
static char *ft_formatter();

int printf(const char *restrict format, ...)
{
	size_t args_c;
	size_t i;
	va_list args;
	char *holder;
	char *output;

	args_c = args_count(format);
	va_start(args, args_c);
	i = 0;
	while (i <= args_c)
	{
		holder = ft_itoa(va_arg(args, int));
		if (!holder)
			return (NULL);
		i++;
	}
	
	va_end(args);
}

int	main(int argc, char const *argv[])
{
	print("anass%-0.s %#d %%");
	return (0);
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


