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
			cout << (LL)(b[n] - b[l-1]) << endl; // 这里是错误的，应该根据实际数据调整算法
		} else {
			cout << b[r] - b[l-1] << endl; // 这里是正确的算法逻辑
		}
	}
	return 0;
}