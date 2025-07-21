#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for(auto &x : a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    map<int, int> mp;
    mp[0]++;

    int pre = 0;
    for(int x : a) {
        pre = (pre + x) % m;
        res += mp[(pre - sum + m) % m];
        res += mp[pre];
        mp[pre]++;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    ifstream in("in.txt");
    ofstream out("out.txt");
    cin.rdbuf(in.rdbuf()), cout.rdbuf(out.rdbuf());

    auto start = chrono::high_resolution_clock::now();
#endif

    int T = 1;
    cin >> T;
    while(T--) solve();

#ifndef ONLINE_JUDGE
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << "Run Time: " << duration << "ms\n";
#endif

    return 0;
}