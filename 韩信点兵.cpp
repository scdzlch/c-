#include <iostream>

class HanXin{
	public:
		int add;
		
		HanXin(){
			add = 0;
		}
		
		line3(int n){
			add += n*70;
		} 
		
		 line5(int n){
			add += n*21;
		}
		
		 line7(int n){
			add += n*15;
		}
		
	showMany(){
			while(add >= 105){
				add -= 105;
			}
			if(add < 100 && add > 10) {
				std::cout << add << std::endl;
			}
			else std::cout << "Impossible" << std::endl;
		}
};

int main() {

    int n, n1, n2, n3;

    std::cin >> n;

    for(int i = 0; i < n; ++i) {

        std::cin >> n1 >> n2 >> n3;

        HanXin hx;  //����

        hx.line3(n1);  //3��һ��

        hx.line5(n2);   //5��һ��

        hx.line7(n3);   //7��һ��

        hx.showMany();

    }
	
}

