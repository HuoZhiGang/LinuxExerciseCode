/*************************************************************************
#	> File Name: waitpid.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 23 Feb 2017 12:58:10 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t pc, pr;
	pc = fork();

	if(pc < 0){
		printf("Error occured on forking\n");
	}
	else if(pc == 0){ // child
		sleep(10);
		return 0;
	}
	do
	{
		pr = waitpid(pc, NULL, WNOHANG);
		if(pr == 0)
		{
			printf("No Child exited\n");
			sleep(1);
		}
	}while(pr == 0);

	if(pr == pc)
	{
		printf("successfully get child %d\n", pr);
	}
	else
	{
		printf("some error occured\n");
	}
	return 0;
}
