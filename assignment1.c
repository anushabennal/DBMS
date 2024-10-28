#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILENAME "example.txt"
#define BUFFER_SIZE 1024

void file_operations_system_calls() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    // Creating a file using system call
    fd = open(FILENAME, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    printf("File created successfully with file descriptor: %d\n", fd);

    // Writing to the file
    const char *text = "Hello, World! This is a test of system calls.\n";
    bytesWritten = write(fd, text, strlen(text));
    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("Written %zd bytes to the file.\n", bytesWritten);

    // Closing the file
    close(fd);
    printf("File closed successfully.\n");

    // Opening the file for reading
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully for reading with file descriptor: %d\n", fd);

    // Reading from the file
    bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0'; // Null-terminate the string
    printf("Read %zd bytes from the file: %s\n", bytesRead, buffer);

    // Closing the file
    close(fd);
    printf("File closed successfully.\n");
}

void file_operations_c_library() {
    FILE *file;
    char buffer[BUFFER_SIZE];

    // Creating and writing to the file using C library functions
    file = fopen(FILENAME, "w");
    if (!file) {
        perror("Error opening file with fopen");
        exit(EXIT_FAILURE);
    }
    printf("File created successfully using fopen.\n");

    const char *text = "Hello, World! This is a test of C library functions.\n";
    size_t bytesWritten = fwrite(text, sizeof(char), strlen(text), file);
    if (bytesWritten != strlen(text)) {
        perror("Error writing to file with fwrite");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    printf("Written %zu bytes to the file using fwrite.\n", bytesWritten);

    // Closing the file
    fclose(file);
    printf("File closed successfully using fclose.\n");

    // Opening the file for reading using C library functions
    file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file with fopen");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully for reading using fopen.\n");

    // Reading from the file
    size_t bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE - 1, file);
    if (bytesRead == 0 && ferror(file)) {
        perror("Error reading from file with fread");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0'; // Null-terminate the string
    printf("Read %zu bytes from the file using fread: %s\n", bytesRead, buffer);

    // Closing the file
    fclose(file);
    printf("File closed successfully using fclose.\n");
}

int main() {
    printf("Demonstrating file operations using system calls:\n");
    file_operations_system_calls();
    printf("\nDemonstrating file operations using C library functions:\n");
    file_operations_c_library();
    return 0;
}
