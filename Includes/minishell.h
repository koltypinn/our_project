
#ifndef MINISHELL_MINISHELL_H
# define MINISHELL_MINISHELL_H
# define CLEAR_SCREEN "\033[?1049h\033[H"

# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef	struct		s_data
{
	struct s_data	*next;
	void			*content;
}					t_data;

void				do_help(void);
void				do_echo(char **str, t_data *data);
int					if_env(char *com, t_data *data);
char				ft_strchr_my(const char *s);

void				do_cd_without(t_data *data);
void				do_cd_sign(char *str, t_data *data);
t_data				*do_cd(char **str, t_data *data);
void				do_cd_return(t_data *data);
t_data				*change_oldpwd(t_data *data);

t_data				*add_list_env(char **env);
void				do_env(t_data *data);
t_data				*do_unsetenv(char **com, t_data *data);
t_data				*do_setenv(char **com, t_data *data);
char				*set_with_kov(char *com);


void				parsecmd(char *com, t_data *data, char **env);
int					manage_error(int k, char *str);

void				initialize_readline(void);

int					do_also(char **com, t_data *data, char **env);
char				*find_path(char *com, t_data *data);
t_data				*lstnew(void *content);
t_data				*list_add_back(t_data *list, void *content);
t_data				*parse_env(t_data *env, char *name);

void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *src);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putstr(char const *s);
int					ft_strcmp(const char *str, const char *dst);
int					count(char **ret);
char				**freest(char **d);
char				*ft_strjoin(char const *str, char const *dst, int in);
char				*ft_strdup(const char *str);
char				**ft_strsplit(char const *s, char c);

#endif
