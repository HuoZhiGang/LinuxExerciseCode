/*************************************************************************
	> File Name: test_gdb.c
	> Author: huozhigang
	> Mail: 495080640@qq.com 
	> Created Time: Wed 15 Feb 2017 11:41:29 PM PST
 ************************************************************************/

#include<stdio.h>

int fun()
{
	int i = 0;
	int sum = 0;
	printf("This is fun fun!\n");
	for(; i <= 100; ++i){
		sum += i;
	}

	return sum;
}

int main()
{
	printf("This is fun main!\n");
	int sum = fun();
	printf("%d\n", sum);
	return 0;
}
