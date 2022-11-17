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
int shmid,flagsid;
char *data;
int *flags;
int in;

void exit(int signum){
  shmdt(data);                              //segmento 3
  shmctl(shmid, IPC_RMID, NULL);            //

  shmdt(flags);                             //segmento 4
  shmctl(flagsid, IPC_RMID, NULL);        //
  exit(0);
}

void consumer(){
  printf("Consumer was born!\n");
  while(1){
    while(!flags[3]);
    flags[1] = 1;
    while(flags[0] && (!flags[2]));
    dado = data[in];
    data[in] = ' ';
    printf("Consumed... %c \n", dado);
    in = ++in % REP;
    flags[3]--;
    flags[2] = 0;
    flags[1] = 0;
  }
}

void main(){
  key = ftok("/home", 'A');                      //  Segmento
  shmid = shmget(key, 1024, 0644 | IPC_CREAT);   //
  data = (malloc(REP*sizeof(char)));               //     1
  data = shmat(shmid, (void *)0, 0);             //

  //Peterson
  key = ftok("/home/downloads", 'B');            //  Segmento
  flagsid = shmget(key, 1024, 0644 | IPC_CREAT); //
  flags = (malloc(4*sizeof(int)));               //     2
  flags = shmat(flagsid, (void *)0, 0);          //


  printf("The Producer x Consumer Problem\n");
  int status;
  in = 0;
  
  signal(SIGINT, exit);
  consumer();
}
