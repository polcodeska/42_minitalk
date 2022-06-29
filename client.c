/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:23:41 by tmasur            #+#    #+#             */
/*   Updated: 2022/06/29 16:31:16 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char_via_sig(char a, int bits, int pid)
{
	while (bits > 0)
	{
		if (a & (char)128)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(1);
		a <<= 1;
		bits--;
	}
}

void	send_str_via_sig(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char_via_sig(str[i++], 8, pid);
		printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	send_str_via_sig(argv[2], atoi(argv[1]));
	return (0);
}
