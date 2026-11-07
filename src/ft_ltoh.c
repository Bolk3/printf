/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:46:47 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/07 22:42:19 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <printf.h>
#include <stdlib.h>

int	get_byte_size(unsigned long value)
{
	int	res;

	res = 0;
	if (!value)
		return (1);
	while (value)
	{
		res++;
		value /= 16;
	}
	return (res);
}

char	*ft_ltoh(unsigned long value, const char *charset)
{
	char	*res;
	int		size;

	size = get_byte_size(value);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res[size--] = 0;
	while (size > -1)
	{
		res[size] = charset[value % 16];
		value /= 16;
		size--;
	}
	return (res);
}
