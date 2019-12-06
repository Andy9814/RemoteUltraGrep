#include "Socket.hpp"
SOCKET hScoket;
Socket::Socket(SOCKET s)
{
}

Socket::Socket()
{
	
}

void Socket::initializeWinSock()
{
	
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		std::cerr << "WSAStartup failed: " << iResult << std::endl;
		std::cerr << "Quiting the Program" << std::endl;
		return;
	}
}

void Socket::createSocket()
{
	// Create the TCP socket
	hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Create the server address
	serverAddress = { 0 };
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT);
	//serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // old
	inet_pton(AF_INET, "127.0.0.1", &(serverAddress.sin_addr));
}
void Socket::connectSocket()
{
	// connect the socket
	if (connect(hSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
		std::cerr << "connect() failed" << std::endl;
		Socket::endSocket();
	}
}
void Socket::listenSocket()
{
	if (listen(hSocket, 1) == SOCKET_ERROR) {
		std::cerr << "Error listening on socket\n";
		Socket::endSocket();
	}
}

void Socket::bindSocket()
{
	// bind the socket
	if (bind(hSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
		std::cerr << "Bind() failed" << std::endl;
		Socket::endSocket();
	}
	std::cout << "TCP/IP socket bound.\n";
}




void Socket::acceptConnection()
{
	std::cout << "Waiting for connection\n";
	hAccepted = SOCKET_ERROR;
	while (hAccepted == SOCKET_ERROR) {
		hAccepted = accept(hSocket, NULL, NULL);
	}
	std::cout << "Client connected\n";
}


void Socket::client_sendRecv()
{
	char sendbuf[32] = "Hello";
	char recvbuf[32] = "";
	char sendbuf1[32] = "Hello11";
	char recvbuf1[32] = "";

	int bytesSent = send(hSocket, sendbuf, strlen(sendbuf) + 1, 0);
	std::cout << "Sent = " << bytesSent << " bytes" << std::endl;
	int bytesRecv = recv(hSocket, recvbuf, 32, 0);
	std::cout << "Recv = " << bytesRecv << ": " << recvbuf << std::endl;


	int bytesSent1 = send(hSocket, sendbuf1, strlen(sendbuf1) + 1, 0);
	std::cout << "Sent = " << bytesSent1 << " bytes" << std::endl;
	int bytesRecv1 = recv(hSocket, recvbuf1, 32, 0);
	std::cout << "Recv = " << bytesRecv1 << ": " << recvbuf1 << std::endl;

	int i = 42;
	send(hSocket, (char*)&i, sizeof(i), 0);

}

void Socket::server_SendRecv()
{
	int bytesSent;
	int bytesSent1;

	char sendbuf[32] = "Goodbye";
	char recvbuf[32] = "";
	char sendbuf1[32] = "Goodbye1";
	char recvbuf1[32] = "";

	int bytesRecv = recv(hAccepted, recvbuf, 32, 0);
	std::cout << "Recv = " << bytesRecv << ": " << recvbuf << std::endl;
	bytesSent = send(hAccepted, sendbuf, strlen(sendbuf) + 1, 0);
	std::cout << "Sent = " << bytesSent << " bytes" << std::endl;

	int bytesRecv1 = recv(hAccepted, recvbuf1, 32, 0);
	std::cout << "Recv = " << bytesRecv1 << ": " << recvbuf1 << std::endl;
	bytesSent1 = send(hAccepted, sendbuf1, strlen(sendbuf1) + 1, 0);
	std::cout << "Sent = " << bytesSent << " bytes" << std::endl;


	int i;
	bytesRecv = recv(hAccepted, (char*)&i, 4, 0);
	std::cout << "i = " << i << std::endl;

	// terminate
	std::cout << "Closing the accepted socket.\n";
	closesocket(hAccepted);
}
void Socket::receiveBytes()
{
	char recvbuf[32] = "";
	//int bytesRecv = recv(hAccepted, recvBuf, DEFAULT_BUF, 0); // recvBuf = char default = int
	int bytesRecv = recv(hSocket, recvbuf, 32, 0);
	
	if (bytesRecv > 0) {
		std::cout << "Recv" << bytesRecv << ": " << recvBuf << std::endl;
	}
	else {
		Socket::endSocket();
	}

	int i;
	bytesRecv = recv(hAccepted, (char*)&i, 4, 0);
	std::cout << "i = " << i << std::endl;
	// terminate
	std::cout << "Closing the accepted socket.\n";
	closesocket(hAccepted);
}
void Socket::sendBytes(const std::string& sendBuf)
{
	char sendbuf[32] = "Hello";
	int bytesSent = send(hSocket, sendbuf, strlen(sendbuf) + 1, 0);
	//int bytesSend = send(hAccepted, sendBuf.c_str(), sendBuf.length(), 0);  // see if we need to aDDD + 1
	if (bytesSent == SOCKET_ERROR) {
		Socket::endSocket();
	}
	std::cout << "send" << bytesSent << "bytes" << std::endl;

	int i = 42;
	send(hSocket, (char*)&i, sizeof(i), 0);

}
void Socket::endSocket()
{
	std::cout << "Closing the listening socket.\n";
	closesocket(hSocket);
	WSACleanup();
	return; // try this see what happen
}