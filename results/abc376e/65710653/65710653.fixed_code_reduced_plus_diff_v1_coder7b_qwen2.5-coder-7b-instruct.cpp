#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += (long long)a[n - 1 - i] * b[i];
        }
        
        cout << ans << '\n';
    }

    return 0;
}