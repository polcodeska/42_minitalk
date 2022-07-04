/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:02:55 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:33:22 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*r;

	if (!dest && !src)
		n = 0;
	r = dest;
	if (dest < src)
		while (n--)
			*(char *)dest++ = *(char *)src++;
	else
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	return (r);
}
