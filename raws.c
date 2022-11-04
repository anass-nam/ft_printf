#include <stdio.h>
#include <string.h>
#include <stdlib.h>      

typedef struct raws
{
    char *countent;
    char sp;
    char p;
    char h;
    int pf;
    int sf;
}    t_list;

int t_helper(char c, char *set)
{
    while(*set)
    {
        if(*set == c)
            return (1);
        set++;
    }
    return (0);
}
void f_one(char *s, t_list *f, int *i)
{
    if (*s == '#')
        f->h = '#';
    else if (*s == '+')
        f->p = '+';
    else if (*s == ' ')
        f->sp = ' ';
    else
        return ;
    *i += 1;
    gen(s + 1, f, i);
}
void f_two(char *s, t_list *f, int *i)
{

}

int    main(void)
{
    t_list format;
    size_t l;
    size_t i;
    
    char *ss = "ss%# +-0.1dn %p";
    char *s = strdup(ss);
    l = 0;
    i = 0;
    while (*s)
    {
        if (*s == '%')
        {
            gen(s+1, &format, &i);
            s += i;
        }
        else
            printf("%c", *s);
        s++;
    }
    return (0);
}