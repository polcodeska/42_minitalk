/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:49:09 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 20:30:44 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace_char(char c);

int	ft_atoi(const char *nptr)
{
	int	r;
	int	sign;

	r = 0;
	sign = 1;
	while (ft_is_whitespace_char(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		r = r * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * r);
}

static int	ft_is_whitespace_char(char c)
{
	int	r;

	r = 0;
	if (c == ' ' || c == '\t' || c == '\n')
		r = 1;
	else if (c == '\f' || c == '\r' || c == '\v')
		r = 1;
	return (r);
}
