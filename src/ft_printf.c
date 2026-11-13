/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:24:32 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/13 15:04:36 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <printf.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	arguments;

	va_start(arguments, format);
	result = ft_vprintf(format, arguments);
	va_end(arguments);
	return (result);
}
