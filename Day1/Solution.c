#include <stdio.h>
#include <string.h>
#include "../Tools/Queue.h"

#define MAX_LEN 256

int PartOne() {
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
	return result;
}

//TODO giving different results with runs over 1000 loops.
//The fgets loop is having issues reading I think.
//Also, results not being printed from main()
int PartTwo() {
	int result = 0;
	struct Queue* queue = createQueue(3);
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
			int sum1;
			int sum2;
			if (sscanf(buffer, "%d", &number) == 1) {
				printf("number is % d\n", number);
				if (isFull(queue)) {
					/*printf("sum1 queue %d, %d, %d \n", queue->array[queue->head], queue->array[queue->tail - 1], queue->array[queue->tail]);
					printf("sum2 queue %d, %d, %d \n", queue->array[queue->tail - 1], queue->array[queue->tail], number);
					printf(" head %d, tail %d\n", queue->head, queue->tail);*/
					sum1 = queue->array[queue->head] + queue->array[queue->tail - 1] + queue->array[queue->tail];
					sum2 = queue->array[queue->tail - 1] + queue->array[queue->tail] + number;
					//printf("sum 1 = %d and sum 2 = %d\n", sum1, sum2);
					if (sum1 < sum2) result++;
					dequeue(queue);
					enqueue(queue, number);
				}
				else { //fill up the queue so we can start comparing
					enqueue(queue, number);
				}
			}
	}
	printf("Result = %d", result);
	fclose(fp);
	return result;
}


int main() {
	printf("Part One Result: %d\n", PartOne());
	printf("Part Two Result: %d\n", PartTwo());
	return 0;
}