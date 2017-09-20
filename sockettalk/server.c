#include "my.h"
#include <wait.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <errno.h>

#define BUFF_SIZE 512

void error(char *msg)
{
    perror(msg);
    exit(1);
}


int main(int argc, char *argv[])
{

    int sockfd, newsockfd, portno, pid;
    socklen_t clilen; 
    char buffer[BUFF_SIZE];
    struct sockaddr_in serv_addr, cli_addr; 
    char *user, *newname;

    if(argc != 2)
    {
        error("Usage: ./server [port]");
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        error("Socket Failed");
    }

    else
    {
        my_str("Socket Successful\n");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = my_atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        error("Bind Failed");
    }
    
    else
    {
        my_str("Bind Successful\n");
    }

    if(listen(sockfd,5) < 0)
    {
        error("Listen Failed");
    }
    
    else
    {
        my_str("Listen Successful\n");
    }

    while(1)
    {

        clilen = sizeof(cli_addr); 
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);

        if(newsockfd < 0)
        {
            error("Accept Failed");
        }
        
        else
        {
            my_str("Accept Successful\n");
        }


        pid = fork();

        if(pid < 0)
        {
            error("Fork failed");
        }

        else if( pid == 0)
        {
            if((read(newsockfd, buffer, BUFF_SIZE -1)) < 0)
            {
                error("Read failed");
            }
           
            else
            {
                user = my_strdup(buffer);
                my_str(user);
                my_str(" has connected.\n");
            }

            while(1)
            {
                if((read(newsockfd, buffer, BUFF_SIZE -1)) < 0)
                {
                    error("Read failed");
                } 
                
                else
                {
                   
                    if(my_strncmp("/exit", buffer, 5) == 0)
                    {
                        my_str(user);
                        my_str(" has disconnected.\n");
                        exit(0);
                        memset(buffer, 0, BUFF_SIZE);;
                    } 
                    
                    else if(my_strncmp("/me", buffer, 3) == 0)
                    {
                        my_str(user);
                        my_str(" ");
                        my_str(&(buffer[4]));
                        my_str("\n");
                        memset(buffer, 0, BUFF_SIZE);;
                    } 
                    
                    else if(my_strncmp("/nick", buffer, 5) == 0)
                    {
                        newname = my_strdup(&(buffer[6]));
                        my_str(user);
                        my_str(" changed their name to ");
                        my_str(newname);
                        my_str(".\n");
                        user = newname;
                        memset(buffer, 0, BUFF_SIZE);;
                    } 

                    else
                    {
                        my_str(user);
                        my_str(": ");
                        my_str(buffer);
                        my_str("\n");
                        memset(buffer, 0, BUFF_SIZE);;
                    }

                }
            }
        }
    }
    return 0;
}





