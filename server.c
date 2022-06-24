#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void)
{
	pid_t pid = getpid();
	printf("%d\n", pid);
	return (0);
}
