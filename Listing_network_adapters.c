#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct ifaddrs *addresses; // store the addresses				   
	if (getifaddrs(&addresses) == -1) { // Error verification
		printf("getifaddrs call failed!");
		return -1;
	}

	struct ifaddrs *address = addresses; 
	while(address){
		int family = address->ifa_addr->sa_family; //address family (IPv4 or v6)						//'Cause getifaddrs() can return other types
		if (family == AF_INET || family == AF_INET6){ // It helps to define wheter
			printf("%s\t", address->ifa_name);
			printf("%s\n", family == AF_INET ? "IPv4" : "IPv6");


			char ap[100];
			const int family_size = family == AF_INET ?
				sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
			getnameinfo(address->ifa_addr, family_size, ap, sizeof(ap), 0, 0,
					NI_NUMERICHOST);	
		}
		address = address->ifa_next;
	}

}
