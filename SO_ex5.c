#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
static int flag = 0;
void funchandler(int sig)
{
    flag = 1;
}

int main()
{
    int val;
    int val2;
    int fd[2];
    int status;
    int status2;
    pipe(fd);
    signal(SIGUSR1, funchandler);
    if(val = fork())
    {
        
        if(val2 = fork())
        {
            // P1
            
            waitpid(val2, &status2, 0);
            waitpid(val, &status, 0);


            
        }
        else{
            // P2
            kill(val, SIGUSR1);

        }
    }else
    {
        // P3
       while(!flag);
       printf("flag %d", flag);
    }
    
    return 0;
}
