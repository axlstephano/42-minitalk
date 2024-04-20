#include "./42_collection/ft_printf.h"
#include "./42_collection/libft.h"

//sigusr1 = 1
//sigusr2 = 0

static void	send_char(char c, pid_t pid)
{
	int bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while(bit >= 0)
	{
		if(kill(pid, 0) < 0)
			exit(1);
		if(c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
	}
}

static void	send_str(char *str, pid_t pid)
{
	while(*str)
		send_char(*str++, pid);
	send_char('\0', pid);
}

int main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("¡ARGUMENTS ARE MISSING :3");
		return(1);
	}
	pid = atoi(argv[1]);
	send_str(argv[2], pid);
	return(0);
}