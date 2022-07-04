/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:28:09 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:33:12 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*r;

	if (!dest && !src)
		n = 0;
	r = dest;
	while (n--)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (r);
}
