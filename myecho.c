#include <unistd.h>
#include "apue.h"

#define BUFFSIZE 4096

int main(void)
{
  int n;
  char buf[BUFFSIZE];

  // Usually, I would use other functions like fgets and friends
  while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      err_sys("write error");
    }
    if (n < 0) {
      err_sys("read error");
    }
  }

  return 0;
}
