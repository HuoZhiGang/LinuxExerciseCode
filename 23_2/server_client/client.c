/*************************************************************************
#	> File Name: client.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 22 Feb 2017 07:08:36 PM PST
 ************************************************************************/

#include<stdio.h>
int main()
{
	char buf[128];
	while(1)
	{
		printf("Please Enter#");
		fflush(stdout);
		ssize_t s = read(0, buf, sizeof(buf));
		
		if(s>0)
		{
			buf[s-1] = '\0';
			write(fd,buf,strlen(buf));
		}
		else if(s == 0)
		{
			printf("error\n");
			break;
		}
		else
		{
			perror("read");
			return 3;
		}
	}
	return 0;
}
