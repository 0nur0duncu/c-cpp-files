#include<stdio.h>
int main(){
 int m,n,i=2,fibo1=1,fibo2=1,fiboHold,totFibo=1;
 int j=3,tribo1=1,tribo2=1,tribo3=2,triboHold1,totTribo=2;
 printf("Please enter two number respectively m n:  ");
 scanf("%d%d",&m,&n);
for(;i<=m;i++){
	totFibo+=fibo2;
	fiboHold=fibo1+fibo2;
	fibo1=fibo2;
	fibo2=fiboHold;		
}
for(;j<=n;j++){
	totTribo+=tribo3;
	triboHold1=tribo1+tribo2+tribo3;
	tribo1=tribo2;
	tribo2=tribo3;
	tribo3=triboHold1;		
}
printf("%d",totTribo+totFibo);

return 0;    
}