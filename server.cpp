// C++ program to show the example of server application in 
// socket programming 
#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 
  
using namespace std; 
  
int main() 
{ 
    //port number
    int port_num = 9093;

    // creating socket 
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0); 
  
    // specifying the address 
    sockaddr_in serverAddress; 
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(port_num); 
    serverAddress.sin_addr.s_addr = INADDR_ANY; 
  
    // binding socket 
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        cerr << "Bind failed" << endl;
        close(serverSocket);
        return -1;
    }
    cout << "Binding successful." << endl;
  
    // listening to the assigned socket 
    if (listen(serverSocket, 5) < 0) {
        cerr << "Listen failed" << endl;
        close(serverSocket);
        return -1;
    }
    cout << "Server is listening on port " << port_num << endl;
  
    // accepting connection request 
    int clientSocket = accept(serverSocket, nullptr, nullptr); 
    if (clientSocket < 0) {
        cerr << "Accept failed" << endl;
        close(serverSocket);
        return -1;
    }
    cout << "Connection accepted." << endl;
  
    // receiving data 
    char buffer[1024] = { 0 }; 
    recv(clientSocket, buffer, sizeof(buffer), 0); 
    cout << "Message from client: " << buffer << endl; 
  
    // sending data back (echoing with "Hello client!")
    const char* response = "Server has received message from this client";
    send(clientSocket, response, strlen(response), 0);
  
    // closing the socket 
    close(clientSocket); 
    close(serverSocket); 
  
    return 0; 
}
