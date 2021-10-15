
#include "../Includes/minishell.h"

void		parsecmd(char *com, t_data *data, char **env)
{
	char	**my_com;

	if ((my_com = ft_strsplit(com, ' ')) && *my_com)
	{
		if (!(ft_strcmp(my_com[0], "clear")))
			ft_putstr(CLEAR_SCREEN);
		else if (!(ft_strcmp(my_com[0], "cd")))
			data = do_cd(my_com, data);
		else if (!(ft_strcmp(my_com[0], "echo")))
			do_echo(my_com, data);
		else if (!(ft_strcmp(my_com[0], "setenv")))
			data = do_setenv(my_com, data);
		else if (!(ft_strcmp(my_com[0], "unsetenv")))
			data = do_unsetenv(my_com, data);
		else if (!(ft_strcmp(my_com[0], "env")) ||
			!(ft_strcmp(my_com[0], "/usr/bin/env")))
			do_env(data);
		else if (!(ft_strcmp(my_com[0], "exit")))
			exit(0);
		else if (!(ft_strcmp(my_com[0], "help")))
			do_help();
		else
			do_also(my_com, data, env);
		freest(my_com);
	}
}

static void	my_int(int ret)
{
	ft_putstr("\n$> ");
	ret = 0;
}

int			main(int argc, char **argv, char **env)
{
	char	*cmd;
	t_data	*data;
	char	**split;
	int		c;

	argc = 1;
	*argv = NULL;
	data = add_list_env(env);
	ft_putstr(CLEAR_SCREEN);
	while (argc)
	{
		c = -1;
		signal(SIGINT, my_int);
		initialize_readline();
		if (!(cmd = readline("$> ")))
			return (1);
		add_history(cmd);
		if (!(split = ft_strsplit(cmd, ';')))
			return (0);
		while (split[++c])
			parsecmd(split[c], data, env);
		freest(split);
		free(cmd);
	}
	return (0);
}
