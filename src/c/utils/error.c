#include "utils/error.h"
#include "includes.h"
void error(const char * msg) 
{
   perror(msg);
   exit(1);
}
