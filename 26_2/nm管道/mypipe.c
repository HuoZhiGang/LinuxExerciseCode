/*************************************************************************
#	> File Name: mypipe.c
# Author: HuoZG
# Created Time: Sat 25 Feb 2017 08:10:36 PM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>  // pipe()  fork()
#include<string.h>  // strlen()
#include<sys/wait.h>
#include<sys/types.h>

int main()
{

	int mypipe[2] = {0, 0};// [0] read [1]  write

	if(pipe(mypipe) < 0)
	{
		printf("pipe erroe!\n");
		return 1;
	}

	pid_t id = fork();

	if(id < 0)
	{
		printf("fork error!\n");
		return 2;
	}
	else if (id == 0)
	{ // child -> write 
		close(mypipe[0]);  // close read 

		const char * msg = "Hello World!";
		int count = 5;

		while(1)
		{
			write(mypipe[1], msg, strlen(msg) + 1);
			sleep(1);  
		}

	   	close(mypipe[1]);
	}
	else
	{ // father -> read
		close(mypipe[1]);   // close write
		int buf[128];
		int count = 5;
		while(1)   
		{
			count--;
			ssize_t _s = read(mypipe[0], buf, sizeof(buf)); 
			if( _s > 0)
			{ // read sucess
				printf("%d: child -> father: %s \n", count ,buf);
			}
			else if (_s == 0) 
			{
				printf(" end of file  read return is %d\n", _s);
				break;
			}
			if (count == 0)
			{
				close(mypipe[0]); //关闭读端
				break;
			}
		}	
		int status = 0;
		ssize_t ret = waitpid(id, &status, 0);
		if(ret>0 && WIFSIGNALED(status))// 等待子进程 成功且子进程异常终止为真
		{
			printf("status:%d\n", WTERMSIG(status)); //返回一个信号编号
		}

	}
	return 0;
}
