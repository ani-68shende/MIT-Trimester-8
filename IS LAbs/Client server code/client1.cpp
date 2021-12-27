#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};
    char client_buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6542);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(0);
    }

    while (1)
    {
        memset(&client_buffer, '\0', 1024);
        memset(&message, '\0', 1024);

        printf("\nClient: ");
        gets(message);

        if (send(sock, message, strlen(message), 0) < 0)
        {
            printf("\nMessage not sent");
        }

        if (strcmp(message, "exit") == 0)
            break;

        if (read(sock, client_buffer, 1024) < 0)
        {
            printf("\nCan't Listen...");
        }
        printf("\nServer: %s", client_buffer);
        if (strcmp(client_buffer, "exit") == 0)
            break;
    }
    close(sock);
    printf("\n");
    return 0;
}