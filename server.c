#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void        sighandler(int signum)
{
	static char	a = 0;
	static int	bitwidth = 8;

	if (signum == SIGUSR1)
		a |= 1;
	if (--bitwidth > 0)
		a <<= 1;
	else
	{
		write(1, &a, 1);
		bitwidth = 8;
		a = 0;
	}
}

int main(void)
{
	pid_t pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	write(1, "Läuft", 6);
	while (1);
	return (0);
}
