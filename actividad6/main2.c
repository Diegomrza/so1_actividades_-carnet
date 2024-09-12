#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Proceso inicial - PID: %d, PPID: %d\n", getpid(), getppid());

    fork(); // Primera llamada
    printf("Después de 1er fork - PID: %d, PPID: %d\n", getpid(), getppid());

    fork(); // Segunda llamada
    printf("Después de 2do fork - PID: %d, PPID: %d\n", getpid(), getppid());

    fork(); // Tercera llamada
    printf("Después de 3er fork - PID: %d, PPID: %d\n", getpid(), getppid());

    return 0;
}
