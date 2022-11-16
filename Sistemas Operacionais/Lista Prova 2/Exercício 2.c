#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mensagem = "Mensagem enviada.";

int main() {
  int size = strlen(mensagem) + 1;
  char buf[1024];
  char buf2[1024];
  char buf3[1024];

  int fd[2];
  int fd2[2];
  int fd3[2];

  pipe(fd);
  pipe(fd2);
  pipe(fd3);

  if(fork() != 0){// Pai
    read(fd3[0], buf3, 1024);
    printf("Mensagem final: %s\n", buf3);
  }else{
    if (fork() != 0) {// Filho 3
      read(fd2[0], buf2, 1024);
      write(fd3[1], buf2, size);
    }else{
      if (fork() != 0) {// Filho 2
        read(fd[0], buf, 1024);
        write(fd2[1], buf, size);
      }else{// Filho 3
        write(fd[1], mensagem, size);
      }
    }
  }
  return 0;
}
