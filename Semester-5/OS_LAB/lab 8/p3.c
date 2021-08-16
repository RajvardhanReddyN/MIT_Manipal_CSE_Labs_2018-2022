#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *prime(void* arr)
{
	int n1 = *((int*)arr);
	int n2 = *(((int*)(arr + sizeof(int))));
	printf("Prime numbers: ");
	for (int i = n1; i <= n2; i++)
	{
		int flag = 0;
		for (int j = 2; j <= i / 2; j++)
		{
			if ((i % j) == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("%d ", i);
	}
	printf("\n");
}

int main()
{
	int arr[2];
	printf("Enter lower limit: ");
	scanf("%d", &arr[0]);
	printf("Enter upper limit: ");
	scanf("%d", &arr[1]);
	pthread_t thread;
	pthread_create(&thread, 0, &prime, (void*)arr);
	pthread_join(thread, NULL);
}
