#include <iostream>
#include <string>
#include "PracticalSocket.h"

const string  servIp =  "127.0.0.1"
const int  servPort  = 8080



using namespace std;

int main() {

  try {
	  // Connect to the server.
    TCPSocket sock(servIp, servPort);

    //send message to server
	iostream& stream = sock.getStream();
	stream << "hallo" << endl;

	//wait for response
    string antwoord;
	getline(stream, antwoord);
	cout << "het antwoord is: " << antwoord << endl;

 }catch(SocketException &e) {
	 //report errors
    cerr << e.what() << endl;
  }
}
