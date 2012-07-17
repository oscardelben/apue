/*
 * This is my own ls. It only runs on a 64bit mac os x but could easily
 * be adapated to run on other systems. This is a learning project.
 */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/* #define _DARWIN_FEATURE_64_BIT_INODE */

int isDirectory(const char *path)
{
  struct stat buf;

  if (lstat(path, &buf) == -1) {
    printf("Error: can't read %s\n", path);
    exit(1);
  } else {
    return S_ISDIR(buf.st_mode);
  }
}


int main(int arcg, char *argv[])
{

  char path[] = ".";

  if (isDirectory(path)) {
    DIR *dir;
    struct dirent *dp;
    struct stat buf;

    if ((dir = opendir(path)) == NULL) {
      printf("Error: Can't open dir.\n");
      exit(1);
    }

    while((dp = readdir(dir)) != NULL) {
      fstat(dp->d_name, &buf);

      printf("%s %d\n", dp->d_name, buf.st_birthtimespec.tv_sec);
    }

    closedir(dir);
  } else {
      //
  }

  return 0;
}
