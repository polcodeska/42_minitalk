/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:24:51 by tmasur            #+#    #+#             */
/*   Updated: 2022/07/04 10:05:00 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = 0;
	sigfillset(&sa.sa_mask);
	sa.sa_sigaction = sighandler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
		sigaction(SIGUSR2, &sa, NULL) == -1)
		perror("SIGACTION");
	while (pause())
		;
	return (0);
}

void	sighandler(int signum, siginfo_t *info,
			void *context __attribute__((unused)))
{
	static char	c = 0;
	static int	bits_need = 8;

	if (signum == SIGUSR1)
		c |= 1;
	if (--bits_need > 0)
		c <<= 1;
	else
	{
		write(1, &c, 1);
		bits_need = 8;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
