#include<stdio.h>
#include<stdlib.h>
int main(){
	int p,q,m,n;
	printf("Enter the dimensions of the first matrix: ");
	scanf("%d%d",&p,&q);
	printf("Enter the dimensions of the second matrix: ");
	scanf("%d%d",&m,&n);
	if(m!=q){
		printf("The matrices are unsuitable for multiplication");
		return 0;
	}
	int size1 = p*q*sizeof(int);
	int size2 = m*n*sizeof(int);
	int arr1 = (int)malloc(size1);
	int arr2 = (int)malloc(size2);
	printf("Enter the elements of the first array\n");
	int i,j,k;
	for (i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",arr1+q*i+j);
		}
	}
	printf("Enter the elements of the second array\n");
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",arr2+n*i+j);
		}
	}
	int size3 = p*n*sizeof(int);
	int res = (int)malloc(size3);
	int sum = 0;
	for(i=0;i<p;i++){
		for(j=0;j<n;j++){
			for(k=0;k<m;k++){
				sum+= arr1[i*m+k] * arr2[k*n+j];
			}
			res[i*n+j] = sum;
			sum=0;
		}
	}
	printf("The result is\n");
	for(i=0;i<p;i++){
		for(j=0;j<n;j++){
			printf("%d ",*(res+n*i+j));
		}
		printf("\n");
	}
	return 0;
}