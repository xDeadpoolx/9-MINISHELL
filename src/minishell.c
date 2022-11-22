/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:22:01 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/22 09:56:52 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	t_vault	*data;

	init_struct(&data);
	while (1)
	{
		data->read_line = readline("alive>");
		add_history(data->read_line);
		explore_readline(data);
		free(data->read_line);
	}
	return (0);
}
