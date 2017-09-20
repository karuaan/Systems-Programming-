#include "my.h"
#include <wait.h>
#include <signal.h>
#include <strings.h>

#define MAX_LENGTH 1124

int main(int argc, char *argv[])
{
	int parentfd[2];
	int childfd[2];
	int pid, length;
	char buffer[MAX_LENGTH];

	if(argc < 2)
	{
		my_str("Usage: ./pipes <string>\n");
		exit(2);
	}
	pipe(parentfd);
	if((pid=fork()) < 0)
	{
		my_str("Error");
		exit(1);
	}


	if( pid > 0)
	{

		close(parentfd[0]);

		char* read_in = my_vect2str(&argv[1]);

		my_str("Parent: ");
		my_str(read_in);
		my_char('\n');

		printf("%d",my_strlen(read_in));
		write(parentfd[1],read_in,(my_strlen(read_in)));
		wait((int *) 0);
		free(read_in);
		exit(0);
	}
	else
	{
		close(parentfd[1]);

		length = read(parentfd[0],buffer,MAX_LENGTH-1);
		buffer[length] = '\0';

		my_str("Child: ");
		my_str(buffer);
		my_char('\n');

		pipe(childfd);
		if((pid = fork()) < 0)
		{
			my_str("Error");
			exit(1);
		}

		if (pid > 0)
		{
			close(childfd[0]);

			write(childfd[1],buffer,(my_strlen(buffer)));
			wait((int *) 1);
			exit(0);

		}
		else
		{
			close(childfd[1]);

			length = read(childfd[0],buffer,MAX_LENGTH-1);
			buffer[length]= '\0';


			my_str("Grandchild: ");
			my_str(buffer);
			my_char('\n');

		}
	}
}



