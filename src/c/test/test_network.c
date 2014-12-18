#include "utils/net.h"
#include "includes.h"
int main ( int argc, char *argv[] )
{
   int a = atoi(argv[1]);
   if(a == 0) 
   {
      printf("server\n");
      int serverfd = init_server("54321");
      char * res = "12345";
      sendall(serverfd, res, 6);
      //      close(serverfd);
   }
   else 
   {
      printf("client\n");
      int sockfd = init_client("127.0.0.1", "54321");
      char res[6];
      recvall(sockfd, res, 6);
      printf("%s\n", res);
      //      close(sockfd);
   }

}
