/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 09:48:28 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/08 10:13:36 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPS_HPP
# define WRAPS_HPP
# include <cstddef>

extern size_t			g_malloc_fail_at;

extern "C" {
	void	*__real_malloc(size_t size);
	void	__real_free(void *ptr);

	void		*__wrap_malloc(std::size_t size);
	void		__wrap_free(void *ptr);
}

#endif
