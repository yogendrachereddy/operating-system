#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main() {
    int file_descriptor = open("example.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file_descriptor == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    const char *text = "Hello, Unix System Calls!\n";
    ssize_t bytes_written = write(file_descriptor, text, strlen(text));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }
    printf("%zd bytes written to the file.\n", bytes_written);
    char buffer[1024];
    lseek(file_descriptor, 0, SEEK_SET); 
    ssize_t bytes_read = read(file_descriptor, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Error reading from file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0'; 
    printf("Read from file: %s", buffer);
    close(file_descriptor);
    return 0;
}
