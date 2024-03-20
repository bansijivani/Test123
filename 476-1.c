// https://www.immuniweb.com/vulnerability/null-pointer-dereference.html
// NULL Pointer Dereference [CWE-476] vulnerable code example
// (c) HTB Research
#undef UNICODE
#include "StdAfx.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment (lib, "Ws2_32.lib")
 
int __cdecl main(int argc, char **argv)
{
        WSADATA wsaData;
        int iResult;
        INT iRetval;
 
        DWORD dwRetval;
        int i = 1;
        struct addrinfo *result = NULL;
        struct addrinfo *ptr = NULL;
        struct addrinfo hints;
 
        if(argc<2){
                printf("usage: %s <proto> <hostname> <servicename>\n", argv[0]);
                return 1;
        }
       
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0) {
                printf("WSAStartup failed: %d\n", iResult);
                return 1;
        }
        ZeroMemory( &hints, sizeof(hints) );
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        dwRetval = getaddrinfo(argv[2], argv[3], &hints, &result);
 
        if ( dwRetval != 0 ) {
                printf("getaddrinfo failed with error: %d\n", dwRetval);
                WSACleanup();
                return 1;
        }
        printf("getaddrinfo returned success\n");
        return 0;
}
