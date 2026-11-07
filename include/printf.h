/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:00:18 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/07 22:40:54 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

# define UPP_HEX "0123456789ABCDEF"
# define LOW_HEX "0123456789abcdef"

char	*ft_ltoh(unsigned long value, const char *charset);

int		ft_vfprintf(int fd, const char *format, va_list args);
int		ft_vprintf(const char *format, va_list args);

int		ft_fprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
