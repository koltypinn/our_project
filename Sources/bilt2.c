
#include "../Includes/minishell.h"

void	do_help(void)
{
	ft_putstr("Argvailable cmds:\n");
	ft_putstr("clear\ncd\necho\nsetenv\nunsetenv\nenv\nexit\n");
}

void				do_cd_return(t_data *data)
{
	t_data			*lst;
	char			*src;

	if ((lst = parse_env(data, "OLDPWD")))
	{
		src = ft_strdup(lst->content + 7);
		change_oldpwd(data);
		chdir(src);
		free(src);
	}
}

void				do_cd_sign(char *str, t_data *data)
{
	t_data			*lst;
	char			*src;

	if ((lst = parse_env(data, "HOME")))
	{
		if (str[1])
			src = ft_strjoin(lst->content + 5, str + 1, 0);
		else
			src = ft_strdup(lst->content + 5);
		data = change_oldpwd(data);
		chdir(src);
		free(src);
	}
}

void				do_cd_without(t_data *data)
{
	t_data			*lst;
	char			*src;

	if ((lst = parse_env(data, "HOME")))
	{
		src = ft_strdup(lst->content + 5);
		data = change_oldpwd(data);
		chdir(src);
		free(src);
	}
}

void				do_echo(char **str, t_data *data)
{
	int		i;
	char	c;
	int		j;

	i = 1;
	c = 0;
	while (str[i])
	{
		j = -1;
		if (!if_env(str[i], data))
		{
			if (!c)
				c = ft_strchr_my(str[i]);
			while (str[i][++j])
				if (str[i][j] != c)
					write(1, str[i] + j, 1);
		}
		if (str[++i])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
