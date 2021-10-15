
#include "../Includes/minishell.h"

char			*set_with_kov(char *com)
{
	char		*str;
	int			i;
	int			j;

	str = malloc(ft_strlen(com - 2));
	i = 0;
	j = 0;
	while (com[i] != '\0')
	{
		if (com[i] != '"')
		{
			str[j] = com[i];
			j++;
		}
		i++;
	}
	free(com);
	return (str);
}

int					if_env(char *com, t_data *data)
{
	t_data			*str;

	if (com[0] == '$')
	{
		if ((str = parse_env(data, &com[1])))
			ft_putstr(str->content + ft_strlen(com));
		return (1);
	}
	return (0);
}

t_data				*change_oldpwd(t_data *data)
{
	char			*str;
	t_data			*to_del;
	t_data			*lst;
	char			*pwd;

	lst = data;
	if ((to_del = parse_env(data, "OLDPWD")))
	{
		while (data->next != to_del)
			data = data->next;
		data->next = to_del->next;
		free(to_del->content);
		free(to_del);
	}
	if (!(pwd = getcwd(NULL, 0)))
		return (data);
	str = ft_strjoin(ft_strjoin("OLDPWD", "=", 0), pwd, 1);
	lst = list_add_back(data, str);
	free(pwd);
	return (lst);
}

t_data			*add_list_env(char **env)
{
	t_data		*head;
	char		*str;
	int			i;

	head = lstnew(env[0]);
	i = 0;
	while (env[++i])
	{
		str = ft_strdup(env[i]);
		head = list_add_back(head, str);
	}
	return (head);
}

char			*find_path(char *com, t_data *data)
{
	t_data		*path_lst;
	char		**split;
	char		*str;
	int			i;

	if ((path_lst = parse_env(data, "PATH")))
	{
		split = ft_strsplit(path_lst->content + 5, ':');
		i = -1;
		while (split[++i])
		{
			str = ft_strjoin(ft_strjoin(split[i], "/", 0), com, 1);
			if (!access(str, X_OK))
			{
				freest(split);
				return (str);
			}
			free(str);
		}
		freest(split);
	}
	return (NULL);
}
