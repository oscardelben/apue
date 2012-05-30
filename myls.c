#include "apue.h"
#include <dirent.h>

// Why do I have to redefine them here?
#define DT_DIR 4
#define DT_REG 8

int main(int argc, char *argv[])
{
  DIR *dp;
  struct dirent *dirp;

  if (argc != 2) {
    err_quit("Usage: %s directory_name", argv[0]);
  }

  if ((dp = opendir(argv[1])) == NULL) {
    err_sys("can't open %s\n", argv[1]);
  }

  // Here I'm checking what tipe of file we're dealing with
  while ((dirp = readdir(dp)) != NULL) {
    int d_type = dirp->d_type;
    if (d_type == DT_DIR)
      printf("DIR: %s\n", dirp->d_name);
    else if (d_type == DT_REG)
      printf("FILE: %s\n", dirp->d_name);
    else
      printf("%s\n", dirp->d_name);
  }

  closedir(dp);
  return 0;
}
