#include <stdio.h>
#include <signal.h>

int main()
{
	sigset_t new_mask;

	sigfillset(&new_mask); // {SIGINT, SIGUSR1, SIGUSR2, ...}

	sigdelset(&new_mask, SIGUSR1); // {SIGINT, SIGUSR2, ...}

	sigsuspend(&new_mask);
}
