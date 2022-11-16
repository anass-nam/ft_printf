#include "ft_printf.h"

static char	**ft_realoc(char **t, int l);
static int	ft_strdlen(char *s, char d);
static void	ft_memclear(char **strs, int last);

char **ft_helper(va_list a, char *s)
{
	char **ret;
	int i;
	int j;
	int dlen;

	i = 0;
	ret = (char **)malloc(sizeof(char *));
	if (ret)
	{
		while (*(s + i))
		{
			dlen = ft_strdlen((char *)s, '%');
			*(ret + j) = ft_substr(s, i, dlen);
			if (!*(ret + j++))
				return (ft_memclear(ret, j), NULL);
			ret = ft_realoc(ret, j);
			if (!ret)
				return (ft_memclear(ret, j), NULL);
			i += dlen;
			*(ret + j) = ft_gen(a, s, &i);
			if (!*(ret + j))
				*(ret + j) = ft_substr(s, i, ft_strdlen((char *)s + 1, '%') + 1);
			if (!*(ret + j++))
				return (ft_memclear(ret, j), NULL);
			ret = ft_realoc(ret, j);
			if (!ret)
				return (ft_memclear(ret, j), NULL);
		}
		return (ret);
	}
	return (NULL);
}

static char	**ft_realoc(char **t, int l)
{
	char	**new;
	int		i;

	new = (char **)malloc(sizeof(char *) * (l + 1));
	if (new)
	{
		i = -1;
		while (++i < l)
			*(new + i) = *(t + i);
		return (free(t), new);
	}
	return (ft_memclear(new, l + 1), NULL);
}

static int	ft_strdlen(char *s, char d)
{
	int	c;

	c = 0;
	while (*(s + c) && *(s + c) != d)
		c++;
	return (c);
}

static void	ft_memclear(char **strs, int last)
{
	int	i;

	i = 0;
	while (i < last)
		free(strs[i++]);
	free(strs);
	strs = NULL;
}