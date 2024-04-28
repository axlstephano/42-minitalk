#include "./42_collection/ft_printf.h"
#include "./42_collection/libft.h"

void	send_str(char *str, pid_t pid, int len)
{
	int	i;
	int	bit;

	i = 0;
	if(*str == 0)
	{
		ft_printf("empty string!!\n");
		exit (1);
	}
	while (i < len)
	{
		bit = __CHAR_BIT__ * sizeof(char) - 1;
		while(bit >= 0)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(50);
		}
		i++;
	}
}

//this works fine
int main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("¡ARGUMENTS ARE MISSING :3\n");
		return(1);
	}
	pid = atoi(argv[1]);
	argv[2] = ft_strjoin(argv[2], "\n");
	send_str(argv[2], pid, ft_strlen(argv[2]));
	free(argv[2]);
	return(0);
}
