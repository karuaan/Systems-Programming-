#include "my.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <errno.h>

#define BUFF_SIZE 512

void error(char *msg){
	perror(msg);
	exit(0);
}



int main(int argc, char *argv[]){

	int sockfd, portno, n; 
	struct sockaddr_in serv_addr;
	struct hostent *server; 
	char buffer[BUFF_SIZE];
	char *username;

	if(argc != 3){
		error("Usage: ./client [host] [port]");
	}

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        error("Socket Failed");
    } 

    else{
        printf("Socket Successful\n");
    }


	portno = my_atoi(argv[2]);

	server = (struct hostent*) gethostbyname(argv[1]);

	if(server == NULL){
		error("No such host");
	}
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if((connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0){
        error("Connect Failed");
    } 
    else{


        printf("Please input your username:\n");
        bzero(buffer, BUFF_SIZE);
        username = fgets(buffer,BUFF_SIZE-1,stdin);

        printf("Your username is: ");
        printf("%s\n", username);


        while(1){

            printf("Enter Message \n");

            if((read(1, buffer, BUFF_SIZE-1)) < 0){
                error("Read Failed");
            }
            else{

                n = write(sockfd,buffer,my_strlen(buffer));

                if(n < 0){
                    error("Write Failed");
                }
                else{

                    if(my_strcmp(buffer, "/exit") == 0){
                        
                        close(sockfd);
                        exit(0);
                    }

                }
            }
        }
    }

    return 0;
}



















