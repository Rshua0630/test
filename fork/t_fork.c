/*
 * =====================================================================================
 *
 *       Filename:  t_fork.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年12月29日 14时18分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int g_count = 10;

int main(int argv,char ** argc)
{
    char    s_sount = 1;
    pid_t   pid;
    printf("Joshua : t_fork begin\r\n");
    

    if((pid = fork()) < 0){
        printf("Joshua : fork error\r\n");
    }
    else if(pid == 0){
        s_sount++;
        g_count++;
    }
    else{
        sleep(2);
    }

    printf("Joshua g_count is %d,s_sount is %d\r\n",g_count,s_sount);

}
