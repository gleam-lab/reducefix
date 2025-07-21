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
    map<int, int> maps[2];
    maps[0][0] = 1;  // Start with a count of 1 for the initial state
    for (int x : a) {
        int pre = (sum + x) % m;
        res += maps[0].count(pre);
        maps[1][pre]++;
        maps[0][pre]++;
    }

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    while (T--) solve();
    
    return 0;
}