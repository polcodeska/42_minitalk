/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:23:21 by tmasur            #+#    #+#             */
/*   Updated: 2022/07/04 08:50:09 by tmasur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	sighandler(int signum,
			siginfo_t *info __attribute__((unused)),
			void *context __attribute__((unused)));
void	send_char_via_sig(char a, int bitwidth, int pid);
void	send_str_via_sig(char *str, int pid);
#endif
