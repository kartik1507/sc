#include "net.h"
#include "includes.h"

int init_server(const char *port)
{
   int listenfd = 0, connfd = 0;
   struct sockaddr_in serv_addr; 

   char sendBuff[1025];
   time_t ticks; 

   listenfd = socket(AF_INET, SOCK_STREAM, 0);
   memset(&serv_addr, '0', sizeof(serv_addr));
   memset(sendBuff, '0', sizeof(sendBuff)); 

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   serv_addr.sin_port = htons(atoi(port)); 

   bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

   listen(listenfd, 10); 

   connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

   return connfd;
}

int init_client(const char *addr, const char *port)
{
   int sockfd = 0, n = 0;
   char recvBuff[1024];
   struct sockaddr_in serv_addr; 

   memset(recvBuff, '0',sizeof(recvBuff));
   if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      error("\n Error : Could not create socket \n");

   memset(&serv_addr, '0', sizeof(serv_addr)); 

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(atoi(port)); 

   if(inet_pton(AF_INET, addr, &serv_addr.sin_addr)<=0)
      error("\n inet_pton error occured\n");

   if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      error("\n Error : Connect Failed \n");

   return sockfd;
}

/* modified from
http://beej.us/guide/bgnet/output/html/multipage/advanced.html#sendall */
   int
sendall(int s, char *buf, size_t len)
{
   size_t total = 0;
   size_t bytesleft = len;
   int n;

   while (total < len) {
      n = send(s, buf + total, bytesleft, 0);
      if (n == -1)
         break;
      total += n;
      bytesleft -= n;
   }
   return n == -1 ? -1 : 0;
}

   int
recvall(int s, char *buf, size_t len)
{
   size_t total = 0;
   size_t bytesleft = len;
   int n;

   while (total < len) {
      n = recv(s, buf + total, bytesleft, 0);
      if (n == -1)
         break;
      total += n;
      bytesleft -= n;
   }
   return n == -1 ? -1 : 0;
}
