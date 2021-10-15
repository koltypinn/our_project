#include "../Includes/minishell.h"

char	*ft_strdup(const char *str)
{
	int				i;
	char			*ret;

	ret = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char				*ft_strjoin(char const *str, char const *dst, int in)
{
	char			*ret;
	size_t			i;
	size_t			k;

	if (!str || !dst)
		return (NULL);
	ret = (char*)malloc(ft_strlen((char*)str) + ft_strlen((char*)dst) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
		ret[k++] = str[i++];
	i = 0;
	while (dst[i])
		ret[k++] = dst[i++];
	ret[k] = '\0';
	(in == 1) ? free((void*)str) : 0;
	(in == 2) ? free((void*)dst) : 0;
	return (ret);
}

char				**freest(char **d)
{
	int				i;

	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
	return (NULL);
}

int					count(char **ret)
{
	int				i;

	i = 1;
	while (ret[i])
		i++;
	return (i);
}

int					ft_strcmp(const char *str, const char *dst)
{
	while(*str && *str == *dst)
	{
		str++;
		dst++;
	}
	return ((unsigned char)*str - (unsigned char)*dst);
}
