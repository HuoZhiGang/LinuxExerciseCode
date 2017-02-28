/*************************************************************************
	> File Name: stat.c
	> Author: huozhigang
	> Mail: 495080640@qq.com 
	> Created Time: Sat 18 Feb 2017 01:46:04 AM PST
 ************************************************************************/

#include<stdio.h>

#include<unistd.h>

int main()
{
	while(1)
		printf("hello bit%d\n", getpid());
	return 0;
}
