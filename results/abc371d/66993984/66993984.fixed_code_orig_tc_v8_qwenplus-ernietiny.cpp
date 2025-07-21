#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; // 输入的数字序列长度
	cin >> n; // 读取输入的长度

	// 初始化一个长度为n的数组来存储生成的序列
	vector<int> sequence(n);

	// 根据输入的数字序列生成序列
	for (int i = 0; i < n; i++) {
		// 根据输入的数字减去一个固定的值来生成序列中的元素值
		sequence[i] = n - i; // 例如，序列中的元素值可以是输入数字减去一个固定的值，例如-某个特定的值。
	}

	// 输出生成的序列
	cout << sequence << endl; // 输出生成的序列

	return 0;
}