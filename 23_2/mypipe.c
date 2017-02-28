/*************************************************************************
#	> File Name: mypipe.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 22 Feb 2017 05:38:14 PM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int pipefd[2] = {0,0}; // [0] read  [1] write

	//create a pipe
	//syns auto 匿名管道  自动同步  读写速度一致
	if(pipe(pipefd)<0) // sucess ret 0  failed ret -1
	{
		perror("pipe");
		return;
	}
	//create a process 
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return;
	}
	else if(id == 0)
	{// child write
		close(pipefd[0]);	
		const char* msg = "hello,bit";
		int count = 5;
		while(count)
		{
			write(pipefd[1], msg, strlen(msg));
			count--;
			if(count == 0)
			{
				count--;
			}
			sleep(1);
		}

		close(pipefd[1]);
		exit(0);
	}
	else
	{// father read

		close(pipefd[1]);	

		int count = 5;
		char buff[128];
		while(count)
		{
			ssize_t _s = read(pipefd[0], buff, sizeof(buff)-1); 
			if(_s > 0)
			{
				buff[_s] = '\0';
				printf("%d:,child->father:%s\n",count, buff);
			}
			else if (_s == 0)
			{
				printf("pipe write is close\n");
				break;
			}
			count--;

		}
		close(pipefd[0]);
	}

	return 0;
}
