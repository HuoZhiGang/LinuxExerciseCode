#include "comm.h"

int main()
{
	int msgid =  createMsgQueue();
	printf("msgid : %d \n", msgid);
	long type = SERVER_TYPE; 
	const char *msg = "hello";
	char buf[SIZE];
	while(1)
	{
		while(1)
		{
			int rec_int = recvMsg(msgid, CLIENT_TYPE, buf);
			if(rec_int!= -1)
				break;
		
		    printf("	client#%s \n", buf);
		    fflush(stdout);
		    printf("Pelase Enter$");
		    fflush(stdout);
		    ssize_t _s  = read(0, buf, sizeof(buf)-1);
		    if(_s>0)
		    {
		    	buf[_s-1] = '\0';
		    	sendMsg(msgid,SERVER_TYPE, buf);
		    }
		}
		if(strcmp(buf, "exit") == 0)
			break;

	}

	destroyMsgQueue(msgid);

	return 0;
}
