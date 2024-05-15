/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:22:02 by axcastil          #+#    #+#             */
/*   Updated: 2024/05/15 14:46:24 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_collection/ft_printf.h"
#include "42_collection/libft.h"

int		g_confirmation;

void	send_char(char letter, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(char) - 1;
	while (bit >= 0)
	{
		g_confirmation = 0;
		if ((letter >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_confirmation != 1)
			usleep(10);
	}
}

void	send_str(char *str, pid_t pid)
{
	int	cur;

	cur = 0;
	while (str[cur])
	{
		send_char(str[cur], pid);
		cur++;
	}
	send_char('\n', pid);
	send_char(0, pid);
}

void	sig_usr_handler(int signal)
{
	if (signal == SIGUSR1)
		g_confirmation = 1;
	else if (signal == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("¡ARGUMENTS ARE MISSING :3\n");
		return (1);
	}
	signal(SIGUSR1, &sig_usr_handler);
	signal(SIGUSR2, &sig_usr_handler);
	pid = ft_atoi(argv[1]);
	send_str(argv[2], pid);
	while (1)
		sleep(1);
}
