#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void * even(void *brr)
{
	int *arr = (int*)brr;
	int size = arr[0];
	int sum = 0;
	for (int i = 1; i <= size; i++) 
		if (arr[i] % 2 == 0)
			sum += arr[i];
	return (void *) sum;
}

void * odd(void *brr)
{
	int *arr = (int*)brr;
	int size = arr[0];
	int sum = 0;
	for (int i = 1; i <= size; i++)
		if (arr[i] % 2 != 0)
			sum += arr[i];
	return (void *) sum;
}

int main()
{
	int n, e, o;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int arr[n + 1];
	arr[0] = n;
	printf("Enter elements:\n");
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	pthread_t t1, t2;
	pthread_create(&t1, 0, &even, (void *)arr);
	pthread_create(&t2, 0, &odd, (void *)arr);
	pthread_join(t1, (void*) &e);
	pthread_join(t2, (void*) &o);
	printf("Sum of even numbers in the array is = %d\n", (int)e);
	printf("Sum of odd numbers in the array is = %d\n", (int)o);
}