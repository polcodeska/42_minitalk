/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:23:21 by tmasur            #+#    #+#             */
/*   Updated: 2022/07/07 17:08:38 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

char	get_char_to_send(char **message_to_send);
int		is_bit_to_send_one(char *c);
void	send_bits(pid_t pid, char *message);
void	sighandler(int signum,
			siginfo_t *info __attribute__((unused)),
			void *context __attribute__((unused)));
#endif
