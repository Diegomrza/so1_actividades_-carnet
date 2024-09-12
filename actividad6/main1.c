#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Crear un nuevo proceso
    pid = fork();

    if (pid < 0) {
        // Error al crear el proceso
        perror("Error en fork");
        exit(1);
    }

    if (pid == 0) {
        // Proceso hijo
        printf("Soy el proceso hijo (PID: %d), voy a terminar.\n", getpid());
        exit(0); // El proceso hijo termina, pero el padre no lo recoge inmediatamente
    } else {
        // Proceso padre
        printf("Soy el proceso padre (PID: %d), mi hijo es (PID: %d).\n", getpid(), pid);

        // Esperar 60 segundos antes de recoger el proceso hijo
        sleep(60);

        // Verificación: El hijo debería estar en estado zombie durante este tiempo.
        // Usa "ps -l" para ver el estado del proceso hijo (debería mostrar 'Z' en STAT).

        // Recolectar el proceso hijo (evitar que quede como zombie permanentemente)
        wait(NULL);

        printf("El proceso hijo (PID: %d) ha sido recolectado.\n", pid);
    }

    return 0;
}
