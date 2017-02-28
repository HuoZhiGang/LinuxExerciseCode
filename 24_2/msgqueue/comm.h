/*************************************************************************
#	> File Name: comm.h
# Author: HuoZG
# mail:248786797@qq.com
# Created Time: Thu 23 Feb 2017 07:35:39 PM PST
 ************************************************************************/

#ifndef _COMM_H_
#define _COMM_H_

int commMsgQueue(int flags);
int createMsgQueue();
int getMsgQueue();
int sendMsg();
int recvMsg();
int destroyMsgQueue(int msgid);

#endif
