#include <stdio.h>
#include <string.h>

#define MAX_LEN 256
int main() {
	// previous number in input stream
	int prev = 0;
	int result = 0;
	FILE* fp;
	fp = fopen("Input.txt", "r");
	if (fp == NULL) {
		perror("Failed: ");
		return 1;
	}

	char buffer[MAX_LEN];
	// change fp to stdin if using standard input
	while (fgets(buffer, MAX_LEN, fp)) {
		int number;
		if (sscanf(buffer, "%d", &number) == 1) {
			if (prev != 0 && number > prev) {
				result++;
			}
			prev = number;
		}
	}

	fclose(fp);
	printf("%d\n", result);
	return result;
}