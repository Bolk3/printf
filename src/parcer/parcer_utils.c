/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:04:20 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/14 10:39:58 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <writers.h>
#include <parcer.h>
#include <stdlib.h>

int	correct_node(t_list *node)
{
	if (!node)
		return (0);
	if (!node -> content)
		return (0);
	if (!((t_print *)node->content)->data)
	{
		if (((t_print *)node->content)->type != ERROR)
			return (0);
	}
	return (1);
}

void	free_node(void *node)
{
	t_print	*t_node;

	t_node = (t_print *)node;
	free(t_node -> data);
	free(t_node);
}

t_list	*printf_cleanup(t_list **lst)
{
	ft_lstclear(lst, free_node);
	return (NULL);
}

char	*handle_ptr(void *arg)
{
	char	*result;

	if (!arg)
		result = ft_strdup("(nil)");
	else
		result = ft_ltoh((unsigned long)&arg, LOW_HEX);
	return (result);
}

enum e_type	set_arg(const char *str)
{
	if (str[1] == 'd' || str[1] == 'i')
		return (INT);
	if (str[1] == 'u')
		return (UINT);
	if (str[1] == '%')
		return (PERCENT);
	if (str[1] == 'p')
		return (PTR);
	if (str[1] == 'c')
		return (CHR);
	if (str[1] == 's')
		return (STR);
	if (str[1] == 'x')
		return (LOW_X);
	if (str[1] == 'X')
		return (UPP_X);
	return (ERROR);
}
