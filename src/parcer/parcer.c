/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:28:48 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/14 10:39:21 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <parcer.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <writers.h>

enum e_type	get_arg(const char *str, char **data, va_list args)
{
	enum e_type	result;

	result = set_arg(str);
	if (result == ERROR)
		*data = NULL;
	else if (result == PERCENT)
		*data = ft_strdup("%");
	else if (result == LOW_X)
		*data = ft_ltoh(va_arg(args, uint), LOW_HEX);
	else if (result == UPP_X)
		*data = ft_ltoh(va_arg(args, uint), UPP_HEX);
	else if (result == PTR)
		*data = handle_ptr(va_arg(args, void *));
	else if (result == UINT)
		*data = ft_ultoa(va_arg(args, unsigned int));
	else if (result == INT)
		*data = ft_itoa(va_arg(args, int));
	else if (result == STR || result == CHR)
		*data = ft_strdup(va_arg(args, char *));
	return (result);
}

t_print	*create_arg_node(const char *str, va_list args, size_t *head_pos)
{
	t_print	*result;
	char	*data;

	result = malloc(sizeof(t_print));
	if (!result)
		return (NULL);
	result -> type = get_arg(str, &data, args);
	result -> data = data;
	if (!result -> data && result -> type != ERROR)
	{
		free(result);
		return (NULL);
	}
	if (result -> type != ERROR)
		result -> size = ft_strlen(result -> data);
	*head_pos += 2;
	return (result);
}

t_print	*create_str_node(const char *str, int start, int end)
{
	t_print	*result;

	result = malloc(sizeof(t_print));
	if (!result)
		return (NULL);
	result -> type = STR;
	result -> data = ft_substr(str, start, end);
	if (!result -> data)
	{
		free(result);
		return (NULL);
	}
	result -> size = ft_strlen(result -> data);
	return (result);
}

t_list	*parcer(const char *str, va_list args)
{
	t_list	*result;
	t_list	*new_node;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = NULL;
	while (str[i])
	{
		if (str[j] == '%')
			new_node = ft_lstnew(create_arg_node(str + j, args, &j));
		else
		{
			while (str[j] && str[j] != '%')
				j++;
			new_node = ft_lstnew(create_str_node(str, i, j));
		}
		if (!correct_node(new_node))
			return (printf_cleanup(&result));
		ft_lstadd_back(&result, new_node);
		i = j;
	}
	return (result);
}
