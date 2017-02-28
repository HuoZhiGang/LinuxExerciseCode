/*************************************************************************
	> File Name: test_atexit.c
	> Author: HuoZG
	> Mail: 248786797@qq.com 
	> Created Time: Sun 19 Feb 2017 02:12:18 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void  fun1()
{
	printf("this is fun1 \n");
}

void  fun2()
{
	printf("this is fun2 \n");
}


int main()
{
	atexit(fun1);
	atexit(fun1);
	atexit(fun2);
	atexit(fun2);
	atexit(fun2);
	return 0;
}
