#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), prefix_sum(2 * n);
    unordered_map<int, int> count;
    long long ans = 0;
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[n + i] = a[i];
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
    }
    
    for(int i = 0; i < 2 * n; ++i) {
        if(i >= n) {
            ans = (ans + count[(prefix_sum[i] - prefix_sum[i - n] + m) % m]) % MOD;
        }
        count[prefix_sum[i]]++;
    }
    
    cout << ans << '\n';
    return 0;
}