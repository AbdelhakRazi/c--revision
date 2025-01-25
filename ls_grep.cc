#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
// writing a program that does this: ls | grep
// reminder on exec
// execl: exec list, pass arguments as a list
// execv: pass arguments as a vector
// always add a NULL pointer at the end of arguments
// vp: searches for program in PATH environment, so u don't need full path
// ve: custom of environment variables, don't forget to add NULL at the end always
int main() {
    int fd[2];
    int child;
    if(pipe(fd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if((child = fork()) == -1){
        perror("pid");
        exit(EXIT_FAILURE);
    }
    if(child == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO); // redirect output descriptor into write
        execlp("ls", "ls", nullptr); 
        // current process is replaced, we don't actually go back to the code unless there is an error
        perror("exec failed");
        exit(EXIT_FAILURE);
    }
    wait(nullptr);

}