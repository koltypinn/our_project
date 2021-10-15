
#include "../Includes/minishell.h"


char				ft_strchr_my(const char *s)
{
	int				i;
	char			c;

	i = 0;
	while (s[i] != 34 && s[i] != 39)
	{
		if (!s[i])
			return (0);
		i++;
	}
	c = s[i];
	return (c);
}

t_data			*list_add_back(t_data *list, void *content)
{
	t_data		*item;
	t_data		*ret;

	if (!list)
		return (lstnew(content));
	ret = list;
	while (list->next)
		list = list->next;
	item = malloc(sizeof(t_data));
	if (!item)
	{
		write(1, "Malloc error\n", 13);
		exit(1);
	}
	item->content = content;
	item->next = NULL;
	list->next = item;
	return (ret);
}

t_data			*lstnew(void *content)
{
	t_data		*ret;

	ret = malloc(sizeof(t_data));
	if (!ret)
	{
		write(1, "Malloc error\n", 13);
		exit(1);
	}
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

t_data			*parse_env(t_data *env, char *name)
{
	char		**split;

	while (env)
	{
		split = ft_strsplit(env->content, '=');
		if (!ft_strcmp(split[0], name))
		{
			freest(split);
			return (env);
		}
		freest(split);
		env = env->next;
	}
	return (NULL);
}

int			manage_error(int k, char *str)
{
	if (k == 1)
		ft_putstr("using: unsetenv [name]\n");
	if (k == 2)
		ft_putstr("using: setenv [name] [value]\n");
	if (k == 3)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putstr(str);
		write(1, "\n", 1);
	}
	if (k == 4)
	{
		ft_putstr("minishell: cmd not found: ");
		ft_putstr(str);
		write(1, "\n", 1);
		exit(0);
	}
	if (k == 5)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putstr(str);
		write(1, "\n", 1);
	}
	return (1);
}