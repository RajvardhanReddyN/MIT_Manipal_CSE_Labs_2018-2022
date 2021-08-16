#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* thread_code(void* n)
{
	int sum = 0;
	int limit = *((int*)n);
	for (int i = 1; i <= limit; i++)
		sum += i;
	*((int*)n) = sum;
}

void main()
{
	int n, num;
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	num = n;
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void*)&n);
	pthread_join(thread, NULL);
	printf("Sum of all non-negetive numbers from 1 to %d = %d\n", num, n);
}