#include <stdio.h>
#include <unistd.h>

int main()
{
    //before
    printf("Before: pid is %d\n",getpid());
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return 0; 
    }
    //after
    printf("After: pid is %d, fork return %d\n",getpid(),pid);
    sleep(1);
    return 0;
}

