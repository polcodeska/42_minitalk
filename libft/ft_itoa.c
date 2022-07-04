/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:49:09 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:32:34 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_char_count(int n);

char	*ft_itoa(int n)
{
	char	*r;
	int		i;

	i = ft_get_char_count(n);
	r = malloc(i);
	if (!r)
		return (NULL);
	*(r + --i) = '\0';
	if (n == 0)
		*(r + --i) = '0';
	else if (n < 0)
		*r = '-';
	while (n != 0)
	{
		if (n < 0)
			*(r + --i) = -(n % 10) + '0';
		else
			*(r + --i) = (n % 10) + '0';
		n = n / 10;
	}
	return (r);
}

static int	ft_get_char_count(int n)
{
	int	counter;

	counter = 1;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}
