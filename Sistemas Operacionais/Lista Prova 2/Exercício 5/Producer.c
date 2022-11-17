#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <pthread.h>


#define SHM_SIZE 1024

const int REP = 5;
char dado;
key_t key;
int shmid,counterid;
char *data;
int *counter;
int in;
pthread_mutex_t mut;

void exit(int signum){
  shmdt(data);                              //segmento 3
  shmctl(shmid, IPC_RMID, NULL);            //

  shmdt(counter);                             //segmento 4
  shmctl(counterid, IPC_RMID, NULL);        //
  exit(0);
}

void producer(){
  printf("Producer was born!\n");

  while(1){
    pthread_mutex_lock(&mut);
    while(counter[0] == REP);

    data[in] = (char) in + 0x61;
    printf("Stored... %c \n", data[in]);

    in = ++in % REP;
    counter[0]++;
    pthread_mutex_unlock(&mut);
  }
}

int main(){
  printf("The Producer x Consumer Problem\n");
  int status;
  in = 0;

  key = ftok("/home", 'A');                      //  Segmento
  shmid = shmget(key, 1024, 0644 | IPC_CREAT);   //
  data = (malloc(5*sizeof(char)));               //     1
  data = shmat(shmid, (void *)0, 0);             //

  //Peterson
  key = ftok("/home/downloads", 'B');            //  Segmento
  counterid = shmget(key, 1024, 0644 | IPC_CREAT); //
  counter = (malloc(1*sizeof(int)));               //     2
  counter = shmat(counterid, (void *)0, 0);          //

  counter[0] = 0;

  signal(SIGINT, exit);
  producer();
  return 0;
}
