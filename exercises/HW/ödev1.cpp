//Soruda Dizi kullanmak zorunludur. Aşağıdaki A[16] ve B[4] dizileri kullanılacaktır.
#include<stdio.h>
int main(){ 
    int A[16],B[4],i=0,sakla1,sakla2,gecici1,gecici2;
    for(;i<16;){
        scanf("%d",&A[i]);
        if(i==3 || i==7 || i==11 || i==15){
            for(int j=i-3;j<=i;j++){
                sakla1=j;
                for(int k=j+1;k<=i;k++){
                    if(A[sakla1]<=A[k]) sakla1=k;
                }
                gecici1=A[j];
                A[j]=A[sakla1];
                A[sakla1]=gecici1;
            }
        }
        if(i==15){
            for(int t=0;t<4;t++) B[t]=A[5*t];
            for(int s=0;s<=3;s++){
            	sakla2=s;
				for(int m=s+1;m<=3;m++){
					if(B[sakla2]<=B[m]) sakla2=m;
				} 
				gecici2=B[s];
                B[s]=B[sakla2];
                B[sakla2]=gecici2;		
        	}
			printf("%d",B[0]+B[3]);
    	}
    	i++;
	}
return 0;    
}