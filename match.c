#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pattern;
int ignore_case = 0;

void usage(char *s) {
	fprintf(stderr, "Usage: %s [-i] pattern\n", s);
	exit(2);
}

void parse_args(int argc, char *argv[]) {
	if (argc == 3) {
		ignore_case = (strcmp(argv[1], "-i") == 0);
		pattern = argv[2];
	} else if (argc == 2) {
		pattern = argv[1];
	} else {
		usage(argv[0]);
	}
}

int main(int argc, char *argv[]) {
	parse_args(argc, argv);
	if (strlen(pattern) == 0)
		usage(argv[0]);

	char buffer[256];
	int match_count = 0;
	while (fgets(buffer, 256, stdin) != NULL) {
		if (strstr(buffer, pattern) != NULL) {
			printf("%s", buffer);
			match_count++;
		}
	}
	if (match_count > 0)
		return 0;
	else
		return 1;
}
