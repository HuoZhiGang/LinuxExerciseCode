/*************************************************************************
#	> File Name: myexec.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 23 Feb 2017 03:07:02 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h> // exit()
#include<unistd.h> // execl  execle execlp execv execvp

int main()

{
	//pid_t id = fork();
	printf("heiheihei\n ");
	execl("/bin/ls","ls", "-a", "-i", NULL);
	printf("You can't see me!\n'");
	return 0;
}
