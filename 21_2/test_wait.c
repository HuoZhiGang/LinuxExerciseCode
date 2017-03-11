/*************************************************************************
#	> File Name: test_wait.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Mon 20 Feb 2017 06:17:43 PM PST
 ************************************************************************/

#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t id = fork();

	if(id ==0 )
		while(1)
		{
			printf("child :pid : %d , ppid:%d \n", getpid(), getppid());
			sleep(1);
		}
	//{
	//	printf("child :pid : %d , ppid:%d \n", getpid(), getppid());
	//	
	//	sleep(5);
	//	printf("work is done,child begin work\n");
	//	exit(0);
	//}
	else
	{
		printf("father:pid:%d, ppid:%d\n", getpid(), getppid());
		int status  = 0;

		waitpid(id, &status, WNOHANG);
		do
		{
			printf("i am father, Tam reading again...\n");
			sleep(1);
		}while(waitpid(id, &status, WNOHANG));

	//	pid_t ret = waitpid(id, &status, 0);
	//	if(ret == id)
	//	{
	//		printf("wait is success... status code:%d, signal:%d\n",(status>>8)&0xff,status&0xff);
	//	}
	//	else
	//	{
	//		printf("wait is f%d\n",status);
	//	}

		//pid_t ret = wait(NULL);
		//if(ret == id)
		//{
		//	printf("wait is success\n");
		//}
		//else
		//{
		//	printf("wait is fail\n");
		//}
	}
	return 0;
}
