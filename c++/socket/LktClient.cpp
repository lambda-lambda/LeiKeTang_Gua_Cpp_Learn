#include "LktServer.hpp"

#include <iostream>

using namespace std;


// Mac上引入库
// #include <sys/unistd.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <netinet/tcp.h>

// Windows上引入库
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <string>

// 使用下列新的 pragma 来指定链接器选项：
// #pragma comment(linker, "<linker options>")
// 工程中加入链接库


#pragma comment(lib, "Ws2_32.lib")

// 客户端函数主体
void client()
{
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    // 要连接的服务器的 ip 和 端口
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    // IP 地址
    serverAddress.sin_addr.s_addr = 0x00000000;
    // 端口
    serverAddress.sin_port = 0xBEAF;

    //客户端直接连接服务器无需其他设置
    connect(socketFd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    string data = "hello world";
    send(socketFd, data.c_str(), data.length(), 0);
}

int main()
{
    client();

    return 0;
}