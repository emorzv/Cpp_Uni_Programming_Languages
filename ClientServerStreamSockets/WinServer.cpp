#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

using std::cout;
using std::endl;

#define SERVER_PORT		"27015"
#define SERVER_IP		"192.168.173.10"
#define MAX_CONNECTIONS	2
#define MAX_RECEIVE_LEN	50

int main() {
	/* Variable used to initialize the windows socket dll */
	WSADATA wsaData;

	int res = 0;
	struct addrinfo* result = NULL, * ptr = NULL, hints;

	/* MAKEWORD request a certain version of the winsock dll */
	res = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (0 != res)
	{
		cout << "Startup failed\n";
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;			// IPv4
	hints.ai_socktype = SOCK_STREAM;	// Stream sockets
	hints.ai_protocol = IPPROTO_TCP;	// TCP protocol

	/* Get the linked list with returned addresses */
	/* We provide hints parameters based on which the OS returns corresponding addresses */
	res = getaddrinfo(SERVER_IP, SERVER_PORT, &hints, &result);
	if (0 != res)
	{
		cout << "getaddrinfo failed - " << res << endl;
		WSACleanup();
		return 1;
	}

	/* Create the socket */
	SOCKET server_socket;

	/* Request the socket descriptor */
	server_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (INVALID_SOCKET == server_socket) 
	{
		cout << "Error at socket(): " << WSAGetLastError() << endl;
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	/* Bind the socket to a system address */
	res = bind(server_socket, result->ai_addr, (int)result->ai_addrlen);
	if (SOCKET_ERROR == res) 
	{
		cout << "bind failed with error: " << WSAGetLastError() << endl;
		freeaddrinfo(result);
		closesocket(server_socket);
		WSACleanup();
		return 1;
	}

	/* Since the binding has been successful, we free the address returned by getaddrinfo */
	freeaddrinfo(result);

	/* After a successful binding - listen on that address for incoming connections */
	if (listen(server_socket, MAX_CONNECTIONS) == SOCKET_ERROR)
	{
		cout << "listen failed with error: " << WSAGetLastError() << endl;
		closesocket(server_socket);
		WSACleanup();
		return 1;
	}
	cout << "Listening...\n";

	/* Create a socket for the incoming connection */
	SOCKET client_socket = INVALID_SOCKET;

	/* Accept the connection */
	client_socket = accept(server_socket, NULL, NULL);
	if (INVALID_SOCKET == client_socket)
	{
		cout << "accept failed with error: " << WSAGetLastError() << endl;
		closesocket(server_socket);
		WSACleanup();
		return 1;
	}
	cout << "Acceptance phase...\n";

	/* Send initial message to the connected client */
	std::string init_msg = "The server sees you!";
	char recv_buf[MAX_RECEIVE_LEN] = { 0 };

	/* Tell the OS to send the message */
	send(client_socket, init_msg.c_str(), init_msg.size(), 0);

	/* Start receiving data from the client */
	do
	{
		/* Receive */
		res = recv(client_socket, recv_buf, MAX_RECEIVE_LEN, 0);

		if (0 < res)
		{
			cout << "Received from client: " << std::string(recv_buf) << endl;
			ZeroMemory(recv_buf, MAX_RECEIVE_LEN);

			/* Send "ACK" */
			init_msg = "Acknowledged!";
			send(client_socket, init_msg.c_str(), init_msg.size(), 0);
		}
		else if (0 == res)
		{
			cout << "Session ending!" << endl;
		}
		else
		{
			cout << "recv failed with error: " << WSAGetLastError() << endl;
			closesocket(client_socket);
			WSACleanup();
			return 1;
		}
	} 
	while (res > 0); // if == 0, then EOF has been automatically sent

	/* Cut the sending part of the server socket */
	res = shutdown(client_socket, SD_BOTH);

	/* Close the socket */
	closesocket(client_socket);

	WSACleanup();

	return 0;
}