/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:28:48 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/09 13:48:15 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <__stdarg_va_list.h>
#include <libft.h>
#include <printf.h>
#include <stddef.h>
#include <stdlib.h>

t_print	*create_arg_node(const char *str, va_list args)
{
	t_print	*result;
	char	*data;

	result = malloc(sizeof(t_print));
	if (!result)
		return (NULL);
	result -> type = get_arg(&data, args);
	result -> data = data;
	if (!result -> data)
	{
		free(result);
		return (NULL);
	}
	result -> size = ft_strlen(result -> data);
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
			new_node = ft_lstnew(create_arg_node(str + i, args));
		else
		{
			while (str[j] && str[j] != '%')
				j++;
			new_node = ft_lstnew(create_str_node(str, i, j));
		}
		if (!new_node || !new_node->content || !((t_print *)new_node->content)->data)
			return (cleanup(&result));
		ft_lstadd_back(&result, new_node);
		i = j;
	}
	return (result);
}
