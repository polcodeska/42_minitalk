/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:42:09 by tmasur            #+#    #+#             */
/*   Updated: 2022/01/18 23:34:57 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_substrings(const char *s, char c);
static char	*ft_get_substring(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	char	**r;

	if (!s)
		return (NULL);
	r = malloc((ft_count_substrings(s, c) + 1) * sizeof(char *));
	if (!r)
		return (NULL);
	tmp = r;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			*(tmp++) = ft_get_substring(s, c);
		while (*s != c && *s)
			s++;
	}
	*tmp = NULL;
	return (r);
}

static int	ft_count_substrings(const char *s, char c)
{
	int		counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

static char	*ft_get_substring(char const *s, char c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*s != c && *s)
	{
		s++;
	}
	return (ft_substr(tmp, 0, s - tmp));
}
