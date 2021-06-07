#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char** argv){
	/*Print Version and Exit Information */
	puts("Lispy Version(LISPY) 0.0.0.0.1");
	puts("Press Ctrl+C to Exit\n");

	/*Never Ending Loop*/
	while(1){
		/*Output o*/
		char* input = readline(">>>>");

		add_history(input);

		printf("No You're a %s", input);

		free(input);
	}
	return 0;
}