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
char data;
intcounter;
int in;
pthread_mutex_t mut;

void exit(int signum){
  shmdt(data);                              //segmento 3
  shmctl(shmid, IPC_RMID, NULL);            //

  shmdt(counter);                             //segmento 4
  shmctl(counterid, IPC_RMID, NULL);        //
  exit(0);
}

void consumer(){
  printf("Consumer was born!\n");
  while(1){
    pthread_mutex_lock(&mut);
    while(!counter[0]);
    dado = data[in];
    data[in] = ' ';
    printf("Consumed... %c \n", dado);
    in = ++in % REP;
    counter[0]--;
    pthread_mutex_unlock(&mut);
  }
}

int main(){
  printf("The Producer x Consumer Problem\n");
  int status;
  in = 0;

  key = ftok("/home", 'A');                      //  Segmento
  shmid = shmget(key, 1024, 0644 | IPC_CREAT);   //
  data = (malloc(5sizeof(char)));               //     1
  data = shmat(shmid, (void)0, 0);             //

  //Peterson
  key = ftok("/home/downloads", 'B');            //  Segmento
  counterid = shmget(key, 1024, 0644 | IPC_CREAT); //
  counter = (malloc(1sizeof(int)));               //     2
  counter = shmat(counterid, (void)0, 0);          //
  counter[0] = 0;

  signal(SIGINT, exit);
  consumer();
  return 0;
}
