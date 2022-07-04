/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:31:12 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:35:49 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r1;
	char	*r2;

	if (!s1 || !s2)
		return (NULL);
	r1 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r1)
		return (NULL);
	r2 = r1;
	while (*s1)
		*(r1++) = *s1++;
	while (*s2)
		*(r1++) = *s2++;
	*(r1) = '\0';
	return (r2);
}
