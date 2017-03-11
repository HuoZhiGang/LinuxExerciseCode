#include "comm.h"

void server()
{
	int msgid =  getMsgQueue();
	printf("msgid : %d \n", msgid);
	char buf[SIZE];
	while(1)
	{
		while(1)
		{
		    printf("Pelase Enter$");
		    fflush(stdout);
		    ssize_t _s  = read(0, buf, sizeof(buf)-1);
		    if(_s>0)
		    {
		    	buf[_s-1] = '\0';
		    	sendMsg(msgid,CLIENT_TYPE, buf);
		    }
		    int ret_int = recvMsg(msgid, 	SERVER_TYPE,buf);
		    if(ret_int != -1)
		    	break;
		    }
			printf("	server#%s \n", buf);
		    fflush(stdout);
	}
}


int main()
{
	server();
	return 0;
}
