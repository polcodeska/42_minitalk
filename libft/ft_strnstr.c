/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:30:06 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:37:10 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (*(s1 + i) && i < n)
	{
		j = 0;
		while (*(s1 + i + j) && i + j < n && *(s1 + i + j) == *(s2 + j))
		{
			if (!*(s2 + j + 1))
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
