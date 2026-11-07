/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:20:00 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/07 21:23:49 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <__stdarg_va_list.h>
#include <printf.h>
#include <stdarg.h>

int	ft_fprintf(int fd, const char *format, ...)
{
	int		result;
	va_list	arguments;

	va_start(arguments, format);
	result = ft_vfprintf(fd, format, arguments);
	va_end(arguments);
	return (result);
}
