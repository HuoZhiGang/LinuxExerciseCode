/*************************************************************************
#	> File Name: wait2.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 22 Feb 2017 11:25:29 PM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h> // fork()
#include<sys/types.h> // getpid() getpid
#include<sys/wait.h>
#include<stdlib.h> // exit()
int main()
{
	pid_t pc, pr;
	pc = fork();
	if(pc < 0)
	{
		printf("fork error!\n");
		exit(0);
	}
	else if(pc == 0) //child
	{
		printf("This is child process with pid of %d\n", getpid());
		sleep(30);
		exit(3);
	}
	else // father
	{
		/*如果wait()的参数值不是NULL， wait 就会把子进程退出时的状态取出并存入其中，
		 * 这是一个整数值（int） 指出了子进程是正常退出还是被非正常结束的
		 * 由于这些信息被存放在一个整数的不同二进制位中，所以就专门设计了一套宏来完成
		 * WIFEEXITED(status)这个宏指出子进程是否为正常退出的，如果是会返回一个非零值
		 * WEXITSTATUS(status)当WIFEXITED返回非零值的时候，我们可以用这个宏来提取
		 * 子进程的返回值，如果子进程调用exit(5) 就会返回5 
		 * 如果进程不是正常退出的 也就是说，WIFEXITED返回0 那么这个值无意义
		 * */
		int status;

		pr = wait(&status);
		if(WIFEXITED(status))  // 返回值不为0 表示是正常退出
		{// 子进程正常退出 WIFEXITED 返回1
			printf("The child process %d exit normally\n", pr);
			printf("The WEXITSTATUS return code is %d\n", WEXITSTATUS(status) );
			printf("The WIFEXITED return code is %d  \n", WIFEXITED(status));
		}
		else
		{
			printf("Ther child process %d exit abbormally.\n", pr);
			printf("Stutus is %d \n", status);
		}
		sleep(5);
	}
	return 0;
}
