#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{

	int var_1=0;
	int var_2=0;
	
	pid_t pid;

		do
		{
			printf("Input number which exceeds to 0.\n"); 
  			scanf("%d", &var_2);	
		}while (var_2 <= 0);

		pid = fork();

		if (pid == 0)
		{
			printf("Child Process is executing without issues ...\n");
			printf("%d\n",var_2);
			while (var_2!=1)
			{
				if (var_2%2 == 0)
				{
					var_2 = var_2/2;
				}
				else if (var_2%2 == 1)
				{
					var_2 = 3 * (var_2) + 1;
				}	
			
				printf("%d\n",var_2);
			}
		
			printf("Child process completed.\n");
		}
		else
		{
			printf("Parent waiting for the child Process' termination\n");
			wait(0);
			printf("Parent process executed\n");
		}
	return 0; 
}

