# Client-Server Socket Programming Example in C++

This example demonstrates a simple client-server communication using sockets in C++. The server listens for connections from clients, receives messages from clients, and echoes back a response. The client connects to the server, sends a message passed as a command-line argument, and displays the echoed response from the server.

## Files Included

- **client.cpp**: Client application that connects to a server, sends a message passed as a command-line argument, and displays the server's response.
- **server.cpp**: Server application that binds to a specified port, listens for incoming client connections, receives messages from clients, and echoes a response.

## How to Run

### Prerequisites
- C++ compiler (e.g., clang++)

### Steps to Compile and Run

1. **Pre-compilationn**
    Before compiling, modify the `port_num` variable in both `client.cpp` and `server.cpp` to ensure they are set to the same port number. By default, we'll use `9093` as an example.


2. **Compiling the program**

   Open a terminal/command prompt window and navigate to the directory containing `server.cpp` and `client.cpp`.

   ```bash
   //compile the program for server
   clang++ server.cpp -o server

   //compile the program for client
   clang++ client.cpp -o client
   ```

3. **Running the program**
    Open a terminal and run the server program
    ```bash
    ./server
    ```

    Open another terminal and run the client program
    ```bash
    ./client "Your message here"
    ```

    
### Possible Issues

1. **Port already taken**
    
    If you encounter connection issues, such as failing to bind the server socket due to the port already being taken or busy, follow these steps to resolve the issue:

   Open a terminal/command prompt window and run the following command to check if the port specified (`port_num`) is already in use: if the command returns output (i.e., it's not empty), it indicates that the port is already taken.


   ```bash
   ss -tuln | grep port_num
   ```

   To solve this issue, you need to modify the port_num variable in both client.cpp and server.cpp to another available port number. 


