#include<stdio.h>
int recur(int,int,int);
int main(){
int number1,number2,state,great,small;
scanf("%d%d%d",&number1,&number2,&state);
great = (number1 > number2) ? number1:number2;
small = (number1 < number2) ? number1:number2;
printf("%d",recur(small,great,state%2));
return 0;    
}
int recur(int a,int b,int c){
	if(a == b && c == 0 && a%2==1) return 0;
	else if(a == b && c == 0 && a%2==0) return a;
	else if(a == b && c == 1 && a%2==1) return a;
	else if(a == b && c == 1 && a%2==0) return 0;
	else if(a % 2 == c) return a + recur(a+1,b,c);
	else return recur(a+1,b,c);
}