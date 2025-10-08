#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif
#include <stdio.h>

#if defined(_WIN32)
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRNO() (WSAGEtLastError())

#else
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {

#if defined(_WIN32)
	WSADATA d;
	if (WSAStartup(MAKEWORD(2,2), &d)) {
		fprintf(stderr, "Failed to initialize. \n");
		return 1;
	}
#endif
	printf("Configuring local addresses...\n");
	struct addrinfo hints; // It tells information about the socket
	memset(&hints, 0, sizeof(hints)); // it sets all the memory value to zero
	hints.ai_family = AF_INET; // it ensures we're using IPv4
	hints.ai_socktype = SOCK_STREAM; // Using this for TCP connections. 
					 // (SOCK_DRAM for UDP)
	hints.ai_flags = AI_PASSIVE; // set up the addresses, we listen on any available
				     // interface

	struct addrinfo *bind_adress;
	getaddrinfo(0, "8080", &hints, &bind_address);

	printf("Creating socket...\n");
	SOCKET socket_listen;
	socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype,
			bind_address->ai_protocol);
	
	if (!ISVALIDSOCKET(socket_listen) {
			fprintf(stderr, "socket() failed", GETSOCKETERRNO());
			return 1;
			}
	printf("Binding socket to local address...\n");
	if (bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen)){
		fprintf(stderr, "bind() failed. {%d}\n", GETSOCKETERRNO());
		return 1;
	}
	freeaddrinfo(bind_address);

	printf("Client is connected");
	char address_buffer[100];
	getnameinfo((struct sockaddr*)&client_address,
		client_len, address_buffer, sizeof(address_buffer), 0, 0, NI_NUMERICHOST)
	printf("%s\n", address_buffer)
	



	
	








}
