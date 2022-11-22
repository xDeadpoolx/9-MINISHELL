/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:18:06 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/22 09:57:14 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <curses.h>
# include "../libft/includes/libft.h"
# include "../librl/readline.h"
# include "../librl/history.h"

/***** STRUTURE *****/

typedef struct s_vault
{
	char	**env;
	char	*read_line;
	char	**readline_decomposer;
}	t_vault;

/***** minishell.c *****/

void	init_struct(t_vault **data);

/***** explore_readline.c *****/

void	explore_readline(t_vault	*data);

/**** built_in.c ****/

void	ft_cd(t_vault *data);

/***** POUR DEBUG *****/

void	print_double_array(char **array);

#endif