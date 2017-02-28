/*************************************************************************
#	> File Name: kejianP2.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Sun 19 Feb 2017 08:22:05 PM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
int main()
{
	uid_t uid;
	uid_t euid;
	pid_t pid;
	pid_t ppid;
	if(pid < 0 )
	{
		printf("%d\n",errno);
		exit(2);
	}
	else if(pid == 0)
	{
		uid = getuid();
		euid = geteuid();
		printf("child->pid:%d, ppid%d, iud:%d, euid:%d\n",getpid(), getppid(), uid, euid);
		exit(0);
	}
	else
	{
		uid = getuid();
		euid = geteuid();
		printf("Father->pid:%d, ppid%d, iud:%d, euid:%d\n",getpid(), getppid(), uid, euid);
		sleep(2);
	}
	return 0;
}
