
#include "../Includes/minishell.h"

t_data				*do_cd(char **str, t_data *data)
{
	if (count(str) > 2)
		manage_error(3, str[1]);
	if (str[1] && !(ft_strcmp("-", str[1])))
		do_cd_return(data);
	else if (str[1] && str[1][0] == '~')
		do_cd_sign(str[1], data);
	else if (str[1] && ft_strcmp("~", str[1]) && ft_strcmp("-", str[1]))
	{
		data = change_oldpwd(data);
		if (chdir(str[1]))
			manage_error(5, str[1]);
	}
	else
		do_cd_without(data);
	return (data);
}

void			do_env(t_data *data)
{
	while (data)
	{
		ft_putstr(data->content);
		data = data->next;
		write(1, "\n", 1);
	}
}

t_data			*do_unsetenv(char **com, t_data *data)
{
	t_data		*to_del;
	t_data		*lst;

	lst = data;
	if (count(com) != 2)
		manage_error(1, NULL);
	else if ((to_del = parse_env(data, com[1])))
	{
		while (data->next != to_del)
			data = data->next;
		data->next = to_del->next;
		free(to_del->content);
		free(to_del);
	}
	return (lst);
}

t_data			*do_setenv(char **com, t_data *data)
{
	char		*str;
	t_data		*lst;
	t_data		*to_del;

	lst = data;
	if (count(com) != 3)
		manage_error(2, NULL);
	else
	{
		if (ft_strchr(com[2], '"'))
			com[2] = set_with_kov(com[2]);
		if ((to_del = parse_env(data, com[1])))
		{
			while (data->next != to_del)
				data = data->next;
			data->next = to_del->next;
			free(to_del->content);
			free(to_del);
		}
		str = ft_strjoin(ft_strjoin(com[1], "=", 0), com[2], 1);
		lst = list_add_back(data, str);
	}
	return (lst);
}

int				do_also(char **com, t_data *data, char **env)
{
	pid_t		pid;
	char		*path;

	if (!(pid = fork()))
	{
		if (access(com[0], X_OK))
		{
			if ((path = find_path(com[0], data)))
			{
				free(com[0]);
				com[0] = path;
				free(path);
				execve(com[0], com, env);
			}
			else
			{
				wait(&pid);
				return (manage_error(4, com[0]));
			}
		}
		else
			execve(com[0], com, env);
	}
	wait(&pid);
	return (0);
}