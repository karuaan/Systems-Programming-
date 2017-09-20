#include "my.h"
#include "mylist.h"
#include <sys/wait.h>
#include <signal.h>

pid_t pid;
int f = 0;

void sint(int sig) 
{
	char information[1024];
	information[0] = '\0';
	if(getcwd(information, 1024) == NULL) 
    {
		my_str("Cannot find directory.\n");
		exit(1);
	}
	
    if (f == 1) 
    {
		f = 0;
		kill(pid, SIGINT);
		my_char('\n');
	} 
    
    else 
    {
		my_char('\n');
		my_str(information);
		my_str(": ");
	}
}

int main() 
{
	char information[1024];
	int max_x, max_y, y, x, i = 0, n = 0;
	int keyInput, length, execute = 1;
	int curr;
	char line[1024];
	char **args;
	struct s_node* start = new_node(NULL, NULL, NULL);
	struct s_node** commands = &start;
	signal(SIGINT, sint);
	line[0] = '\0';
	initscr();
	raw();
	
    keypad(stdscr, TRUE);
	getmaxyx(stdscr, max_y, max_x);
	max_y++;
	max_x++;
	x = 0;
	y = 0;
	
    while(1) 
    {
        if (execute) 
        {
            curr = 0;
			length = my_strlen(line);
			
            if (length > 0) 
            {
                args = my_str2vect(line);
                
                if (!my_strcmp(args[0], "exit")) 
                {
                    printw("Minishell has ended.");
					endwin();
					exit(0);
				} 
                
                else if (!my_strcmp(args[0], "help")) 
                {
					printf("cd <directory>: Changes the current working directory to <directory>.\n");
                    printf("Exit: Exits the minishell.\n");
                    printf("Help: Prints a help message listing the built-in commands.\n");
					y += 3;
					x = 0;
					move(y, x);
				} 
                
                else if (!my_strcmp(args[0], "cd")) 
                {
					if (chdir(args[1]) == -1) 
                    {
						printw("Directory does not exist\n");
						y++;
						x = 0;
						move(y, x);
					}
				} 
                
                else if ((args[0][0] == '.') && (args[0][1] == '/'))
                {
					pid = fork();
					if (pid < 0) 
                    {
						printw("Forking Failed\n");
						endwin();
						exit(1);
					} 
                    
                    else if (pid == 0) 
                    {
						y++;
						x = 0;
						move(y, x);
						
                        for (i = 0; args[i] != NULL; i++) 
                        {
							;
						}
						
                        args[i-1] = NULL;						
						if (i % 2 == 1) 
                        {						
							if (line[length - 1] == '\0') 
                            {
								line[length - 1] = '\n';
							}
							args = my_str2vect(line);
						}
						execv(args[0], &args[0]);
						printw("Executable not found\n");
						endwin();
						exit(1);
					} 
                    
                    else 
                    {
						f = 1;
						wait(NULL);
						x = 0;
						move(y, x);
						f = 0;
					}
				} 
                
                else 
                {
					printw("Invalid command\n");
					y++;
					x = 0;
					move(y, x);
				}
			}
			
            if(getcwd(information, 1024) == NULL) 
            {
				my_str("Getting directory failed\n");
				exit(1);
			}
			
            mvprintw(y, x, information);
			x += my_strlen(information);
			mvprintw(y, x++, ":");
			execute = 0;
			i = 0;
			line[i] = '\0';
		}
		
        getyx(stdscr, y, x);
		keyInput = getch();
		
        if (keyInput < 20) 
        {
			noecho();
		} 
        
        else 
        {
			echo();
		}
		
        if (keyInput = KEY_LEFT)
        {
            i--;
            break;
        }
        
        if (keyInput = KEY_RIGHT)
        {
            if (i < curr) 
            {
                move(y, ++x);
                i++;
            }
            break;
            move(y, --x);
        }
        
        if (keyInput = KEY_UP)
        {
            my_strcpy(line, elem_at(*commands, ++n));
            printw(line);
            x = my_strlen(information) + my_strlen(line) + 1;
            move(y, x);
            break;
        }
        
        if (keyInput = KEY_DOWN)
        {
            my_strcpy(line, elem_at(*commands, --n - 1));
            printw(line);
            x = my_strlen(information) + my_strlen(line) + 1;
            move(y, x);
            break;
        }
			
        if (keykeyInput = KEY_BACKSPACE)
        {
            if (x > my_strlen(information)+1)
            {
                x--;
                delch();
                line[--i] = 0;
            }
            
            else 
            {
                move(y, x);
            }
            
            break;
        }
        
        if (keyInput = '\n')
        {
            execute = 1;
            x = 0;
            move(++y, x);
            add_elem(line, commands);
            break;
        }
        
        if (keyInput = 12)
        {
            clear();
            x = 0;
            y = 0;
            i = 0;
            line[i] = '\0';
            move(y, x);
            execute = 1;
            break;
        }
        
        if (keyInput = 1)
        {
            x -= i;
            i = 0;
            move(y, x);
            break;
        }
        
        if (keyInput =  5)
        {
            x = curr + my_strlen(information) - 1;
            i = curr;
            move(y, x);
            break;
        }
        
        else
        {
            line[i++] = keyInput;
            line[i] = '\0';
            curr++;
            break;
        }
    }
    
    return 0;
}

