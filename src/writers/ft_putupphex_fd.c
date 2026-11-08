/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupphex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:52:21 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/08 10:53:40 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

void	ft_putupphex_fd(int fd, unsigned long value)
{
	char	*result;

	result = ft_strjoin("0x", ft_ltoh(value, UPP_HEX));
	if (result)
		ft_putstr_fd(fd, result);
}
