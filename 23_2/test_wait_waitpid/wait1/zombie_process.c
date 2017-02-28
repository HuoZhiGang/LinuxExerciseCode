/*************************************************************************
#	> File Name: zomb_process.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 22 Feb 2017 10:03:31 PM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h> // fork()
#include<sys/types.h> // getpid()  getppid()
#include<sys/wait.h> // wait()
int main()
{
	pid_t pc, pr;
	pr = wait(NULL);
	pc = fork();// create process  // test 2
	
	if(pc < 0)// create process
		printf("error ocurred!\n");
	else if(pc == 0)
	{
		printf("Child pid %d,  Father pid %d  \n", getpid(), getppid());
		sleep(2);
	}
	else
	{// 当父进程忘了用wait 函数等待已终止的子进程时，子进程就会进入一种无父进程
	// 清理自己清理自己的尸体状态，此时子进程就是僵尸进程
	//	wait(NULL);// 加上次行说明以及被父进程wait 回收掉了 // test 1

		sleep(5);
		printf("ret wait:%d", pr);
	}
	
	return 0;
}
