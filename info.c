
#include <stdio.h>
#include <sys/syslimits.h>
#include <fcntl.h>

int main()
{
  /*
   * You can actually open as many files as you want provided that you
   * have enough memory.
   */
  printf("OPEN_MAX: %d\n", OPEN_MAX);

  return 0;
}
