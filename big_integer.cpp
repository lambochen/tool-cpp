#include <iostream>
#include <stack>
#include <list>
#include <cstring>
#define N 10005
using namespace std;

// 用于存放中间值数组 
int tmp_a[N];

// 加法 
string addition(string a, string b);
// 阶乘
string factorial(long n);
int main(){
	string a = "11111111";
	string b = "2222222222";

	// 加法 
//	string res = addition(a,b);
//	cout<<a<<"+"<<b<<"="<<res<<endl;

	// 阶乘 
	long c = 11111;
	cout<<factorial(c)<<endl;	
	return 0;
}

/* 
大整数加法 
Args:
	a: 待计算大整数
	b: 待计算大整数 
*/ 
string addition(string a, string b){
	// 用双向链表作堆栈的底层结构
	stack<int, list<int> > s1,s2,res;
	int len_a = a.length(), len_b = b.length();
	for(int i=0;i<len_a;i++){
		s1.push(a.at(i) - '0');
	}
	for(int i=0; i<len_b; i++){
		s2.push(b.at(i) - '0');
	}
	int len = min(len_a, len_b), f = 0;
	// 计算公共长度的部分 
	for(int i=0; i<len; i++){
		f += s1.top() + s2.top();
		s1.pop(), s2.pop();
		res.push(f%10);
		f /= 10;
	}
	// 此部分代码只会执行一个while 
	while(s1.empty() == false){
		f += s1.top();
		s1.pop();
		res.push(f%10);
		f /= 10;
	}
	while(s2.empty() == false){
		f += s2.top();
		s2.pop();
		res.push(f%10);
		f /= 10;
	}
	// 计算最后剩余的进位f 
	while(f){
		res.push(f%10);
		f /= 10;
	}
	// res 逆序即结果字符串 
	string result = "";
	while(res.empty() == false){
		result += res.top() + '0';
		res.pop();
	}
	return result;
}

/**
计算一个数的阶乘
Args:
	n: 待计算数 
Return:
	阶乘 
*/
string factorial(long n){
	// 负数直接返回空串 
	if(n < 0){
		return "";
	}
	// 将数组a初始化为0 
	memset(tmp_a, 0, sizeof(tmp_a));
	tmp_a[0] = 1;
	// carry:进位 
	int tmp, carry = 0;
	for(int i=2; i<=n; i++){
		// TODO 此处可做优化内层循环跳出条件判断 
		for(int j=0; j<N-1; j++){
			tmp = tmp_a[j] * i + carry;
			tmp_a[j] = tmp % 10;
			carry = tmp / 10;
		} 
	}
	string result = "";
	for(int i=N-1; i>=0; i--){
		if(tmp_a[i] != 0){
			for(int j=i; j>=0; j--){
				result += tmp_a[j] + '0';
			}
			break;
		}
	}
	return result;
}
