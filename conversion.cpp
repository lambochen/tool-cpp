#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <string>
using namespace std;
string conversion(long long data, int conv);
int main(){
	long long data = 100000;
	int conv = 16;
	cout<<conversion(data, conv)<<endl;
	return 0;
} 
/* 
进制转换
Args:
	data:原始数据，十进制整型 
	conv:待转换进制数 (2-16)
*/  
string conversion(long long data, int conv){
	string result = "";
	stack<int, vector<int> > s;
	// 处理负数情况 
	if(data < 0){
		result += "-";
	}
	while(data){
		s.push(data % conv);
		data /= conv;
	}
	while(s.empty() == false){
		int temp = s.top();
		s.pop();
		// 说明conv小于等于十进制 
		if(temp < 10){
			result += temp + '0';
		} else {
			result += temp - 10 + 'A';
		}
	}
	return result;
}

