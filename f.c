#include "ft_printf.h"

char *ft_formater();

int main() {
    t_con format;

    bzero(&format, sizeof(t_con));
    format.s = 1;
    format.w = 0;
    format.p = 6;
    format.c = 2;
    format.pr = '+';
    format.content = strdup("18");
    printf("%s\n", ft_formater(&format));
    printf("%+-.6d\n", 18);
    return 0;
}

char *ft_formater(t_con *f)
{
    char *str;
    int v;
    int l;
    int a;
    
    v = BIGGER(f->w, (f->c + f->s));
    l = BIGGER(v, (f->s + f->p));
    a = BIGGER((f->p - f->c), (f->c - f->c));
    str = calloc(l + 1, sizeof(char));
    if (str)
    {
        memset(str, ' ', f->w);
        memset(str, f->pr, f->s);
        memset(str + f->s, '0', f->p);
        memcpy(str + a + f->s, f->content, f->c);
    }
    return str;
}
