/*************************************************************************
	> File Name: proc.c
	> Author: huozhigang
	> Mail: 495080640@qq.com 
	> Created Time: Sat 18 Feb 2017 12:20:33 AM PST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int g_val;

int main()
{
	
	pid_t id = fork();
	if(id == 0)
	{
		g_val = 100;
		printf("child, pid:%d, ppid:%d, data:%d ,addr:%p\n ", getpid(), getppid(), g_val, &g_val );
		printf("child is done \n");
		exit(1);
	}
	else
	{
		sleep(3);
		printf("father, pid:%d, ppid:%d, data:%d ,addr:%p\n ", getpid(), getppid(), g_val, &g_val );
	}
	exit(1);
	return 0;
}
