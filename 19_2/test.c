/*************************************************************************
	> File Name: test.c
	> Mail: 495080640@qq.com 
	> Created Time: Sat 18 Feb 2017 11:07:21 PM PST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>

void fun()
{
	printf("this is fun !\n");
}

int main()
{

	// 有博客作业验证 
	atexit(fun);// 结束后做一些清理工作
	printf("register done ... \n");
	sleep(5);
	exit(0);

	// 测试 _exit
	//printf("222");
	//sleep(5);
	//_exit(0);// 退出不会回收数据


// 测试孤儿进程
//	pid_t id = fork();
//	if(id == 0){
//		printf("child:%d, %d\n", getpid(), getppid());
//		while(1);
//	}
//	else{
//		printf("father:%d, %d \n", getpid(), getppid());
//		exit(1);
//		//sleep(3);
//	}
//
	return 0;
}
