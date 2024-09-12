#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void* thread_function(void* arg) {
    printf("Hilo creado - PID: %d, TID: %lu\n", getpid(), pthread_self());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    // Primer fork
    pid = fork();
    
    if (pid == 0) { 
        // Proceso hijo
        printf("Proceso hijo creado - PID: %d, PPID: %d\n", getpid(), getppid());

        // Segundo fork dentro del proceso hijo
        fork();
        
        // Crear un hilo dentro del proceso hijo
        pthread_create(&thread, NULL, thread_function, NULL);
        pthread_join(thread, NULL); // Esperar que el hilo termine
    }
    
    // Tercer fork
    fork();

    // Mantener el proceso activo por un momento para ver los resultados
    sleep(1);

    return 0;
}
