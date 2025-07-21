#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x %= m;
    }

    // Compute prefix sums modulo m
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = (prefix[i] + a[i]) % m;

    long long res = 0;
    map<int, int> cnt;
    cnt[0] = 1;

    // We want to count the number of pairs (i, j) such that:
    // (prefix[j] - prefix[i]) % m == 0 => prefix[j] == prefix[i]
    // So we keep track of counts and add them as we go
    for (int i = 1; i <= n; ++i) {
        int curr = prefix[i];
        res += cnt[curr];
        cnt[curr]++;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    static ifstream in("in.txt");
    static ofstream out("out.txt");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
#endif

    int T = 1;
    // Uncomment below if multiple test cases are expected
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}