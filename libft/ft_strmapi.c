/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:51:44 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:36:45 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r1;
	char			*r2;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	r1 = malloc(ft_strlen(s) + 1);
	if (!r1)
		return (NULL);
	r2 = r1;
	i = 0;
	while (*(s + i))
	{
		*r1++ = (*f)(i, *(s + i));
		i++;
	}
	*r1 = '\0';
	return (r2);
}
