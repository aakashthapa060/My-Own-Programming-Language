#include <stdio.h>
#include <stdlib.h>
// If we are compiling on windows
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// Fake readline function

char *readline(char* prompt){
	fputs(prompt, stdout);
	fgets(buffer, 2048,stdin);

	char* cpy = malloc(strlen(buffer) + 1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy) -1] = '\0';
	return cpy;
}

// Fake and_history function
void add_history(char* unused){}


// OtherWise Include The Editlink headers

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char **argv){
	puts("Lispy Version 0.0.0.0.0.0.1");
	puts("Press Crtl+C to Exit\n");

	while(1){
		char* input = readline(">>>> ");

		add_history(input);

		printf("No you're a %s \n", input);

		free(input);

	}
	return 0;
}