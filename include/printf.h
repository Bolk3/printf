/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:00:18 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/09 13:36:38 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

# define UPP_HEX "0123456789ABCDEF"
# define LOW_HEX "0123456789abcdef"

enum e_type {
	STR,
	CHR,
	INT,
	UINT,
	PTR,
	LOW_X,
	UPP_X,
	ERROR
};

typedef struct s_print 
{
	e_type	type;
	char	*data;
	int		size;
} t_print;

void			ft_putupphex_fd(int fd, unsigned long value);
void			ft_putlowhex_fd(int fd, unsigned long value);
void			ft_putptr_fd(int fd, void *ptr);
char			*ft_ltoh(unsigned long value, const char *charset);
char			*ft_ultoa(unsigned long value);

int				ft_vfprintf(int fd, const char *format, va_list args);
int				ft_vprintf(const char *format, va_list args);

int				ft_fprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);

#endif
