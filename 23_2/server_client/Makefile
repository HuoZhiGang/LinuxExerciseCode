.PHONY:all
all:client server

client:client.c
	gcc -o $@ $^ #简写方法 
server:server.c
	gcc -o $@ $^ #简写方法 
.PHONY:clean
clean:
	rm -r server client fifo 
