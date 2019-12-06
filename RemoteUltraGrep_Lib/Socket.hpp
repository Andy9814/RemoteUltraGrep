#pragma once

#include<iostream>
#define _CRTDBG_MAP_ALLOC
// Create a dbg version of new that provides more information
#ifdef _DEBUG
#define DBG_NEW new ( NORMAL_BLOCK , __FILE_ , _LINE_ )
#else
#define DBG_NEW new
#endif

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

#pragma comment (lib,"ws2_32.lib")
unsigned short constexpr PORT = 27015;
#define DEFAULT_BUF 1042
class Socket {
public:
	Socket(SOCKET s);
	Socket();
	

	SOCKET hSocket ;
	sockaddr_in serverAddress;
	SOCKET hAccepted;
	char recvBuf[DEFAULT_BUF]= "";
	void initializeWinSock();
	void createSocket();
	void endSocket();
	void bindSocket();
	void acceptConnection();
	void connectSocket();
	void listenSocket();
	void client_sendRecv();
	void server_SendRecv();
	void sendBytes(const std::string&);
	//void receiveLine();
	void receiveBytes();
};