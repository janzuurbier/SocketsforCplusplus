#include <iostream>
#include "PracticalSocket.h"
#include <string>

using namespace std;

void handleConnection(TCPSocket *);

int main(int argc, char *argv[]) {
  try {
    // Make a socket to listen for client connections.
    TCPServerSocket servSock(8080);
	cout << "server running: " << servSock.getLocalAddress().getAddress() << endl;

    // Repeatedly accept connections
    for (;;) {
		TCPSocket *sock = servSock.accept(); // Get next client connection
		cout << "connection accepted " << sock->getForeignAddress().getAddress() << endl;
		handleConnection(sock);

    }
  } catch (SocketException &e) {
	  // Report errors to the console
    cerr << e.what() << endl;
  }

  return 0;
}

void handleConnection(TCPSocket *sock){
		iostream& stream = sock->getStream();
		string regel;
		getline(stream, regel);
		stream << regel << endl;
		sock->close();
		delete sock;
}

