#include <iostream>
using namespace std;
long long max_substring(int a[], int n);
int main(){
	int a[7] = {-4,11,-2,13,-7,-3,12};
	int b = 7;
	cout<<max_substring(a,b)<<endl;
	return 0;
}
/**
给定一个数字序列，求出最大子串和（子串：数字需要紧邻）
Args:
	data: 数字数组
	len: 数组长度 
*/
long long max_substring(int data[], int len){
	long long result = data[0], tmp = data[0];
	for(int i=0; i<len; i++){
		if(tmp > 0){
			tmp += data[i];
		} else {
			tmp = data[i];
		}
		if(tmp > result){
			result = tmp;
		}
	} 
	return result;
}
