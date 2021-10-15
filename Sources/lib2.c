
#include "../Includes/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, len + 1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static int	ft_count_strings(const char *str, char c)
{
	const char	*temp;
	int			n_strings;

	n_strings = 0;
	while (*str)
	{
		temp = str;
		while (*str != c && *str != '\0')
		{
			str++;
		}
		if (temp != str)
		{
			n_strings++;
		}
		while (*str == c && *str != '\0')
		{
			str++;
		}
	}
	return (n_strings);
}

static int	ft_split_string(const char *str, char c, char **result_p)
{
	const char	*string_start_p;
	size_t		len_str;
	size_t		i;

	i = 0;
	while (*str)
	{
		string_start_p = str;
		while (*str != c && *str != '\0')
			str++;
		if (string_start_p != str)
		{
			len_str = str - string_start_p;
			result_p[i] = ft_substr(string_start_p, 0, len_str);
			if (!(result_p[i++]))
				return (0);
		}
		while (*str == c && *str != '\0')
			str++;
	}
	return (1);
}

static void	ft_free_result(char **result)
{
	size_t	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		n_strings;

	if (s == NULL)
		return (NULL);
	n_strings = ft_count_strings(s, c);
	result = (char **)malloc((n_strings + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (n_strings != 0)
	{
		if (ft_split_string(s, c, result) == 0)
		{
			ft_free_result(result);
			return (NULL);
		}
	}
	result[n_strings] = 0;
	return (result);
}