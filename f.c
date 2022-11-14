//#include "ft_printf.h"

int check_set(char c)
{
	char *set;

	set = "diuxXp%";
    while(*set)
    {
        if(*set == c)
            return (1);
        set++;
    }
    return (0);
}

static void ft_helper(t_con *f, char *s, int *i)
{
	if (*(s + (*i)) == ' ' || *(s + (*i)) == '+')
		f->pr =	BIGGER(f->pr, *(s + (*i)));
	else if (*(s + (*i)) == '#')
		f->h = 1;
	else
		return ;
	(*i)++;
	ft_helper(f, s, i);
}

static char *ft_formatter(t_con *f)
{
    char *str;
    int v;
    int l;
    int a;
    
	if (f->pr)
		f->s = 1;
    v = BIGGER(f->w, (f->c + f->s));
    l = BIGGER(v, (f->s + f->p));
    a = BIGGER((f->p - f->c), (f->c - f->c));
    str = calloc(l + 1, sizeof(char));
    if (str)
    {
        ft_memset(str, ' ', f->w);
        ft_memset(str, f->pr, f->s);
        ft_memset(str + f->s, '0', f->p);
        ft_memcpy(str + a + f->s, f->content, f->c);
    }
    return str;
}

int main() {
    t_con format;
	int i;

	i = 0;
    ft_bzero(&format, sizeof(t_con));
	ft_helper(&format, "%+-5.6d\n", &i);
    format.c = 2;
    format.content = ft_strdup("18");
    printf("%s\n", ft_formatter(&format));
    printf("%+-5.6d\n", 18);
    return 0;
}