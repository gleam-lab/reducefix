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
    if(sum == 0) res++;
    unordered_map<int, int> prefix_count;
    prefix_count[0] = 1;
    int pre = 0;
    for(auto x : a) {
        pre = (pre + x) % m;
        res += prefix_count[(pre - sum + m) % m];
        prefix_count[pre]++;
    }

    cout << res << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    ifstream in("in.txt"), out("out.txt");
    cin.rdbuf(in.rdbuf()), cout.rdbuf(out.rdbuf());
    auto start = chrono::system_clock::now();
#endif
    int T = 1;
    cin >> T;
    while(T--) solve();
#ifndef ONLINE_JUDGE
    auto end = chrono::system_clock::now();
    cout << "Run Time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";
#endif
    return 0;
}