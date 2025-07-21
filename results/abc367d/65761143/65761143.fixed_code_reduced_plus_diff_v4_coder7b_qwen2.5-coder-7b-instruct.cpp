#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for(int &x : a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    map<int, int> cnt;
    cnt[0]++;

    for(int x : a) {
        sum = (sum + x) % m;
        res += cnt[(sum * 2) % m];
        res += cnt[(sum + m - m / gcd(m, x)) % m];
        cnt[sum]++;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    ifstream cin("in.txt"), cout("out.txt");
    auto start = chrono::high_resolution_clock::now();
#endif

    int T = 1;
    cin >> T;
    while(T--) solve();

#ifndef ONLINE_JUDGE
    auto end = chrono::high_resolution_clock::now();
    cout << "Runtime: " << chrono::duration<double>(end - start).count() << " ms\n";
#endif

    return 0;
}