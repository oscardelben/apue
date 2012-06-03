#include "apue.h"
#include <sys/wait.h>
#include <string.h>

#define MAX_PARAMS 1000

int main(int argc, char *argv[])
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% ");
  while(fgets(buf, MAXLINE, stdin) != NULL) {
    if(buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }

    if((pid = fork()) < 0) {
      err_sys("fork error");
    } else if(pid == 0) { // child

      execl("/bin/sh", "sh", "-c", buf, (char *) NULL);
      err_ret("Couldn't execute %s", buf);
      exit(127);
    }

    // parent
    if((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }
    printf("%% ");
  }

  exit(0);
}
