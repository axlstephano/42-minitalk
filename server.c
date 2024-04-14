#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	sig_usr(int sig)
{
	static char	c = 0;
	static int	bit = 7;

	if(sig == SIGUSR1)
		c |= (1 << bit);
	else if(sig == SIGUSR2)
		c &= ~(1 << bit);
	bit--;
	if(c && bit == 0)
	{
		write(1, &c, 1);
		bit = 7;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	signal(SIGUSR1, &sig_usr);
	signal(SIGUSR2, &sig_usr);
	printf("pid: %d", pid);
	while (1)
		sleep(1);
}

/*    printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
    printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
    printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
    printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
    printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
    printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");*/