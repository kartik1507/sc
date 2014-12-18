#ifndef NET_H__
#define NET_H__
#include "includes.h"
int init_server(const char *port);

int init_client(const char *addr, const char *port);

int sendall(int s, char *buf, size_t len);

int recvall(int s, char *buf, size_t len);

#endif
