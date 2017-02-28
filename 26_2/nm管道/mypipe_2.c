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

		while(count--)
		{
			write(mypipe[1], msg, strlen(msg) + 1);
			sleep(1);  
			if(count == 0)
			{
				sleep(5);   //此时文件描述符没关闭 也不写数据 
				count = 3; //5s 后读端继续读取 
			}
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
			ssize_t _s = read(mypipe[0], buf, sizeof(buf));//父进程一直读取  子进程slep时 父进程等待 sleep结束子进程开始写 父进程继续读取 
			if( _s > 0)
			{ // read sucess
				printf("%d: child -> father: %s \n", count ,buf);
			}
			else if (_s == 0) 
			{
				printf(" end of file  read return is %d\n", _s);
				break;
			}
		}	

	}
	return 0;
}
