// C++ program of client application in socket programming 
#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h>

using namespace std;
  
int main(int argc, char* argv[]) 
{ 
    //port number
    int port_num = 9093;

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <message>" << endl;
        return -1;
    }

    // creating socket 
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0); 
  
    // specifying address 
    sockaddr_in serverAddress; 
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(port_num); 
    serverAddress.sin_addr.s_addr = INADDR_ANY; 
  
    // sending connection request 
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        cerr << "Connection failed" << endl;
        close(clientSocket);
        return -1;
    }
    cout << "Connection successful on port " << port_num<< endl;
  
    // sending data passed through program argument
    const char* message = argv[1]; 
    send(clientSocket, message, strlen(message), 0); 
  
    // receiving echoed data 
    char buffer[1024] = { 0 }; 
    recv(clientSocket, buffer, sizeof(buffer), 0); 
    cout << "Echo from server: " << buffer << endl; 
  
    // closing socket 
    close(clientSocket); 
  
    return 0; 
}
