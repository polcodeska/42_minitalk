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

char	get_char_to_send(char **message_to_send)
{
	if (!**message_to_send)
		exit (0);
	return ((*(*message_to_send)++));
}

int		is_bit_to_send_one(char *c)
{
	int	bit;

	bit = *c & 128;
	*c <<= 1;
	return (bit);
}

void send_bits(pid_t pid, char *message)
{
	static pid_t pid_s;
	static char *message_to_send;
	static char char_to_send;
	static int bit_to_send = 8;

	if (pid)
		pid_s = pid;
	if (message)
		message_to_send = message;
	if (bit_to_send == 8)
		char_to_send = get_char_to_send(&message_to_send);
	if (--bit_to_send == 0)
		bit_to_send = 8;
	if (is_bit_to_send_one(&char_to_send))
		kill(pid_s, SIGUSR1);
	else
		kill(pid_s, SIGUSR2);
}

void	sighandler(int signum,
			siginfo_t *info __attribute__((unused)),
			void *context __attribute__((unused)))
{
	if (signum == SIGUSR1)
		send_bits(0, 0);
}

int	main(int argc, char *argv[])
{
	struct sigaction my_sigact;

	my_sigact.sa_handler = 0;
	sigfillset(&my_sigact.sa_mask);
	my_sigact.sa_sigaction = sighandler;
	my_sigact.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &my_sigact, NULL) == -1)
		perror("SIGACTION");
	if (argc != 3)
		return (0);
	send_bits(atoi(argv[1]), argv[2]);
	while (pause())
		;
	return (0);
}
