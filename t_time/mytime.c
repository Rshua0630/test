




#include "stdio.h"
#include "time.h"
#include "string.h"


int main()
{
    time_t myt = time(NULL);
    printf("myt is %d \r\n",myt);
    return 0;
}
