/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:28:48 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/13 17:08:22 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <printf.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void	free_node(void *node)
{
	t_print	*t_node;

	t_node = (t_print *)node;
	free(t_node -> data);
	free(t_node);
}

t_list	*cleanup(t_list **lst)
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
		result = ft_strjoin("0x", ft_ltoh((unsigned long)arg, LOW_HEX));
	return (result);
}

enum e_type	set_arg(const char *str)
{
	if (*(char *)str + 1 == 'd' || *(char *)str + 1 == 'i')
		return (INT);
	if (*(char *)str + 1 == 'u')
		return (UINT);
	if (*(char *)str + 1 == '%')
		return (PERCENT);
	if (*(char *)str + 1 == 'p')
		return (PTR);
	if (*(char *)str + 1 == 'c')
		return (CHR);
	if (*(char *)str + 1 == 's')
		return (STR);
	if (*(char *)str + 1 == 'x')
		return (LOW_X);
	if (*(char *)str + 1 == 'X')
		return (UPP_X);
	return (ERROR);
}

enum e_type	get_arg(const char *str, char **data, va_list args)
{
	enum e_type	result;

	result = set_arg(str);
	if (result == ERROR)
		*data = NULL;
	else if (result == PERCENT)
		*data = ft_strdup("%");
	else if (result == LOW_X)
		*data = ft_strjoin("0x", ft_ltoh(va_arg(args, uint), LOW_HEX));
	else if (result == UPP_X)
		*data = ft_strjoin("0x", ft_ltoh(va_arg(args, uint), UPP_HEX));
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

t_print	*create_arg_node(const char *str, va_list args)
{
	t_print	*result;
	char	*data;

	result = malloc(sizeof(t_print));
	if (!result)
		return (NULL);
	result -> type = get_arg(str, &data, args);
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

t_list	*a(const char *format, ...)
{
	va_list	args;
	t_list	*lst;

	va_start(args, format);
	lst = parcer(format, args);
	va_end(args);

	return (lst);
}

int	main(void)
{
	t_list	*test= a("belle bite; %s", "shinji");
	t_print	*current_node;

	while (test)
	{
		current_node = test -> content;
		printf("%s\n", current_node -> data);
		test = test -> next;
	}
}
