# Chamadas de Sistema: o que são e como melhorar a performance do código

As chamada de sistema (_System Calls_, ou _syscalls_) são mecanismos que programas computacionais utilizam para solicitar serviços ao kernel do sistema operacional. Os tipos de chamadas de sistema são: Controle de Processos, Gerenciamento de Arquivos, Gerenciamento de Dispositivos, Manutenção de Informações, Comunicações e Proteção.

## 1. Controle de processos: 
Chamadas de sistema que lidam com a criação, gerenciamento e término de processos.

- `fork()`: Duplica um processo atual.
- `execve()`: Substitui um processo por um novo problema.
- `wait()`: Espera um processo filho terminar.
- `exit()`: Termina o processo.
- `getpid()`: Obtém o ID do processo atual.
- `kill()`: Envia um sinal para um processo.
- `getppid()`: Obtém o ID processo pai.

### Exemplo com fork(), wait(), getpid() e getppid():

```C
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
```
### Saida:

```bash
Processo Pai (PID: 16871, Filho PID: 16872)
Processo Filho (PID: 16872, PPID: 16871)
Processo Filho terminado.
Processo Filho foi finalizado, Pai continua.
```

## 2. Gerenciamento de Arquivos: 
Chamadas de sistema que manipulam arquivos e diretórios.

- `open()`: Abre um arquivo.
- `read()`: Le dados de um arquivo.
- `write()`: Escreve dados em um arquivo.
- `close()`: Fecha um arquivo.
- `unlink()`: Remove um arquivo.
- `lseek()`: Define posição de leitura/escrita de um arquivo.
- `stat()`: Obtém informações sobre um arquivo.
- `mkdir()`: Cria um diretório.
- `rmdir()`: Remove um diretório.
- `chmod()`: Altera permissões de um arquivo.

## 3. Gerenciamento de Dispositivos: 
Chamadas de sistema que manipulam dispositivos de hardware.

- `mknod()`: Cria um arquivo de dispositivo especial.
- `ioctl()`: Controlador de dispositivos de hardware.
- `read()` e `write()`: Aplicados ao contexto de hardware.

## 4. Manutenção de Informações: 
Chamadas de sistema que coletam ou modificam informações do sistema.

- `uname()`: Informações sobre o sistema.
- `gettimeofday()`: Hora do sistema.
- `sysinfo()`: Informações sobre recurso do sistema.
- `gethostname()`: Nome do host.
- `sethostname()`: Define o nome do host.

## 5. Comunicações: 
Chamadas de sistema usadas para comunicação entre processos (IPC) e redes.

pipe() – Cria um pipe (comunicação unidirecional entre processos).
socket() – Cria um socket para comunicação via rede.
connect() – Conecta um socket a um endereço remoto.
send() – Envia dados através de um socket.
recv() – Recebe dados através de um socket.
bind() – Associa um socket a um endereço local.
listen() – Coloca um socket em modo de escuta.
accept() – Aceita uma conexão de um socket.
shmget() – Obtém um segmento de memória compartilhada.
shmat() – Anexa um segmento de memória compartilhada.

## 6. Proteção: 
Chamadas de sistema relacionadas à segurança, permissões e controle de acesso.

chmod() – Altera as permissões de um arquivo.
chown() – Altera o proprietário de um arquivo.
setuid() – Define o ID do usuário efetivo.
getuid() – Obtém o ID do usuário real.
setgid() – Define o ID do grupo efetivo.
getgid() – Obtém o ID do grupo real.
umask() – Define a máscara de criação de arquivos.

