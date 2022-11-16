#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[]){
  key_t key;
  int shmid;
  char *segmento;
  int modo,filho;
  char buf[1024];
  /* Criar a chave: */
  key = ftok("/tmp", 'X');
  if (key == -1){
    perror("ftok");
    exit(1);
  }
  /*Criar o segmento */
  shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }
  /*Vincula o segmento de memória á variável segmento*/
  segmento = (char*)shmat(shmid, (void *)0, 0);
  if (segmento == (char *)(-1)) {
    perror("shmat");
    exit(1);
  }
  if (fork() != 0) {//Código do pai
    strncpy(buf, segmento, 1024);
    printf("%s\n", buf);
  }else{//Código do filho
    strncpy(segmento, "Mensagem escrita!", SHM_SIZE);
  }
  /* Desvincular do segmento */
  if (shmdt(segmento) == -1) {
    perror("shmdt");
    exit(1);
  }
  return 0;
}
