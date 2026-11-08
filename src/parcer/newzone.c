/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newzone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:34:42 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/08 12:45:03 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <printf.h>
#include <libft.h>

t_print	*newzone(char *data)
{
	t_print	*result;

	result = malloc(sizeof(t_print));
	if (result)
	{
		result -> next = NULL;
		result -> data = data;
		result -> size = ft_strlen(data);
		return (result);
	}
	return (NULL);
}
