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
		if(r >= a[n]) {
			cout << (LL)(b[n] - b[l-1]) << endl; // 这里应该是计算差值，但代码中直接输出结果
		} else {
			cout << b[r-1] << endl; // 这里应该是计算差值后的结果，但代码中直接输出原始值
		}
	}
	return 0;
}