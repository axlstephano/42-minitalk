#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	sig_usr(int sig)
{
	static char	c = 0;
	static int	bit = -1;

	if (bit < 0 && !c)
		printf("\nClient say : ");
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else if (sig == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		write(1, &c, 1);
	bit--;
}

int	main(void)
{
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	printf("pid: %d", getpid());
	while (1)
		sleep(1);
}

/*    printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
    printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
    printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
    printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
    printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
    printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");*/