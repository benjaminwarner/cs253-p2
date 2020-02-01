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
		printf("ignore_case: %d\n", ignore_case);
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
	#if ignore_case
		#define str_contains strcasestr
	#else
		#define str_contains strstr
	#endif

	char buffer[256];
	int match_count = 0;
	while (fgets(buffer, 256, stdin) != NULL) {
		if (str_contains(buffer, pattern) != NULL) {
			printf("%s", buffer);
			match_count++;
		}
	}
	if (match_count > 0)
		return 0;
	else
		return 1;
}
