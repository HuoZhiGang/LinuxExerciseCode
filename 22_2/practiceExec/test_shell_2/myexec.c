/*************************************************************************
#	> File Name: myexec.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 23 Feb 2017 03:19:42 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


int main()
{
	pid_t id = fork();

	if(id < 0)
	{
		printf("create child failed\n");
		exit(1);
	}
	else if(id == 0)
	{
		printf("I am child process!\n");
		execl("/bin/ls","ls","-a","-h",NULL);
		sleep(3);
		exit(2);
	}
	else
	{
		pid_t ret = waitpid(id,NULL,0);
		
		if(ret>0)
		{
			printf("wait sucessf!\n ");
			exit(3);
		}
		else
		{
			printf("wait failed!\n ");
			exit(4);
		}
	}

	return 0;
}
