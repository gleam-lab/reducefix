#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long max_a = a[k-1];
        long long sum_b = accumulate(b.begin(), b.begin()+k, 0LL);

        long long ans = max_a * sum_b;

        for(int i=k; i<n; i++) {
            sum_b -= b[i-k];
            sum_b += b[i];
            max_a = max(max_a, a[i]);
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << '\n';
    }
    return 0;
}