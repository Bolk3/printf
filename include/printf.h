/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:00:18 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/14 10:42:58 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

int				ft_vfprintf(int fd, const char *format, va_list args);
int				ft_vprintf(const char *format, va_list args);
int				ft_fprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
#endif
