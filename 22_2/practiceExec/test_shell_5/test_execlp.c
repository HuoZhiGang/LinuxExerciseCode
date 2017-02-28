/*************************************************************************
#	> File Name: test_execlp.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 23 Feb 2017 04:16:27 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t id = fork();

	if(id < 0)
	{
		printf("creater failed!\n");
		exit(1);
	}
	else if(id == 0)
	{
		printf("I am child process!\n");
		sleep(2);
		execlp("ls","ls","-a",NULL);// 参数带p只需输入名字即可  会在环境变量中找
		exit(2);
	}
	else
	{
		int status = 0;
		pid_t ret = waitpid(id, &status,0);
		if(ret > 0)
		{
			printf("wait sucess! status:%d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("wait failed!\n");
			exit(3);
		}
	}

	return 0;
}
