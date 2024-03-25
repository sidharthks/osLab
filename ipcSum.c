#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int fd[2], n;
    pid_t p;
    pipe(fd); // creates a unidirectional pipe with two ends: fd[0] and fd[1]

    printf("Enter the number of elements to send to child: ");
    scanf("%d", &n);

    p = fork();

    if (p > 0) { // parent process
        close(fd[0]); // close the read end of the pipe in the parent process
        printf("Parent Sending %d numbers to child\n", n);
        int numbers[n];
        printf("Enter %d numbers:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]); // read numbers from user
        }
        write(fd[1], numbers, n * sizeof(int)); // write the array of numbers to the pipe
        close(fd[1]); // close the write end of the pipe in the parent process
        wait(NULL); // wait for the child process to finish
    } else { // child process
        close(fd[1]); // close the write end of the pipe in the child process
        printf("Child receiving %d numbers\n", n);
        int received_numbers[n];
        read(fd[0], received_numbers, n * sizeof(int)); // read the array of numbers from the pipe
        close(fd[0]); // close the read end of the pipe in the child process

        // calculate the sum
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += received_numbers[i];
        }
        printf("Child calculated sum: %d\n", sum);
    }

    return 0;
}