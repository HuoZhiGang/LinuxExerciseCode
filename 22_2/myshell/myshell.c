/*************************************************************************
#	> File Name: myshell.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 23 Feb 2017 05:23:22 AM PST
 ************************************************************************/

#include<stdio.h>
#include<ctype.h> // isspace()
#include<stdlib.h> // exit()  fflush();
#include<sys/wait.h> // waitpid()
#include<unistd.h> // execvp // 需要 argv  和 命令 不需要  

int main()
{
	char buf[128]; // save input
	while(1)
	{
		char path[100];
	
		gethostname(path, sizeof(path));
		printf("[test@%s ~]$", path);
		fflush(stdout);
		ssize_t _s = read(0, buf, sizeof(buf)-1);	
		if(_s >0)
		{// read sucess
			buf[_s-1] = '\0';
		}
		else
		{// read failed
			printf("read!\n");
			return 1;
		}
		
		char* myargv[32];// get command
		myargv[0] = buf;
		int index = 1;
		char* start = buf;
		while(*start)
		{
			if(isspace(*start))
			{
				*start = '\0';
				start++;
				myargv[index] = start;
				index++;
			}
			else
			{
				start++;
			}
		}


		myargv[index] = NULL;
		pid_t id = fork();
		if(id < 0 )
		{
			printf("create failed\n");
			return 2;
		}
		else if(id == 0)
		{//child
			execvp(myargv[0], myargv);
			printf("command not found\n");
			return 3;
		}
		else
		{// father
			int status = 0;
			ssize_t ret = waitpid(id, &status, 0);					
			if(ret > 0 && WIFEXITED(status))
			{
				//printf("wait sucess ;status:%d \n", WEXITSTATUS(status));
			}
			else
			{
				perror("waitpid");
			}
		}
	}
	return 0;
}
