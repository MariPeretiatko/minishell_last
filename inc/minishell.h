/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:58:10 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 23:18:21 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../src/libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define NC "\033[0m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define BOLD "\033[1m"

typedef struct s_envp
{
	char			*name;
	char			*value;
	struct s_envp	*next;
	struct s_envp	*prev;
}					t_envp;

extern int			g_exit_status;

typedef struct s_execute
{
	t_envp			**env;
	char			***cmds;
	int				**toks;
	char			**cmds_old;
	int				*tok_old;
	int				heredoc_fd[16][2];
	int				pipe_fd[2][2];
	int				cmd_cnt;
	int				*cpid;
	// char			*minishell;
}					t_execute;

typedef enum e_token
{
	CMD_NAME = 1,
	CMD_ARG,
	R_IN_SIG,
	R_IN_FILE,
	HEREDOC_SIG,
	HEREDOC_LIM,
	R_OUT_SIG,
	R_OUT_FILE,
	R_APP_SIG,
	R_APP_FILE,
	PIPE,
	EMPTY,
}					t_token;

typedef enum e_sig_state
{
	SIG_DEFAULT = 1,
	SIG_HEREDOC,
	SIG_CHILD,
	SIG_PARENT
}					t_sig_state;

/* Builtins */
void				cd(char **args, t_envp *env);
void				echo(char **args);
void				env(t_envp *env, char **args);
void				export(t_envp **env, char **args);
void				pwd(void);
void				unset(t_envp **env, char **args);
void				ft_exit(char **args, t_execute *exec);

/* Function for envlst linked list */
t_envp				*get_env_variables(char **envp);
t_envp				*envlst_new(char *str);
void				envlstadd_back(t_envp **env, t_envp *new_env);
void				envlst_clear(t_envp **env);
void				envlst_clearone(t_envp **root, t_envp *env);
t_envp				*envlst_search(t_envp *env, char *searched);
int					envlst_size(t_envp *env);

/* Parsing */
char				*parse_operator(char *cmd);
bool				parse_line(char *line);
bool				check_empty_line(char *line);
void				chg_qte_state(int *state, int c);
char				**args_split(char *cmd);
int					*tokenise_line(char **cmd);
void				expand_env_var(char **cmd, int *cmd_type);
void				expand_doll(char **cmd, int *tokens, t_envp *env);
void				remove_quote(char **cmd);
void				remove_quote_in_tok(char **cmd);
bool				check_tokens(int *cmd_type);

void				chg_qte_state(int *state, int c);

# define E_OPERATOR_PARSE \
	"minishell>\
	syntax error near unexpected token `%c%c'\n"

/* Signals */
void				handle_sig(int state);

/* Prompt */
void				get_prompt(t_envp *env);

/* Utils */
bool				is_pipe(char c);
bool				is_redirection(char c);
bool				is_space(char c);
char				**env_lst_to_array_name(t_envp *env);
char				**env_lst_to_array_value(t_envp *env);

/* Redirections */
int					heredoc_init(int hd_arr[16][2], char ***cmds, int **toks);
void				redirection_hdl(t_execute *exec, int cmd_nb);
int					check_heredoc_use(int fd, t_execute *exec, int cmd_nb);
void				close_heredocs(int hd_arr[16][2]);
bool				stdin_state(void);
# define HD_EOF \
	"minishell> warning: here-document delimited by end-of-file \
(wanted `%s')\n"

/* Execution */
void				main_execute(char *raw_cmd, t_envp **env);
char				*get_cmd_path(char **cmd_arg, int *tokens, t_envp *env);
char				**get_cmd_args(char **cmd_arg, int *tokens, t_envp *env,
						char *cmd);
bool				check_dir(char *cmd);

char				**transform_envp(t_envp *env);
int					cmd_counter(char **args, int *tokens);
char				**get_nxt_cmd(char **cmd_split, int *tokens);

void				sec_close(int fd);
void				sec_full_close(int pipe_fd[2][2], int cmd_nb);
void				free_exec(t_execute *exec, char *path, char **args);

bool				is_builtin(char **cmds, int *toks);
bool				isbuiltin_env(char **cmd, int *toks);
void				start_builtin_env(char **cmd, int *toks, t_execute *exec);
void				init_builtin_exec(char **cmds, int *toks, t_execute *exec,
						int cmd);

#endif
