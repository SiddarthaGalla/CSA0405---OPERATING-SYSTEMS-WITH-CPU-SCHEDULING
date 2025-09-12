#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int src_fd,des_fd;
    char buffer[1024];
    ssize_t n;

    src_fd = open("source.txt",O_RDONLY);
    if (src_fd < 0){
        perror("Error opening source file\n");
        exit(1);
    }

    des_fd = open("destination.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (des_fd < 0) {
        perror("Error opening/creating destination file");
        close(src_fd);
        exit(1);
    }
     while ((n = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(des_fd, buffer, n) != n) {
            perror("Error writing to destination file");
            close(src_fd);
            close(des_fd);
            exit(1);
        }
    }

 
    close(src_fd);
    close(des_fd);

    printf("File copied successfully!\n");
    return 0;
}

Output:
No such file or directory
