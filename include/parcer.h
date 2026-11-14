/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:06:43 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/14 10:42:01 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCER_H
# define PARCER_H

# include "libft.h"
# include <stdarg.h>

enum e_type
{
	STR,
	CHR,
	INT,
	UINT,
	PTR,
	LOW_X,
	UPP_X,
	ERROR,
	PERCENT
};

typedef struct s_print
{
	enum e_type	type;
	char		*data;
	int			size;
}	t_print;

int			correct_node(t_list *node);
void		free_node(void *node);
t_list		*printf_cleanup(t_list **lst);
char		*handle_ptr(void *arg);
enum e_type	set_arg(const char *str);
enum e_type	get_arg(const char *str, char **data, va_list args);
t_print		*create_arg_node(const char *str, va_list args, size_t *head_pos);
t_print		*create_str_node(const char *str, int start, int end);
t_list		*parcer(const char *str, va_list args);
#endif
