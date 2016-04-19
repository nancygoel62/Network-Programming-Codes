//This the server side code using UDP Protocol - very simple one


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1000
#define port 9999
int main()
{

	struct sockaddr_in servaddr ,clientaddr ;

	bzero(&servaddr , sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(9999);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	int sockfd= socket(AF_INET, SOCK_DGRAM, 0);

	bind(sockfd, (struct sockaddr *)&servaddr , sizeof(servaddr));

	int n;
	socklen_t len;
	char mssg[MAXLINE];

	for(;;)
	{	
		scanf("%s", mssg);
		socklen_t len= sizeof(clientaddr);
		n=recvfrom(sockfd,mssg , MAXLINE,0,(struct sockaddr *)&clientaddr, &len);
		printf("%s", mssg);
	}


	return 0;
}
