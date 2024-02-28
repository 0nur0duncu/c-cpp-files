#include<stdio.h>
#include <stdlib.h> 
int *enuzuntekrar(int B[ ],int x); 

int main()
{
	int *A,n,*B;
	scanf("%d",&n);
	A = (int *) malloc( sizeof(int)*n );
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	B = enuzuntekrar(A,n);
	printf("%d",*B);
	free(A);
	return 0;    
}

int *enuzuntekrar(int B[ ],int x) 
{
	int counter = 1, holdValue = 0, *pholdValue = &holdValue,state = B[0];
	for(int i = 1; i< x; i++){
		if(B[i] == state)
			counter++;
		else{
			state = B[i];
			counter = 1;
		}
		if(x > 0 && counter >= holdValue)
			holdValue = counter;
	}
	return pholdValue;
}    