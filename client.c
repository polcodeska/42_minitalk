#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	send_char_via_sig(char a, int bitwidth, int pid)
{
	while (bitwidth > 0)
	{
		if (a & (char)128)
		{
			kill(pid, SIGUSR1);
			printf("+");
		}
		else
		{
			kill(pid, SIGUSR2);
			printf("-");
		}
		usleep(1);
		a <<= 1;
		bitwidth--;
	}
}

void	send_str_via_sig(char *str, int pid)
{
  int i;

  i = 0;
  while (str[i])
  {
      send_char_via_sig(str[i++], 8, pid);
	  printf("\n");
  }
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);

	send_str_via_sig(argv[2], atoi(argv[1]));
	return (0);
}
