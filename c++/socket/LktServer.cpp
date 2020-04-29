// #include "LktServer.hpp"

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

#pragma comment(lib, "Ws2_32.lib")

void server()
{   
    // windows socket接口 初始化
    // Mac 直接注释即可
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);


    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    // 服务器的 ip 和 端口
    struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    // IP 地址
    serverAddress.sin_addr.s_addr = 0x00000000;
    // 端口
    serverAddress.sin_port = 0xBEAF;

    // 向 OS 申请端口
    bind(socketFd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    // 开始监听请求，第二个参数无脑写 6，不用关心
    listen(socketFd, 6);

    //接收客户端连接
    struct sockaddr_in clientAddress;
    socklen_t len = sizeof(clientAddress);
    int connection = accept(socketFd, (struct sockaddr *)&clientAddress, &len);

    // 执行到这，说明已经创建链接，可以读取客户端发送来的数据

    const int size = 100;
    char data[size];

    // 接收 客户端数据包
    // WINSOCK_API_LINKAGE int PASCAL recv (SOCKET, char *, int, int);
    recv(connection, data, size, 0);
    
    printf("recv:(%s)\n", data);
}

int main()
{
    server();

    return 0;
}