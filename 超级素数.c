#include<stdio.h>
#include<math.h>
int susu(int a){
	int i;
	for(i = 2; i < sqrt(a); i++){
		if( a%i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n,i,count=0, he=0, max;
	for(i = 100; i < 999; i++){
		int a, b, c;
		a = i/100, b = i/10%10, c=i%10;
		int m1 = a*b*c, m2 = a+b+c, m3=a*a+b*b+c*c;
		int n1 = susu(m1), n2 = susu(m2), n3 = susu(m3),n4 = susu(i);
		if(n1 == 1&&n2 == 1&&n3 == 1&&n4 == 1){
			count++, he+=i, max=i;	
		}
	}
	printf("%d %d %d",count, he, max);
	return 0;
}
