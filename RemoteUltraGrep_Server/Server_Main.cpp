#include<iostream>
#include"Socket.hpp"

int main() {
	//std::shared_ptr<Socket> s;
	Socket s;
	s.initializeWinSock();
	s.createSocket();
	s.bindSocket();  
	s.listenSocket();
	s.acceptConnection();
	s.server_SendRecv();
	//s.receiveBytes();
	//s.sendBytes("GoodBye");
}