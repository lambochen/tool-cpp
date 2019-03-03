#include <iostream>
#include <stack>
#include <list>
using namespace std;
string addition(string a, string b);
int main(){
	string a = "11111111";
	string b = "2222222222";
	// 加法 
	string res = addition(a,b);
	cout<<a<<"+"<<b<<"="<<res<<endl;
	
	return 0;
} 

// 大整数加法 
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
