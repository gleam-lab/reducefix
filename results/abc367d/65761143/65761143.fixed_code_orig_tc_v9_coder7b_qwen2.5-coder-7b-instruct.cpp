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
    map<int, int> prefix_sum_count;
    prefix_sum_count[0] = 1;
    int pre = 0;
    for(int x : a) {
        pre = (pre + x) % m;
        res += prefix_sum_count[(pre - sum + m) % m];
        prefix_sum_count[pre]++;
    }
    
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}