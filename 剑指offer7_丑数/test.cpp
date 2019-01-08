#include<iostream>
using namespace std;

//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，
//但14不是，因为它包含质因子7。
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数
typedef struct N_uglynumber{
	int ugly_number;
	int N;
}N_uglynumber;

class Solution {
public:
	bool Is_prime_number(int index){
		int i = 1;
		for (i = 1; i < index; ++i){
			if (index%i == 0){
				return false;
			}
		}
		return true;
	}

	bool Is_Ugly_number(int index){
		//初步分析，能被7整除的都不是丑数，质数除外
		//7,11,13,14,17,19,21

		//判断index是否为质数
		if (index == 1 || index == 2 || index == 3 || index == 5){
			return true;
		}
		if (Is_prime_number(index)){
			return false;
		}
		if (index % 7 == 0){
			return false;
		}
		return true;
	}

	int GetUglyNumber_Solution(int index) {
		N_uglynumber number;
		number.N = 1;
		number.ugly_number = 1;
		//int ugly_number=1;
		int i = 2;
		while (1){
			if (number.N < index){
				if (Is_Ugly_number(i)){
					number.N++;
					number.ugly_number = i;
					/*ugly_number = i;*/
				}
			}
			else if (number.N == index){
				return number.ugly_number;
			}
			++i;
		}
		return number.ugly_number;
	}
};

int main(){
	Solution s;
	/*cout<<s.Is_Ugly_number(14)<<endl;*/
	cout<<s.GetUglyNumber_Solution(100)<<endl;//获得第一个丑数
	
	system("pause");
	return 0;
}