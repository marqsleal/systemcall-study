#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 

int main() {
    pid_t pid = fork();  // Cria um novo processo

    if (pid < 0) {
        perror("Falha no fork");
        return 1;
    }
    else if (pid == 0) {
        printf("Processo Filho (PID: %d, PPID: %d)\n", getpid(), getppid());
        sleep(2);  // Simula uma tarefa demorada
        printf("Processo Filho terminado.\n");
    }
    else {
        printf("Processo Pai (PID: %d, Filho PID: %d)\n", getpid(), pid);
        wait(NULL);
        printf("Processo Filho foi finalizado, Pai continua.\n");
    }

    return 0;
}
