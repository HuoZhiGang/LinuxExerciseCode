#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


int main()
{
	int _o = open("./fifo",O_WRONLY);
	if(_o == -1)
	{
		perror("open\n");
		return 2;
	}
		 
	
	char buf[128];
	while(1)
	{
		printf("请输入聊天内容：");
		fflush(stdout);
		ssize_t _s = read(0, buf, sizeof(buf));
		if(_s > 0)
		{
			buf[_s] = '\0';
			write(_o, buf,strlen(buf));
		}
	}
	close(_o);
	return 0;
}
