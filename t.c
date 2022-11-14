#include <stdio.h>
#include "ft_printf.h"
char *ft_formater(t_con *f);
int main()
{
	t_con format;

    ft_bzero(&format, sizeof(t_con));
    format.s = 0;
    format.m = 0;
    format.w = 4;
    format.p = 0;
    format.c = 2;
    format.pr = '+';
    format.content = ft_strdup("18");
    printf("%s\n", ft_formater(&format));
	printf("%32d\n", 18);
	return 0;
}

char *ft_formater(t_con *f)
{
    char *str;
    int v;
    int l;
    int a;
    int b;
    
    v = BIGGER(f->w, (f->c + f->s));
    l = BIGGER(v, (f->s + f->p));
    a = BIGGER((f->p - f->c), (f->c - f->c));
	b = 0;
	if (!f->m)
		b = l - f->p - f->s;
    str = ft_calloc(l + 1, sizeof(char));
    if (str)
    {
        ft_memset(str, ' ', f->w);
        ft_memset(str + b, f->pr, f->s);
        ft_memset(str + b + f->s, '0', f->p);
        ft_memcpy(str + b + a + f->s, f->content, f->c);
    }
    return str;
}