#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
    printf("Child process received signal: %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        signal(SIGUSR1, handle_signal);
        printf("Child waiting for signal...\n");
        pause(); // Wait for signal
    } else if (pid > 0) {
        // Parent process
        sleep(1); // Allow child to set up
        printf("Parent sending signal to child\n");
        kill(pid, SIGUSR1);
    } else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}
