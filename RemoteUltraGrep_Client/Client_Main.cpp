#include<iostream>
#include "Socket.hpp"
int main() {

	//std::shared_ptr<Socket> s;
	Socket s;
	s.initializeWinSock();
	s.createSocket();
	s.connectSocket();
	//s.sendBytes("Hello");
	//s.receiveBytes();
	s.client_sendRecv();

}