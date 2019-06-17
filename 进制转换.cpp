#include <iostream>

class Number{
	public:
		int n;
		int m;
		int add[100],sum;
		Number(int n0, int m0){
			n = n0, m = m0,sum = 0;
		}
		
		Number converto(int t){
			int i = 0; 
			do{	
				i++;
				add[i] = n%t; 
				n = n/t;
			}
			while(n != 0);
			
			for(; i>0;i--)
				sum = sum*10 + add[i];
			return *this;
		}
		
		void show(){
			std::cout << sum << std::endl;
		}
		
};

int main() {

    int n, n1, n2;

    std::cin >> n;

    for(int i = 0; i < n; ++i) {

        std::cin >> n1 >> n2;

        Number no1(n1, 10);     //n1是10进制正整数

        Number no3 = no1.converto(n2);  //no3是n2进制的正整数

        no3.show();     //输出结果

    }

}

