
#ifndef __CBASE__
#define __CBASE__
 

    typedef long long __int64;
    typedef unsigned char byte;
    const unsigned long INFINITE = 0xFFFFFFFFul; // Infinite timeout
    const long INVALID_SOCKET = -1;
    const  long SOCKET_ERROR = -1;
    unsigned long GetTickCount(void);
    unsigned long GetCurrentThreadId(void);

#   define Sleep(s) usleep((long)s*1000)
#   define Random random
#   define closesocket(s) close(s)
#   include <sys/ioctl.h>
#   include <sys/socket.h>
#   include <sys/time.h>
#   include <sys/types.h>
#   include <netinet/in.h>
#   include <arpa/inet.h>
#   include <netdb.h>
#   include <fcntl.h>
#   include <unistd.h>
#   include <pthread.h>
#   include <signal.h>
#   include <errno.h>
#   define __stdcall
#endif




