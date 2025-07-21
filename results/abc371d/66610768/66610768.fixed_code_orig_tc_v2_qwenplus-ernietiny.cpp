#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6+7;
int main() {
	int n, m;
	cin >> n;
	vector<int>a(n+1), b(n+1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while(m--) {
		int l, r;
		cin >> l >> r;
		// 这里应该检查边界条件，并确保所有输入都是合法的
		// ...
		auto l_i = lower_bound(a.begin(), a.end(), l); // 这里存在错误，应该使用lower_bound_range而不是lower_bound
		auto r_j = upper_bound(b.begin(), b.end(), r); // 这里同样存在错误，应该是upper_bound_range
		int i = l_i - a.begin(); // 这里计算索引错误，应该是r_j - b.begin()
		// 这里应该使用正确的索引来获取对应的值并进行计算
		// ...
	}
	return 0;
}