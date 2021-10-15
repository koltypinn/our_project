
#include "../Includes/minishell.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*mem;

	mem = (unsigned char *)s;
	while (n--)
		*mem++ = '\0';
}

void			ft_putstr(char const *s)
{
	int			i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

char			*ft_strchr(const char *s, int c)
{
	char		*ret;
	int			i;
	char		k;

	k = (char)c;
	i = 0;
	while (s[i] != k)
	{
		if (!s[i])
			return (0);
		i++;
	}
	ret = (char*)s;
	return (&ret[i]);
}

size_t			ft_strlen(const char *src)
{
	size_t		i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}
