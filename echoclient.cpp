#include <iostream>
#include <cstdlib>
#include <string>
#include "PracticalSocket.h"

#define servIp "127.0.0.1"
#define servPort 8080



using namespace std;

int main(int argc, char *argv[]) {

  try {
    TCPSocket sock(servIp, servPort);      // Connect to the server.
	iostream& stream = sock.getStream();
	stream << "hallo" << endl;
    string antwoord;
	getline(stream, antwoord);
	cout << "het antwoord is: " << antwoord << endl;
 }catch(SocketException &e) {
    cerr << e.what() << endl;
  }
}
