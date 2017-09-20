#include <stdlib.h>
#include <unistd.h>
#include "../lib/my.h"

#define BUFF_SIZE 1024

char *my_splitBuffer(char *a)
{
    for(int b = 0; a[b] != '\n' && a[b] != '\0'; b++)
        ;
    a[b] = '\0';

    return a;
}

void killChildClass(int sig)
{
	if (forkNum != -1)
	{
		kill(forkNum, SIGTERM);
		forkNum = -1;
	}
	my_str("\n");
}

int main(int argc, char **argv)
{
    int a;
    int forkNum;
    int i;
    char** vect;
    char buffer[BUFF_SIZE];
    char* str;
    char* homeDirectory;
    char* username;

    username = malloc(sizeof(char) * BUFF_SIZE);
    homeDirectory = malloc(sizeof(char) * BUFF_SIZE);
    getUsername(homeDirectory, BUFF_SIZE-1);

    while(1)
    {
    	forkNum = -1;
    	signal(SIGINT, killChildClass);

        my_str("MINISHELL: ");
        my_str(getUsername(username, BUFF_SIZE-1));
        my_str(" $ ");
        
        if((a = read(1, buffer, BUFF_SIZE-1)) < 0)
        {
            my_str("MINISHELL isn't working.\n");
            exit(0);
        }
        
        else
        {
            str = my_splitBuffer(buffer);
            vect = my_str2vect(str);

            if(vect[0] = NULL)
            {

            }

            if(my_strcmp(vect[0], "cd") == 0)
            {
                if((a = chdir(vect[1])) < 0)
                {
                    if(chdir(homeDirectory) == -1)
                    {
                    	my_str("Problem accessing home directory.\n");
                    }
                }

                else if (chdir(vect[1]) == -1)
                {
                	my_str("Directory cannot be found.\n");
                }
            }
            
            else if(my_strcmp(vect[0], "exit") == 0)
            {
                my_str("Bye Bye!!!\n");

                for(i = 0; vect[i] != NULL; i++)
                {
                	free(vect[i]);
                }

                free(vect);
                free(username);
                free(homeDirectory);
                exit(0);
            }

            else if(my_strcmp(vect[0], "help") == 0)
            {
            	my_str("List of Builtin Commands: ")
                my_str("The Built In Functions Are:\n");
                my_str("cd (directory): Changes the current working directory to directory.\n")
                my_str("exit: Exits the minishell.\n");
                my_str("help: Prints a help message listing the built in commands.\n");
                my_str(" ls: Lists all files in the directory.\n");
                my_str("CTRL + C: Kills current process.");
                exit(0);
            }
            
            else
            {
                if((forkNum = fork()) < 0)
                {
                    my_str("Fork failed");
                    exit(0);
                }
                
                if(forkNum > 0)
                {
                    wait();

                    for(i = 0; vect[i] != NULL; i++)
                    {
                    	free(vect[i]);
                    }
                }
                
                else
                {
                    if((a = execvp(vect[0], vect)) < 0)
                    {
                        my_str("Execution of ");
                        my_str(vect[0]);
                        my_str(" failed.\n");
                        exit(0);
                    }
                }
            }
        }
    }
}