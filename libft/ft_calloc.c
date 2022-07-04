/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:07:25 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:30:19 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	r = malloc(nmemb * size);
	if (!r)
		return (r);
	ft_bzero(r, nmemb * size);
	return (r);
}
