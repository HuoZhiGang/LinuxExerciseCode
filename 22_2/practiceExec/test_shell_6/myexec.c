/*************************************************************************
#	> File Name: myexec.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 23 Feb 2017 03:19:42 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


int main()
{
	pid_t id = fork();

	if(id < 0)
	{// create failed
		printf("create child failed\n");
		exit(1);
	}
	else if(id == 0)
	{// child
		printf("I am child process!\n");
		sleep(3);
		char* const  myargv[]={"ls", "-l", "-h", NULL};
		//execv("bin/ls",myargv);
		char* const myenv[] = {
			"MYPATH=/ADASD/ADSADSAD/SADSD",NULL
	};

		// 谁再给NULL加引号 谁是孙子！！！！！
		execle("./other","other",NULL, myenv);
		exit(2);
	}
	else
	{// father
		int status = 0;
		pid_t ret = waitpid(id,&status,0);
		
		if(ret>0)
		{// waitpid sucess
			printf("wait sucessf status: %d, %d!\n ", WEXITSTATUS(status), (status>>8)&0xff );
			exit(3);
		}
		else
		{// waitpid failed
			printf("wait failed!\n ");
			exit(4);
		}
	}

	return 0;
}
