#include <iostream>
#include <sys/types.h>		// getaddrinfo
#include <sys/socket.h>		// getaddrinfo
#include <netdb.h>			// getaddrinfo
#include <sys/types.h>		// sockets && bind
#include <sys/socket.h>		// sockets && bind
#include <cstring>
#include <arpa/inet.h>		// inet_ntop
#include <unistd.h>

using std::cout;
using std::endl;
using std::string;

#define SERVER_ADDRESS "192.168.173.10"
#define SERVER_PORT    "27015"

int main(int argc, char const *argv[])
{
	int status;
	int socket_res;
	int connect_res;
	struct addrinfo hints;
	struct addrinfo* servinfo, *p;
	char ipstr[INET6_ADDRSTRLEN];

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;			// AF_INET - it's IPv4
	hints.ai_socktype = SOCK_STREAM;	// stream sockets - using the TCP protocol
	//hints.ai_flags = AI_PASSIVE;		// assign the localhost to the servinfo structs || hardcode an IP

	// hardcode an IP instead of NULL if no IP is set in the ai_flags param
	// the client will actually hardcode an address that it wants to connect to
	status = getaddrinfo(SERVER_ADDRESS, SERVER_PORT, &hints, &servinfo);
	if (0 != status)
	{
		cout << "getaddrinfo() ERROR - " << gai_strerror(status) << endl;
	}

	// Print all of the addresses found by the getaddrinfo
	for(p = servinfo;p != NULL; p = p->ai_next) {
        void *addr;
        char *ipver;

        // get the pointer to the address itself,
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
        addr = &(ipv4->sin_addr);
        ipver = "IPv4";

        // convert the IP to a string and print it:
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("  %s: %s\n", ipver, ipstr);
    }

    /* Create the socket descriptor */
    socket_res = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (-1 == socket_res)
    {
    	cout << "Socket creation - error!\n";
    }

    /* Bind the socket to a port provided by the OS */
    connect_res = connect(socket_res, servinfo->ai_addr, servinfo->ai_addrlen);
    if (-1 == connect_res)
    {
    	cout << "Connection - error\n";
        return 0;
    }
    cout << "Connected!\n";

    /* Receive an ACK from the server */
    int recv_res = 0;
    char recv_buf[50];
    std::string send_to_server;

    recv_res = recv(socket_res, recv_buf, 50, 0);
    if (recv_res > 0)
    {
        printf("First message from the server: %s\n", recv_buf);
    }

    while (send_to_server != "Bye!")
    {
        cout << "Enter msg: ";
        getline(std::cin, send_to_server);

        send(socket_res, send_to_server.c_str(), send_to_server.size(), 0);

        memset(recv_buf, 0, sizeof(recv_buf));
        recv_res = recv(socket_res, recv_buf, 50, 0);

        if (recv_res > 0)
        {
            printf("From the server: %s\n", recv_buf);
        }
    }
    

    close(socket_res);

	freeaddrinfo(servinfo);		// frees the linked list returned by getaddrinfo

	return 0;
}