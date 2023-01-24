#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

static int received = 0;
void handler(int sig)
{
    received = 1 ;
}

int main()
{
    pid_t p;
    signal(SIGUSR1, handler);
    int P1_pid = getpid();
    int P2_pid;
    int P3_pid;
    int fd[2];
    pipe(fd);
    if ( P2_pid = fork())
    {
        // P1
        kill(P2_pid, SIGUSR1);
        wait(NULL);
    }else{
        if(P3_pid = fork())
        {

            // P2
            if(received)
            {
                // send signal to P3
                close(fd[0]);
                int n = 200;
                if( write(fd[1], &n, sizeof(int) ) < 0)
                    printf("\nSome error occured writing!.\n");
                close(fd[1]);
            }
            else{
                printf("\nWaiting for signal from P1...!\n");
            }
        }
        else{

            // P3
            close(fd[1]);
            int status = 404;
            if( read(fd[0], &status, sizeof(int)) < 0 )
                printf("\nSome error occured reading.\n");
            close(fd[0]);

            if(status == 200)
                printf("\nSuccesfully received package!\n");
            else
                printf("\nSome ERROR!\n");
        }
        wait(NULL);
    }
    
    return 0;
}
