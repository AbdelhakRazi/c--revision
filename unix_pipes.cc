#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
// pipe allows one process to send data to another process
int main() {
    int fd[2];
    pid_t pid;
    if(pipe(fd) == -1){
        perror("Couldn't open a pipe");
        exit(EXIT_FAILURE);
    }
    if((pid = fork()) == -1){
        perror("Couldn't fork a process");
        exit(EXIT_FAILURE);
    }
    if(pid == 0){ // means we're in child process now 
        close(fd[0]); // close read file since we won't be reading
        write(fd[1], "Hello world", sizeof("Hello world")); // write data to the pipe
        close(fd[1]);
    }
    // parent process will read this data.
    close(fd[1]);
    char buffer[128]; // similar to char* buffer
    int readData = read(fd[0], buffer, sizeof(buffer));
    if(readData > 0){
        std::cout << buffer << std::endl;
    }
    close(fd[0]);
    wait(nullptr); // wait for children to finish
    return 0;
}