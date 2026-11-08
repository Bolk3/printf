/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:35:40 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/08 11:09:05 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <printf.h>

static int	get_byte_size(unsigned long value)
{
	int	result;

	result = 0;
	if (!value)
		return (1);
	while (value)
	{
		result++;
		value /= 10;
	}
	return (result);
}

char	*ft_ultoa(unsigned long value)
{
	char	*result;
	int		size;

	size = get_byte_size(value);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size--] = 0;
	while (size > -1)
	{
		result[size] = '0' + value % 10;
		value /= 10;
		size--;
	}
	return (result);
}
