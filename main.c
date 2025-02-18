#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

#define N 10
int main(void){
    int pid;
    int status;
    int num_processos = 0;
    int total_processos = N;
    int sleep_time;

    while(num_processos < total_processos){
        pid = fork();

        // cria o processo filho, espera terminar, continua no loop e cria outro
        if(pid == 0){
            srand(time(NULL) + getpid());
            sleep_time = rand() % 10 + 1;
            sleep(sleep_time);
            return sleep_time;
        }
        else{
            wait(&status);
            num_processos++;
            printf("No processo pai %d: processo filho: %d, status de saida do filho: %d\n", (int)getpid(), pid, status);
        }
    }
    return 0;
}