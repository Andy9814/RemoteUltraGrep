# RemoteUltraGrep

It's a C++ 17 Grep console application using C++ 11 threads that recursively searches a files system for text files or code files and list all of the lines that contain a given regular expression. 

Made by using Client server methodology. 

Once launched the client should provide at least a standard console interface (cout/cin) supporting the following commands:

•	grep [-v] remotefolder regex .exts

•	drop

•	connect address

•	stopserver

The grep command ultragrep –v c:\user [Gg]et .cpp.hpp.h

The drop command disconnects from the server.

The connect command connects the client the server at the specified address.

The stopserver command instructs the grep server to shutdown.

