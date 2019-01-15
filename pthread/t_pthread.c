/*
 * =====================================================================================
 *
 *       Filename:  t_pthread.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年12月29日 15时24分07秒
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
#include <pthread.h>
#include <unistd.h>

int g_count = 10;
int g_pthreadexit_status = 0;

void * t_pthread_func(void * arg);

int main(int argc,char ** argv)
{
    int s_count = 1;
    pthread_t pid;  
    printf("Joshua : pthread begin \r\n");
    
    if(pthread_create(&pid,NULL,t_pthread_func,NULL) < 0){
        printf("Joshua : pthread_create failed\r\n");
    }
    printf("Joshua: g_count is %d,s_count is %d\r\n",g_count,s_count);
    sleep(3);
    pthread_join(pid,NULL);
    printf("Joshua : pthread end \r\n");
    exit(0);
}


void *t_pthread_func(void * arg)
{
    int s_count = 1;    
    printf("Joshua: t_pthread_func begin\r\n");
    g_count++;
    s_count++;
    printf("Joshua1: g_count is %d,s_count is %d\r\n",g_count,s_count);
    for(;;) s_count ++;
    //return 0;
    //pthread_exit(&g_pthreadexit_status);
}



