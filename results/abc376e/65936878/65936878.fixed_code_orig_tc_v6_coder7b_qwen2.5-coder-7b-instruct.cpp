#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        
        // Read input into pairs (A_i, B_i)
        for(int i = 0; i < n; i++) {
            cin >> v[i].f >> v[i].s;
        }
        
        // Sort by A_i in descending order and by B_i in descending order
        sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
            return a.f > b.f || (a.f == b.f && a.s > b.s);
        });
        
        int ans = 0;
        for(int i = 0; i < k; i++) {
            ans += v[i].f * v[i].s;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}