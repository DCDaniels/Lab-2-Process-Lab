#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
  int status;   
  pid_t  child1, child2, pid;
  child1 = fork();
  
if (child1 == 0){
//child 1 code
  time_t t;
      int i;
      srand((unsigned) time(&t));
      int loops = (rand()%30);
      for (i =1; i <= loops; i++){
        printf("Child Pid: %d is going to sleep!\n",getpid());
        sleep((rand()%10));
        printf("Child Pid: %d is awake! \nWhere is my Parent: %d?\n", getpid(), getppid());
      }
      printf("***Child A: %d process is done ***\n",getpid());
      exit(getpid());
} else {
  child2 = fork();
  if (child2 == 0){
//child2 code
    time_t t;
    int i;
    srand((unsigned) time(&t));
      int loops = (rand()%30);
      for (i =1; i <= loops; i++){
        printf("Child Pid: %d is going to sleep!\n",getpid());
        sleep((rand()%10));
        printf("Child Pid: %d is awake! \nWhere is my Parent: %d?\n", getpid(), getppid());
      }
      printf("***Child B: %d process is done ***\n",getpid());
      exit(getpid());
  } else{
//Parent code
    while ((pid = wait(&status)) > 0)
    {
      printf("Child Pid: %d has completed.Exit status of was %d (%s)\n", (int)pid, status,
            (status > 0) ? "accept" : "reject");
    }
  }
}      
}
