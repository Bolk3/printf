/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlowhex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:49:18 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/08 10:51:05 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <libft.h>

void	ft_putlowhex_fd(int fd, unsigned long value)
{
	char	*result;

	result = ft_strjoin("0x", ft_ltoh(value, LOW_HEX));
	if (result)
		ft_putstr_fd(fd, result);
}
