#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for (int &x : a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    long long res = 0;
    map<int, int> countMap;
    countMap[0] = 1; // Start with count of 0 as 1 for the case when prefix sum is 0 initially.
    int prefix = 0;
    for (int x : a) {
        prefix = (prefix + x) % m;
        // Count how many times the prefix sum modulo m equals to (prefix - sum) modulo m
        res += countMap[(prefix - sum + m) % m];
        countMap[prefix]++;
    }

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}