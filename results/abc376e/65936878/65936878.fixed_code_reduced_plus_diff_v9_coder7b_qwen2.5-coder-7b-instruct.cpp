#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<double, pair<int, int>>> v(n);

        for(int i = 0; i < n; ++i) {
            cin >> v[i].s.f >> v[i].s.s;
            v[i].f = double(v[i].s.f) / v[i].s.s;
        }

        sort(v.begin(), v.end());

        double ans = 1e18;
        for(int i = 0; i <= n-k; ++i) {
            int sumB = 0;
            for(int j = i; j < i+k; ++j) {
                sumB += v[j].s.s;
            }
            ans = min(ans, v[i].f * sumB);
        }

        cout << ans << '\n';
    }

    return 0;
}