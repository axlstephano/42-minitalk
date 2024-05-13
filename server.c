/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:21:54 by axcastil          #+#    #+#             */
/*   Updated: 2024/05/13 19:47:19 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./42_collection/ft_printf.h"
#include "./42_collection/libft.h"
#include <signal.h>
#include <stdlib.h>

void	sig_handler(int signal, siginfo_t *pid, void *opcional)
{
	static char	letter;
	static int	bit = -1;
	static int	sigusr;
	
	(void)opcional;
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(char) - 1;
	if (kill(pid->si_pid, 0) < 0)
		exit(1);
	if (signal == SIGUSR1)
		sigusr = 1;
	else if (signal == SIGUSR2)
		sigusr = 0;
	letter = (letter << 1) + sigusr;
	if (!bit && letter)
		ft_putchar_fd(letter, 1);
	else if (!bit && !letter)
		kill(pid->si_pid, SIGUSR2);
	bit--;
	kill(pid->si_pid, SIGUSR1);
}

void	sigaction_set(int signal, void (*signal_handler)(int, siginfo_t *, void *))
{
	struct sigaction susr;

	susr.sa_sigaction = signal_handler;
	susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;	
	sigemptyset(&susr.sa_mask);
	if (signal == SIGUSR1)
		sigaction(SIGUSR1, &susr, 0);
	else if(signal == SIGUSR2)
		sigaction(SIGUSR2, &susr, 0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	ft_printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
	ft_printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	ft_printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	ft_printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
	ft_printf("\t\t\tpid: %d\n", pid);
	sigaction_set(SIGUSR1, &sig_handler);
	sigaction_set(SIGUSR2, &sig_handler);
	while (1)
		sleep(1);
}