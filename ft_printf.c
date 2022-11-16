#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	char *f;
	int i;

	f = ft_strdup(format);
	if (f)
	{
		va_start(args, format);
		i = 0;
		while (*(f + i))
		{
			if (*(f + i) == '%')
				ft_putstr_fd(ft_gen(args, f, &i), 1);
			ft_putchar_fd(*(f + i), 1);
			i++;
		}
		va_end(args);
	}
	return (-1);
}

int main(void)
{
	int s;

	s = -48;
	ft_printf("% -.4d1\n", s);
	printf("% -.4x1\n", s);
	return 0;
}

	// ar = va_arg(args, void *);