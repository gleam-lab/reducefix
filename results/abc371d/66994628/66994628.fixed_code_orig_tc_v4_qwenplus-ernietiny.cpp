#include<bits/stdc++.h>
using namespace std;
int n,q;
long long sum[100005]; // 假设输入数据长度不会超过这个范围

int main(){
	// ... 你的代码 ...

	// 读取输入数据
	long long x, p;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> x; // x 是要查询的区间左端点
		cin >> p; // p 是查询区间右端点
		sum[x] = sum[p] + (long long)(n - x); // 计算区间和
	}

	// 对每个查询区间进行计算并输出结果
	while(q--){
		long long l, r; // 查询区间左端点和右端点
		cin >> l >> r; // 输入查询区间左端点和右端点
		// 查找左端点在数组中的索引位置，如果找不到则输出错误提示
		if(sum[l] != sum[r]){ // 如果区间和不相等，输出错误提示
			cout << "Invalid query" << endl; // 或者使用其他错误处理方式
		} else { // 如果区间和相等，输出查询结果
			cout << sum[r] - sum[l] << endl; // 减去区间初始值得到结果
		}
	}
}