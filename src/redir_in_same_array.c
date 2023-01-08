/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in_same_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:50:08 by mbertin           #+#    #+#             */
/*   Updated: 2023/01/08 13:39:01 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redir_in_same_array(t_vault *data, int i, int *j, char c)
{
	data->flag->chevron = c;
	if (c == '>' && data->tab_arg[i][*j + 1] == c)
	{
		data->flag->append = TRUE;
		data->tab_arg[i] = clean_the_chevron(data, data->tab_arg[i], 0, 0);
		find_redir_in_same_array(data, data->tab_arg[i], i);
	}
	else if (c == '<' && data->tab_arg[i][*j + 1] == c)
	{
		data->tab_arg[i] = clean_the_chevron(data, data->tab_arg[i], 0, 0);
		find_redir_in_same_array(data, data->tab_arg[i], i);
		if (ft_strlen(data->tab_arg[i]) != 1)
			heredoc(data, i);
	}
	else
		find_redir_in_same_array(data, data->tab_arg[i], i);
	clean_redir(data, i);
	data->tab_arg[i] = clean_the_chevron(data, data->tab_arg[i], i, 0);
	*j = -1;
	redirection(data, data->flag->output);
	free (data->flag->output);
}

void	find_redir_in_same_array(t_vault *data, char *rl_dec_array, int line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len_of_redir(data, rl_dec_array, line);
	i = move_index_chevron2(data, line, i, rl_dec_array);
	// while (rl_dec_array[i] != data->flag->chevron)
	// {
	// 	if (rl_dec_array[i + 1] == data->flag->chevron)
	// 	{
	// 		i++;
	// 		while (is_in_quote(data, line, i) == TRUE)
	// 			i++;
	// 		i--;
	// 	}
	// 	i++;
	// }
	i++;
	while (rl_dec_array[i] == ' ')
		i++;
	if (rl_dec_array[i] == '\"' || rl_dec_array[i] == '\'')
	{
		data->quote->quote_priority = rl_dec_array[i];
		i++;
		while (rl_dec_array[i] != data->quote->quote_priority)
		{
			data->flag->output[len] = rl_dec_array[i];
			len++;
			i++;
		}
	}
	else
	{
		while (rl_dec_array[i] && rl_dec_array[i] != ' '
			&& rl_dec_array[i] != '<' && rl_dec_array[i]
			!= '>' && rl_dec_array[i] != '|')
			data->flag->output[len++] = rl_dec_array[i++];
	}
}

void	len_of_redir(t_vault *data, char *rl_dec_array, int line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	i = move_index_chevron(data, line, i, rl_dec_array);
	// while (rl_dec_array[i])
	// {
	// 	if (rl_dec_array[i] == data->flag->chevron
	// 		&& is_in_quote(data, line, i) == FALSE)
	// 		break ;
	// 	i++;
	// }
	i++;
	while (rl_dec_array[i] == ' ')
		i++;
	if (rl_dec_array[i] == '\"' || rl_dec_array[i] == '\'')
	{
		data->quote->quote_priority = rl_dec_array[i];
		i++;
		len++;
		while (rl_dec_array[i] != data->quote->quote_priority)
		{
			i++;
			len++;
		}
	}
	else
		len = while_is_not_flag(rl_dec_array, i) - i;
	data->flag->output = ft_calloc(sizeof(char), len + 1);
}

int	move_index_chevron(t_vault *data, int line, int i, char *rl_dec_array)
{
	while (rl_dec_array[i])
	{
		if (rl_dec_array[i] == data->flag->chevron
			&& is_in_quote(data, line, i) == FALSE)
			break ;
		i++;
	}
	return (i);
}

int	move_index_chevron2(t_vault *data, int line, int i, char *rl_dec_array)
{
	while (rl_dec_array[i] != data->flag->chevron)
	{
		if (rl_dec_array[i + 1] == data->flag->chevron)
		{
			i++;
			while (is_in_quote(data, line, i) == TRUE)
				i++;
			i--;
		}
		i++;
	}
	return (i);
}

// autre fonction commune potentielle :
// a la place des lignes 101-111 et 131-141.
// attention au int *len
// int	move_index_chevron3(t_vault *data, int i, int *len, char *rl_dec_array)
// {
// 	if (rl_dec_array[i] == '\"' || rl_dec_array[i] == '\'')
// 	{
// 		data->quote->quote_priority = rl_dec_array[i];
// 		i++;
// 		(*len)++;
// 		while (rl_dec_array[i] != data->quote->quote_priority)
// 		{
// 			i++;
// 			(*len)++;
// 		}
// 	}
// 	return (i);
// }
