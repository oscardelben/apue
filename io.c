#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096 // I haven't tested the performance of using various BUF_SIZE values. Note that when testing subsequent io operations the OS may cache the data, so you may get screwed results

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s file\n", argv[0]);
    return 1;
  }

  ssize_t bytes_read;

  int filedes = open(argv[1], O_RDONLY);

  char buffer[BUF_SIZE];

  while((bytes_read = read(filedes, buffer, BUF_SIZE)) > 0) {
    if(write(STDOUT_FILENO, buffer, bytes_read) == -1) {
      return 1;
    }

    if (bytes_read == -1) {
      return 1;
    }
  }

  // close the file
  close(filedes);

  return 0;

}
