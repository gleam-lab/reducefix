#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for(int &x: a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    if(sum == 0) res++;
    unordered_map<int, int> map;
    map[0]++;
    int pre = 0;
    for(int x: a) {
        pre = (pre + x) % m;
        res += map[(pre - sum + m) % m];
        map[pre]++;
    }

    cout << res << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    ifstream in("in.txt"); ofstream out("out.txt");
    cin.rdbuf(in.rdbuf()); cout.rdbuf(out.rdbuf());
    auto start = chrono::system_clock::now();
#endif
    int T = 1;
    // cin >> T;
    while(T--) solve();
#ifndef ONLINE_JUDGE
    auto stop = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    cout << "Run Time: " << duration << "ms\n";
#endif
    return 0;
}