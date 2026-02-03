#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

// parsing della linea in argv
char **parse_line(char *line) {
    char **argv = malloc(sizeof(char *) * MAX_ARGS);
    int i = 0;
    char *token = strtok(line, " \t\n");
    while (token != NULL && i < MAX_ARGS - 1) {
        argv[i++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    argv[i] = NULL;
    return argv;
}
// libera argv
void free_argv(char **argv) {
    for (int i = 0; argv[i] != NULL; i++)
        free(argv[i]);
    free(argv);
}
int main() {
    char line[MAX_LINE];
    while (1) {
        // prompt
        printf("mini-shell> ");
        fflush(stdout);
        // input
        if (!fgets(line, MAX_LINE, stdin))
            break;

        // parsing
        char **argv = parse_line(line);
        if (argv[0] == NULL) {
            free_argv(argv);
            continue;
        }
        // builtin: exit
        if (strcmp(argv[0], "exit") == 0) {
            free_argv(argv);
            break;
        }
        // fork
        pid_t pid = fork();
        if (pid == 0) {
            // FIGLIO
            execvp(argv[0], argv);
            perror("execvp");
            exit(1);
        }
        else if (pid > 0) {
            // PADRE
            wait(NULL);
        }
        else {
            perror("fork");
        }
        free_argv(argv);
    }
    return 0;
}