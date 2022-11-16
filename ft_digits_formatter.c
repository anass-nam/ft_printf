#include "ft_printf.h"

void ft_dformatter(t_con *f, char c)
{
    int v;
    int l;
    int a;
    int b;
    
    f->clen = ft_strlen(f->content);
    v = BIGGER(f->width, (f->clen + f->prefix));
    l = BIGGER(v, (f->prefix + f->precision));
    b = 0;
    if (!f->minus)
        b = l - f->precision - f->prefix;
    if (!f->minus && !f->precision)
        b = l - f->precision - f->prefix - f->clen;
    a = BIGGER((f->precision - f->clen), (f->clen - f->clen));
    f->conversion = ft_calloc(l + 1, sizeof(char));
    if (f->conversion)
    {
        ft_memset(f->conversion, ' ', f->width);
        ft_memset(f->conversion + b, f->p, f->prefix);
        ft_memset(f->conversion + b + f->prefix, '0', f->precision);
        ft_memcpy(f->conversion + b + a + f->prefix, f->content, f->clen);
    }
}