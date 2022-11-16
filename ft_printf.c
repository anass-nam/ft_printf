#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	char *f;
	char **output;
	int i;

	i = 0;
	f = ft_strdup(format);
	if (f)
	{
		output = ft_helper(args, f);
		if (output)
		{
			while (*output)
			{
				i += ft_strlen(*output);
				ft_putstr_fd(*output, 1);
			}
			return (i);
		}
	}
	return (-1);
}

int main(void)
{
	int s;

	s = 48;
	ft_printf("%#+0 -d", s);
	return 0;
}

	// ar = va_arg(args, void *);