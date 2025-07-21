#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; ++i) cin >> a[i].first;
        for(int i = 0; i < n; ++i) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        long long ans = LLONG_MAX;
        for(int i = 0; i <= n-k; ++i) {
            long long curr_ans = 1LL * a[i+k-1].first * accumulate(b.begin()+i, b.begin()+i+k, 0LL);
            ans = min(ans, curr_ans);
        }

        cout << ans << '\n';
    }
    
    return 0;
}