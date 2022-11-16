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

  int fd[2];
  int fd2[2];

  pipe(fd);
  pipe(fd2);

  if(fork() != 0){// Pai
    read(fd2[0], buf2, 1024);
    printf("Mensagem final: %s\n", buf2);
  }else{
    if (fork() != 0) {// Filho 2
      read(fd[0], buf, 1024);
      write(fd2[1], buf, 1024);
    }else{// Filho 1
      write(fd[1], mensagem, size);
    }
  }
  return 0;
}
