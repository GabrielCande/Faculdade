#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int main(){
  int fd[2];
  pipe(fd);
  char buf[1024];
  int var = 0;
  if (fork() != 0) { /* I am the parent */
    read(fd[0], &var, sizeof(int));
    var += 5;
  }else{ /*Child code */
    var += 10;
    write(fd[1], &var, sizeof(int));
  }
  printf("%d\n",var);
}
