#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

struct proc* p;

int
main(int argc, char *argv[])
{
	int i;
	for (i=0; i<10; i++)
	{
		printf(1, "%d\n", i);
		sleep(100);
		if(i==5){
			printf(1, "saving\n");
			savestate();
			printf(1, "saved\n");
		}
	}
	exit();
}