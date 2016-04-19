#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define port 9999
#define MAXLINE 10000
int main()
{
	char *IP= "127.0.0.1";

	struct sockaddr_in clientaddr, servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port= htons(port);
	inet_pton(AF_INET, IP , &servaddr.sin_addr);

	int sockfd= socket(AF_INET, SOCK_DGRAM , 0);

	char mssg[MAXLINE];
	for(;;)
	{
		socklen_t len= sizeof(servaddr);
		scanf("%s",mssg);
		sendto(sockfd, mssg, strlen(mssg),0, (struct sockaddr*)&servaddr,len);
		recvfrom(sockfd, mssg, MAXLINE, 0, (struct sockaddr*)&servaddr, &len);
		printf("%s\n",mssg);
	}

	return 0;
}