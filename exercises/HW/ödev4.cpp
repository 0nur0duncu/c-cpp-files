#include<stdio.h>
int main()
{ 
	int A[5][5],i=0,total=0;
	do{
		int j=0;
		do{
			scanf("%d",&A[i][j]);
			j++;
		}while(j<5);
		i++;
	}while(i<5);
	
	for(int c=0;c<5;c++){//column number [][c]
		for(int t=0;t<5;t++){
			int holdElement=t;
			for(int k=t+1;k<5;k++) if(A[k][c]<A[holdElement][c]) holdElement=k;
			int temp=A[t][c];
			A[t][c]=A[holdElement][c];
			A[holdElement][c]=temp;
		}
		
	}
	for(int r=0;r<5;r++){//row number [r][]
		for(int t=0;t<5;t++){
			int holdElement=t;
			for(int k=t+1;k<5;k++) if(A[r][k]>A[r][holdElement]) holdElement=k;
			int temp=A[r][t];
			A[r][t]=A[r][holdElement];
			A[r][holdElement]=temp;
		}		
	}
	for(int r=0;r<5;r++) for(int c=r+1;c<5;c++)	total+=A[r][c];
	printf("%d",total);
return 0;    
}
