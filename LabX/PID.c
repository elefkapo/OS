#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    pid_t pid;
    int fd = open("pids.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // Child process
        dprintf(fd, "Child PID: %d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        dprintf(fd, "Parent PID: %d\n", getpid());
    } else {
        perror("Fork failed");
        return 1;
    }

    close(fd);
    return 0;
}
