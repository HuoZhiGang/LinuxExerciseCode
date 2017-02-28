/*************************************************************************
#	> File Name: other.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 23 Feb 2017 04:56:46 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("I am a other pricess!, MYPATH:%s\n", getenv("MYPATH"));
	return 0;
}
