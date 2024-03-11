#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/* void    sig_handler(int signal, siginfo_t *info)
{
    static char c;
    static int  i;

    c = 0;
    i = -1;
    if(kill(info->si_pid, 0) < 0)
        exit(1);
    if(i < 0)
        i = 7;
    if(signal == SIGUSR1)
        printf("1\n");
        //c |= (1 << i);
    else if(signal == SIGUSR2)
        printf("0\n");
        //c |= (0 << i);
    if(i == 0 && c != '\0')
        write(1, &c, 1);
    else if(i == 0 && c == '\0')
        kill(info->si_pid, SIGUSR2);
    i--;
    kill(info->si_pid, SIGUSR1);
}

int main()
{
    signal(SIGUSR1, &sig_handler);
    signal(SIGUSR2, &sig_handler);
    printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
    printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
    printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
    printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
    printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
    printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
    printf("\t\tPID: %d\n", getpid());
    while(1)
        sleep(1);
} */

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	susr;

	susr.sa_sigaction = handler;
	susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&susr.sa_mask);
	if (sig == SIGUSR1)
		sigaction(SIGUSR1, &susr, 0);
	else if (sig == SIGUSR2)
		sigaction(SIGUSR2, &susr, 0);
}


void	sig_usr(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = -1;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		printf("ERROR : cant send sig to pid : %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
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
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	init_sig(SIGUSR1, &sig_usr);
	init_sig(SIGUSR2, &sig_usr);
	printf("pid: %d\n", getpid());
	while (1)
		sleep(1);
}
