#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 2e6+7;
vector<pair<int, LL>> prefixSum;

LL query(int left, int right) {
    if (left == 1) {
        return prefixSum[right - 1].second;
    } else {
        return prefixSum[right - 1].second - prefixSum[left - 2].second;
    }
}

int main() {
    int n, m;
    cin >> n;
    prefixSum.push_back({1, 0});
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        prefixSum.push_back({a, prefixSum.back().second + a});
    }
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}