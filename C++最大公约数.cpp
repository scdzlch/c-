#include<iostream>

int max(int* m, int* n){
	if(m < n){
		int q = *m;
		*m = *n;
		*n = q;
	} 
}

class Number{
	private:
		int n;
	public : 
		Number(int j){
			n = j;
		}
		void show(){
			std::cout << n <<std::endl;
		}
		int maxDivisor(Number m0){
			int m = m0.n;
			max(&m, &n);
			int q = m % n;
			while(q != 0){
				m = n;
				n = q;
				q = m % n;
			} 
			return n;
		}
};
 
int main() {

    int n, n1, n2;

    std::cin >> n;

    for(int i = 0; i < n; ++i) {

        std::cin >> n1 >> n2;

        Number no1(n1), no2(n2);

        Number no3 = no1.maxDivisor(no2);  //最大公约数

        no3.show();

    }

}

