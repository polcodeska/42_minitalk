/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:09:59 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:36:20 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int			src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (*src && --size)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_len);
}
