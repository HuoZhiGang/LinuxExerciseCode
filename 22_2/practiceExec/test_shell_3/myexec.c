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
	{// create failed
		printf("create child failed\n");
		exit(1);
	}
	else if(id == 0)
	{// child
		printf("I am child process!\n");
		sleep(3);
		char* const  myargv[]={"ls", "-l", "-h", NULL};
		execv("/bin/ls",myargv);
		exit(2);
	}
	else
	{// father
		pid_t ret = waitpid(id,NULL,0);
		
		if(ret>0)
		{// waitpid sucess
			printf("wait sucessf!\n ");
			exit(3);
		}
		else
		{// waitpid failed
			printf("wait failed!\n ");
			exit(4);
		}
	}

	return 0;
}
