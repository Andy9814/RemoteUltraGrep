#include<iostream>
#include<sstream>
#include<string>
#include "Socket.hpp"

using namespace std;

int main(int argc, char* argv) {

	string ip = "";
	string command = "";

	if (argc == 1)
	{
		ip = "127.0.0.1";
	}
	else
	{
		ip = argv[1];
	}

	cout << "Please connect to the server (connect [ip]): ";
	//cin >> command;
	getline(cin, command);
	cout << endl;

	//cout << command << endl;

	istringstream iss(command);
	string word = "";
	string connectIP = "";

	while (iss >> word)
	{
		if (word != "connect" && word != "")
		{
			connectIP = word;
		}
		else
			connectIP = "127.0.0.1";
	}

	cout << connectIP << endl;

	//std::shared_ptr<Socket> s;
	//Socket s;
	//.initializeWinSock();
	//s.createSocket();
	//s.connectSocket();
	//s.sendBytes("Hello");
	//s.receiveBytes();
	//s.client_sendRecv();

} 