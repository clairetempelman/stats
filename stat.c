#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>

int main(){
  struct stat stats;
  int error = stat("stat.c", &stats);
  if (error == -1){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  printf("Printing stats about stat.c...\n");
  printf("File size: %lld bytes\n", stats.st_size);
  printf("File permissions: %o\n", stats.st_mode);
  printf("Time of last access: %s\n", ctime(&stats.st_atime));
}
