#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void    sig_handler(int signal, siginfo_t *info)
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
    else if(signal == SIGUSR2)
        printf("0\n");
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
}

void	init_sig(int sig, void (*handler)(int, siginfo_t *))
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

