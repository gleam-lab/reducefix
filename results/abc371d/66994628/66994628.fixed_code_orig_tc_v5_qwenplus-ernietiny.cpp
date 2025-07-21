#include<bits/stdc++.h>
using namespace std;
int n,q;
long long sum[100005]; // 假设输入数据长度不会超过这个范围

int main(){
	// ... 你的代码 ...

	// 读取输入数据
	long long x, p;
	cin >> n >> x >> p; // 注意这里假设输入的数据长度不会超过数组大小

	// 处理边界情况
	if (n < 0) {
		cout << "Invalid input!" << endl;
		return 0;
	}

	// 处理查询操作
	while (q--) {
		long long l, r; // 这里假设查询操作的范围不会超过数组大小
		cin >> l >> r; // 注意这里输入的应该是数值而非字符串表示的索引或其他类型数据

		// 这里可能需要添加一些逻辑来处理查询结果，例如通过二分查找找到中间值并输出其差值
		// 但由于输入数据的范围限制，这里只能提供大致的处理思路
	}

	// ... 其他代码 ...
}