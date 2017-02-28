/*************************************************************************
#	> File Name: testMaxFork.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Sat 25 Feb 2017 01:31:23 AM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main()
{
	int count = 0;
	while(1)
	{

	
	pid_t id = fork();
	if(id < 0)
	{
		printf("create failed %d\n", count);
	}
	else if(id == 0 )
	{
		count++;
		printf("count: %d\n", count);
		
		sleep(100);
			
	}
	else
	{
		;
	}
	}
	return 0;
}
