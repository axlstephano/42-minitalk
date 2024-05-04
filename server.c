/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:21:54 by axcastil          #+#    #+#             */
/*   Updated: 2024/05/04 17:21:55 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./42_collection/ft_printf.h"
#include "./42_collection/libft.h"

void	sig_usr(int sig)
{
	static char	letter;
	static int	number;
	static int	bit;

	if (number == 0)
		bit = 7;
	if (sig == SIGUSR1)
		letter |= (1 << bit);
	else if (sig == SIGUSR2)
		letter &= ~(1 << bit);
	number++;
	bit--;
	if (number == 8)
	{
		write(1, &letter, 1);
		letter = 0;
		number = 0;
	}
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
	while (1)
	{
		signal(SIGUSR1, &sig_usr);
		signal(SIGUSR2, &sig_usr);
		sleep(1);
	}
}
