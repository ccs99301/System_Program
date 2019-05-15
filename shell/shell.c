#include "apue.h"
#include <sys/wait.h>
#include <string.h>

static void	sig_int(int);		/* our signal-catching function */
int
main(void)
{
		char	buf[MAXLINE],*de=" ",*arg[10];	/* from apue.h */
		pid_t	pid;
		int	status,i=0;

		if (signal(SIGINT, sig_int) == SIG_ERR)
				err_sys("signal error");

		printf("%% ");	/* print prompt (printf requires %% to print %) */
		while (fgets(buf, MAXLINE, stdin) != NULL) {
				if (buf[strlen(buf) - 1] == '\n')
						buf[strlen(buf) - 1] = 0; /* replace newline with null */
				for(i=0;i<10;i++)
					arg[i]=NULL;
				i=0;
				arg[0]=strtok(buf,de);
				while(arg[i]!=NULL&&i<10)
				{
					i++;
					arg[i]=strtok(NULL,de);
					if(arg[i]==NULL) break;
				}
				if(strcmp(arg[0],"cd")==0)
					chdir(arg[1]);
				else if ((pid = fork()) < 0) {
						err_sys("fork error");
				} else if (pid == 0) {		/* child */
						/*for(i=0;i<10;i++)
							arg[i]=NULL;
						i=0;
						arg[0]=strtok(buf,de);
						while(arg[i]!=NULL&&i<10)
						{
							i++;
							arg[i]=strtok(NULL,de);
							if(arg[i]==NULL) break;
						}*/
						execvp(arg[0],arg);
						err_ret("couldn't execute: %s", arg[0]);
						exit(127);
				}
				/* parent */
				if ((pid = waitpid(pid, &status, 0)) < 0&&strcmp(arg[0],"cd")!=0)
						err_sys("waitpid error");
				printf("%% ");
		}
		exit(0);
}

		void
sig_int(int signo)
{
		printf("interrupt\n%% ");
}

