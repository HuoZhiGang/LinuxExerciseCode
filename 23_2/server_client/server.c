/*************************************************************************
#	> File Name: server.c
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Wed 22 Feb 2017 07:08:26 PM PST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	umask(0);
	// int mkfifo(const char* pathname, mode_t mode); 路径和权限信息 success 0  failed -1
	// open  	
	// read()
	if(mkfifo("./fifo", 0666|S_IFIFO) < 0){
		perror("mkfifo");
		return 1;
	}
	


	int fd  = open("./fifo", O_RDONLY);
	if(fd  < 0){
		perror("open");
		return 2;
	}

	char buf[128];

	while(1){

		ssize_t s = read(fd, buf, sizeof(buf));
	    if(s>0){

  	  	   buf[s-1] = '\0';
  	  	   printf("client#%s\n", buf);
  	  }
  	  else if(s == 0){
  	    	printf("client quit! I should quit!\n");
  	  	    break;
  	  }
		else{
			perror("read");
		}
	}
	return 0;
}
