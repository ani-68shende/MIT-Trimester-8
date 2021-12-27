#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char server_buffer[1024] = {0};
    char message[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("\nsocket failed to create");
        exit(0);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(6542);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    printf("\nClient Connected!\n");
    while (1)
    {
        memset(&server_buffer, '\0', 1024);
        memset(&message, '\0', 1024);

        if (read(new_socket, server_buffer, 1024) < 0)
        {
            printf("\nCan't Listen...");
        }
        printf("\nClient: %s", server_buffer);
        if (strcmp(server_buffer, "exit") == 0)
            break;
        printf("\nServer: ");
        gets(message);

        if (send(new_socket, message, strlen(message), 0) < 0)
        {
            printf("\nMessage not sent");
        }
        if (strcmp(message, "exit") == 0)
            break;
    }

    close(server_fd);
    close(new_socket);
    printf("\n");
    return 0;
}