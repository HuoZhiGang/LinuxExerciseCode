/*************************************************************************
#	> File Name: test_fork.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Sat 25 Feb 2017 12:58:04 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int glob = 6;
char buf[] = "a write to stdout\n";
int main()
{
	int var = 88;
	
	if(write(1, buf, sizeof(buf)-1) != sizeof(buf)-1)
	{
		printf("write error!\n");
		exit(1);
	}
	printf("before fork :\n");
	pid_t pid = fork();
	if(pid < 0){
		printf("fork error\n");
		exit(2);
	}else if (pid == 0){
		glob++;
		var++;
	}
	else
	{
		sleep(2);
	}

	printf("pid: %d ,glob: %d ,var: %d\n", getpid(), glob, var);
	return 0;
}
