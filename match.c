#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

char *pattern;
int ignore_case = 0;

void usage(char *s) {
	fprintf(stderr, "Usage: %s [-i] pattern\n", s);
	exit(2);
}

void parse_args(int argc, char *argv[]) {
	if (argc == 3) {
		if (strstr(argv[1], "-i") == NULL)
			usage(argv[0]);
		ignore_case = 1;
		pattern = argv[2];
	} else if (argc == 2) {
		if (strstr(argv[1], "-i") != NULL)
			usage(argv[0]);
		pattern = argv[1];
	} else {
		usage(argv[0]);
	}
}

int main(int argc, char *argv[]) {
	parse_args(argc, argv);
	if (strlen(pattern) == 0)
		usage(argv[0]);

	char buffer[1024];
	int match_count = 0;
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		char *found;
		if (ignore_case) {
			found = strcasestr(buffer, pattern);
		} else {
			found = strstr(buffer, pattern);
		}
		if (found != NULL) {
			printf("%s", buffer);
			match_count++;
		}
	}
	if (match_count > 0)
		return 0;
	else
		return 1;
}
