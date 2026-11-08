/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:00:47 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/08 11:06:07 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <libft.h>

void	ft_putptr(int fd, void *ptr)
{
	if (!ptr)
		ft_putstr_fd(fd, "(nil)");
	else
		ft_putlowhex_fd(fd, (unsigned long)&ptr);
}
