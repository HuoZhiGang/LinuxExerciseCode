#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


int main()
{
	umask(0);
	
	int _pipe = mkfifo("./fifo", 0666|S_IFIFO);
	if(_pipe < 0)
	{
		perror("mkfifo\n");
		return 1;
	}

	
	int _o = open("./fifo",O_RDONLY);
	if(_o == -1)
	{
		perror("open\n");
		return 2;
	}
		 
	
	char buf[128];
	while(1)
	{// server read
		ssize_t _s = read(_o, buf, sizeof(buf));
		if(_s > 0)
		{
			buf[_s-1] = '\0';
			printf("client #: %s\n", buf);

		}
		else if (_s == 0)
		{
			printf("client quit, I should quit!\n");
			break;
		}
		else
		{
			perror("read\n");
		}

	}
	close(_o);
	return 0;
}
