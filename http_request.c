#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
	struct addrinfo hints, *res;
	int sockfd;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo("www.google.com", "80", &hints, &res);

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	connect(sockfd, res->ai_addr, res->ai_addrlen);
	
	char *msg = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\n";
	send(sockfd,msg,strlen(msg), 0);

	char buffer[1024];
	int bytes_received;
	printf("------- RESPOSTA ------");

	while ((bytes_received = recv(sockfd,buffer,sizeof(buffer) - 1, 0)) > 0) {
		buffer[bytes_received] = '\0';
		printf("%s", buffer);
			printf("\n \n");
	}

	close(sockfd);
	freeaddrinfo(res);
}
