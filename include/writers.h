/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:36:53 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/14 10:42:25 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITERS_H
# define WRITERS_H

# define UPP_HEX "0123456789ABCDEF"
# define LOW_HEX "0123456789abcdef"

char	*ft_ltoh(unsigned long value, const char *charset);
char	*ft_ultoa(unsigned long value);
#endif
