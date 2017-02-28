/*************************************************************************
	> File Name: proc_bar.c
	> Author: huozhigang
	> Mail: 495080640@qq.com 
	> Created Time: Thu 16 Feb 2017 02:15:49 AM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h> // sleep() 以秒睡眠  usleep()以微秒睡眠 1s = 10^6ms 

void proc_bar()
{
	int count = 0; // 记录百分比数
	char buf[102]={'\0'};  // 存储0 - 100  101个‘#’ 和 '\0'
	const char* stat = {"-\\|/"}; // 存储标志正在工作 假装在“旋转“
	while( count<=100 )
	{
		// -101 是为了固定两个括号之间的距离不变
		printf("[%-101s][%%%d]%c\r",buf, count, stat[count%4]);
		fflush(stdout); // 刷新缓冲区
		buf[count++] = '#';
		usleep(100000);

	}
	printf("\n");
}

int main()
{
	proc_bar();
	return 0;
}
