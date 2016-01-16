#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

struct proc* p;

int
main(int argc, char *argv[])
{
	int pid = fork();
	if(pid == 0){
		// printf(1, "2: %d\n", getpid());
		int i;
		for (i=0; i<10; i++)
		{
			printf(1, "%d\n", i);
			sleep(100);
			if(i==3){
				printf(1, "%d: saving\n", getpid());

				savestate();

				printf(1, "%d: reloaded\n", getpid());
			}
		}
	} else {
		printf(1, "parent: %d\n", getpid());
		sleep(400);
		// wait();
		printf(1, "child saved\n");
		pid = reloadproc();
	}
	wait();
	wait();
	exit();
}