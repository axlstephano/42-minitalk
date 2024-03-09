#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void	send_char(char c, pid_t pid)
{
	int	i; 
	
	i = 7;
	while(i >= 0)
	{
		if(kill(pid, 0) < 0)
			exit(1);
		if(c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		//crear bucle para confirmacion de envío con **variable global**
	}
}

static void	send_str(char *str, pid_t pid)
{
	while(*str)
	{
		send_char(*str, pid);
		str++;
	}
	send_char('\0', pid);
}

static void	signal_handler(int signal)
{

}

int main(int argc, char **argv)
{
	pid_t pid;

	if (argc != 3)
	{
		printf("¡ARGUMENTS ARE MISSING :3");
		return(1);
	}
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	pid = atoi(argv[1]);
	send_str(argv[2], pid);
	while(1)
		sleep(1);
}